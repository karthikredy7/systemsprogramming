#include"include.h"
int S_OP,s_OP,s_OP_size,f_OP,t_OP,e_OP,E_OP;
char *f_OP_str=NULL,*OP_PATH,*e_OP_str,*E_OP_str;
char t_OP_CH;
size_t pathlen;
char *fullpath;
char name[1000];
char *Ename[1000];
int  FileCount =0;
Myfunc myfunc;

/* this is a enter point of the homwwork  calling the diffrent function from here */

int main(int argc,char *argv[])
{
	int ret;
	pid_t pid;
	int status;


	if (copy_args(argc,argv) < 0)
	{
		return -1;
	}
	if(OP_PATH == NULL)
		OP_PATH = ".";
	//printf("%s\n",OP_PATH);
	myftw(OP_PATH,myfunc); /*passing the path */
	if(E_OP == 1)
	{
		pid = fork(); /*creating the child process execute the execvp */
		if(pid == 0) /*child process */
		{
	//		for(int i =0; i < FileCount ; i++)
	//			printf("%s\n",Ename[i]);
			Ename[FileCount] = NULL;
			if(execvp(Ename[0],Ename))
				perror("execpv");
			printf("Echild terminated\n");
			exit(-1);
		}
		else{ /*parent process*/
		//	printf("waiting for child  process terminated\n");
			wait(&status);
		//	printf("parent process terminated\n");
		}
	}
	return 0;
}
static int myftw(char *pathname,Myfunc *func)
{
#if 1
	pathlen = strlen(pathname) +1;
   fullpath = (char *)malloc((pathlen)); /* allocate the memmory */
  if (pathlen < strlen(pathname))
  {
    pathlen = strlen(pathname) * 2;
    if((fullpath = realloc(fullpath,pathlen)) == NULL)
     { printf("error in realloc faild"); return -1;}
  }
#endif
  // fullpath = (char *)malloc((strlen(pathname) + 1)* sizeof(char));

  strcpy(fullpath,pathname);
  //printf("#\n");
  return(dopath(func));
}

