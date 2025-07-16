#include <stdio.h>
#include <stdarg.h>

typedef enum{
    TURN_ON,
    TURN_OFF,
    SET_LEVEL,
    SEND_MESSAGE
} Command;

void SET_COMMAND(Command cmd, ...){
    va_list args;
    va_start(args, cmd);

    switch(cmd){
        case TURN_ON:{
            int deviceID =  va_arg(args,int);
            printf("Device ID %d will %s\n",deviceID, cmd == TURN_ON ? "TURN_ON" : "TURN_OFF");
            break; 
        }
        case TURN_OFF:{
            int deviceID =  va_arg(args,int);
            printf("Device ID %d will %s\n",deviceID, cmd == TURN_ON ? "TURN_ON" : "TURN_OFF");
            break; 
        }
        case SET_LEVEL:{
            int deviceID = va_arg(args, int);
            int level = va_arg(args, int);
            printf("Set Device ID %d to %d\n", deviceID, level);
            break;
        }
        case SEND_MESSAGE:{
            int deviceID = va_arg(args, int);
            char* message = va_arg(args, char*);
            printf("Device ID %d send message: %s\n", deviceID, message);
            break;
        }

    }
    va_end(args);
}

int main(){
        SET_COMMAND(TURN_ON,1);
        SET_COMMAND(TURN_OFF,2);
        SET_COMMAND(SET_LEVEL,3, 755);
        SET_COMMAND(SEND_MESSAGE, 4, "HELLO WORLD\n");
}