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


### Bitwise operators and bit manipulation

BITWISE OPERATORS - QUICK REFERENCE

* What They Are =
Operators that work on individual bits of integers at binary level
Faster than arithmetic operations, used for low-level programming

* Six Bitwise Operators =

& (AND)
6 & 3    // 0110 & 0011 = 0010 = 2
// Result is 1 only if BOTH bits are 1

| (OR)
6 | 3    // 0110 | 0011 = 0111 = 7
// Result is 1 if AT LEAST ONE bit is 1

^ (XOR)
6 ^ 3    // 0110 ^ 0011 = 0101 = 5
// Result is 1 if bits are DIFFERENT

~ (NOT/Complement)
~5       // 00000101 becomes 11111010 = -6
// FLIPS all bits (0→1, 1→0)

<< (Left Shift)
3 << 2   // 0011 becomes 1100 = 12
// Shifts bits LEFT, multiplies by 2^n

>> (Right Shift)
12 >> 2  // 1100 becomes 0011 = 3
// Shifts bits RIGHT, divides by 2^n


= Common Bit Manipulation Techniques =

Set nth bit to 1:
x = x | (1 << n);

Clear nth bit to 0:
x = x & ~(1 << n);

Toggle nth bit:
x = x ^ (1 << n);

Check if nth bit is set:
if (x & (1 << n)) { /* bit is set */ }

Fast multiply by 2:
x << 1

Fast divide by 2:
x >> 1

Swap two numbers without temp variable:
a = a ^ b;
b = a ^ b;
a = a ^ b;


* Common Use Cases
- Performance optimization (faster than arithmetic)
- Memory efficiency (pack multiple flags in one int)
- Hardware/embedded programming
- Networking and protocol handling
- Graphics and image processing
- Encryption and hashing algorithms

### Variable argument lists (va_list, va_start, va_end)

Static vs dynamic scoping