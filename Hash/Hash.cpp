#include <iostream>

class Encode {
protected:
	static std::string _encode(std::string data)
	{
		std::string temp = data;
		for (size_t i = 0; i < temp.size(); i++)
		{
			data[i] = (temp[i] + 1);
		}
		return data;
	}
};

class Decode {
protected:
	static std::string _decode(std::string data)
	{
		std::string temp = data;
		for (size_t i = 0; i < temp.size(); i++)
		{
			data[i] = (temp[i] - 1);
		}
		return data;
	}
};

class Hash : public Encode, public Decode {
public:
	static std::string encode(std::string data)
	{
		return _encode(data);
	}
	static std::string decode(std::string data)
	{
		return _decode(data);
	}
};

int main()
{
	std::string name = "Fuad Hasan";

	std::cout << "Normal Text: ";
	std::cout << name << std::endl;

	name = Hash::encode(name);

	std::cout << "Encoded Text: ";
	std::cout << name << std::endl;

	name = Hash::decode(name);

	std::cout << "Decoded Text: ";
	std::cout << name << std::endl;
}