/**
 * @file actions.h
 * @brief action processing functions
 */

#ifndef ACTIONS_H
#define ACTIONS_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief convert text to uppercase
 * @param data data buffer
 * @param size buffer size
 * @return 0 on success, -1 on error
 */
int action_uppercase(uint8_t *data, size_t size);

/**
 * @brief convert text to lowercase
 * @param data data buffer
 * @param size buffer size
 * @return 0 on success, -1 on error
 */
int action_lowercase(uint8_t *data, size_t size);

#endif /* ACTIONS_H */

