#include<stdlib.h>
#include<stdio.h>


void read_file(char *file_path){
	
	FILE *fp = fopen(file_path , "r") ; 
	
	if(fp == NULL){
		perror(file_path);
		return ; 
	}

	size_t bytes_read ; 
	char buffer[4096] ; 

	while((bytes_read = fread(buffer , 1 , sizeof(buffer) , fp)) > 0){
		fwrite(buffer , 1 , bytes_read , stdout);
		if(ferror(fp)){
			perror("An error has occured while reading the file\n");
			return ; 
		}
	}

	fclose(fp) ;

}



int main(int argc  , char *argv[]){

	if(argc < 2){
		perror("Invalid Arguments");
		return 1 ; 
	}

	
	for(int i=1 ; i<= argc - 1 ; i++){
		read_file(argv[i]);
	}

	return 0 ; 
}
