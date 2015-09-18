#include <iostream>

int main(void)
{
	long number = 600851475143;
	for (long i = 2; i < number; i++) 
	{
		if (number % i == 0) number /= i;
	}
	std::cout << "answer: " << number << std::endl;
	return 0;
}
