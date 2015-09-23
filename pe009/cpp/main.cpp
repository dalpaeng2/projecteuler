#include <iostream>

int main(void)
{
	for (auto a = 1; a < 1000; a++)
	{
		for (auto b = a+1; b < 1000; b++)
		{
			for (auto c = b+1; c < 1000; c++)
			{
				if (a*a + b*b == c*c && a + b + c == 1000)
				{
					std::cout << "answer: " << a*b*c << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
