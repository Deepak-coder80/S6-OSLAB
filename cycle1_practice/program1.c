// program for read contents of file and write to new file all content
// header for open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// standard header
#include <stdio.h>
// header for read and write
#include <unistd.h>
void main()
{
    // variable for saving the fd
    int fd, fd2;
    int n; // for saving amount of content read
    // variable storing the read data
    char data_read[255];
    // open a source file
    fd = open("text.txt", O_RDONLY);
    // check if file is opened or not
    if (fd > 2)
    {
        // file opened successfully
        printf("####file opened successfully######\n");
        // open destination file if not present create
        fd2 = open("target.txt", O_WRONLY | O_CREAT, 0644);
        // read the content
        while (read(fd, data_read, 1))
        {

            // write the read content to destination file
            write(fd2, data_read, 1);
        }

        printf("\nFinished Task\n");
    }
    else
    {
        // file not opened
        printf("some error occured, not such file\n");
    }
}