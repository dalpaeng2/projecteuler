#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int sum_of_proper_divisors(const int n)
{
	int s = 0;
	for (auto i = 1; i <= n/2; i++)
	{
		if (n % i == 0)
		{
			s += i;
		}
	}
	return s;
}

int main(void)
{
	auto answer = 0;
	std::set<int> s;
	const int limit = 10000;

	for (auto a = 1; a < limit; a++)
	{
		auto d_a = sum_of_proper_divisors(a);
		if (a == d_a || d_a >= limit)
			continue;

		if (a == sum_of_proper_divisors(d_a))
			s.insert(a);
	}

	answer = std::accumulate(s.begin(), s.end(), 0);
	std::cout << "answer: " << answer << "\n";

	return 0;
}
