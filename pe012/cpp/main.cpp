#include <iostream>
#include <cmath>

int number_of_factors(const int number)
{
	int cnt = 0;
	double sqrt_n = floor(sqrt(number));
	for (auto i = 1; i < sqrt_n; i++)
	{
		if (number % i == 0)
			cnt += 2;
	}

	if (sqrt_n * sqrt_n == number)
		cnt++;
	return cnt;
}

int main(void)
{
	int triangular_number = 0;
	int counter = 0;
	do {
		triangular_number += (counter++);
	} while(number_of_factors(triangular_number) < 500);

	std::cout << "answer: " << triangular_number << "\n";
	return 0;
}
