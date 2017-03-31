#include<iostream>
int main() {
	int a;
	while (std::cin >> a)
	{
		int i = 1, sum = 0;
		while (i <= a)
		{
			sum += i;
			++i;
		}
		std::cout << sum << std::endl << std::endl;
	}
}