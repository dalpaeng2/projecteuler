#ifndef PRIME_FACTORIZATION_HPP
#define PRIME_FACTORIZATION_HPP

#include <vector>

template <typename T>
std::vector<T> prime_factorization(const T number)
{
	std::vector<T> prime_factors;

	for (T i = 2; i <= number/2; i++)
	{
		if (number % i == 0)
		{
			prime_factors.push_back(i);
		}
	}

	return prime_factors;
}

#endif // PRIME_FACTORIZATION_HPP
