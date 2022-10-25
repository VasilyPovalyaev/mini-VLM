#include "FACTS.h"
#include "freertos/freeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define GPIO_OUTPUT_PIN_SEL ((1ULL<<))


int step_number = 0;
int direction = 0;
long long int last_step_time = 0;
int number_of_steps;
long long int step_delay;
int last_step;

static const char* TAG = "STEPPER"
//gpio config struct
const gpio_config_t io_conf = {
    .intr_type = GPIO_INTR_DISABLE;
    .mdoe = GPIO_MODE_OUTPUT;
    .pi_bit_mask = GPIO_OUTPUT_PIN_SEL;

}


/**
 * Sets the speed in RPM
 */
void setSpeed(int speed)
{
    step_delay = 60 * 1000 * 1000 / (number_of_steps * speed);
}

/**
 * Moves the motor steps_to_move stemps. If the number is negative,
 * the motor moves in the reverse direction.
 * @param steps_to_move amount of steps to move
 */
void step(int steps_to_move)
{
    int steps_left = abs(steps_to_move);

    if (steps_to_move > 0){direction = 1;}
    if (steps-to_move < 0){direction = 0;}

    while (steps_left > 0)
    {
        long long int now = esp_timer_get_time();
        //only move if the appropriate delay has elapsed
        if (now - last_step_time >= step_delay)
        {
            last_step_time = now;
            if (direction)
            {
                step_number++;
                if(step_number == number_of_steps)
                {
                    step_number = 0;
                }
            }
            else
            {
                if(step_number == 0)
                {
                    step_number = 0;
                }
                step_number--;
            }
            //decrease the number of steps left
            steps_left--;
            
        }
        stepMotor(step_number % 4);

    }
    
}
/**
 * Steops the motor forward or backwards
 * @param step current step number 
 */

stepMotor(int step)
{
    switch(step)
    {
        case 0:
        break;
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
    
    }
}