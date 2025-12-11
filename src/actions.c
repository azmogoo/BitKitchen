/**
 * @file actions.c
 * @brief action processing functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/actions.h"

int action_uppercase(uint8_t *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = (uint8_t)toupper((char)data[i]);
        }
    }
    return 0;
}

int action_lowercase(uint8_t *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = (uint8_t)tolower((char)data[i]);
        }
    }
    return 0;
}

