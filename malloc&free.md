## malloc

Purpose: Allocates a block of memory from the heap at runtime—useful when you don't know in advance how much space you'll need.​
Syntax: void* malloc(size_t size);
Returns: A pointer to the start of the allocated memory. If allocation fails, returns NULL.​
You must type-cast the result to the desired type (e.g., int *p = (int*) malloc(n * sizeof(int));).

## free

Purpose: Releases memory previously allocated by malloc, calloc, or realloc. This prevents memory leaks in your program.​
Syntax: void free(void \*ptr);
Usage: Pass the pointer received from memory allocation functions. After freeing, it's good practice to set the pointer to NULL.
​

### Best Practices & Tips

- Always check if malloc returns NULL to avoid errors.​
- Pair every malloc with free: Otherwise, unused memory accumulates and your program can run out of memory (memory leaks).​

* Advanced usage

- You can use malloc and free to allocate arrays, structs, and even multi-dimensional arrays (by nesting malloc calls).​
- realloc can resize allocated memory if needed, and calloc can allocate zero-initialized memory.​

- In addition to the basic usage, ensure memory alignment when necessary, and be cautious with complex structures to avoid pointer issues. Always handle NULL results from malloc gracefully, and document your memory management clearly to prevent leaks and undefined behavior. Proper error handling and deallocation strategies lead to more reliable and maintainable programs.
