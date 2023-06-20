#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <stdlib.h>

void main(){
	int nl = 0;
	printf("Enter no. of lines want to copy : ");
	scanf("%d",&nl);

	if(nl<0){
		printf("INVALID INPUT\n");
		exit(0);
	}

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
		
		}else{fd2 = open(des_file,O_WRONLY|O_CREAT|O_TRUNC,0644);
		again = 1;}

		
	}while(again!=1);
	

	
	
	// open source file
	int fd = open(source_file,O_RDONLY);
	
	if(fd>2){
		printf("FILE OPENDED\n");
		
		lseek(fd2,0,SEEK_SET);
		off_t filelength = lseek(fd,0,SEEK_END);

		int count = 0;
		int nlc =0;
		
		while(count+filelength > 0){
			lseek(fd,count-2,SEEK_END);
			read(fd,data_read,1);
			if(data_read[0]=='\n'){
				nlc++;
			}
			if (nlc == nl){
				break;
			}else{
				
				write(fd2,data_read,1);}
			count -=1;
		}
		write(fd2,data_read,1);
		printf("OPERATION COMPLETE SUCCESSFULLY\n");
	}else{
		printf("FILE NOT FOUND\n");
	}
}
