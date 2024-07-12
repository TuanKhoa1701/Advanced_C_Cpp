#include <stdio.h>
#include "Global_Static_Motor.h"

#define PIN int
// General function
void startMotor(PIN pin)
{
    printf("Start motor at PIN %d\n", pin);
}

void stopMotor(PIN pin)
{
    printf("Stop motor at PIN %d\n", pin);
}

void changeSpeedMotor(PIN pin, int speed)
{
    printf("Change speed at PIN %d: %d\n", pin, speed);
}

void init_motor(MotorController *motorName)
{
    motorName->start = startMotor;
    motorName->stop = stopMotor;
    motorName->changeSpeed = changeSpeedMotor;
}
