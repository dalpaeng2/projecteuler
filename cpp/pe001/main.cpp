#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
	auto limit = 1000;
	std::vector<int> numbers(limit);

	{
		int n(0);
		std::generate(numbers.begin(), numbers.end(), [&n](){ return n++; });
	}
			
	auto total = 0;
	for (auto number : numbers)
	{
		if (number % 3 == 0 || number % 5 == 0)
		{
			total += number;
		}
	}

	std::cout << "answer: " << total << std::endl;
	return 0;
}
