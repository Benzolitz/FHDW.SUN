#include <pthread.h>
#include <stdio.h>


void *mutexThread(void *args) {

	pthread_mutex_t mtx;
	pthread_mutex_init(&mtx, NULL);

	pthread_mutex_lock(&mtx);

	printf("Thread %d is now in the critical area!\n", (int*) args);

	sleep(2);

	pthread_mutex_unlock(&mtx);
	pthread_mutex_destroy(&mtx);

	return 1;
}


int main()
{
	int i;

	int threadCount = 4;

	int thread[threadCount];
	pthread_t threadId[threadCount];
	void *threadPointer;

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

	return 1;
}
