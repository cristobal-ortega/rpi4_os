#include "utils.h"

void set_address_to(unsigned long long address, unsigned int value) {

    *(unsigned int*) address = value;
}

int get_value_from(unsigned long long address) {

    return (unsigned int) *((volatile unsigned int*) address);
}