#include <thread>
#include <mutex>
#include <atomic>
#include <iostream>

using namespace std::chrono_literals;

volatile bool t = true; //tells the compiler not to change the variable

std::atomic<int> s;

void runner()
{
	while (t)
	{
		std::cout << "Running...\n";
	}
}

void disable()
{
	std::cin.get();
	t = false;
}

int main()
{
	std::thread t1(runner);
	std::thread t2(disable);
	t1.join();
	t2.join();
	std::cin.get();
}