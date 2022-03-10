#include"include.h"
/* show the output based on client requirement 
 * print the type of file and size */
int myfunc(const char *pathname,const struct stat *statptr,int type)
{
	//printf("name:%s\n",name);
char *ptr;
#if 1
	static char j=0;

	//if(((f_OP ==1) && strstr(statptr->d_name,f_OP_str) == NULL) ||
	if(((f_OP ==1) && strstr(name,f_OP_str) == NULL) ||
	   ((s_OP==1)  && ( statptr->st_size < s_OP_size )))  /* return thr file if file not satisfied the user requiremet */  
	{  return 0;}

	if((t_OP ==1)&& (((t_OP_CH =='d')&& !S_ISDIR(statptr->st_mode)) ||
				 ((t_OP_CH =='f')&& !S_ISREG(statptr->st_mode))  ))
	{  return 0;}

	if((E_OP == 1) && strcmp(pathname,OP_PATH))
	{
	      Ename[FileCount] = malloc(strlen(pathname) +1);
	      strcpy(Ename[FileCount],pathname);
	      FileCount +=1;
	}	
#if 0		    
	if( (j !=0) && i==1 )
		{
			printf("\t"); /* this is for allignment */
		    }
#endif
	printf("%-40s ",pathname);

	switch(type)
	{
	  case FTW_F:
		  switch(statptr->st_mode & S_IFMT){
			  case S_IFREG:printf("REGULAR FILE ");
				       break;
			  case S_IFBLK:printf("BLK FILE ");
				       break;
			  case S_IFCHR:printf("CHR FILE ");
				       break;
			  case S_IFIFO:printf("FIFO FILE ");
				       break;
			  case S_IFLNK:printf("LINK FILE ");
				       break;
			  case S_IFSOCK:printf("SOCK FILE ");
				       break;
			  case S_IFDIR:printf("DIR FILE ");
				       break;
				  	}
		      break;
	  case FTW_D:
		  printf("DIR ");
		  break;
	  case FTW_DNR:
		  printf("CANT READ DIR ");
		  break;
	  case FTW_NS:
		  printf("STAT ERROR ");
		  break;
	  default:
		  printf("unknow error ");
	
	
	}
	if((S_OP ==1))
		printf(" (%ld)",statptr->st_size);

	printf("\n");
	int status;
	if((e_OP ==1))
	{
		pid_t put_pid;
		put_pid = fork(); /* creating the child process */
		if(put_pid == 0)
		{
			if((e_OP ==1) && type != FTW_D )
			{
#if 0	
				char eBuff[1000]={0};
				strcpy(eBuff,e_OP_str);
				strcat(eBuff," ");
				strcat(eBuff,pathname);
				system(eBuff);
#endif
				char *ptr ;
				char *buff[10];
				char Count =0;
				ptr = strtok(e_OP_str," \n");
				while(ptr !=NULL)
				{
					buff[Count] = malloc(strlen(ptr)+1);
					strcpy(buff[Count],ptr);
					ptr = strtok(NULL," \n");
					Count +=1;
				}
				buff[Count] = malloc(strlen(pathname) +1);
				strcpy(buff[Count],pathname);
				Count +=1;
				buff[Count] =NULL;
				if(execvp(buff[0],buff) <0)
					perror("execlp");
   			      //return 0;
				exit(-1);
			}
			printf("\n");
		}
		else	
		{
			wait(&status);/* waiting for child termination */
		//	printf("child terminated\n");
				//exit(-1);
   			return 0;
		}
	}
	else
   	 return 0;
#endif
}
