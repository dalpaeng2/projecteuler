#include <iostream>
#include <algorithm>
#include <string>

bool is_palindrome(const int number)
{
	std::string s = std::to_string(number);
	std::string rs = s;
	std::reverse(rs.begin(), rs.end());
	return s.compare(rs) == 0;
}

int main(void)
{
	int max = 0;
	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100; j < 1000; j++)
		{
			int number = i * j;
			if (is_palindrome(number) && number > max)
			{
				max = number;
			}
		}
	}
	std::cout << "answer: " << max << "\n";
	return 0;
}
