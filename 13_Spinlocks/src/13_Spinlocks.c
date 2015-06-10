#include <stdio.h>
#include <pthread.h>

int *lock = 0;

int TestAndSet()
{
	int ret = *lock;
	*lock = 1;
	return ret;
}

void enterCritical()
{
	while (TestAndSet())
	{
	}
}

void leaveCritical()
{
	*lock = 0;
}

void *thread(void *args)
{
	printf("Thread %d startet!\n", (int) args);

	enterCritical();

	printf("Thread %d is now in the crtical area!\n", (int*) args);
	// Do critical stuff!
	sleep(3);

	leaveCritical();
	return 1;
}

int main()
{
	int i;

	int threadCount = 5;

	int thread[threadCount];
	pthread_t threadId[threadCount];
	void *threadPointer;

	for (i = 0; i < threadCount; i++)
	{
		thread[i] = pthread_create(&threadId[i], 0, thread, i);
	}

	int arrayLength = sizeof(thread) / sizeof(thread[0]);

	for (i = 0; i < arrayLength; i++)
	{
		pthread_join(threadId[i], &threadPointer);
	}

	printf("-------\n");

	return 1;
}
