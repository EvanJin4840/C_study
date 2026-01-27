Preprocessor directives (#define, #include, macros)

Typedef and typecasting for type management

PREPROCESSOR DIRECTIVES - QUICK REFERENCE

* What They Are =
Commands starting with # that run BEFORE compilation
Modify source code text, not executed at runtime

* Core Directives =
#define PI 3.14
// Creates constant - every PI becomes 3.14

#define SQUARE(x) ((x) * (x))
// Macro with parameters - always use parentheses

#include <stdio.h>
// Include standard library (angle brackets)

#include "myheader.h"
// Include user file (quotes)

#ifdef DEBUG
    printf("Debug mode\n");
#endif
// Compile only if DEBUG is defined

#ifndef MAX_SIZE
    #define MAX_SIZE 100
#endif
// Define only if not already defined

#ifndef HEADER_H
#define HEADER_H
    // header contents
#endif
// Header guard - prevents multiple inclusion

#undef MAX
// Remove macro definition

* Key Points =
- Preprocessor runs BEFORE compiler
- Text substitution, not execution
- No semicolons at end of directives
- Macros are faster than functions but watch for side effects
- Always parenthesize macro parameters: ((x) * (x))

* Common Uses =
- Constants: #define MAX 100
- Debugging: #ifdef DEBUG
- Header guards: #ifndef HEADER_H
- Platform-specific code: #ifdef _WIN32


Bitwise operators and bit manipulation

Variable argument lists (va_list, va_start, va_end)

Static vs dynamic scoping