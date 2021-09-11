#include <iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("created!\n");
		m_size = strlen(string);
		m_data = new char[m_size];
		memcpy(m_data, string, m_size);
	}
	String(const String& other)
	{
		printf("copied!\n");
		m_size = other.m_size;
		m_data = new char[m_size];
		memcpy(m_data, other.m_data, m_size);
	}
	String(String&& other)
	{
		printf("moved!\n");
		m_size = other.m_size;
		m_data = other.m_data;

		other.m_size = 0;
		other.m_data = nullptr;
	}

	String& operator=(String&& other) noexcept
	{
		printf("moved!\n");

		if (this != &other)
		{
			delete[] m_data;
			m_size = other.m_size;
			m_data = other.m_data;

			other.m_size = 0;
			other.m_data = nullptr;
		}
		return *this;
	}

	~String()
	{
		printf("Destroyed\n");
		delete[] m_data;
	}
	void print()
	{
		for (uint32_t i = 0; i < m_size; i++)
		{
			printf("%c", m_data[i]);
		}
		printf("\n");
	}
private:
	char* m_data;
	uint32_t m_size;
};

class Entity
{
public:
	Entity(const String& name)
		:m_name(name)
	{
	}
	Entity(String&& name)
		:m_name(std::move(name))
	{
	}
	void printname()
	{
		m_name.print();
	}
private:
	String m_name;
};

int main()
{
	{
		Entity entity(("Fuad"));
		entity.printname();

		String string = "Hello";
		String dest = std::move(string);
	}
	std::cout << "Done!" << std::endl;
	std::cin.get();
}