#include <iostream>

const int SIZE = 60;
const int LENGTH = 3;

void buildResult(char *result, char counts[][LENGTH]);
int countSymbols(char *array, char symbol, size_t position);
bool isInArray(char array[][LENGTH], char symbol);
void clearDoubleArray(char arr[][LENGTH]);
void clearArray(char *&array);
char *countChars(char *inputString);
size_t findNumberLength (size_t number);
char *intToString(size_t number, const size_t LENGTH);

int main()
{

	char string[SIZE];

	std::cout << "Please enter the string: ";
	std::cin.getline(string, SIZE);

	char *result = countChars(string);

	std::cout << result;

	clearArray(result);

	return 0;
}

char *countChars(char *inputString)
{
	if (inputString == nullptr)
	{
		return nullptr;
	}

	char *result = new char[SIZE];
	char charCounts[SIZE][LENGTH];
	size_t i = 0;
	size_t j = 0;
	const char SPACE = ' ';
	int symbolCount = 0;
	char symbol = ' ';
	bool isSymbolInArray = 0;

	while	(*(inputString + i))
	{
		symbol = *(inputString + i);

		if (symbol == SPACE)
		{
			i++;
			continue;
		}

		isSymbolInArray = isInArray(charCounts, symbol);

		if (!isSymbolInArray)
		{
			*(*(charCounts + j)) = symbol;
			symbolCount = countSymbols(inputString, symbol, i);
			*(*(charCounts + j) + 1) = (char)symbolCount;
			*(*(charCounts + j) + 2) = '\0';
			j++;
		}
		else
		{
			i++;
			continue;
		}

		i++;
	}
	*(*(charCounts + j)) = '\0';

	buildResult(result, charCounts);

	return result;
}

void clearArray(char *&array)
{
	delete[] array;
}

bool isInArray(char array[][LENGTH], char symbol)
{
	size_t i = 0;

	while	( *(*(array + i)) )
		{
			if ( symbol == *(*(array + i)) )
			{
				return 1;
			}
			i++;
		}

		return 0;
}

int countSymbols(char *array, char symbol, size_t position)
{
	int result = 0;

	while (*(array + position))
	{
		if(*(array + position) == symbol)
		{
			result++;
		}

		position++;
	}

	return result;
}

void buildResult(char *result, char counts[][LENGTH])
{
	size_t i = 0;
	size_t resultPos = 0;
	size_t currentNumber = 0;
	size_t currentNumberLength = 0;
	char *numberString = nullptr;

	while( *(*(counts + i)) )
	{
		size_t j = 1;
		*(result + resultPos) = *(*(counts + i));
		resultPos++;
		*(result + resultPos) = ':';
		resultPos++;
		*(result + resultPos) = ' ';
		resultPos++;

		while( *(*(counts + i) + j) )
		{
			//TODO write function to take the symbol from second position of counts, convert to int, find size, and return back.
			currentNumber = *(*(counts + i) + j);
			currentNumberLength = findNumberLength(currentNumber);

			if (currentNumberLength > 1)
			{
				//we do the conversion int to string, put the string to the result, continue.
				numberString = intToString(currentNumber, currentNumberLength);

				size_t k = 0;

				while(*(numberString + k))
				{
					*(result + resultPos) = *(numberString + k);
					resultPos++;
					k++;
				}

				delete[] numberString;
				j++;
				continue;
			}

			*(result + resultPos) = *(*(counts + i) + j) + '0';
			resultPos++;
			j++;
		}

		*(result + resultPos) = ',';
		resultPos++;
		*(result + resultPos) = ' ';
		resultPos++;		
		i++;
	}

	resultPos -= 2;
	*(result + resultPos) = '\0';
}

size_t findNumberLength (size_t number)
{
	size_t result = 0;
	while (number)
	{
		number /= 10;
		result++;
	}

	return result;
}

char *intToString(size_t number, const size_t LENGTH)
{
	char *result = new char[LENGTH + 1];

	*(result + LENGTH) = '\0';
	size_t i = LENGTH - 1;

	while	(number)
	{
		*(result + i) = (number % 10) + '0';
		number /= 10;
		i--;
	}

	return result;
}