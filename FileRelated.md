## FILE POINTER

### System call
- System calls are function invocation made from user space - to request a service from the krenel

### file descriptor(fd)
- fd is an integer that uniquely identifies an opened file
- An fd is a non-negative integer, represented in C language as the type int

## <fcntl.h>(file control operation)related file management System call
#### open()
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

##### Defined Symbols in <sys/stat.h>
- S_IRWXU: (00700) – All authority for owner
- S_IRUSR: (00400) – Read authority for owner
- S_IWUSR: (00200) – Write authority for owner
- S_IXUSR: (00100) – Execute authority for owner
- S_IRWXG: (00070) – All authority for group
- S_IRGRP: (00040) – Read authority for Group
- S_IWGRP: (00020) – Write authority for Group
- S_IXGRP: (00010) – Execute authority for Group
- S_IRWXO: (00007) – All authority for Others
- S_IROTH: (00004) – Read authority for Others
- S_IWOTH: (00002) – write authority for Others
- S_IXOTH: (00001) – Execute authority for Others

#### creat()
creat() can only open a file for writing only. To open a file for reading or read-write access, you must use open().
- If the file already exists, its contents are discarded (truncated to zero length).
- It returns a file descriptor on success and -1 on failure.
- syntax
```
#include <fcntl.h>
int creat(const char *pathname, mode_t mode);
```
- Parameters
- pathname: The path of the file to be created.
- mode: Specifies the permissions to use if a new file is created (e.g., 0644).
- Relationship with open(): The creat() call is precisely equivalent to calling open() with a specific set of flags. The following two lines of code are identical in function

#### read()
- The core job of read() is to copy a sequence of bytes from the kernel's internal buffers into a memory location you provide within your program (called user space).
- returns the size of read bytes on success, -1 on failure
- What to tell?
1. WHAT to read from: Using the file descriptor (fd) you got from open().
2. WHERE to put the data: The address of a buffer (like a char array) in your program.
3. HOW MUCH data to read: The maximum number of bytes you want.
```
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
```
* return value
The return value is ssize_t (a signed size type) and is crucial for error checking:
1. A positive number: This indicates success. The number is the count of bytes that were actually read and placed into your buffer. This can be less than the count you requested if the end of the file was reached or if data wasn't immediately available.
2. Zero (0): This means you have reached the End Of File (EOF). No more data can be read.
3. -1: An error occurred (e.g., the file descriptor was invalid, or there was a hardware read error). You can check the global variable errno to find out the specific error.
- the maximum value of ssize_t is SSIZE_MAX which is 2,1747,483,647 bytes on 32-bit machine

#### write()

## <stdio.h>(FILE type)related file management function
#### fopen

## fputs function usage
- syntax: int fputs(const char* str, FILE* pFile);
fputs means file + put + string
* function description
- 1st parameter: the string which will be put in file.
- 2nd parameter: file pointer
- return value: the counts of the character. 
    1. return value is over than 0 : the function works well
    2. return value is less than 0 : the function completed abnormally.
* how this function works
- write the str string given by parameter.

## fgets function usage
- syntax: char* fgets(char* str, int num, FILE* pFile);
fgets means file + get + string -> get string from the file.
* function description
- 1st parameter: the variance to put string from the file.
- 2nd parameter: the length of string to bring 
- 3rd parameter: file pointer
- return value: return the string that was brought or null in case of reaching the end of file.
* how this function works
- take the strings up to the size of 2nd paramter-1 strings. if there is \n in the middle, read until \n.
출처: https://blockdmask.tistory.com/404 [가면 뒤의 기록:티스토리]
* terms
- Null-terminated means a string of characters that ends with a special character called the null character ('\0'), which has value zero. This marks the end of the string so functions know where it stops in memory, even if the array is longer. For example, the string "hi" is stored as {'h', 'i', '\0'}. This is standard in C programming to know string length at runtime without storing length separately.
- feof() and ferror() are C library functions to check the status of a file stream after a read operation. feof() returns true if the end-of-file (EOF) has been reached, meaning no more data to read. ferror() returns true if an I/O error occurred during reading. You use these to distinguish why a function like fgets() returned NULL — whether it was because the file ended or because of an error.
- A pointer to the buffer is a memory address that points to where the read characters are stored in your program (the buffer array you passed to fgets()). fgets() returns this pointer to indicate success and allow further access to the read string. If it returns NULL, no characters were read.