#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
	char source_file[20];
	char des_file[20];
	char data_read[2];
	printf("ENTER SOURCE FILE : ");
	scanf("%s",source_file);
	
	printf("ENTER DES FILE : ");
	scanf("%s",des_file);
	
	int again = 0;
	int fd2 = 0;

	do{
		
		int test = open(des_file,O_EXCL);
		if(test!=-1){
			printf("DES FILE ALREADY EXIST\n");

			printf("ENTER DES FILE : ");
	scanf("%s",des_file);
		
		}else{fd2 = open(des_file,O_WRONLY|O_CREAT,0644);
		again = 1;}

		
	}while(again!=1);
		
		
		

	
	int fd = open(source_file,O_RDONLY);
	if(fd<2){
		printf("source file doesn't exist");
		exit(0);
	}


	while(read(fd,data_read,1)){
			write(fd2,data_read,1);
		}
		printf("CONTENTS COPIED SUCCESSFULLY\n");
	

}