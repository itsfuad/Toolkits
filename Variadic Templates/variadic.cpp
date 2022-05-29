#include <iostream>
#include <cstdarg>
#include <iomanip>
#include <type_traits>
#include <stdio.h>
#include <string.h>

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


//void print(const char* format)
//{
//	std::cout << format;
//}
//
//template <typename T, typename... Args>
//void print(const char* format, T value, Args... args)
//{
//	for (; *format != '\0'; format++)
//	{
//		if (*format == '%')
//		{
//			std::cout << value;
//			print(format + 1, args...);
//			break;
//		}
//		else {
//			std::cout << *format;
//		}
//	}
//}

template <typename T, typename... Args>
void print(const char* format, T value, Args... args)
{
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			std::cout << value;
			(print(format + 1, args),...);
			break;
		}
		else {
			std::cout << *format;
		}
	}
}





void printfu(const char* format, ... ) 
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			//std::cout << *(format+1) << std::endl;
			va_list list;
			va_start(list, format);
			switch (*(++format))
			{
			case 'd':
				std::cout << va_arg(list, int);
				break;
			case 'c':
				putchar(va_arg(list,char));
				break;
			}
			*format++;
		}
		putchar(*format);
		format++;
	}
}

int main()
{
	//std::cout << "Hello World!" << std::endl;
	//printfu("Hello %d\n", 4);
	print("Hello %", "Fuad");
}