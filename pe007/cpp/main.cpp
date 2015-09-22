#include <iostream>

bool is_prime(const int n)
{
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;

	int i = 5;
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
		i += 6;
	}

	return true;
}

int main(void)
{
	const int index = 10001;
	int number = 0;
	int i = 0;

	do 
	{
		if (is_prime(++number))
		{
			i++;
		}
	} while (i < index);

	std::cout << "answer: " << number << "\n";
	return 0;
}
