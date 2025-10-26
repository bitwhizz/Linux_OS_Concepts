/*wap that creates a thread.pan an integer argument to this thread from the main function.the thread function should print this integer value after every one second in a never ending while loop.observe if the program continues running or dies after some time.(hint:dont use pthread_join anywhere)*/

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
		//printf("the value o thread1 is %d\n",pthread_self());	
		printf("%c\n",p->character);
	}	
	return NULL;
}

int main()
{
	pthread_t thread1_id;
	//pthread_t thread2_id;
	int i;
	struct para_hello thread1_arg;
	//struct para_hello thread2_arg;
	
	thread1_arg.character='h';
	thread1_arg.count=10;
	pthread_create(&thread1_id,NULL,&hello,&thread1_arg);
	
	for(i=0;i<4;i++)
	{	
	sleep(1);	
	printf("world\n");
	//printf("the value o thread2 is %d\n",pthread_self());
	}

	//pthread_join(thread1_id,NULL);
	/*thread1_arg.character='w';
	thread1_arg.count=10;
	pthread_create(&thread2_id,NULL,&hello,&thread2_arg);*/
	
	return 0;
}









