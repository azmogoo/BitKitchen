/**
 * @file file_io.c
 * @brief file input/output operations
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/bitkitchen.h"

int read_file(const char *filename, format_t format, buffer_t *buffer) {
    FILE *file;
    size_t file_size;
    int result = -1;

    buffer->data = NULL;
    buffer->size = 0;

    file = fopen(filename, "rb");
    if (!file) {
        perror("opening input file");
        return -1;
    }

    /* get file size */
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (format == FORMAT_BYTES) {
        buffer->data = (uint8_t *)malloc(file_size);
        if (!buffer->data) {
            fprintf(stderr, "memory allocation failed\n");
            fclose(file);
            return -1;
        }
        buffer->size = fread(buffer->data, 1, file_size, file);
        if (buffer->size != file_size) {
            fprintf(stderr, "failed to read entire file\n");
            free(buffer->data);
            buffer->data = NULL;
            fclose(file);
            return -1;
        }
        result = 0;
    } else {
        fprintf(stderr, "format not yet supported\n");
        result = -1;
    }

    fclose(file);
    return result;
}

