#include <iostream>
#include <vector>
#include <numeric>
#include <cstdint>
#include <cstdlib>

// http://codereview.stackexchange.com/questions/66711/greatest-common-divisor
int64_t gcd(int64_t a, int64_t b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int64_t lcm(int64_t a, int64_t b)
{
	return llabs(a*b) / gcd(a, b);
}

int main(void)
{
	std::vector<int64_t> v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int64_t multiple = std::accumulate(v.begin(), v.end(), 1, [](int64_t a, int64_t b){ return lcm(a, b); });

	std::cout << "answer: " << multiple << "\n";
	return 0;
}
