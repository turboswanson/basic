# Scripting Language Interpreter for Testing Shared Libraries

This project implements a scripting language interpreter for testing shared function libraries. The interpreter is developed in C as a console application for GNU/Linux (x86 processor architecture) using POSIX.1-2001 APIs.

## Features

### Commands:

use <so_name>: Loads a shared library (.so file).

### Errors:

```bash
File not found.
File is not a valid shared library.
call <func_name>: Calls a function from the loaded library.
```

### Errors:

Function not found.
No library loaded.
echo <message>: Prints a message to the console (optional feature for debugging).

### Error Handling:

Syntax errors are accompanied by warnings but do not stop script execution.

Execution stops if a command fails (e.g., library load failure or function call failure).

### Script File Syntax:

One command per line.
Comments are supported (# or ;).

### Example of using:

```bash
use test/test_library.so
call example
call test1_func 
```

## Project Structure


Makefile                # Build instructions

main.c                  # Entry point for the interpreter

library_handler.c       # Library handling logic

library_handler.h       # Header file for library handling

test/                   # Shared library source files directory
    test_library.c      # First test library
    other_test_library.c # Second test library

test_scripts/           # Directory containing test scripts
    test_one.sc         # Regular test script
    test_two.sc         # Script for testing non-existent library
    test_three.sc       # Script for testing non-existent function

## Compilation Instructions

### Build the Interpreter: Run the following command to compile the interpreter:

```bash
make all
```

#### Generate Shared Libraries: The Makefile automatically compiles all .c files in the test directory into .so files.

#### Clean Up: Remove generated files:

```bash
make clean
```

### Usage

#### All exported functions should have prototype:

```bash
void example (void);
```

#### Run the Interpreter: Execute the interpreter with a script file:

```bash
./sotest test_scripts/test_one.sc
```

#### Run Tests: Use predefined targets in the Makefile:

```bash
make test_one
make test_two
make test_three
```

#### Expected Output

Example output for test_one.sc:

```bash
Library 'test/test_library.so' loaded successfully.
Calling function 'example' ...
Function 'example' executed.
Calling function 'test1_func' ...
Function 'test1_func' executed. Sum of 5 and 10 is 15.
Calling function 'env_func' ...
Function 'env_func' executed. LD_LIBRARY_PATH: /home/mitchelk/code/test/so_lib/test
Calling function 'random_func' ...
Function 'random_func' executed. Random number: 42
Library 'test/other_test_library.so' loaded successfully.
Calling function 'reverse_string' ...
Function 'reverse_string' executed. Original: Hello, World!, Reversed: !dlroW ,olleH
Calling function 'calculate_sqrt' ...
Function 'calculate_sqrt' executed. Square root of 25.00 is 5.00
Calling function 'division_by_random' ...
Function 'division_by_random' executed. Result: 2.50
Calling function 'random_float' ...
Function 'random_float' executed. Random float: 42.35
```

#### Memory leak checking

```bash
make memcheck
```

##### Example Script File

##### Test script for sotest

```bash
use test/test_library.so
call example
call test1_func
call env_func
call random_func
use test/other_test_library.so
call reverse_string
call calculate_sqrt
call division_by_random
call random_float
```


### Known Issues

#### Ensure LD_LIBRARY_PATH is set correctly

```bash
export LD_LIBRARY_PATH=$(pwd)/test
```