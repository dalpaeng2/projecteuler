#include <iostream>
#include <vector>
#include <algorithm>

const int limit = 2000000;

struct c_range {
	int64_t current;
	
	c_range() : current{1LL} {}

	int64_t operator()() 
	{
		return current++;
	}
} RangeGenerator;


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
	std::vector<int> numbers(limit);
	std::generate(numbers.begin(), numbers.end(), RangeGenerator);
	std::vector<int> primes;
	std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(primes), is_prime);

	int64_t sum = std::accumulate(primes.begin(), primes.end(), 0LL);
	std::cout << "answer: " << sum << "\n";

	return 0;
}

