#include <stdio.h>
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/freeRTOS.h"
#include "freertos/task.h"

const char* TAG = "timer";
void app_main(void)
{
    for(;;)
    {
        ESP_LOGI(TAG, "time now: %lld", esp_timer_get_time());
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
