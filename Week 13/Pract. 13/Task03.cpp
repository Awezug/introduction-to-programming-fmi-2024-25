#include <iostream>

size_t digitsSum(size_t number);

int main()
{
	size_t promptNumber = 0;

	std::cout << "Please enter the number: ";
	std::cin >> promptNumber;

	size_t result = digitsSum(promptNumber);

	std::cout	<< result;

	return 0;
}

size_t digitsSum(size_t number)
{
	const size_t LAST_DIGIT_DELIMETER = 10;

	if (!number)
	{
		return 0;
	}

	return number % LAST_DIGIT_DELIMETER + digitsSum(number / LAST_DIGIT_DELIMETER);
}