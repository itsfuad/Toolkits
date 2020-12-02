#include <iostream>
#include <cstdarg>

int printsum(int a, ...) // c style
{
	va_list list;
	va_start(list, a);
	auto sum = 0;
	for (auto i = 0; i < a; i++)
	{
		sum += static_cast<int>(va_arg(list, int));
	}
	return sum;
}

template<typename... Args>
int printsum2(Args... args)
{
	return (args + ...);
}

int main()
{
	int a;
	std::cout << printsum(3, 1, 2, 3) << std::endl;
	std::cout << printsum2(1, 2, 3) << std::endl;
}