# Библиотека timerDelay для STM32F1

Библиотека `timerDelay` предоставляет функции для задержки выполнения программы с использованием аппаратного таймера на микроконтроллерах STM32F1.

## Назначение библиотеки

Библиотека `timerDelay` предназначена для реализации задержек выполнения программы с использованием аппаратного таймера на микроконтроллерах STM32F1. Она обеспечивает возможность блокирующей и неблокирующей задержки выполнения программы.

## Установка и использование

1. Скопируйте файлы библиотеки из папки `ThisLibrary` в ваш проект.
2. Подключите файл `timerDelay.h` в вашем проекте.
3. Обратите внимание, что функция `HAL_TIM_PeriodElapsedCallback` переопределена в библиотеке. Необходимо настроить таймер, который будет использоваться для работы с этими методами.
4. Определите указатель `P_TIM` после создания структуры типа `htim`. Например:

    ```c
    TIM_HandleTypeDef * const P_TIM = &htim2;
    volatile uint8_t flagMultiblink = 0;
    ```

## Примеры использования

Пример использования библиотеки можно найти в файле `main.c`.

## Зависимости и требования

Библиотека была протестирована с использованием файла `stm32f1xx_hal.h`. Другие версии не проверялись.

## Документация API

Документация по функциям API предоставлена в файле `timerDelay.h`.

## Лицензирование

Библиотека распространяется под лицензией MIT.

## Помощь и обратная связь

По вопросам помощи и обратной связи вы можете связаться с разработчиком по адресу электронной почты: arruin1996@gmail.com

