/*
write is a system call which is used to write
contents in the buffer to a file discriptor.
write() writes up to count bytes from the buffer 
starting at buf to the file referred to by the file descriptor fd.
*/
//header file needed
#include <unistd.h>
// executable main fuction
void main(){
    // write function takes 3 parameters
    // first one is file discriptor fd
    write(1,"Hello I am Deepak\n",18);
    // default values for fd are
    /*
        0 for stdin
        1 for stdout
        2 for stderr
    */
    // second parameter is the buffer which is our data
    // third one is count , which indicate how much amount
    // of data want to write to the fd.
}