#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union{
    struct{
        uint8_t value_id[2];
        uint8_t value_data[4];
        uint8_t value_status[2];
    }value;
    uint8_t frame[8]
} Dta_frame;

int main(){
    Dta_frame data_tx;
    strcpy(data_tx.value.value_id, "01"); // Set value_id to 1
    strcpy(data_tx.value.value_data, "1010"); // Set value_data to 10
    strcpy(data_tx.value.value_status, "11"); // Set value_status to 3

    Dta_frame data_rx;
    strcpy(data_rx.frame, data_tx.frame); // Copy value_id

}
