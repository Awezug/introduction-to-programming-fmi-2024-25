#include <iostream>

bool isInNumber(size_t number, size_t digit);

int main()
{
	size_t promptNumber = 0;
	size_t promptDigit = 0;

	std::cout << "Please enter the number: ";
	std::cin >> promptNumber;

	std::cout << "Please enter the digit: ";
	std::cin >> promptDigit;

	bool result = isInNumber(promptNumber, promptDigit);

	result ? std::cout << "True" : std::cout << "False";

	return 0;
}


bool isInNumber(size_t number, size_t digit)
{
	const size_t LAST_DIGIT_DELIMETER = 10;
	bool result = 0;

	if (number % LAST_DIGIT_DELIMETER == digit)
	{
		return 1;
	}
	else
	{
		if (number / LAST_DIGIT_DELIMETER)
		{
			result = isInNumber(number / LAST_DIGIT_DELIMETER, digit);
		}
	}

	 return result;
}