#pragma once

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

extern const char* use_command;
extern const char* call_command;

int load_library(void** current_library, const char* library_path);
void close_library(void** current_library);
int call_function(void* current_library, const char* function_name);
void process_line(void** current_library, char* line);
