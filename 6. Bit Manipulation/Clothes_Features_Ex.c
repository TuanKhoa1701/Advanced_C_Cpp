#include <stdio.h>
#include <stdint.h>

#define Gender 1 << 0U // 1 bit
#define Hat 1 << 1U // 1 bit
#define Glasses 1 << 2U // 1 bit

#define FEATURE1 1 << 3U // 1 bit
#define FEATURE2 1 << 4U // 1 bit
#define FEATURE3 1 << 5U // 1 bit

void enable_Feature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}
void disable_Feature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}
void is_Feature_Enabled(const uint8_t *features, uint8_t feature) {
    if (*features & feature) {
        printf("Feature is enabled.\n");
    } else {
        printf("Feature is disabled.\n");
    }
}
void Display_Features_Status(const uint8_t *features) {
    printf("Selected Features Status:\n");
    if (*features & Gender)
        printf("- GENDER\n");
    if (*features & Hat)
        printf("- HAT\n");
    if (*features & Glasses)
        printf("- GLASSES\n");
    for(int i=0; i < 8; i++){
        printf("feature selected: %d\n", (*features >> i) & 1);
    }
}
int main(){
    uint8_t features = 0; // Initialize features to 0

    enable_Feature(&features,Gender| Hat| Glasses);
    disable_Feature(&features, Hat);
    Display_Features_Status(&features);

}