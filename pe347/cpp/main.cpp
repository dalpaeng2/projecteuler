#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

bool is_prime(int number)
{
	if (number == 1)
		return false;
	if (number == 2)
		return true;

	int sqrt_number = ceil(sqrt(number));
	for (int i = 2; i <= sqrt_number; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int M(int p, int q, int N)
{
	int64_t m = 0;
	auto a = 1;
	while (pow(p, a) * q <= N)
	{
		auto b = 1;
		while (pow(p, a) * pow(q, b) <= N)
		{
			int64_t t = pow(p, a) * pow(q, b);
			if (t > m)
				m = t;
			b++;
		}
		a++;
	}
	return m;
}

int main(void)
{
	std::vector<int> primes;
	const int limit = 10000000;
	int64_t s = 0LL;

	for (auto i = 2; i <= limit; i++)
	{
		if (is_prime(i))
			primes.push_back(i);
	}

	for (auto i = 0; i < primes.size() - 1; i++)
	{
		if (pow(primes[i], 2) > limit)
			break;

		for (auto j = i+1; j < primes.size(); j++)
		{
			if (primes[i] * primes[j] > limit)
				break;

			auto m = M(primes[i], primes[j], limit);
			s += m;
		}
	}

	std::cout << "answer: " << s << "\n";

	return 0;
}
