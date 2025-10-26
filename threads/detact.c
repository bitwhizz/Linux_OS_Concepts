/*create athread in detacted state*/

#include<stdio.h>
#include<pthread.h>
struct para_hello

{
	char character;
	int count;
};

void* hello(void* x)
{
	int i;	
	struct para_hello* p=(struct para_hello*) x;
	for(i=0;i<p->count;i++)
	{
		sleep(1);
		
		printf("%c\n",p->character);
	}	
	return NULL;
}

int main()
{
	pthread_t thread1_id;
	
	int i;
	struct para_hello thread1_arg;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	
	thread1_arg.character='h';
	thread1_arg.count=10;
	if(pthread_create(&thread1_id,&attr,&hello,&thread1_arg)==-1)
	{
		return -1;
	}
	
		
	
	for(i=0;i<4;i++)
	{	
	sleep(1);	
	printf("world\n");
	
	}
	pthread_attr_destroy (&attr);

	
	return 0;
}

