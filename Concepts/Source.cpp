#include <iostream>
#include <type_traits>
#include <string_view>
#include <cstdarg>

//template <typename Float, typename = std::enable_if_t<std::is_floating_point_v<Float>>>
//
//auto go(const Float value1, const Float value2)
//{
//	return value1 + value2;
//}

//template <typename Float>
//
//auto go(const Float value1, const Float value2) requires std::is_floating_point_v<Float>
//{
//	return value1 + value2;
//}

//template <typename T>
//
//concept floating_point = std::is_floating_point_v<T>;
//
//template <floating_point Float>
//
//auto go(const Float value1, const Float value2)
//{
//	return value1 + value2;
//}

//template <typename T>
//concept floating_point = std::is_floating_point_v<T>;
//
//auto go(const floating_point auto value1, const floating_point auto value2)
//{
//	return value1 + value2;
//}

//int sum(int a, ...)
//{
//	va_list list;
//	va_start(list, a);
//	int sum = 0;
//	for (int i = 0; i < a; i++)
//	{
//		sum += va_arg(list, int);
//	}
//	return sum;
//}

template <typename T>
concept Float = std::is_floating_point_v<T>;
template <Float... Args>
auto sum(Args... args)
{
	return (args + ...);
}

int main()
{
	//std::cout << sum(1, 2, 3, 4, 5) << std::endl;
	//std::cout << sum(2.5, 3, 6) << std::endl;
	std::cout << sum(2.4, 8.2) << std::endl;
}