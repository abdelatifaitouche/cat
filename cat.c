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
		if(fwrite(buffer , 1 , bytes_read , stdout) != bytes_read){
			perror("write error");
			fclose(fp) ;
			return ; 
		};
	
	}

	if(ferror(fp)){
		perror(file_path) ; 
	}

	fclose(fp) ;

}

void read_stdin(){
	char buffer[4096] ; 
	while(fgets(buffer , sizeof(buffer) , stdin)){
		fputs(buffer , stdout) ; 
	}
}

int main(int argc  , char *argv[]){

	if(argc < 2){
		read_stdin() ; 
		return 0 ; 
	}

	
	for(int i=1 ; i<argc ; i++){
		read_file(argv[i]);
	}

	return 0 ; 
}
