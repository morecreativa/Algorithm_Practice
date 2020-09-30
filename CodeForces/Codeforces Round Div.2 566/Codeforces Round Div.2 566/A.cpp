// Filling shapte

#include <iostream>
#include <vector>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	if (n % 2 == 1)
	{
		std::cout << 0;
		return 0;
	}
	else
	{
		int num_case = 1;
		for (int i = 0; i < n; i++)	num_case *= 2;
		std::cout << num_case;
		return 0;
	}
}