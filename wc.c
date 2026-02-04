#include<stdio.h>
#include<stdlib.h>

typedef enum WordState{
 	IN_WORD , 
	OUT_WORD
}word_state ; 

int word_counter(FILE *fp){
	
	if(fp == NULL){
		return -1 ; 
	}

	int WORD_COUNT = 0 ;
	int state = OUT_WORD ; 
	char c ; 

	while((c = fgetc(fp)) != EOF){
		if(c == 32 && state == IN_WORD){
			state = OUT_WORD ;
			WORD_COUNT++ ; 
		}else if(state == OUT_WORD && c != 32){
				state = IN_WORD ; 
		}else if(state == IN_WORD && c == '\n'){
			state = OUT_WORD ; 
			WORD_COUNT++ ; 
	}	
	}


	return WORD_COUNT ; 
}


int main(int argc , char *argv[]){
	if(argc < 2){
		int result = word_counter(stdin) ;
		if(result < 0){
			fprintf(stderr , "An Error has occured\n");
			return 1 ; 
		}
		printf("Word Count : %d\n" , result) ; 
		return 0 ; 
	}
	
	
	int total_result = 0 ; 
	
	for(int i=1 ; i<argc ; i++){
		char *file_path = argv[i] ;

		FILE *fp = fopen(file_path , "r") ; 
		if (fp == NULL){
			continue ; 
		}
		int result = word_counter(fp) ; 
		
		if(result > -1){
			total_result += result ; 
			printf("%s %d\n" , file_path , result);
		}
		

		fclose(fp) ; 
	}
	
	printf("total : %d\n" , total_result);

	
	
	return 0 ; 

}
