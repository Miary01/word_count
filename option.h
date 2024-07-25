#ifndef OPTION_H
#define OPTION_H
///the -l option
int counting_line(FILE* file,int argc,char* argv[],char line[100]);
void process(FILE* file,int argc,char* argv[]);
void opening_file(FILE* file,int argc,char* argv[]);
///the -c and -m option
int counting_char(FILE* file,int argc,char* argv[],char line[100]);
void process_1(FILE* file,int argc,char* argv[]);
void open_file(FILE* file,int argc,char* argv[]);
///the -w option
int counting_word(FILE* file,int argc,char* argv[],char line[100]);
void process_2(FILE* file,int argc,char* argv[]);
void op_file(FILE* file,int argc,char* argv[]);
///the -L option
int max_word(FILE* file,int argc,char* argv[]);
void process_3(FILE* file,int argc,char* argv[]);
void ropen_file(FILE* file,int argc,char* argv[]);
///without option
void without_option(FILE*file,int argc,char*argv[]);
void happening(FILE*file,int argc,char*argv[]);
#endif
