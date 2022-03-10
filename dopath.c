#include"include.h"
/* this is the main file to do the entire operation like get the information about the files and 
 * passing to print variable */
int dopath(Myfunc * func) 
{
  struct stat statbuf;
  struct dirent *dirp;
  DIR *dp;
  int ret,n;
#if 1

  	   if(lstat(fullpath,&statbuf) <0)  /*  get the information of file */
     		{printf("!!\n") ;  return (func(fullpath,&statbuf,FTW_NS));}
     if(S_ISDIR(statbuf.st_mode) == 0)
     {   return (func(fullpath,&statbuf,FTW_F));}
	     
	     if( (ret = func(fullpath,&statbuf,FTW_D)) != 0)
	     { // printf("retunr here\n");
		     return(ret);}
	     n = strlen(fullpath);
#if 1
	     if(n+ NAME_MAX + 2 > pathlen){
	       pathlen *=2;
	       if((fullpath = realloc(fullpath,pathlen)) == NULL)
	       { printf("Error realloc\n"); return -1;}
	     
	     }
	     fullpath[n++] = '/';
	     fullpath[n] = 0;
#endif
	  //   printf("@@ %s\n",fullpath);
	     if((dp = opendir(fullpath)) == NULL) // open the path mentioned by the user
		     return(func(fullpath,&statbuf,FTW_DNR));

#endif

	     dp = opendir(fullpath);
	     if(dp ==NULL)
	         {printf("Error in dir open\n");	     return -1;}

	     while((dirp = readdir(dp)) != NULL)
	     {
	        if(strcmp(dirp->d_name,".") ==0 ||
		   strcmp(dirp->d_name,"..") == 0)
			continue;
		strcpy(&fullpath[n],dirp->d_name); /* if open path is directory call this function recursively */
		strcpy(name , dirp->d_name);
	//	printf("final name :%s\n",fullpath);
		//if((ret= dopath(func)) != 0)
		if((ret= dopath(func)) !=0 )
			{
				//printf("#");
				break;
			}
	     }
	     fullpath[n-1]= 0;
	     if(closedir(dp) <0)
		     return -1;
	     return(ret);
}
