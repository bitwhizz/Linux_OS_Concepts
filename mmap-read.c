//Read an Integer from a Memory-Mapped File, and
//Double It

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define FILE_LENGTH 0x100

int main (int argc, char* const argv[])
{
    int fd;
    void* file_memory;
    int integer;

    /* Open the file. */
    fd = open (argv[1], O_RDWR, S_IRUSR | S_IWUSR);
    /* Create the memory mapping. */
    file_memory = mmap (0, FILE_LENGTH, PROT_READ | PROT_WRITE,
    MAP_SHARED, fd, 0);

    close (fd);
    /* Read the integer, print it out, and double it. */
    scanf (file_memory, "%d", &integer);
    printf ("value: %d\n", integer);

    sprintf ((char*) file_memory, "%d\n", 2 * integer);
    /* Release the memory (unnecessary because the program exits).*/
    munmap (file_memory, FILE_LENGTH);

return 0;
}

/*
% ./mmap-write /tmp/integer-file
% cat /tmp/integer-file
42
% ./mmap-read /tmp/integer-file
value: 42
% cat /tmp/integer-file
84


saif@saif-Inspiron-5547:~/programmer/Linux_OS_Concepts$ ./exe /tmp/integer-file  
value: 4195952
saif@saif-Inspiron-5547:~/programmer/Linux_OS_Concepts$ cat /tmp/integer-file 
8391904

*/