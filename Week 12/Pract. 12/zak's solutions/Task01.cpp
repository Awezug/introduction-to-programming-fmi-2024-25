#include <iostream>

int main()
{
	const int SIZE = 100;
	char inputSymbols[SIZE];

	std::cin.getline(inputSymbols, SIZE - 1);

	size_t i = 0;
	size_t startWordIndex = 0;
	size_t endWordIndex = 0;
	size_t largestStartWordIndex = 0;
	size_t largestEndWordIndex = 0;
	bool isWord = 0;

	while (*(inputSymbols + i))
	{
		size_t largestValue = 0;
		size_t wordValue = 0;
		char symbol = *(inputSymbols + i);

		if (symbol >= 'a' && symbol <= 'z')
		{
			if (!isWord)
			{
				isWord = 1;
				startWordIndex = i;
				wordValue += asciiValue(symbol);
			}
			else
			{
				wordValue += asciiValue(symbol);
			}
		}
		if (symbol >= 'A' && symbol <= 'Z')
		{
			if (!isWord)
			{
				isWord = 1;
				startWordIndex = i;
				wordValue += asciiValue(symbol);
			}
			else
			{
				std::cout << asciiValue(symbol);
				wordValue += asciiValue(symbol);
			}
		}

		if (symbol < 'a' || symbol > 'z')
		{
			if (symbol < 'A' || symbol > 'Z')
			{
				if (isWord)
				{
					isWord = 0;
					endWordIndex = i;

					if (largestValue < endWordIndex - startWordIndex)
					{
						largestValue = endWordIndex - startWordIndex;
						largestStartWordIndex = startWordIndex;
						largestEndWordIndex = endWordIndex;
					}
					wordValue = 0;
				}
			}
		}
		i++;
	}

	for (size_t i = largestStartWordIndex; i < largestEndWordIndex; i++)
	{
		std::cout << *(inputSymbols + i);
	}

	return 0;
}

size_t asciiValue(char symbol)
{
	return (size_t)symbol;
}