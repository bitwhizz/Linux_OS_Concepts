#include  <stdio.h>
#include  <sys/types.h>

int a=10;

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;		//typedef which is define in sys/types.h

     pid = fork();		//pid of parent and child process
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();
}

void  ChildProcess(void)
{
	a+=2;
     //int a=20;
	printf("child process modified value=%d\n",a);
}

void  ParentProcess(void)
{
     //int a=10;
	printf("parent process value=%d\n",a);

}
