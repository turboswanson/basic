#define _GNU_SOURCE

#include "library_handler.h"
#include "string.h"

#include <dlfcn.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_ARGS_AMOUNT 2

int main(int argc, char* argv[])
{
    if (argc != MIN_ARGS_AMOUNT)
    {
        fprintf(stderr, "Usage: %s <script_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* script_file = fopen(argv[1], "r");
    if (!script_file)
    {
        fprintf(stderr, "Error: Failed to open script file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    void* current_library = NULL;

    char* line = NULL;
    size_t len = 0;

    while (getline(&line, &len, script_file) != -1)
    {
        line[strcspn(line, "\n")] = '\0';
        process_line(&current_library, line);
    }

    free(line);
    fclose(script_file);

    close_library(&current_library);

    return EXIT_SUCCESS;
}