#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "option.h"
///the -l option
int counting_line(FILE* file,int argc,char* argv[],char line[100]){
    int count=0;
    while(feof(file)!=1){
        fgets(line,100,file);
        count++;
    }
   // fclose(file);
    return count;
}
void process(FILE* file,int argc,char* argv[]){
    int number_line;
    char line[100]; //a string which will contain the character on a line
    number_line=counting_line(file,argc,argv,line);
    printf("%d %s",number_line-1,argv[2]);
    fclose(file);
}
void opening_file(FILE* file,int argc,char* argv[]){
    file=fopen(argv[2],"r"); //opening the file
    //if there's problem :
    if(file==NULL){
        printf("file doesn't exist or can't be open!!!\n");
        exit(1);
    }else{
        process(file,argc,argv); //a second main
    }
}
///the -c option
int counting_char(FILE* file,int argc,char* argv[],char line[100]){
    char c;
    int count=0;
   while((c=fgetc(file)) != EOF)
        count++;
   return count;
}
void process_1(FILE* file,int argc,char* argv[]){
    int number_char;
    char line[100]; //a string which will contain the character on a line
    number_char=counting_char(file,argc,argv,line);
    printf("%d %s",number_char,argv[2]);
    fclose(file);
}
void open_file(FILE* file,int argc,char* argv[]){
    file=fopen(argv[2],"r"); //opening the file
    //if there's problem :
    if(file==NULL){
        printf("file doesn't exist or can't be open!!!\n");
        exit(1);
    }else{
        process_1(file,argc,argv); //a second main
    }
}
///the -w option
int counting_word(FILE* file,int argc,char* argv[],char line[100]){
    char c;
    int count=0;
    int count_space=0,count_word=0;
      while(feof(file)!=1){
	fscanf(file,"%s",line);
	count_word++;
     }

    return count_word;
}
void process_2(FILE* file,int argc,char* argv[]){
    int number_word;
    char line[100]; //a string which will contain the character on a line
    number_word=counting_word(file,argc,argv,line);
    printf("%d %s",number_word-1,argv[2]);
    fclose(file);
}

void op_file(FILE* file,int argc,char* argv[]){
    file=fopen(argv[2],"r"); //opening the file
    //if there's problem :
    if(file==NULL){
        printf("file doesn't exist or can't be open!!!\n");
        exit(1);
    }else{
        process_2(file,argc,argv); //a second main
    }
}
///the -L option
int max_word(FILE* file,int argc,char* argv[]){
    //char c;
    char line[100];
    int* tab=NULL;
    int count_word=0,count_1=0;
    int max,cline=0;
    while(feof(file)!=1){
        fgets(line,100,file);
        count_1++;
    }
  	tab=(int *)malloc(count_1*sizeof(int));
	//fseek(file,0,SEEK_SET);
	rewind(file);
	 while(feof(file)!=1){
		/*while((c=fgetc(file))!=EOF){
		//count_word++;
		//fscanf(file,"%s",line);
			if(c!=' ')count_word++;
			if(c=='\n') c=EOF;
		}*/
		fgets(line,100,file);
		for(int i=0;i<strlen(line);i++){
		//	if(strncmp(line+i," ",1)==0) count_word+=0;
			count_word++;
		}
		tab[cline]=count_word;
		cline++;
		count_word=0;
        }

	max=tab[0];
	for(int i=0;i<count_1;i++){
		if(max<tab[i]) max=tab[i];
		//printf("%d,",tab[i]);
	}
     free(tab);
    return max;
}
void process_3(FILE* file,int argc,char* argv[]){
    int number_max;
    ///char line00]; //a string which will contain the character on a line
    number_max=max_word(file,argc,argv);
    printf("%d %s",number_max-1,argv[2]);
    fclose(file);
}

void ropen_file(FILE* file,int argc,char* argv[]){
    file=fopen(argv[2],"r"); //opening the file
    //if there's problem :
    if(file==NULL){
        printf("file doesn't exist or can't be open!!!\n");
        exit(1);
    }else{
        process_3(file,argc,argv); //a second main
    }
}
///without option
void happening(FILE*file,int argc,char*argv[]){
	int number_line;
	int number_word;
	int number_char;
    	char line[100]; //a string which will contain the character on a line
    	number_line=counting_line(file,argc,argv,line);
	rewind(file);
	number_word=counting_word(file,argc,argv,line);
        rewind(file);
	number_char=counting_char(file,argc,argv,line);
	printf("%d %d %d %s",number_line-1,number_word-1,number_char,argv[1]);
}
void without_option(FILE*file,int argc,char*argv[]){
	file=fopen(argv[1],"r"); //opening the file
    	//if there's problem :
    	if(file==NULL){
        	printf("file doesn't exist or can't be open!!!\n");
        	exit(1);
    	}else{
        	happening(file,argc,argv); //a second main
    	}
}


