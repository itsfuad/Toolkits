#include <iostream>
#include <cmath>
#include <typeinfo>

#ifdef MAIN
#define main int main()\
{\
	double a = 12nm;\
	std::cout << a << std::endl;\
}
#endif

constexpr double operator""nm(long double a) noexcept
{
	return a * 0.001;
}
constexpr double operator""nm(unsigned long long a) noexcept
{
	return a * 0.001;
}

constexpr double operator""s(unsigned long long a) noexcept
{
	return a * 60;
}
constexpr double operator""m(unsigned long long a) noexcept
{
	return a * 60;
}
constexpr double operator""h(unsigned long long a) noexcept
{
	return a / 60;
}

int operator""bin(const char* bin, size_t size)
{
	int sum = 0;
	for (int i = size - 1, j = 0; i >= 0; i--, j++)
	{
		if (bin[i] == '1') {
			sum += pow(2, j);
		}
	}
	return sum;
}
int operator""bin(unsigned long long bin)
{
	int sum = 0;
	int exp = 0;
	while (bin != 0)
	{
		if (bin % 10 == 1)
		{
			sum += pow(2, exp);
		}
		exp++;
		bin /= 10;
	}
	return sum;
}

template <typename T>
void print(T a) //this function prints something to the console
{
	std::cout << a << " : is ";
	if (std::string(typeid(a).name()) == std::string("int"))
	{
		std::cout << "an " << typeid(a).name() << std::endl;
	}
	else
	{
		std::cout << "a " << typeid(a).name() << std::endl;
	}
}

int main()
{
	/*
	int a = 101111bin;
	std::cout << a << std::endl;
	*/
	print(8);
	print(4.9);
	print("Hello World!");
}