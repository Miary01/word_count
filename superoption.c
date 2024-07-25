#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "option.h"
#include "superoption.h"
void principal(FILE* file,int argc,char* argv[]){
	if(strcmp(argv[1],"-c")==0 || strcmp(argv[1],"--bytes")==0 || strcmp(argv[1],"m")==0 || strcmp(argv[1],"--chars")==0) open_file(file,argc,argv);
	if(strcmp(argv[1],"-w")==0 || strcmp(argv[1],"--words")==0) op_file(file,argc,argv);
	if(strcmp(argv[1],"-l")==0 || strcmp(argv[1],"--lines")==0) opening_file(file,argc,argv);
	if(strcmp(argv[1],"-L")==0 || strcmp(argv[1],"--max-line-length")==0) ropen_file(file,argc,argv);
	if(argc==2) without_option(file,argc,argv);

}
