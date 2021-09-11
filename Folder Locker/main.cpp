#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void unlock()
{
	std::string pwd;
	std::cout << "Enter password to Unlock Your Secure Folder: ";
	std::getline(std::cin, pwd);
	if (pwd == "laam") //Set your password
	{
		system("attrib -h -s \"Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}\"");
		fs::rename("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}", "Private");
		std::cout << "Folder Unlocked!" << std::endl;
	}
}

int main()
{
	if (fs::exists("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"))
	{
		unlock();
	}
	if (!fs::exists("Private") && !fs::exists("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"))
	{
		fs::create_directories("Private");
		std::cout << "Private Folder Created Successfully" << std::endl;
	}
	else if (fs::exists("Private"))
	{
		std::cout << "Are you sure to lock this folder? (Y/N)" << std::endl;
		char ch;
		std::cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			std::cout << "Locked" << std::endl;
			fs::rename("Private", "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}");
			system("attrib +h +s \"Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}\"");
		}
	}
	else {
		unlock();
	}
	std::cin.get();
}