#include <iostream>

int main()
{
	enum days {
		January = 4, February, March, April,
		May, June, July, August, September,
		October, November, December
	};
	days d;
	d = March;
	std::cout << "Hello World!" << std::endl;
	std::cout << d << std::endl;
	std::cin.get();
}