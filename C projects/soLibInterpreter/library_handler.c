#include "library_handler.h"

const char* use_command = "use";
const char* call_command = "call";

int load_library(void** current_library, const char* library_path)
{
    close_library(current_library);

    *current_library = dlopen(
        library_path, RTLD_LAZY); // delay resolving symbols until they’re actually used.

    if (!*current_library)
    {
        const char* error_message = dlerror();

        if (strstr(error_message, "invalid ELF header") ||
            strstr(error_message, "not a shared object"))
        {
            fprintf(stderr, "Error: '%s' is not a valid shared library: %s\n",
                    library_path, error_message);
        }
        else
        {
            fprintf(stderr, "Error: Failed to load library '%s': %s\n", library_path,
                    dlerror());
        }

        return -1;
    }

    printf("Library '%s' loaded successfully.\n", library_path);

    return 0;
}

void close_library(void** current_library)
{
    if (*current_library)
    {
        dlclose(*current_library);
        *current_library = NULL;
    }
}

int call_function(void* current_library, const char* function_name)
{
    if (!current_library)
    {
        fprintf(stderr, "Error: No library loaded.\n");
        return -1;
    }

    void (*func)(void) = dlsym(current_library, function_name);

    char* error = dlerror();

    if (error)
    {
        fprintf(stderr, "Error Function '%s' not found: %s\n", function_name, error);
        return -1;
    }

    printf("Calling function '%s' ... \n", function_name);
    func();

    return 0;
}

void process_line(void** current_library, char* line)
{
    char command[MAX_LINE_LENGTH];
    char argument[MAX_LINE_LENGTH];

    if (line[0] == '#' || line[0] == ';' || !strlen(line))
    {
        return;
    }

    if (sscanf(line, "%s %s", command, argument) < 2)
    {
        fprintf(stderr, "Warning: Syntax error in line: '%s'\n", line);
        return;
    }

    if (!strcmp(command, use_command))
    {
        if (load_library(current_library, argument))
        {
            exit(EXIT_FAILURE);
        }
    }
    else if (!strcmp(command, call_command))
    {
        if (call_function(*current_library, argument))
        {
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Warning: unknown command '%s.\n", command);
    }
}