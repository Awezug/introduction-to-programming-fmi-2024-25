#include <iostream>

int main()
{
	const int SIZE = 100;
	char inputSymbols[SIZE];
	char resultSymbols[SIZE];

	std::cin.getline(inputSymbols, SIZE-1);

	size_t i = 0;
	size_t resultPos = 0;
	bool isWord = 0;
	size_t startPosWord = 0;

	while (*(inputSymbols + i))
	{
		char symbol = *(inputSymbols + i);

		if (symbol >= 'a' && symbol <= 'z')
		{
			if (!isWord)
			{
				startPosWord = i;
				isWord = 1;
				*(resultSymbols + resultPos) = symbol;
				resultPos++;
			}
		}
		if (symbol >= 'A' && symbol <= 'Z')
		{
			if (!isWord)
			{
				startPosWord = i;
				isWord = 1;
				*(resultSymbols + resultPos) = symbol;
				resultPos++;
			}
		}

		if (symbol < 'a' || symbol > 'z')
		{
			if (symbol < 'A' || symbol > 'Z')
			{
				if (isWord)
				{
					if ((i - 1) == startPosWord)
					{
						*(resultSymbols + resultPos) = symbol;
						resultPos++;
						isWord = 0;
						continue;
					}

					isWord = 0;
					*(resultSymbols + resultPos) = *(inputSymbols + i - 1);
					resultPos++;
					*(resultSymbols + resultPos) = symbol;
					resultPos++;
				}
			}
		}
		i++;
	}

	*(resultSymbols + resultPos) = *(inputSymbols + i-1);
	resultPos++;
	*(resultSymbols + resultPos) = '\0';

	std::cout << resultSymbols;

	return 0;
}