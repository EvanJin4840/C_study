- Pointer Declaration
  Pointers are declared using the asterisk (\*) symbol followed by the variable name. The syntax is data*type* pointer_name; where the data type matches the type of variable the pointer will reference.

- Address-of Operator (&)
  The ampersand (&) operator retrieves the memory address of a variable. To assign an address to a pointer, use the syntax pointer = &variable.

- Dereference Operator (_)
  The asterisk (_) operator, when used with an existing pointer, accesses the value stored at the memory address the pointer references. This is called dereferencing

- Null Pointers
  A pointer can be initialized to NULL to indicate it doesn't point to any valid memory location yet. This syntax looks like int \*ptr = NULL; and helps avoid undefined behavior from uninitialized pointers.

- Pointers and Arrays
  Array names in C act like pointers to the first element. You can use pointer notation to access array elements: if int *p = arr;, then *p gives the first element and \*(p + 1) gives the second. This relationship between pointers and arrays is fundamental to C programming.

- Pointer to Pointer
  C allows pointers that store the address of another pointer, called double pointers. The syntax uses two asterisks like int **ptrptr; and requires double dereferencing **ptrptr to access the final value.
