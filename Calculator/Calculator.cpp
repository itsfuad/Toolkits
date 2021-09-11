/** \Author Fuad Hasan
 * \RealeseDate 6/23/2018
 * \LastModified 3/22/2020
 */
 /*There is class, Methods,Many data structures so on
 it was developed by Fuad Hasan with C++
 Keep coding, keep learning
 Go for the future
 */

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <mmsystem.h>
#include <string>

#define default_sound 23
#define error_sound 17
#define time __TIME__
#define date __DATE__
int i, m, Age;
std::string mail;
char g, o, s, Color;
double temp;

void reset(), conversion(), home(), menu(), math(), trigonomitry(), loga(), pwr(), prcn(), fact(), root(), error(), color(), pass(), cngpass(), setting(), reqpass(), Pack(), license(), erc();
int facthlp(), main();

void game() {
	std::fstream game;
	game.open("Game.exe");
	if (!game.is_open()) {
		std::cout << "Game is not installed. Install and try again!" << std::endl;
		game.close();
	}

	else {
		game.close();
		system("Game.exe");
		std::cin.get();
		home();
	}
	std::cin.get();
	home();
}

void reset()
{
	system("cls");
	system("title Reset All Data");
	std::cout << "\n\nRemember Your Password Protection And other data will be reset\n\nAre you sure?\n1.Yes\n2.No" << std::endl;
	g = _getch();
	if (g == '1') {
		std::fstream clfile;
		clfile.open("Files\\SystemRun.laam", std::ios::in | std::ios::out | std::ios::trunc);
		Color = '7';
		clfile << Color;
		clfile.close();
		system("color f0");
		std::fstream mainfile;
		mainfile.open("Files\\PssT.laam", std::ios::in | std::ios::out | std::ios::trunc);
		mainfile << "hex00ff98 b2zxCApI bz3";
		mainfile.close();
		std::fstream passfile;
		passfile.open("Files\\FactorySet.laam", std::ios::in | std::ios::out | std::ios::trunc);
		passfile.close();
		home();
	}

	else if (g == '2') {
		home();
	}
	else {
		error();
	}
}

class Decode {
public:
	std::string str;
	Decode()
	{
		std::fstream file2;
		file2.open("Files\\FactorySet.laam");
		file2 >> str;
		file2.close();
		for (i = 0; (i < 100 && str[i] != '\0'); i++) {
			str[i] = str[i] - 22;
		}
		//the key for encryption is 22 that is subtracted to ASCII value
	}
};

class bin
{
public:
	bin();
};

class Data
{
public:
	std::string userName;
	std::string password, password1, dt, input, input2;
	std::string License;
	std::string version;
	std::string check;
	Data();
};

Data::Data() :userName("Still not registered")
{
	std::fstream fileLi("Files\\Microsoft.NET.laam");
	fileLi >> this->License;
	fileLi.close();
	std::fstream fileVer("Files\\Json.laam");
	fileVer >> this->version;
	fileVer.close();
	std::fstream filecheck("Files\\IGFx.laam");
	filecheck >> check;
	if (check.length() > 0)
	{
		check = "Activated";
	}
	else
		check = "Not Activated";
}

class Output_data
{
public:
	double num, num1, ans;
};

void conversion()
{
	system("cls");
	char g;
	std::cout << "\n\n\n\n1.Binary to Decimal\n2.Decimal to Binary\n3.Octal to Decimal\n4.Decimal to Octal\n5.Hexadecimal to Decimal\n6.Decimal to Hexadecimal";
	g = _getch();
	if (g == '1')
	{
		system("cls");
	lebel:
		int i = 0;
		int a[1000];
		int j = 0;
		int n;
		int r = 0;
		std::cout << "\nEnter binary number: ";
		std::cin >> n;
		while (n > 0)
		{
			a[i] = n % 10;
			n = n / 10;
			a[i + 1] = n;
			i += 1;
		}
		short x = i - 1;
		while (x != -1)
		{
			if (a[x] != 1 && a[x] != 0)
			{
				std::cout << "\n\nError While Scanning!\nBinary numbers should be in 0 and 1 \n";
				goto lebel;
			}
			x--;
		}
		for (j = 0; j <= i - 1; j++)
		{
			r += a[j] * (pow(2, j));
		}
		std::cout << "Decimal is: " << r;
		std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
		g = _getch();
		switch (g)
		{
		case'1':conversion(); break;
		case'2':menu(); break;
		case'3':home(); break;
		default:error();
		}
	}
	else if (g == '2')
	{
		bin obj;
		std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
		g = _getch();
		switch (g)
		{
		case'1':conversion(); break;
		case'2':menu(); break;
		case'3':home(); break;
		default:error();
		}
	}

	if (g == '3')
	{
		system("cls");
	lebel2:
		int i = 0;
		int a[1000];
		int j = 0;
		int n;
		int r = 0;
		std::cout << "\nEnter Octal number: ";
		std::cin >> n;
		while (n > 0)
		{
			a[i] = n % 10;
			n = n / 10;
			a[i + 1] = n;
			i += 1;
		}
		short x = i - 1;
		while (x != -1)
		{
			if (a[x] > 7)
			{
				std::cout << "\n\nError While Scanning!\nOctal numbers should be in range of 0-7 \n";
				goto lebel2;
			}
			x--;
		}
		for (j = 0; j <= i - 1; j++)
		{
			r += a[j] * (pow(8, j));
		}
		std::cout << "Decimal is: " << r;
		std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
		g = _getch();
		switch (g)
		{
		case'1':conversion(); break;
		case'2':menu(); break;
		case'3':home(); break;
		default:error();
		}
	}
	else if (g == '4')
	{
		long no, r[1000];
		short i = 0, j = 0;
		system("cls");
		std::cout << "\nEnter decimal number: ";
		std::cin >> no;
		if (no >= 999999999)
		{
			std::cout << "\n\t\tToo large!";
		}
		else
		{
			while (no > 0)
			{
				r[i] = no % 8;
				no = no / 8;
				i++;
			}
			std::cout << "\nOctal is: ";

			for (j = i - 1; j >= 0; j--)
			{
				std::cout << r[j];
			}
		}
		std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
		g = _getch();
		switch (g)
		{
		case'1':conversion(); break;
		case'2':menu(); break;
		case'3':home(); break;
		default:error();
		}
	}

	if (g == '5')
	{
		system("cls");
	lebel22:
		std::string s;
		int hx[100], r = 0;
		short i = 0, p = 0;

		std::cout << "Enter Hexadecimal number: ";
		std::cin >> s;
		p = s.length();

		while (i != s.length())
		{
			switch (s[i])
			{
			case '0':hx[i] = 0; break;
			case '1':hx[i] = 1; break;
			case '2':hx[i] = 2; break;
			case '3':hx[i] = 3; break;
			case '4':hx[i] = 4; break;
			case '5':hx[i] = 5; break;
			case '6':hx[i] = 6; break;
			case '7':hx[i] = 7; break;
			case '8':hx[i] = 8; break;
			case '9':hx[i] = 9; break;
			case 'a':hx[i] = 10; break;
			case 'b':hx[i] = 11; break;
			case 'c':hx[i] = 12; break;
			case 'd':hx[i] = 13; break;
			case 'e':hx[i] = 14; break;
			case 'f':hx[i] = 15; break;
			}

			i++;
		}

		i = 0;

		while (i != s.length())
		{
			r = r + hx[i] * pow(16, p - 1);
			i++;
			p--;
		}
		std::cout << "Decimal is: " << r;
		std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
		g = _getch();
		switch (g)
		{
		case'1':conversion(); break;
		case'2':menu(); break;
		case'3':home(); break;
		default:error();
		}
	}
	else if (g == '6')
	{
		system("cls");

		long no, r[1000];
		short i = 0, j = 0;
		system("cls");
		std::cout << "\nEnter decimal number: ";
		std::cin >> no;
		if (no >= 999999999)
		{
			std::cout << "\n\t\tToo large!";
		}
		else
		{
			while (no > 0)
			{
				r[i] = no % 16;
				no = no / 16;
				i++;
			}
			std::cout << "\nHexadecimal is: ";

			for (j = i - 1; j >= 0; j--)
			{
				if (r[j] == 10) { std::cout << 'A'; }
				else if (r[j] == 11) { std::cout << 'B'; }
				else if (r[j] == 12) { std::cout << 'C'; }
				else if (r[j] == 13) { std::cout << 'D'; }
				else if (r[j] == 14) { std::cout << 'E'; }
				else if (r[j] == 15) { std::cout << 'F'; }
				else {
					std::cout << r[j];
				}
			}
		}
		std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;

		g = _getch();
		switch (g)
		{
		case'1':conversion(); break;
		case'2':menu(); break;
		case'3':home(); break;
		default:error();
		}
	}

	else
		error();
}

bin::bin()
{
	long no, r[1000];
	short i = 0, j = 0;
	system("cls");
	std::cout << "\nEnter decimal number: ";
	std::cin >> no;
	if (no >= 999999999)
	{
		std::cout << "\n\t\tToo large!";
	}
	else
	{
		while (no > 0)
		{
			r[i] = no % 2;
			no = no / 2;
			i++;
		}
		std::cout << "\nBinary is: ";

		for (j = i - 1; j >= 0; j--)
		{
			std::cout << r[j];
		}
	}
}

void erc(std::string D)
{
	std::cout << "\n\n\n\nError! Configuration " << D << " file missing.\nTry re-installing." << std::endl;
}

void reqpass()
{
	system("cls");
	std::fstream passfile;
	passfile.open("Files\\FactorySet.laam");
	if (passfile.is_open())
	{
		pass();
	}
	else { erc("Files\\FactorySet.laam"); }
	std::cin.get();
}

void cngpass()
{
	system("cls");
	system("title Password Settings");
	std::cout << "\n\n\n1.Create Password\n2.Remove Password Protection" << std::endl;
	g = _getch();
	if (g == '1')
	{
		system("cls");
	ref:
		system("cls");
		Data dj;
		std::cout << "\n\n\nEnter New Password: ";
		getline(std::cin, dj.password);
		if (dj.password.length() < 8)
		{
			std::cout << "\nPassword Must be more than 8 character!" << std::endl;
			std::cout << "Press Any Key to Try Again" << std::endl;
			std::cout << "Except 1 To return Home" << std::endl;
			g = _getch();
			if (g == '1')
			{
				home();
			}
			else
				goto ref;
		}
		else
		{
			std::cout << "\nConfirm password: ";
			getline(std::cin, dj.password1);
			if (dj.password == dj.password1)
			{
				std::string str;

				str = dj.password;
				for (i = 0; (i < 100 && str[i] != '\0'); i++)
				{
					str[i] = str[i] + 22;
				}
				//the key for encryption is 3 that is added to ASCII value
				std::fstream file1;
				file1.open("Files\\FactorySet.laam", std::ios::in | std::ios::out | std::ios::trunc);
				file1 << str;
				file1.close();
				Decode d;
				std::fstream mainfile;
				mainfile.open("Files\\PssT.laam");
				mainfile << "hex10fc48 b5zxCApI bQ9";
				mainfile.close();
				std::cout << "\n\nPassword changed!\n";
				std::cout << "\n\t\tPress Enter to Continue...." << std::endl;
				std::cin.get();
				home();
			}
			else std::cout << "\nPasswords doesn't match! try again." << std::endl;
			std::cin.get();
			goto ref;
		}
	}
	else if (g == '2')
	{
		std::fstream mainfile;
		mainfile.open("Files\\PssT.laam", std::ios::in | std::ios::out | std::ios::trunc);
		mainfile << "hex00ff98 b2zxCApI bz3";
		mainfile.close();
		std::fstream passfile;
		passfile.open("Files\\FactorySet.laam", std::ios::in | std::ios::out | std::ios::trunc);
		passfile.close();
		home();
	}
	else error();
}

void setting()
{
	system("cls");
	system("title Settings");
	std::cout << "\n\n1.Color Setting\n2.Password\n3.Reset All Settings\n4.Back" << std::endl;
	g = _getch();
	switch (g)
	{
	case'1':
		color();
		break;
	case'2':
		cngpass();
		break;
	case'3':
		reset();
		break;
	case'4':
		home();
		break;
	default: error();
	}
}

void pass()
{
	Data dj;
	Decode dc;
	std::cout << "\n\nThis is password protected by user\n";

paas:

	std::cout << "Enter Password: ";

	getline(std::cin, dj.password);
	if (dc.str == dj.password)
	{
		std::cout << "\npassword is correct!" << std::endl;
		default_sound;
		home();
	}
	else
	{
		std::cout << "\tIncorrect password!" << std::endl;
		goto paas;
	}
}

void error()
{
	system("cls");
	system("title Error!");
	std::cout << "\t\t\tInvalid Command!" << std::endl;
	error_sound;
	std::cout << "\t\tPlease Enter a valid Command!\n\n\n\n\n\t\t\Press any key to Return Home" << std::endl;

	g = _getch();
	home();
}

void root()
{
	Output_data obj;
	system("cls");
	system("title Root");
	std::cout << "\n\nEnter a number...";
	std::cin >> obj.num;
	std::cout << "Enter root: ";
	std::cin >> obj.num1;
	obj.ans = pow(obj.num, (1.00 / obj.num1));
	std::cout << "Ans: " << obj.ans << std::endl;
	std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
	g = _getch();
	switch (g)
	{
	case'1':root(); break;
	case'2':menu(); break;
	case'3':home(); break;
	default:error();
	}
}

int facthlp(int a)
{
	if (a > 1)
	{
		return (a * facthlp(a - 1));
	}
	else {
		return (1);
	}
}

void fact()
{
	Output_data obj;
	system("cls");
	system("title Factorial");
	std::cout << "Maximum Number is 33" << std::endl;
	std::cout << "Enter number for Factorial :";
	std::cin >> obj.num;
	std::cout << obj.num << "!=" << facthlp(obj.num) << std::endl;
	std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
	g = _getch(); switch (g)
	{
	case '1':fact(); break;
	case '2':menu(); break;
	case '3':home(); break;
	default:error();
	}
}

void prcn()
{
	Output_data obj;
	system("cls");
	system("title Percentage");
	std::cout << "\t\tPercentage" << std::endl;
	std::cout << "Enter number: ";
	std::cin >> obj.num;
	std::cout << "Enter percentage: ";
	std::cin >> obj.num1;
	obj.ans = (obj.num * obj.num1) / 100;
	std::cout << "Ans: " << obj.ans << std::endl;
	std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
	g = _getch();
	switch (g)
	{
	case '1': prcn();
		break;
	case '2':menu();
		break;
	case '3':home();
		break;
	default:error();
	}
}

void pwr()
{
	Output_data obj;
	system("cls");
	system("title Power");
	std::cout << "\t\tPower function" << std::endl;
	std::cout << "Enter Number: ";
	std::cin >> obj.num;
	std::cout << "Enter power: ";
	std::cin >> obj.num1;
	obj.ans = pow(obj.num, obj.num1);
	std::cout << "Ans: " << obj.ans << std::endl;
	std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
	g = _getch();
	switch (g)
	{
	case '1': pwr();
		break;
	case '2': menu();
		break;
	case '3': home();
		break;
	default:error();
	}
}

void loga()
{
	Output_data obj;
	system("cls");
	system("title Log");
	std::cout << "\t\tLogarithm" << std::endl;
	std::cout << "Enter log for 10 base and natural log: ";
	std::cin >> obj.num;
	std::cout << "10 base log" << obj.num << " = " << log10(obj.num) << std::endl;
	std::cout << "Natural log " << obj.num << " = " << log(obj.num) << std::endl;
	std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
	g = _getch(); switch (g)
	{
	case '1':  loga(); break;
	case '2':  menu(); break;
	case '3':   home(); break;
	default:  error();
	}
}

void trigonomitry()
{
	Output_data obj;
	system("cls");
	system("title Trigonometry");
	std::cout << "\t\tTrigonometry\n";
	std::cout << "Enter Degree for sin cos tan: ";
	std::cin >> obj.num;
	std::cout << "sin" << obj.num << " " << sin(obj.num) << std::endl;
	std::cout << "cos" << obj.num << " " << cos(obj.num) << std::endl;
	std::cout << "tan" << obj.num << " " << tan(obj.num) << std::endl;
	std::cout << "\n\n1.Continue\n2.Main Menu\n3.Home\n";
	g = _getch();
	switch (g)
	{
	case '1':  trigonomitry(); break;
	case '2':menu(); break;
	case '3':home(); break;
	default:error();
	}
}

void math()
{
	Output_data obj;
	system("cls");
	system("title Simple Math");
	temp = 0;

	std::cout << "\t\t\tSimple Math\n\t\t\[Use 0 for the value of previous answer] \n";
Math:
	{
		std::cout << "Enter Number and operator: ";
		std::cin >> obj.num >> o >> obj.num1;
	}
	if (obj.num == 0)
	{
		obj.num = temp;
	}
	try {
		if (o == '/' && obj.num1 == 0)
		{
			throw(-1);
		}
	}
	catch (int a)
	{
		if (a == -1)
		{
			std::cout << "\t\t\tYou can't divide by Zero.. \n\t\t\tTry again..!\n" << std::endl;
			goto Math;
		}
	}

	if (o == '+') obj.ans = obj.num + obj.num1;
	if (o == '-') obj.ans = obj.num - obj.num1;
	if (o == '*') obj.ans = obj.num * obj.num1;
	if (o == '/') obj.ans = obj.num / obj.num1;
	std::cout << "Answer: \t" << obj.num << "\n" << o << "\t\t" << obj.num1;
	temp = obj.ans;
	std::cout << "\n_________________________\n\t\t" << obj.ans << "\n\n1.Continue\n2.Main Menu\n3.Home" << std::endl;
	g = _getch();

	switch (g)
	{
	case '1':goto Math; break;
	case '2':menu(); break;
	case '3':home(); break;
	default:error();
	}
}

void menu()
{
	system("cls");
	system("title Menu");
	std::cout << "\n\n\t 1 : Math Operations\n\t 2 : Trigonometric Functions\n\t ";
	std::cout << "3 : Logarithmic Functions\n\t 4 : Power Functions\n\t ";
	std::cout << "5 : Percentage\n\t 6 : Factorial Number\n\t 7 : Root\n\t 8 : BASE\n\t 9 : Game\n (Any key) : Return Home" << std::endl;
	g = _getch();
	switch (g)
	{
	case'1':math(); break;
	case'2':trigonomitry(); break;
	case'3':loga(); break;
	case'4':pwr(); break;
	case'5':prcn(); break;
	case'6':fact(); break;
	case'7':root(); break;
	case'8':conversion(); break;
	case'9':game(); break;
	default: home();
	}
}

std::string license(std::string D)
{
	Data dj;
	std::cout << "\n\n\nEnter License: ";
	getline(std::cin, dj.dt);
	if (dj.dt == dj.License)
	{
		std::fstream myfile;
		myfile.open("Files\\IGFx.laam", std::ios::in | std::ios::out | std::ios::trunc);
		std::cout << "\nEnter Your Name: ";
		getline(std::cin, dj.userName);
		std::cout << "\nEnter Your Age: ";
		std::cin >> Age;
		std::cout << "\nEnter Email: ";
		std::cin >> mail;
		myfile << dj.userName << "\nAge: " << Age << "\nEmail: " << mail << "\nLicense Key: " << dj.dt << "\n" << D << std::endl;
		myfile.close();
		std::fstream filex1;
		filex1.open("Files\\Rgx.laam", std::ios::in | std::ios::out | std::ios::trunc);
		filex1 << 10;
		filex1.close();
		std::cout << "\n\n\t\tOperation Successful..!Press any key to continue....";
		std::cin.get();
		home();
	}
	std::cout << "Wrong Key!";
	std::cin.get();
	exit(0);
}

void Pack()
{
	system("color f0");
	system("Title Calculator");
	std::fstream filex("Files\\Rgx.laam", std::ios::in | std::ios::out);
	filex >> m; filex.close();
	if (m == 0)
	{
		system("title Enter License Key");
		std::cout << "\n\n\nSorry! You have used this trial 10 times.\n";
		license("Created After Using Trial");
	}
	else
		m = m - 1;
	filex.open("Files\\Rgx.laam", std::ios::in | std::ios::out | std::ios::trunc);
	filex << m;
	filex.close();
	std::cout << "\n\n\nUser data will not be saved in Trial mode.\nThese will work in full version.\nClick to continue..." << std::endl;
	std::cin.get();
	home();
}

int main()
{
	system("cls");
	Data Dj;
	std::fstream filex;
	filex.open("Files\\Rgx.laam", std::ios::in | std::ios::out | std::ios::app);
	filex >> m;
	filex.close();
	if (m < 10)
	{
		Pack();
	}
	std::string x;
	system("title Calculator");
	std::fstream myfile("Files\\IGFx.laam");
	myfile >> x;
	if (x.length() == 0)
	{
		system("title Enter License Key");
		system("color f0");
		std::cout << "\n\nEnter License Key Or use trial version for 10 times." << std::endl;
		std::cout << "1. Enter License Key\n2. Use trial" << std::endl;
		g = _getch();
		if (g == '1')
		{
			license("Created By Entering License Key");
		}
		if (g == '2')
		{
			Pack();
		}
		else
		{
			std::cout << "Error Input. Please try again!";
			std::cin.get();
			main();
		}
	}
	else
	{
		char Color;
		std::fstream clfile;
		clfile.open("Files\\SystemRun.laam");
		clfile >> Color;
		switch (Color)
		{
		case'1': system("color fc"); break;
		case'2':system("color fa"); break;
		case'3':system("color f9"); break;
		case'4':system("color fd"); break;
		case'5':system("color fe"); break;
		case'6':system("color fb"); break;
		case'7':system("color f0");
		}
		clfile.close();
		std::string mnf, swp;
		std::fstream mainfile;
		mainfile.open("Files\\PssT.laam");
		if (mainfile.is_open())
		{
			getline(mainfile, mnf);
			if (mnf == "hex10fc48 b5zxCApI bQ9")
			{
				reqpass();
			}
			if (mnf == "hex00ff98 b2zxCApI bz3")
			{
				default_sound;
				home();
			}
			else std::cout << "File Corrupted.. Contact with developer or Re install..";
			std::cin.get();
			return 0;
		}
		else
		{
			erc("Files\\PssT.laam");
		}
		std::cin.get();
		return 0;
	}
}

void home()
{
	Data dj;
	system("cls");
	system("title Home");
	std::cout << "\n\t\t\t[##CALCULATOR##]\n\t\t\tVersion: " << dj.version << std::endl;
	std::cout << "\n\n\n\n1.Main Menu\n2.Settings\n3.About" << std::endl;
	if (dj.check == "Not Activated")
	{
		std::cout << "4.Register" << std::endl;
		std::cout << "\n\nTime now: ";
		system("time/t");
		std::cout << "Today's Date: ";
		system("date/t");

		g = _getch();
		if (g == '1')
		{
			menu();
		}
		else if (g == '2')
		{
			setting();
		}
		else if (g == '3')
		{
			system("cls");
			system("title About");
			std::fstream myfile("Files\\IGFx.laam");
			if (myfile.is_open())
			{
				myfile >> dj.userName;
				dj.userName = "Registered with " + dj.userName;
			}
			std::cout << "\n\n\t\t\t****Calculator**** \n\t\t\t  Version:" << dj.version;
			std::cout << "\n\n\t\t\t" << dj.userName << "\n\n\nDeveloper: Fuad Hasan\nLanguage used:Standard C++\n2020 all rights reserved(c) \n\nPress Any key to to Return back" << std::endl;
			std::cin.get();
			home();
		}
		else if (g == '4')
		{
			license("Registered After Using Trial");
		}
		else error();
	}
	else
	{
		std::cout << "\n\nTime now: " << time << std::endl;
		std::cout << "Today's Date: " << date << std::endl;
		g = _getch();
		if (g == '1')
		{
			menu();
		}
		else if (g == '2')
		{
			setting();
		}
		else if (g == '3')
		{
			system("cls");
			system("title About");
			std::fstream myfile("Files\\IGFx.laam");
			if (myfile.is_open())
			{
				myfile >> dj.userName;
				dj.userName = "Registered with " + dj.userName;
			}
			std::cout << "\n\n\t\t\t****Calculator**** \n\t\t\t  Version:" << dj.version;
			std::cout << "\n\n\t\t\t" << dj.userName << "\n\n\nDeveloper: Fuad Hasan\nLanguage used:Standard C++\n2020 all rights reserved(c)\n\nPress Any key to to Return back" << std::endl;
			std::cin.get();
			home();
		}
		else error();
	}
}

void color()
{
	system("cls");
	system("title Color");
	std::cout << "\t\tColor Settings....." << std::endl;
	std::cout << "\t\t\n\n1.Red\n2.Green\n3.Blue\n4.Pink\n5.Yellow\n6.Aqua\n7.Default\n8.Home" << std::endl;
	std::fstream clfile;
	clfile.open("Files\\SystemRun.laam", std::ios::in | std::ios::out | std::ios::trunc);
	Color = _getch();
	clfile << Color;
	clfile.close();
	system("cls");
	switch (Color)
	{
	case'1': system("color fc");
		break;
	case'2':system("color fa");
		break;
	case'3':system("color f9");
		break;
	case'4':system("color fd");
		break;
	case'5':system("color fe");
		break;
	case'6':system("color fb");
		break;
	case'7':system("color f0");
		break;
	case'8':home();
	default:
		std::cout << "Unknown Command! Back to default!" << std::endl;
		system("color f0");
		home();
	}
	home();
}