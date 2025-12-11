/**
 * @file args.h
 * @brief command line argument parsing
 */

#ifndef ARGS_H
#define ARGS_H

#include "../include/bitkitchen.h"

/**
 * @brief parse command line arguments
 * @param argc argument count
 * @param argv argument vector
 * @param config output configuration structure
 * @return 0 on success, -1 on error, -2 for help
 */
int parse_arguments(int argc, char *argv[], config_t *config);

/**
 * @brief free configuration resources
 * @param config configuration structure
 */
void free_config(config_t *config);

#endif /* ARGS_H */

