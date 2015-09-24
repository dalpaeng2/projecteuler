#include <iostream>
#include <map>
#include <cstdint>

int64_t collatz_length(const int64_t number, std::map<int64_t, int64_t>& collatz_sequence)
{
	if (number == 1)
	{
		return 1;
	}

	if (collatz_sequence.find(number) == collatz_sequence.end())
	{
		collatz_sequence[number] = collatz_length((number%2 == 0) ? number/2 : number*3+1, collatz_sequence) + 1;
	}

	return collatz_sequence[number];
}

int main(void)
{
	std::map<int64_t, int64_t> collatz_sequence;
	auto max_length = 0LL;
	auto max_i = 0LL;

	for (auto i = 1; i < 1000000; i++)
	{
		auto length = collatz_length(i, collatz_sequence);
		if (length > max_length)
		{
			max_length = length;
			max_i = i;
		}
	}

	std::cout << "answer: " << max_i << "\n";

	return 0;
}
