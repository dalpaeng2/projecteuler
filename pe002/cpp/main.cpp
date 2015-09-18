#include <iostream>

// 4613732
int main(void)
{
	int i = 1;
	int j = 2;
	int sum = 0;
	const int limit = 4000000;

	while (j < limit)
	{
		if (j % 2 == 0)
		{
			sum += j;
		}
		int tmp = i;
		i = j;
		j += tmp;
	}
	std::cout << "answer: " << sum << std::endl;
	return 0;
}
