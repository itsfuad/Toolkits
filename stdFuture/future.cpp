#include <iostream>

#define log(x) std::cout << x ;
#define MAX 50000

int multiply(int x, int res[], int res_size);
uint64_t factorial2(int a)
{
	uint64_t factorial = 1;
	while (a)
	{
		factorial *= a--;
	}
	return factorial;
}

void factorial(int n)
{
	int res[MAX];
	res[0] = 1;
	int res_size = 1;

	for (int x = 2; x <= n; x++)
	{
		res_size = multiply(x, res, res_size);
	}
	for (int i = res_size - 1; i >= 0; i--)
	{
		log(res[i]);
	}
}

int multiply(int x, int res[], int res_size)
{
	int carry = 0;
	for (int i = 0; i < res_size; i++)
	{
		int prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry)
	{
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

int main()
{
	int a = 0;
	std::cout << "Enter number for factorial: ";
	std::cin >> a;
	//std::cout << "Normal Factorial: " << factorial2(a) << std::endl;
	std::cout << "Extended Factorial: ";
	factorial(a);
	std::cout << std::endl;
	main();
}