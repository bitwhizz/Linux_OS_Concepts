#include  <stdio.h>
#include  <sys/types.h>
#include<stdlib.h>

int main()
{
int a=10;
if(fork()==0)
{
a+=4;
printf("child process with modified value= %d\n",a);

}
else
{
printf("parent process with unmodified value= %d\n",a);

}

return 0;
}
/*if fork is running in parent process then return the pid of child process
but if fork is running in the child process then return pid as zero(0)   */
