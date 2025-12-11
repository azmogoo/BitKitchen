/**
 * @file actions.c
 * @brief action processing functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int action_caesar(uint8_t *data, size_t size, int shift) {
    /* handle negative shifts */
    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }
    for (size_t i = 0; i < size; i++) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = 'a' + ((data[i] - 'a' + shift) % 26);
        } else if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = 'A' + ((data[i] - 'A' + shift) % 26);
        }
    }
    return 0;
}

int action_xor(uint8_t *data, size_t size, const char *key) {
    if (!key || strlen(key) == 0) {
        return -1;
    }
    size_t key_len = strlen(key);
    for (size_t i = 0; i < size; i++) {
        data[i] ^= (uint8_t)key[i % key_len];
    }
    return 0;
}

