#ifndef FACTS_H
#define _FACTS_H
// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// Gear conversions
#define STEPPER_STEPS_PER_REVOLUTION 2048
#define SHELF_NUM 8
#define GEAR_RATIO 36/20
#define SHELF_STEP (STEPPER_STEPS_PER_REVOLUTION * GEAR_RATIO)/SHELF_NUM

// Stepper motor speed in rpm (NOT SHELF SPEED)
#define SPEED 2

// LED strip
#define NUM_LEDS        9
#define LED_PIN         21

// UI
#define CW_PIN          25
#define CCW_PIN         35
#define LED_BUTTON      34
#define BUTTON_LED      33
#define CW_LED          32
#define CCW_LED         26



#endif