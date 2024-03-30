# Library timerDelay for STM32F1
## English

The `timerDelay` library provides functions for delaying program execution using hardware timers on STM32F1 microcontrollers.

### Purpose of the Library

The `timerDelay` library is intended for implementing program delays using hardware timers on STM32F1 microcontrollers. It enables both blocking and non-blocking program execution delays.

### Installation and Usage

1. Copy the library files from the `ThisLibrary` folder to your project.
2. Include the `timerDelay.h` file in your project.
3. Note that the `HAL_TIM_PeriodElapsedCallback` function is overridden in the library. You need to configure the timer that will be used with these methods.
4. Define the `P_TIM` pointer after creating the `htim` structure. For example:

    ```c
    TIM_HandleTypeDef * const P_TIM = &htim2;
    volatile uint8_t flagMultiblink = 0;
    ```

### Usage Examples

You can find an example of using the library in the `main.c` file. For non-blocking delay, in addition to specifying the delay time, you need to pass a pointer to the callback function. This function will be called in the timer interrupt handler upon completion of the delay.

```c
void myCallbackFunction(void) {
    // Actions to perform after the delay completes
    // Note that this function will be called in the interrupt context,
    // so it should be as fast as possible and should not block other interrupts.
    // An option could be setting a flag to be processed in the main program loop.
}

// Example of using the non-blocking delay function
asyncTimerDelay(&htim2, 1000, myCallbackFunction);
```
### Dependencies and Requirements

The library has been tested using the `stm32f1xx_hal.h` file. Other versions have not been tested. Make sure that your project correctly includes the necessary dependencies before using this library.

### API Documentation

Documentation for the API functions is provided in the `timerDelay.h` file. Refer to this file for detailed information about available functions and their parameters.

### Licensing

The library is distributed under the MIT license. Detailed information about the license can be found in the `LICENSE` file.

### Help and Feedback

If you have any questions or need assistance, feel free to contact the developer via email at arruin1996@gmail.com. We are ready to help you with the use and configuration of this library.



## Russian

Библиотека `timerDelay` предоставляет функции для задержки выполнения программы с использованием аппаратного таймера на микроконтроллерах STM32F1.

### Назначение библиотеки

Библиотека `timerDelay` предназначена для реализации задержек выполнения программы с использованием аппаратного таймера на микроконтроллерах STM32F1. Она обеспечивает возможность блокирующей и неблокирующей задержки выполнения программы.

### Установка и использование

1. Скопируйте файлы библиотеки из папки `ThisLibrary` в ваш проект.
2. Подключите файл `timerDelay.h` в вашем проекте.
3. Обратите внимание, что функция `HAL_TIM_PeriodElapsedCallback` переопределена в библиотеке. Необходимо настроить таймер, который будет использоваться для работы с этими методами.
4. Определите указатель `P_TIM` после создания структуры типа `htim`. Например:

    ```c
    TIM_HandleTypeDef * const P_TIM = &htim2;
    volatile uint8_t flagMultiblink = 0;
    ```

### Примеры использования

Пример использования библиотеки можно найти в файле `main.c`. Для неблокирующей задержки, кроме указания времени задержки, необходимо передать указатель на функцию обратного вызова. Эта функция будет вызвана в обработчике прерывания таймера по завершении задержки. 

```c
void myCallbackFunction(void) {
    // Действия, которые нужно выполнить после завершения задержки
    // Обратите внимание, что эта функция будет вызвана в контексте прерывания,
    // поэтому она должна быть максимально быстрой и не должна блокировать другие прерывания.
    // Вариантом может быть установка флага, который будет обработан в основном цикле программы.
}

// Пример использования функции неблокирующей задержки
asyncTimerDelay(&htim2, 1000, myCallbackFunction);
```
### Зависимости и требования

Библиотека была протестирована с использованием файла `stm32f1xx_hal.h`. Другие версии не проверялись. Убедитесь, что ваш проект корректно подключает необходимые зависимости перед использованием этой библиотеки.

### Документация API

Документация по функциям API предоставлена в файле `timerDelay.h`. Обратитесь к этому файлу для получения подробной информации о доступных функциях и их параметрах.

### Лицензирование

Библиотека распространяется под лицензией MIT. Подробную информацию о лицензии вы можете найти в файле `LICENSE`.

### Помощь и обратная связь

Если у вас возникли вопросы или вам требуется помощь, не стесняйтесь обращаться к разработчику по адресу электронной почты: arruin1996@gmail.com. Мы готовы помочь вам в использовании и настройке этой библиотеки.
