/**
 * @file encoders.h
 * @brief encoding/decoding functions for different formats
 */

#ifndef ENCODERS_H
#define ENCODERS_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief encode bytes to hex string
 * @param input input bytes
 * @param input_size number of bytes
 * @param output output hex string buffer (must be at least input_size * 2 + 1)
 * @return 0 on success, -1 on error
 */
int encode_hex(const uint8_t *input, size_t input_size, char *output);

#endif /* ENCODERS_H */

