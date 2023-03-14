/*
The  open() system call opens the file specified by pathname.  If the specified file
 does not exist, it may optionally (if O_CREAT is specified in flags) be created by open().
       
syntax: 
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

       int open(const char *pathname, int flags); if file is already present
       or 
       int open(const char *pathname, int flags, mode_t mode); if file not present

flags : 
    O_APPEND : the fiel is opened in append mode.
    O_CREAT  : if pathname does not exist , create it as a regular file.
    O_RDONLY : file is read only.
    O_WRONLY : file is write only.
    O_RDWR   : write and read.

    The argument flags must include one of the following access modes: O_RDONLY, O_WRONLY, or O_RDWR.

mode : 
    specifies the file permissions for user,group,others
    4 indicate the person have only  read permission , 2 indicate write , 
    1 indicate execute , if all permission put 7.
    example if user has read and write permission and others have only read then put value
    as 0644
*/

// program for read contents of file and display
// header for open
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
// standard header 
#include<stdio.h>
// header for read and write
#include<unistd.h>
void main(){
    // variable for saving the fd
    int fd;
    int n ; // for saving amount of content read
    // variable storing the read data
    char data_read[255];
    // open a file
    fd = open("text.txt",O_RDONLY);
    // check if file is opened or not
    if(fd>2){
        // file opened successfully 
        printf("####file opened successfully######\n");
        // read the content
        n = read(fd,data_read,20);
        // write the read content to screen
        write(1,data_read,n);
        printf("\n");
    }else{
        // file not opened
        printf("some error occured, not such file\n");
    }
}