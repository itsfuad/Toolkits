#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <filesystem>

using namespace System::Collections::Generic;

#define println(x) std::cout << x << std::endl
#define print(x) std::cout << x

namespace fs = std::filesystem;

void unlock()
{
	std::string pwd;
	print("Enter password to Unlock Your Secure Folder: ");
	std::getline(std::cin, pwd);
	if (pwd == "laam") //Set your password
	{
		system("attrib -h -s \"Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}\"");
		fs::rename("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}", "Private");
		println("Folder Unlocked");
	}
	else
	{
		println("Incorrect password");
	}
}

void run()
{
	if (fs::exists("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"))
	{
		unlock();
	}
	else if (!fs::exists("Private") && !fs::exists("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"))
	{
		fs::create_directories("Private");
		println("Private folder created sucessfully");
	}
	else if (fs::exists("Private"))
	{
		println("Are you sure to lock this folder? (Y/N)");
		char ch;
		std::cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			println("Locked");
			fs::rename("Private", "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}");
			system("attrib +h +s \"Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}\"");
		}
	}
	else {
		unlock();
	}
}

int main()
{
	run();
	//System::Console::WriteLine("Hello .NET");
	std::cin.get();
}