#include <iostream>

void fillArray(int *arr, const int SIZE);
void fillChars(int *augArr, int *addArr, char *resultArray, const int SIZE);

int main()
{
	// (augend + addend) % 123 + 65
	// we may only need 2 INT arrays.

	size_t arraySize = 0;

	std::cout << "Please enter the size of your future arrays: ";
	std::cin >> arraySize;

	int *augendArray = new int[arraySize];
	int *addendArray = new int[arraySize];
	char *resultArray = new char[arraySize + 1];

	std::cout << "Please enter numbers for first array: ";
	fillArray(augendArray, arraySize);

	std::cout << "Please enter numbers for second array: ";
	fillArray(addendArray, arraySize);

	fillChars(augendArray, addendArray, resultArray, arraySize);

	std::cout << resultArray;

	delete[] augendArray;
	delete[] addendArray;
	delete[] resultArray;

	return 0;
}

void fillArray(int *arr, const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> *(arr + i);
	}
}

void fillChars(int *augArr, int *addArr, char *resultArray, const int SIZE)
{
	const int END_BOUND = 123;
	size_t i = 0;

	while (i < SIZE)
	{
		int sum = *(augArr + i) + *(addArr + i);

		if (sum >= END_BOUND)
		{
			sum %= END_BOUND;
			*(resultArray + i) = sum + 'A';
			i++;
			continue;
		}

		*(resultArray + i) = sum;

		i++;
	}

	*(resultArray + i) = '\0';
}