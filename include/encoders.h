/**
 * @file encoders.h
 * @brief encoding/decoding functions for different formats
 */

#ifndef ENCODERS_H
#define ENCODERS_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief decode hex string to bytes
 * @param hex input hex string (null-terminated)
 * @param output output buffer
 * @param output_size output buffer size
 * @return number of bytes decoded, or -1 on error
 */
int decode_hex(const char *hex, uint8_t *output, size_t output_size);

/**
 * @brief encode bytes to hex string
 * @param input input bytes
 * @param input_size number of bytes
 * @param output output hex string buffer (must be at least input_size * 2 + 1)
 * @return 0 on success, -1 on error
 */
int encode_hex(const uint8_t *input, size_t input_size, char *output);

#endif /* ENCODERS_H */

