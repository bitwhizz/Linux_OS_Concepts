#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	printf("self_exec:my pid is %d \n",getpid());

	if(argc!=2)
	{
		printf("pass 1 argument as an integer \n");
		exit(1);
	}

	int n=atoi(argv[1]);			//atoi()-convert string to integer
	printf("%d..\n",n);

	if(n!=0)
	{
		char nminus1[10];			//string
		sprintf(nminus1,"%d",n-1);	//write in string
		printf("arg to pass %s \n",nminus1);
		execl(argv[0],argv[0],nminus1,NULL);	//first is the name of program itself and rest are arguments
	}
/* replacing the program by the same program itself -this acts like recursion */

	printf("farewell cruel world\n"); 
	return 0;
}
 
/* cmd: gcc self_exec.c -o self_exec   and   ./self_exec (no) */

