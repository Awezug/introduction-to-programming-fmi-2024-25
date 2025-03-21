#include <iostream>

void insertNumber(size_t *row, size_t index, const size_t SIZE, size_t number);
void printArray(size_t *array, const size_t SIZE);

int main()
{
	const size_t SIZE = 15;
	size_t i = 0;

	size_t promptRow[SIZE];
	size_t promptNumber;

	std::cout << "Please enter the row: ";
	
	while ( i < SIZE)
	{
		std::cin >> promptRow[i];

		i++;
	}

	std::cout << "Please enter the number: ";
	std::cin >> promptNumber;

	insertNumber(promptRow, 0, SIZE, promptNumber);

	printArray(promptRow, SIZE);

	return 0;
}

void insertNumber(size_t *row, size_t index, const size_t SIZE, size_t number)
{
	if (row == nullptr)
	{
		return;
	}

	if ( index + 1 >= SIZE	)
	{
		return;
	}

	if ( number >= *(row + index) )
	{
		insertNumber(row, index + 1, SIZE, number);
	}
	else if ( number < *(row + index) )
	{
		size_t temp = *(row + index);
		*(row + index) = number;

		insertNumber(row, index + 1, SIZE, temp);
	}
}

void printArray(size_t *array, const size_t SIZE)
{
	size_t i = 0;

	while (i < SIZE)
	{
		std::cout << *(array + i) << " ";

		i++;
	}

	std::cout << std::endl;
}