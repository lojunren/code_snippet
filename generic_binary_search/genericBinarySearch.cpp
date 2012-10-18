#include <iostream>

void* BinarySearch(void* key, void* arr, int arrSize, int elemSize, int (*cmp)(void*, void*))
{
	if (key == NULL || arr == NULL)
	{
		return NULL;
	}

	void* low = arr;
	void* high = (char*)arr + arrSize;

	int result = 0;

	while (low <= high)
	{
		int mid = (int) ( ((char*)high - (char*)low) / elemSize >>1 );
		void* middle = (char*)low + mid*elemSize;

		result = cmp(key, middle);

		if(result < 0)
			high = (char*)middle - elemSize;
		else if(result > 0)
			low = (char*)middle + elemSize;
		else
			return middle;
	}
	return NULL;

}

int compare(void* elem1, void* elem2)
{
	int* vp1 = (int*)elem1;
	int* vp2 = (int*)elem2;

	return *vp1 - *vp2;

}

int main(int argc, char const *argv[])
{
	int key = 8;
	int arr[] = {0, 1, 2, 3, 4, 5, 6 ,7};
	int arrSize = sizeof(arr) / sizeof(int);
	int elemSize= sizeof(int);

	int* found =(int*)BinarySearch(&key, arr, arrSize, elemSize, compare);

	if (found == NULL)
	{
		std::cout << "Not found!" << std::endl;
	}
	else
	{
		std::cout << "Found!"<<std::endl;
	}

	return 0;
}