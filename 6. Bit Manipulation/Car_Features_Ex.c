#include <stdio.h>
#include <stdint.h>

#define CAR_COLOR_RED 0
#define CAR_COLOR_BLUE 1
#define CAR_COLOR_GREEN 2
#define CAR_COLOR_YELLOW 3

#define CAR_POWER_50HP 0
#define CAR_POWER_100HP 1
#define CAR_POWER_200HP 2

#define CAR_ENGINE_ON 1
#define CAR_ENGINE_OFF 0

typedef uint8_t CAR_Power;
typedef uint8_t CAR_Color;
typedef uint8_t CAR_EngineStatus;
typedef uint8_t additionalFeatures;
typedef struct {
    CAR_Color color:3;
    CAR_Power power:2;
    CAR_EngineStatus engineStatus:1;
    additionalFeatures features; // 2 bits for additional features
} CarOption;

#define FEATURE_SUNROOF 1 << 0U // 1 bit
#define FEATURE_NAVIGATION 1 << 1U // 1 bit
#define FEATURE_BLIND_SPOT_MONITOR 1 << 2U // 1 bit

void CarOptions_Config(CarOption *car, CAR_Color color, CAR_Power power, CAR_EngineStatus engine ){
    car -> color = color;
    car -> power = power;
    car -> engineStatus = engine;
}
void CarOptions_SetFeatures(CarOption *car, additionalFeatures features){
    car -> features |= features;
}
void CarOptions_ClearFeatures(CarOption *car, additionalFeatures features){
    car -> features &= ~features;
}
void CarOptions_Display(const CarOption *Car){
    const char *colorname[]={"RED", "BLUE", "GREEN", "YELLOW"};
    const char *powerstatus[] = {"50HP", "100HP", "200HP"};
    const char *enginestatus[] = {"OFF", "ON"};
    
    printf("Car Color: %s\n", colorname[Car->color]);
    printf("Car Power: %s\n", powerstatus[Car->power]);
    printf("Car Engine Status: %s\n", enginestatus[Car->engineStatus]);
    printf("Sunroof:%s\n", (Car->features & FEATURE_SUNROOF) ? "On" : "Off");
    printf("Navigation:%s\n", (Car->features & FEATURE_NAVIGATION) ? "On" : "Off");
    printf("Blind Spot Monitor:%s\n", (Car->features & FEATURE_BLIND_SPOT_MONITOR) ? "On" : "Off");
}
int main(){
    CarOption myCar;
    CarOptions_Config(&myCar, CAR_COLOR_YELLOW, CAR_POWER_200HP, CAR_ENGINE_ON);
    CarOptions_SetFeatures(&myCar, FEATURE_SUNROOF | FEATURE_NAVIGATION);
    CarOptions_Display(&myCar);

    CarOptions_ClearFeatures(&myCar, FEATURE_NAVIGATION);
    printf("\nAfter clearing navigation feature:\n");
    CarOptions_Display(&myCar);
    printf("Size of CarOption: %d bytes\n", sizeof(CarOption));
}