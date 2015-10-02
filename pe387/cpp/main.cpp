#include <iostream>
#include <cstdint>
#include <list>
#include <cmath>

const int64_t limit = 100000000000000LL;

int digit_sum(int64_t number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

bool is_prime(const int64_t n)
{
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;

	int i = 5;
	while (i <= sqrt(n))
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
		i += 6;
	}

	return true;
}

int main(void)
{
	std::list<int64_t> harshad_numbers{1,2,3,4,5,6,7,8,9};
	int64_t answer = 0;

	while (!harshad_numbers.empty())
	{
		int64_t harshad_number = harshad_numbers.front();
		harshad_numbers.pop_front();
		int64_t harshad_prime = harshad_number*10 + 10;
		if (harshad_prime > limit)
			continue;

		auto ds = digit_sum(harshad_number);
		if (harshad_number % ds == 0)
		{
			for (auto i = 0; i < 10; i++)
			{
				harshad_numbers.push_back(harshad_number*10 + i);
			}

			if (is_prime(harshad_number/ds))
			{
				for (auto i = 1; i < 10; i++)
				{
					if (is_prime(harshad_number*10+i))
					{
						answer += (harshad_number*10+i);
					}
				}
			}
		}
	}

	std::cout << "answer: " << answer << "\n";
	return 0;
}

