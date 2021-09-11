#include <iostream>
#include <cstdarg>
#include <iomanip>

#define log(x) std::cout << x << std::endl;

int printsum(int a, ...) // c style
{
	va_list list;
	va_start(list, a);
	auto sum = 0;
	for (auto i = 0; i < a; i++)
	{
		sum += (va_arg(list, int));
	}
	return sum;
}

template <typename... Args>
int printsum2(Args... args)
{
	return (args + ...);
}

void print(const char* format)
{
	std::cout << format;
}

template <typename T, typename... Args>
void print(const char* format, T value, Args... args)
{
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			std::cout << value;
			print(format + 1, args...);
			break;
		}
		else {
			std::cout << *format;
		}
	}
}

int main()
{
	std::string s = "HelloWorld";
	log(printsum(3, 1, 2, 3));
	log(printsum2(1, 2, 3));
	print("Hello %, Fuad. Your id is: %\n", "world", 56564);
}