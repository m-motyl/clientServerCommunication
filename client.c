#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int getFileSize(const char* file_name);

int main(){

	int data;
	scanf("%d", &data);

	//write data to buffer.txt
	FILE *writeData = fopen("buffer.txt", "w");
	if(writeData == NULL){
		printf("File opening problem\n");
		exit(-1);
	}

	fprintf(writeData, "%d", data);	
	fclose(writeData);	

	/////
	//waiting for server response, need for delay
	// 1st solution
	//sleep(1);

	// 2nd solution
	while(getFileSize("results.txt") == 0){
		continue;
	}
	/////

	//read processed data from results.txt
	FILE *readData = fopen("results.txt", "r");
	if(readData == NULL){
		printf("File opening problem\n");
		exit(-1);
	}

	fscanf(readData, "%d", &data);
	printf("%d\n", data);
	fclose(readData);

	//clear results.txt file
	fclose(fopen("results.txt", "w"));

	return 0;
}

int getFileSize(const char* file_name){
	FILE *file = fopen(file_name, "r");
	if(file == NULL){
		printf("File opening problem\n");
		exit(-1);
	}
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fclose(file);
	return size;
}
