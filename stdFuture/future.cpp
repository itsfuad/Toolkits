#include <iostream>
#include <thread>
#include <future>

#define log(x) std::cout << x << std::endl

using namespace std::chrono_literals;

void factorial(const int& value)
{
	int temp = value, res = 1;
	while (temp > 0)
	{
		res *= temp--;
	}
	log(res);
}

void set(int& value)
{
	std::this_thread::sleep_for(5s);
	value = 5;
}

int main()
{
	int value = 3;
	std::thread t1(set, std::ref(value));
	t1.join();
	std::thread t2(factorial, std::ref(value));
	t2.join();

	std::promise<int> p;
	std::future<int> fu = p.get_future();
}