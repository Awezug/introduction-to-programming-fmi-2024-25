#include <iostream>

bool isAscending(size_t *row, size_t index, const size_t SIZE);

int main()
{
	const size_t SIZE = 5;
	size_t i = 0;

	size_t promptRow[SIZE];

	std::cout << "Please enter the row: ";
	
	while ( i < SIZE)
	{
		std::cin >> promptRow[i];

		i++;
	}

	bool result = isAscending(promptRow, 0, SIZE);

	result ? std::cout << "True" : std::cout << "False";

	return 0;
}

bool isAscending(size_t *row, size_t index, const size_t SIZE)
{
	if (row == nullptr)
	{
		return 0;
	}

	bool result = 0;

	if ( index + 1 >= SIZE	)
	{
		return 1;
	}

	if ( *(row + index) < *(row + index + 1) )
	{
		result = isAscending(row, index + 1, SIZE);
	}

	return result;
}