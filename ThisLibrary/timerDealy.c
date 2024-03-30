/*
 * timerDealy.c
 *
 *  Created on: Mar 30, 2024
 *      Author: pavel
 */
#include"timerDelay.h"

// Volatile flag indicating that the timer has overflowed, typically set in an interrupt
volatile uint8_t delayComplete;

// Volatile function pointer to store the address of the callback function
volatile void (*delayCompleteCallback)(void);


/**
 * @brief   Delays execution for a specified time using a hardware timer.
 * @param   htim: Pointer to the timer handle structure
 * @param   timDelay: Delay time in milliseconds
 * @retval  None
 */
void timerDelay(TIM_HandleTypeDef *htim, uint32_t timDelay) {
    delayComplete = 0; // Reset the delay complete flag

    // Obtain the current values of the timer's period and prescaler
    uint32_t prescaler = htim->Init.Prescaler;

    // Calculate the reload value for the delay
    uint32_t reloadValue = ((SystemCoreClock / (prescaler + 1)) / 1000) * timDelay;

    // Set the reload value to achieve the desired delay
    __HAL_TIM_SET_AUTORELOAD(htim, reloadValue);

    // Deinitialize and reinitialize the timer to apply the changes
    HAL_TIM_Base_DeInit(htim);
    HAL_TIM_Base_Init(htim);

    // Start the timer with interrupt
    // Check and clear the update flag before starting the timer
    if (__HAL_TIM_GET_FLAG(htim, TIM_FLAG_UPDATE)) {
        __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
    }
    HAL_TIM_Base_Start_IT(htim);

    // Wait until the delay complete flag is set
    while (!delayComplete) {}

    // Stop the timer interrupt after delay completion
    HAL_TIM_Base_Stop_IT(htim);
}

/**
 * @brief   Delays execution asynchronously using a hardware timer and invokes a callback function upon completion.
 * @param   htim: Pointer to the timer handle structure
 * @param   timDelay: Delay time in milliseconds
 * @param   callback: Pointer to the callback function to be executed after the delay
 * @retval  None
 */
void asyncTimerDelay(TIM_HandleTypeDef *htim, uint32_t timDelay, void (*callback)(void)) {
    // Reset the delay complete flag
    delayComplete = 0;

    // Obtain the current values of the timer's period and prescaler
    uint32_t prescaler = htim->Init.Prescaler;

    // Calculate the reload value for the delay
    uint32_t reloadValue = ((SystemCoreClock / (prescaler + 1)) / 1000) * timDelay;

    // Set the reload value to achieve the desired delay
    __HAL_TIM_SET_AUTORELOAD(htim, reloadValue);

    // Deinitialize and reinitialize the timer to apply the changes
    HAL_TIM_Base_DeInit(htim);
    HAL_TIM_Base_Init(htim);

    // Set the callback function to be executed after the delay
    delayCompleteCallback = callback;

    // Start the timer with interrupt
    // Check and clear the update flag before starting the timer
    if (__HAL_TIM_GET_FLAG(htim, TIM_FLAG_UPDATE)) {
        __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
    }
    HAL_TIM_Base_Start_IT(htim);
}

/**
 * @brief  Callback function invoked when the timer's period elapses.
 * @note   This function is weakly defined in the HAL library and can be overridden by the user.
 * @param  htim: Pointer to the timer handle structure
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    // Check if the timer instance matches the predefined timer instance (P_TIM)
    // If so, set the delay complete flag indicating that the delay period has elapsed
    if (htim == P_TIM) {
        delayComplete = 1;

        // If a callback function is set, call it
        if (delayCompleteCallback != NULL) {
            // Stop the timer interrupt
            HAL_TIM_Base_Stop_IT(htim);

            // Call the callback function
            delayCompleteCallback();

            // Reset the callback function to avoid multiple calls
            delayCompleteCallback = NULL;
        }
    }
}

