#include <iostream>

bool isPalindrome(char *row, size_t indexBegin, size_t indexEnd);
size_t actualSize (char *row);

int main()
{
	const size_t SIZE = 50;

	char promptRow[SIZE];

	std::cout << "Please enter the row: ";
	
	std::cin.getline(promptRow, SIZE);

	size_t promptedSize = actualSize(promptRow);

	bool result = isPalindrome(promptRow, 0, promptedSize - 1);

	result ? std::cout << "True" : std::cout << "False";

	return 0;
}

bool isPalindrome(char *row, size_t indexBegin, size_t indexEnd)
{
	if (row == nullptr)
	{
		return 0;
	}

	bool result = 0;

	if ( indexBegin == indexEnd || indexBegin >= indexEnd	)
	{
		return 1;
	}

	if ( *(row + indexBegin) == *(row + indexEnd) )
	{
		result = isPalindrome(row, indexBegin + 1, indexEnd - 1);
	}

	return result;
}

size_t actualSize (char *row)
{
	if (row == nullptr)
	{
		return 0;
	}

	size_t i = 0;

	while (*(row + i))
	{
		i++;
	}

	return i;
}