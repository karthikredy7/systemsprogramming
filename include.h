#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include<unistd.h>
//#include<apue.h>
#include<limits.h>
#include<sys/stat.h>
#include<sys/wait.h>

extern int S_OP,s_OP,s_OP_size,f_OP,t_OP,e_OP,E_OP;
extern  char *f_OP_str,*OP_PATH,*e_OP_str,*E_OP_str;
extern  char t_OP_CH;
extern  size_t pathlen;
extern  char *fullpath;
extern char name[1000];
extern char *Ename[1000];
extern int  FileCount;
extern FILE *FP;
 #define FTW_F		1
 #define FTW_D		2
 #define FTW_DNR	3
 #define FTW_NS 	4
 

typedef int Myfunc(const char *,const struct stat*,int);
extern  Myfunc myfunc;
static int myftw(char *,Myfunc *);
int dopath(Myfunc *);
void recursive(char *);
int copy_args(int argc,char **argv);

