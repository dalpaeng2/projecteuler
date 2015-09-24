#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(void)
{
	std::vector<int> v{1};

	for (auto i = 0; i < 1000; i++)
	{
		std::vector<int> temp;
		auto carry = 0;
		for (auto d : v)
		{
			auto m = d*2 + carry;
			carry = m / 10;
			m %= 10;
			temp.push_back(m);
		}
		if (carry != 0) temp.push_back(carry);
		v = temp;
	}
	std::cout << "answer: " << std::accumulate(v.begin(), v.end(), 0) << "\n";
	return 0;
}
