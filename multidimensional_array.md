# Passing 2D Arrays to Functions in C

## Array Decay

- Arrays decay into a pointer to the first element when passed to a function
- For 2D arrays, only the first dimension decays
- Column size must be known for pointer arithmetic

## Correct Function Parameter Types

- `int arr[][cols]`
- `int (*arr)[cols]`
- Column size must be specified
- Row size can be left empty `[]`

## Incorrect Types

- `int arr[][]` (missing column size)
- `int **arr` (pointer to pointer, not contiguous)
- `int* arr[cols]` (array of pointers, not contiguous)

## Memory Layout of 2D Arrays

- Continuous blocks of rows
- Row size = `cols * sizeof(int)`
- Compiler uses column size to calculate offsets
- True 2D arrays are contiguous in memory
- `int**` is not contiguous

## Key Takeaways

- 2D arrays decay to `int (*)[cols]`
- Column size must be fixed; row size can be empty
- `int**` or `int* arr[cols]` is not equivalent to a 2D array
- Always match the column size in the function parameter with the array
