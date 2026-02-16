- Pointer Declaration
  Pointers are declared using the asterisk (\*) symbol followed by the variable name. The syntax is data*type* pointer_name; where the data type matches the type of variable the pointer will reference.

- Address-of Operator (&)
  The ampersand (&) operator retrieves the memory address of a variable. To assign an address to a pointer, use the syntax pointer = &variable.

- Dereference Operator (_)
  The asterisk (_) operator, when used with an existing pointer, accesses the value stored at the memory address the pointer references. This is called dereferencing

- Null Pointers
  A pointer can be initialized to NULL to indicate it doesn't point to any valid memory location yet. This syntax looks like int \*ptr = NULL; and helps avoid undefined behavior from uninitialized pointers.

* Void Pointers (void *)
  A void * is a "generic pointer" that can point to any data type.
  - Utility: It is used in standard library functions like qsort() or bsearch() to handle different types of data (int, float, structs) using the same function logic.
  - Constraint: You cannot dereference a void * directly; you must cast it to a specific type first.

- Pointers and Arrays
  Array names in C act like pointers to the first element. You can use pointer notation to access array elements: if int *p = arr;, then *p gives the first element and \*(p + 1) gives the second. This relationship between pointers and arrays is fundamental to C programming.

- Pointer to Pointer
  C allows pointers that store the address of another pointer, called double pointers. The syntax uses two asterisks like int **ptrptr; and requires double dereferencing **ptrptr to access the final value.

- Function Pointers
  Pointers can store addresses of functions, enabling callback mechanisms and dynamic function selection. The syntax is int (\*fptr)(int, int); for a pointer to a function taking two ints and returning an int.

- Pointer Arithmetic
  You can perform arithmetic operations on pointers to navigate through memory. When you add 1 to a pointer, it moves forward by the size of the data type it points to. For example, ptr + 1 moves to the next element in an array, and \*(ptr + 2) accesses the third element.

* Wild Pointers vs. Dangling Pointers
- These are the "danger zones" of C programming that cause unexpected crashes (Segmentation Faults).
- Wild Pointer: A pointer that has been declared but not initialized. It points to an arbitrary (random) memory location.
Rule: Always initialize with NULL.
- Dangling Pointer: A pointer that still stores the address of a memory block that has already been deleted (freed).
* Rule: Set the pointer to NULL immediately after free()