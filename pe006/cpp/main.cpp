#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::vector<int> v;
	for (int i = 1; i <= 100; i++) v.push_back(i);	

	int square_of_sum = std::accumulate(v.begin(), v.end(), 0);
	square_of_sum *= square_of_sum;
	int sum_of_square = std::accumulate(v.begin(), v.end(), 0, [](int a, int b){ return a + b*b; });

	int diff = square_of_sum - sum_of_square;
	std::cout << "answer: " << diff << "\n";

	return 0;
}
