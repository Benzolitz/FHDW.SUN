int main()
{
	int heapPointer;

	heapPointer = (int *) malloc(1024); // allocate 1 KiB in the virtual space

	printf("Pointer to the heap Stack: %d\n", heapPointer);

	return 1;
}
