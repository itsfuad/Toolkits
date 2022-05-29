#include <iostream>
#include <type_traits>

//template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
//auto sum(T a, T b)
//{
//	return a + b;
//}

//template <typename T>
//auto sum(T a, T b) requires std::is_floating_point_v<T>
//{
//	return a + b;
//}

//template <typename TemplateType>
//concept Float = std::is_floating_point_v<TemplateType>;
//template <Float T>
//auto sum(T a, T b)
//{
//	return a + b;
//}

template <typename TemplateType>
concept Float = std::is_floating_point_v<TemplateType>;
auto sum(Float auto a, Float auto b)
{
	return a + b;
}

int main()
{
	std::cout << sum(2.8f, 6.1) << std::endl;
}