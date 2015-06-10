#include <stdio.h>
#include <pthread.h>

int global = 0;

void *increaseGlobal(void *args)
{
	global++;
	printf("i: %d - global: %d\n", (int*) args, global);

	return 1;
}

int main()
{
	int i;

	int threadCount = 5000;

	int thread[threadCount];
	pthread_t threadId[threadCount];
	void *threadPointer;

	for (i = 0; i < threadCount; i++)
	{
		thread[i] = pthread_create(&threadId[i], 0, increaseGlobal, i);
	}

	int arrayLength = sizeof(thread) / sizeof(thread[0]);

	for (i = 0; i < arrayLength; i++)
	{
		pthread_join(threadId[i], &threadPointer);
	}

	printf("-------\n");
	printf("%d", global);

	return 1;
}
