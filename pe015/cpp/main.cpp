#include <iostream>
#include <vector>
#include <algorithm>

// binomial coefficient

std::vector<int> factors(int first, int last)
{
	std::vector<int> f;
	for (auto n = first; n <= last; n++)
	{
		auto _n = n;
		auto i = 2;
		while (_n > 1)
		{
			if (_n % i == 0)
			{
				_n /= i;
				f.push_back(i);
			}
			else
			{
				i++;
			}
		}
	}

	std::sort(f.begin(), f.end());
	return f;
}

int64_t combinations(const int n, const int k)
{
	std::vector<int> n_factors = factors(n-k+1, n);
	std::vector<int> k_factors = factors(1, k);
	std::vector<int> diff;

	// n_factors, k_factors should be sorted.
	std::set_difference(n_factors.begin(), n_factors.end(),
			k_factors.begin(), k_factors.end(),
			std::inserter(diff, diff.begin()));
	return std::accumulate(diff.begin(), diff.end(), 1LL, [](int64_t mul, int a){ return mul * a; });
}

int main(void)
{
	auto answer = combinations(40, 20);
	std::cout << "answer: " << answer << "\n";
	return 0;
}
