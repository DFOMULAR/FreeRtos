#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"


void Blink()
{   
    const uint LED = PICO_DEFAULT_LED_PIN;
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    while (true) {
        gpio_put(LED, 1);
        vTaskDelay(100);
        gpio_put(LED, 0);
        vTaskDelay(100);
    }
}

int main()
{
    stdio_init_all();

    xTaskCreate(Blink, "Blink_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};
}