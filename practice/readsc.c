/*
read system call is used to read from file discriptor.
read() attempts to read up to count bytes from file descriptor 
fd into the buffer starting at buf.
*/
// header file need
#include<unistd.h>
// standard header file for printf
#include <stdio.h>
// main function
int main(){
    // like write read also take 3 parameter
    // read(int fd, void *buf, size_t count);
    // create a variable for store data read
    char data[30];
    // variable for indicating how much data
    // we read
    int n;
    //read call
    n = read(0,data,18); // this will read 10 amount of
    //data from stdin and store it on data array
    //display the content read
    // we can use both write and printf
    //write call
    write(1,data,n);
    // printf
    printf("data read : ");
    int i=0; // loop variable
    for(i = 0;i<n;i++){
        printf("%c",data[i]);
    }
    printf("\n");
    return 0;
}