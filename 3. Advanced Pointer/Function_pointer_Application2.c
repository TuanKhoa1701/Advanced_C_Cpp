#include <stdio.h>

typedef struct 
{
  void (*start)(int gpio);
  void (*changeSpeed)(int gpio, int speed);
  void (*stop)(int gpio);  
} MotorControl;
typedef int PIN;
#define INIT_MOTOR(motorName, pinNum)   \
    PIN PIN_##motorName = pinNum;        \
    MotorControl  motorName ={StartMotor, ChangeSpeedMotor, StopMotor}
void StartMotor(int gpio){
    printf("Start motor at pin %d\n", gpio);
}
void ChangeSpeedMotor(int gpio, int Speed){
    printf ("Change motor Speed at Pin %d to %d\n", gpio,Speed);
}
void StopMotor(int gpio){
    printf("Stop motor at pin %d\n", gpio);
}
int main(){
    INIT_MOTOR(motorA,1);
    INIT_MOTOR(motorB,2);

    motorA.start(1);
    motorA.changeSpeed(1, 100);
    motorA.stop (1);
}