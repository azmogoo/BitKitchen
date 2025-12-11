/**
 * @file args.c
 * @brief command line argument parsing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bitkitchen.h"

/* convert format string to enum */
static int parse_format(const char *str) {
    if (strcmp(str, "bytes") == 0 || strcmp(str, "raw") == 0) {
        return FORMAT_BYTES;
    } else if (strcmp(str, "hex") == 0 || strcmp(str, "hexadecimal") == 0) {
        return FORMAT_HEX;
    } else if (strcmp(str, "base64") == 0 || strcmp(str, "b64") == 0) {
        return FORMAT_BASE64;
    }
    return -1;
}

/* convert action string to enum */
static int parse_action(const char *str) {
    if (strcmp(str, "CAESAR") == 0 || strcmp(str, "caesar") == 0) {
        return ACTION_CAESAR;
    } else if (strcmp(str, "RC4") == 0 || strcmp(str, "rc4") == 0) {
        return ACTION_RC4;
    } else if (strcmp(str, "UPPERCASE") == 0 || strcmp(str, "uppercase") == 0) {
        return ACTION_UPPERCASE;
    } else if (strcmp(str, "LOWERCASE") == 0 || strcmp(str, "lowercase") == 0) {
        return ACTION_LOWERCASE;
    } else if (strcmp(str, "XOR") == 0 || strcmp(str, "xor") == 0) {
        return ACTION_XOR;
    }
    return -1;
}

