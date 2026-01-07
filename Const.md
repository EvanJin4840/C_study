const means the value cannot be modified after initialization; attempts to change it cause a compile-time error.

It is used to prevent accidental changes, make code intention clear, and enable better type checking than macros like #define.

With pointers, the position of const matters:

const int \*p: the data is read-only, the pointer can change.

int \*const p: the pointer is fixed, the data can change.

const int \*const p: both pointer and data are read-only.

In function parameters, const promises that the function will not modify the passed data, improving safety and readability.
