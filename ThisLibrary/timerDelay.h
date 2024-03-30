/*
 * timerDelay.h
 *
 *  Created on: Mar 30, 2024
 *      Author: pavel
 */

#ifndef TIMERDELAY_H_
#define TIMERDELAY_H_

#include "stm32f1xx_hal.h"

/*********************************
 * External Predefined Timer Pointer
 *
 * This section declares the external pointer P_TIM, which is a constant pointer to TIM_HandleTypeDef structure.
 * It must be defined in the main file after creating the TIM_HandleTypeDef structure.

 * Example usage:
 * TIM_HandleTypeDef * const P_TIM = &htim2;
 * volatile uint8_t flagMultiblink = 0;
 */
extern TIM_HandleTypeDef * const P_TIM;
/*
 ************************************/


// Function prototypes

/**
 * @brief Delays program execution for a specified duration using the provided timer.
 *
 * @param htim Pointer to the TIM_HandleTypeDef structure that contains the configuration information for the specified TIM module.
 * @param timDelay The delay duration in milliseconds.
 */
void timerDelay(TIM_HandleTypeDef *htim, uint32_t timDelay);

/**
 * @brief Delays program execution for a specified duration using the provided timer, with a callback function to execute when the delay is complete.
 *
 * @param htim Pointer to the TIM_HandleTypeDef structure that contains the configuration information for the specified TIM module.
 * @param timDelay The delay duration in milliseconds.
 * @param callback A pointer to the callback function to be executed when the delay is complete.
 */
void asyncTimerDelay(TIM_HandleTypeDef *htim, uint32_t timDelay, void (*callback)(void));

// Override of the weakly defined HAL_TIM_PeriodElapsedCallback function
/**
 * @brief Override of the weakly defined HAL_TIM_PeriodElapsedCallback function.
 *
 * This function is called when the period of the timer elapses.
 *
 * @param htim Pointer to the TIM_HandleTypeDef structure that contains the configuration information for the specified TIM module.
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* TIMERDELAY_H_ */
