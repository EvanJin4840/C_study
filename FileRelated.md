# FILE POINTER

### System call
- System calls are function invocation made from user space - to request a service from the krenel

### file descriptor(fd)
- fd is an integer that uniquely identifies an opened file
- An fd is a non-negative integer, represented in C language as the type int

## <fcntl.h>(file control operation)related file management function
#### open
- Including <sys/types.h>, <sys/stat.h> and <fcntl.h> is required
##### format: ```int open(const char *path, int flags(, optional -> /*, mode_t mode */));```
- path: The path to the file you want to open (e.g., "myfile.txt").
- flags: Options specifying how to open the file. Multiple flags can be combined using the | (bitwise OR) operator.
- O_RDONLY: Open for reading only.
- O_WRONLY: Open for writing only.
- O_RDWR: Open for both reading and writing.
- O_CREAT: Create the file if it does not exist.
- O_TRUNC: If the file exists, truncate its length to 0 (i.e., clear its contents).
- O_APPEND: If the file exists, write data to the end of the file.
- mode: Specifies the file permissions (e.g., 0644) to be used if the file is newly created with the O_CREAT flag. This parameter is optional.

## <stdio.h>(FILE type)related file management function
#### fopen
