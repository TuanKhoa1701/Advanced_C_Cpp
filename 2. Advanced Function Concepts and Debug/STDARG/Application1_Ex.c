#include <stdio.h>
#include <stdarg.h>

typedef enum{
    TEMPERATURE_SENSOR,
    PRESSURE_SENSOR
}SENSOR_TYPE;

void ProcessData(SENSOR_TYPE type, ...){
    va_list args;
    va_start(args, type);
    switch(type){
        case TEMPERATURE_SENSOR:
        {
                        int NumArgs = va_arg(args,int);
            int sensorID = va_arg(args,int);
            float temperature = va_arg(args, double);
            printf("Temperature Sensor ID: %d, reading: %d", sensorID, temperature);
            if (NumArgs > 2){
                 char* additionInfo = va_arg(args, char*);
                 printf(", Additional Info: %s", additionInfo);
            }
            break;
        }
        case PRESSURE_SENSOR:
        {
                        int NumArgs = va_arg(args,int);
            int sensorID = va_arg(args,int);
            int sensorData = va_arg(args, int);
            printf("Pressure Sensor ID: %d, reading: %d ", sensorID, sensorData);
            if(NumArgs > 2){
                char* Unit = va_arg(args, char*);
                printf(", Unit: %s", Unit);
            }
            break;
        }

    }

    va_end(args);
}
int main(){
    ProcessData(TEMPERATURE_SENSOR,3,0,45.0,"Temperature in the room\n");
    ProcessData(PRESSURE_SENSOR,3,1,10222,"cm");
}