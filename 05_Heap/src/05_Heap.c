int main()
{
	int heapPointer;

	heapPointer = (int *) malloc(5242880); // allocate 1 KiB in the virtual space
	// The space is only allocated. The initialization will not be made by malloc()!
	// Therefore the allocated space can exceed the physical avialble space!

	printf("Pointer to the heap Stack: %d\n", heapPointer);

	return 1;
}
