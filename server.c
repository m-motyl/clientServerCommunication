#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<math.h>

int getFileSize(const char* file_name);

int main(){

	int data;
	while(1){
		//if file is not empty
		if(getFileSize("buffer.txt") != 0){

			//opening buffer.txt in read mode
			FILE *readData = fopen("buffer.txt", "r");
			if(readData == NULL){
				printf("File opening problem\n");
				exit(-1);
			}

			//read from file
			fscanf(readData, "%d", &data);
			//printf("%d\n", data);
			fclose(readData);
	
			//clear buffer.txt file after reading from file
			fclose(fopen("buffer.txt", "w"));

			//save result to results.txt
			FILE *writeData = fopen("results.txt", "w");
			if(writeData == NULL){
				printf("File opening problem\n");
				exit(-1);
			}

			//x^3
			data = pow(data, 3);

			fprintf(writeData, "%d", data);
			fclose(writeData);
		}

		//loop delay
		//sleep(1);
	}

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
