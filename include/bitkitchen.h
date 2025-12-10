/**
 * @file bitkitchen.h
 * @brief main header file for bitkitchen tool
 */

#ifndef BITKITCHEN_H
#define BITKITCHEN_H

#include <stddef.h>
#include <stdint.h>

/* maximum buffer size for file operations */
#define MAX_BUFFER_SIZE (1024 * 1024)  /* 1MB */

/* input/output format types */
typedef enum {
    FORMAT_BYTES,
    FORMAT_HEX,
    FORMAT_BASE64
} format_t;

/* action types */
typedef enum {
    ACTION_NONE,
    ACTION_CAESAR,
    ACTION_RC4,
    ACTION_UPPERCASE,
    ACTION_LOWERCASE,
    ACTION_XOR
} action_t;

/* configuration structure */
typedef struct {
    char *input_file;
    char *output_file;
    format_t input_format;
    format_t output_format;
    action_t action;
    char *action_param;  /* for xor key, caesar shift, rc4 key, etc. */
} config_t;

/* data buffer structure */
typedef struct {
    uint8_t *data;
    size_t size;
} buffer_t;

#endif /* BITKITCHEN_H */

