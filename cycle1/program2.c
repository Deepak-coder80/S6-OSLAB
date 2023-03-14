// copy n lines of file to new file in reverse order

#include <sys/types.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

void main(){

    // read no of lines want to copy
    int nl=0;
    printf("Enter no. of lines want to copy : ");
    scanf("%d",&nl);
    
    if(nl<0){
        printf("INVALID INPUT\n");
        exit(0);
    }

    int fd;
    char data[30];
    
    fd = open("text.txt",O_RDONLY);
    int fd2 = open("target2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    lseek(fd2,0,SEEK_SET);
    if(fd>2){
       off_t filelen =  lseek(fd,0,SEEK_END);
        printf("%ld\n",filelen);
        int count = 0;
        int nlc = 0;
        while(count+filelen > 0){
            lseek(fd,count-1,SEEK_END);
            read(fd,data,1);    
            if(data[0] == '\n'){
                nlc++;
            }
            if(nlc==nl){
                    break;
            }else{
                    write(fd2,data,1);            
            }
            count -=1;
        }
        printf("\nread completly\n");
    }else{
        printf("\nERROR OCCURED\n");
    }
}