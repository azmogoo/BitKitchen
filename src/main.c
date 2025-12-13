/**
 * @file main.c
 * @brief main entry point for bitkitchen tool
 */

#include "../include/bitkitchen.h"
#include "../include/processor.h"

int main(int argc, char *argv[]) {
    config_t config;
    int result = parse_arguments(argc, argv, &config);
    
    if (result == -2) {
        /* help was printed */
        return 0;
    }
    if (result < 0) {
        return 1;
    }
    
    result = execute_config(&config);
    free_config(&config);
    
    return result;
}

