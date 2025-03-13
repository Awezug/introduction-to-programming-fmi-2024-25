#include <iostream>

char *intToString(int number, const size_t NUMBER_LENGTH);
size_t stringToInt (char *symbols, const size_t &START_POS, const size_t &END_POS);
int getNumberLength (int number);
size_t myPow (size_t base, int indicator);

int main()
{
	const int SIZE = 100;
	char inputSymbols[SIZE];
	char resultSymbols[SIZE];

	std::cin.getline(inputSymbols, SIZE-1);

	size_t i = 0;
	size_t resultPos = 0;
	bool isNumber = 0;
	size_t digitStartPos = 0;
	int squaredNumber = 0;
	size_t numberLength = 0;

	while (*(inputSymbols + i))
	{
		char symbol = *(inputSymbols + i);

		if (symbol >= '0' && symbol <= '9')
		{
			if (!isNumber)
			{
				digitStartPos = i;
				isNumber = 1;
			}
		}

		if (symbol < '0' || symbol > '9')
		{
			if (isNumber)
			{
				if ((i - 1) == digitStartPos)
				{
					squaredNumber = myPow(*(inputSymbols + digitStartPos) - '0', 2);
					numberLength = getNumberLength(squaredNumber);

					if (numberLength > 1)
					{
						// todo - why wasn't possible to do *&squaredNumber? Check with the mathtricks project.
						char *squaredNumberString = intToString(squaredNumber, numberLength);

						size_t j = 0;

						while (*(squaredNumberString + j))
						{
							*(resultSymbols + resultPos) = *(squaredNumberString + j);

							resultPos++;
							j++;
						}

						delete[] squaredNumberString;
					}
					else
					{
						*(resultSymbols + resultPos) = squaredNumber + '0';
						resultPos++;
					}

					isNumber = 0;
					continue;
				}

				// make this repeating code in the separate function
				size_t convertedInputNumber = stringToInt(inputSymbols, digitStartPos, i);
				squaredNumber = myPow(convertedInputNumber, 2);
				numberLength = getNumberLength(squaredNumber);
				char *squaredNumberString = intToString(squaredNumber, numberLength);
				size_t j = 0;

				while (*(squaredNumberString + j))
				{
					*(resultSymbols + resultPos) = *(squaredNumberString + j);

					resultPos++;
					j++;
				}

				isNumber = 0;
				*(resultSymbols + resultPos) = *(inputSymbols + i);
				resultPos++;
				
				delete[] squaredNumberString;
			}
			else
			{
				*(resultSymbols + resultPos) = *(inputSymbols + i);
				resultPos++;
			}
		}

		i++;
	}

	*(resultSymbols + resultPos) = '\0';

	std::cout << resultSymbols;

	return 0;
}

char *intToString(int number, const size_t NUMBER_LENGTH)
{
	char *result = new char[NUMBER_LENGTH + 1];
	size_t resultPos = NUMBER_LENGTH;

	*(result + resultPos) = '\0';
	resultPos--;

	while (number)
	{
		*(result + resultPos) = (number % 10) + '0';

		number /= 10;
		resultPos--;
	}

	return result;
}

int getNumberLength (int number)
{
	int result = 0;
	
	while (number)
	{
		number /= 10;
		result++;
	}

	return result;
}

size_t stringToInt (char *symbols, const size_t &START_POS, const size_t &END_POS)
{
	size_t result = 0;
	size_t iteration = 0;

	for (int i = END_POS - 1; i >= START_POS; --i)
	{
		result += (*(symbols + i) - '0') * myPow(10, iteration);
		iteration++;
	}

	return result;
}

size_t myPow (size_t base, int indicator)
{
	size_t i = 1;
	size_t result = base;
	bool negative = 0;

	if (!indicator)
	{
		return 1;
	}
	
	if (indicator < 0)
	{
		indicator = -indicator;
		negative = 1;
	}

	while (i < indicator)
	{
		result *= base;

		i++;
	}

	if (negative)
	{
		return (1 / result);
	}

	return result;
}