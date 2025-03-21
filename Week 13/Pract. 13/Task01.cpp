#include <iostream>

int sum(int number);

int main()
{
	int promptNumber = 0;

	std::cout << "Please enter the number: ";
	std::cin >> promptNumber;

	int result = sum(promptNumber);

	std::cout << result << std::endl;

	return 0;
}

int sum(int number)
{
	if (!number || number <= 0)
	{		
		return 0;
	}

	return number + sum(number - 1);
}