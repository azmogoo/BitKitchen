/**
 * @file encoders.c
 * @brief encoding/decoding functions for different formats
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/encoders.h"

static char value_to_hex_char(int value) {
    if (value >= 0 && value <= 9) {
        return '0' + value;
    } else if (value >= 10 && value <= 15) {
        return 'a' + (value - 10);
    }
    return '?';
}

int encode_hex(const uint8_t *input, size_t input_size, char *output) {
    for (size_t i = 0; i < input_size; i++) {
        output[i * 2] = value_to_hex_char((input[i] >> 4) & 0x0F);
        output[i * 2 + 1] = value_to_hex_char(input[i] & 0x0F);
    }
    output[input_size * 2] = '\0';
    return 0;
}

