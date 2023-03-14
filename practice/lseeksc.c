/*
lseek - reposition read/write file offset

SYNOPSIS
       #include <sys/types.h>
       #include <unistd.h>

       off_t lseek(int fd, off_t offset, int whence);

DESCRIPTION
       lseek()  repositions  the  file offset of the open file description associated with the file descriptor fd to the argument offset according to the
       directive whence as follows:
       SEEK_SET
              The file offset is set to offset bytes.

       SEEK_CUR
              The file offset is set to its current location plus offset bytes.

       SEEK_END
              The file offset is set to the size of the file plus offset bytes.
*/

#include <sys/types.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>

void main(){
    
    int fd;
    char data[30];
    
    fd = open("text.txt",O_RDONLY);
    int fd2 = open("target2.txt", O_WRONLY | O_CREAT, 0644);
    lseek(fd2,0,SEEK_SET);
    if(fd>2){
       off_t filelen =  lseek(fd,0,SEEK_END);
        printf("%ld\n",filelen);
        int count = 0;
        int nlc = 0;
        while(count+filelen > 0){
            lseek(fd,count-1,SEEK_END);
            read(fd,data,1);
            //printf("%s",data);
            char c = data[0];            
            if(c == '\n'){
                nlc++;
            }
            printf("\n%d",nlc);
            if(nlc==2){
                    break;
            }else{
                    write(fd2,data,1);            
            }
            count -=1;
        }
        printf("\nread completly\n");
    }else{
        printf("ERROR OCCURED");
    }
}