#include <sys/shm.h>
#include <stdio.h>

int main()
{
	int memoryId;
	key_t key = 666;
	size_t size = 1024;
	void* memoryPointer;

	memoryId = shmget(key, size, 0666 | IPC_CREAT); // Create Shared Memory Segment

	memoryPointer = shmat(memoryId, (void*) NULL, 0); // Point to the Shared Memory

	shmdt(memoryPointer); // Delete Segment from Shared Memory

	shmctl(memoryId, IPC_RMID, 0); // Delete Segment

	return 1;
}
