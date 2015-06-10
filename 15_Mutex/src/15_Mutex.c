#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mtx;
void *mutexThread(void *args)
{
	pthread_mutex_lock(&mtx);

	printf("Thread %d is now in the critical area!\n", (int*) args);

	sleep(2);

	pthread_mutex_unlock(&mtx);

	return 1;
}

int main()
{
	int i;

	int threadCount = 4;

	int thread[threadCount];
	pthread_t threadId[threadCount];
	void *threadPointer;

	pthread_mutex_init(&mtx, NULL);
	for (i = 0; i < threadCount; i++)
	{
		thread[i] = pthread_create(&threadId[i], 0, mutexThread, i);
	}

	int arrayLength = sizeof(thread) / sizeof(thread[0]);

	for (i = 0; i < arrayLength; i++)
	{
		pthread_join(threadId[i], &threadPointer);
	}

	printf("All threads are done!\n");
	pthread_mutex_destroy(&mtx);

	return 1;
}
