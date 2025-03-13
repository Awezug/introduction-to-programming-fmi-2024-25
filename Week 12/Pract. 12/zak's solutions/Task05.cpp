#include <iostream>

void replaceChar(char *source, char *symbols);

int main()
{
	const int SIZE = 100;

	char string[SIZE];

	char array[SIZE];

	std::cout << "Please enter the string: ";
	std::cin.getline(string, SIZE);

	std::cout << "Please enter the characters: ";
	std::cin.getline(array, SIZE);

	replaceChar(string, array);

	std::cout << string;

	return 0;
}

void replaceChar(char *source, char *symbols)
{
	if (source == nullptr || symbols == nullptr)
	{
		std::cout << "\nYou have entered incorrect string or characters!\n";

		return;
	}

	const char REP = '*';
	size_t i = 0;
	while (*(source + i))
	{
		size_t j = 0;
		while (*(symbols + j))
		{
			if (*(source + i) == *(symbols + j))
			{
				*(source + i) = REP;
			}
			j++;
		}
	i++;
	}
}