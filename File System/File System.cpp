#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

class Encode {
protected:
	static void _encode(std::string& data) {
		std::string temp = data;
		for (size_t i = 0; i < temp.size(); i++) {
			data[i] = (temp[i] + 23);
		}
	}
};

class Decode {
protected:
	static void _decode(std::string& data) {
		std::string temp = data;
		for (size_t i = 0; i < temp.size(); i++) {
			data[i] = (temp[i] - 23);
		}
	}
};

class Hash : public Encode, public Decode {
public:
	static void encode(std::string& data) {
		_encode(data);
	}
	static void decode(std::string& data) {
		_decode(data);
	}
};

struct File {
	File(std::string name) {
		file_name = name;
		file.open(name, std::ios::in | std::ios::out | std::ios::binary);
		getline(file, file_data);
	}
	~File() {
		file.close();
	}
private:
	std::string file_data;
	std::fstream file;
	std::string file_name;
	friend class File_System;
};
class File_System {
private:
	std::fstream FILE_SYSTEM_STORAGE;
	std::string FILE_SYSTEM_NAME;
public:
	File_System(const std::string& name) {
		FILE_SYSTEM_NAME = name;
	}
	void File_Write(File& file) {
		std::stringstream ss;
		FILE_SYSTEM_STORAGE.open(FILE_SYSTEM_NAME, std::ios::out);
		ss << "[" << file.file_name << "]" << file.file_data << "${eof}" << std::endl;
		std::string encrypted_data = ss.str();
		Hash::encode(encrypted_data);
		FILE_SYSTEM_STORAGE << encrypted_data;
		std::cout << "Data Written: " << ss.str() << "\nEncripted data: " << encrypted_data << std::endl;
		FILE_SYSTEM_STORAGE.close();
	}
	std::stringstream File_Read() {
		FILE_SYSTEM_STORAGE.open(FILE_SYSTEM_NAME, std::ios::in);
		std::stringstream ss;
		ss << FILE_SYSTEM_STORAGE.rdbuf();
		FILE_SYSTEM_STORAGE.close();
		return ss;
	}
};

int main()
{
	File F("data.txt");
	File_System file("filesystem.txt");
	file.File_Write(F);
	std::cin.get();
	std::smatch match;

	std::string s = file.File_Read().str();
	Hash::decode(s);
	//std::cout << "found : " << s << std::endl;
	if (std::regex_search(s, match, std::regex(R"(\[data\.txt\])"))) {
		s = match.suffix();
		//std::cout << "found 1: " << s << std::endl;
		if (std::regex_search(s, match, std::regex(R"(\$\{eof\})"))) {
			s = match.prefix();
			//std::cout << "found 2: " << s << std::endl;
		}
	}
	else {
		//std::cout << "Nothing found" << std::endl;
	}
	std::fstream nFile;
	nFile.open("newfile.txt", std::ios::out, std::ios::trunc);
	nFile << s;
	std::cout << "found : " << s << std::endl;
	std::cout << "Data Written!" << std::endl;
	nFile.close();
	std::cin.get();
}