#include<stdio.h>
main()
{

	#if 0
	/*this doesn't print one period every second instead the periods are buffered,
	 and bunch of them are printed together*/
	while(1)
	{
		printf(".");
		sleep(1);
		//fflush(stdout); //by using this function we can flush the contents in buffer immidiately
	}
	#endif

	#if 1
	/* period appear once a second*/
	while(1)
	{
		/*redirecting stdout to a file while allow stderr to print on console directly*/
		fprintf(stderr,".");
		sleep(1);
	}
	#endif
}

/*stderr is not buffered ,data written to stderr goes directly to the console */
