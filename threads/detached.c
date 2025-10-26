#include <pthread.h>
#include <stdio.h>

/*Thread attributes provide a mechanism for fine-tuning the behavior of individual threads*/

void* thread_function (void* thread_arg)
{
	while (1)
	{
		fputc ('x', stderr);
		sleep(1);
	}
	return NULL;
}

int main ()
{
	/*easiest way is simply to declare an auto-matic variable of this type.*/
	pthread_attr_t attr;

	pthread_t thread;

	/*initializes the attributes to their default values.*/
	pthread_attr_init (&attr);
	
	/*To set the detach state in a thread attribute object,pass PTHREAD_CREATE_DETACHED as the second argument.*/
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);	

	pthread_create (&thread, &attr, &thread_function, NULL);

	pthread_attr_destroy (&attr);	//release the attribute object.
	
	while (1)
	{
		fputc ('o', stderr);
		sleep(1);
	}
	return 0;

	/* No need to join the second thread.return 0;*/
}
