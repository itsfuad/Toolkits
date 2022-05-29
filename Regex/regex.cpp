#include <iostream>
#include <regex>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>

void regex()
{
	std::regex mail("[\\w\.]+@[\\w]+\.com");
	std::regex website("http[s]?://[\\w\.]+\.[\\w]+");
	std::smatch match;
	std::string strings = "Here is my email: fuad.cs22@gmail.com. itsfuad1@yandex.com https://www.itsfuad.netlify.app";
	while (std::regex_search(strings, match, mail))
	{
		std::cout << match.str() << std::endl;
		strings = match.suffix();
	}
}

int main()
{
	nana::form fm;
	fm.caption(L"Hello World");
	nana::button btn(fm, nana::rectangle{ 20,20, 150,30 });
	btn.caption(L"Quit");
	btn.events().click(nana::API::exit);
	fm.show();
	nana::exec();
}