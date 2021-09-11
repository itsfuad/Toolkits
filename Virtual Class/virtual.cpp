#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#define log(x) std::cout << x << std::endl

class File
{
protected:
	std::fstream file_name;
	void open(const std::string& f_name)
	{
		file_name.open(f_name);
	}
	virtual std::string read()
	{
		std::string m_Data;
		getline(file_name, m_Data);
		return m_Data;
	}
	virtual std::string read(const std::string& f_name)
	{
		open(f_name);
		std::string m_Data;
		getline(file_name, m_Data);
		return m_Data;
	}
	virtual void write(const std::string& m_Data)
	{
		file_name << m_Data;
	}
	virtual ~File()
	{
		if (file_name.is_open()) file_name.close();
	}
	void close()
	{
		file_name.close();
	}
};

class FileRead : public File
{
public:
	std::string read(const std::string& f_name) override
	{
		open(f_name);
		std::string m_Data;
		getline(file_name, m_Data);
		return m_Data;
	}
};

class FileWrite : public File
{
public:
	void write(const std::string& m_Data) override
	{
		file_name << m_Data;
	}
};

int  main()
{
	FileRead fileread;
	log(fileread.read("file.txt"));
	using namespace std::chrono_literals;
	std::cin.get();
}