#include<stdlib.h>
#include<stdio.h>


int main(int argc  , char *argv[]){

	if(argc < 2){
		perror("Invalid Arguments");
		return 1 ; 
	}

	FILE *fp = fopen(argv[1] , "r") ;

	size_t bytes_read ; 
	char buffer[4096];
	while((bytes_read=fread(buffer , 1 , sizeof(buffer) , fp)) > 0){
		fwrite(buffer , 1 , bytes_read , stdout);
	}

	fclose(fp);

	return 0 ; 
}
