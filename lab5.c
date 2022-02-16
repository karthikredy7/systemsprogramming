#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#define ERROR_NULL NULL
int function_list(char *);
int main(int argc,char **argv)
{
        if(argc == 1)
	printf( "RET=%d \n",function_list("./"));
	else
	printf( "RET=%d \n",function_list(argv[1]));
	return 0;
}

int  function_list(char * pointer)
{

	DIR  *aa = ERROR_NULL;

	aa = opendir(pointer);
	
		if(aa == ERROR_NULL) return -1;

	struct dirent *st_dirent =ERROR_NULL;

	for ( ;((st_dirent = readdir(aa)) != ERROR_NULL); )
	{
	   if(strcmp((*st_dirent).d_name,".") && strcmp((*st_dirent).d_name,".."))
	   {
		if((*st_dirent).d_type  == DT_DIR)
		{
			char *pp = ERROR_NULL;
			pp = (char *)malloc(  50 +(sizeof(char) * strlen(pointer)));
			memcpy(pp,pointer,strlen(pointer)+1);
			//strcpy(pp,pointer);
			strcat(pp,"/");
			strcat(pp,(*st_dirent).d_name);
			
			printf("%s %s \n",pp,(*st_dirent).d_name);
			function_list(pp);
		}
			printf(" %s \n",(*st_dirent).d_name);

	  }	
	}

	closedir(aa);

}
