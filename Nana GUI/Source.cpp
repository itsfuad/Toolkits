#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <filesystem>
#include <functional>
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/msgbox.hpp>
#include <nana/gui/widgets/panel.hpp>

#define println(x) std::cout << x << std::endl
#define print(x) std::cout << x

namespace fs = std::filesystem;

namespace alert {
	nana::msgbox unlocked("Folder Unlocked!");
	nana::msgbox locked("Folder Locked!");
	nana::msgbox incorrect("Incorrect Password!");
	nana::msgbox newfolder("Private folder created sucessfully");
}

void run()
{
	if (!fs::exists("Private") && !fs::exists("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"))
	{
		fs::create_directories("Private");
		//println("Private folder created sucessfully");
		alert::newfolder.show();
	}
}

void init()
{
	nana::form fm;
	fm.icon(nana::paint::image("resources/lock1.ico"));
	fm.size({ 300,200 });
	fm.caption(L"Folder Locker v1.0 beta");
	//fm.bgcolor(nana::color_rgb(0xdf0000));

	nana::textbox txt(fm, nana::rectangle{ 5, 30, 290, 50 });
	nana::button lock(fm, nana::rectangle{ 70, 120, 50,30 });
	nana::button unlock(fm, nana::rectangle{ 180, 120, 50,30 });
	nana::label lb(fm, nana::rectangle{ 120, 180, 70,30 });
	lb.caption("AlterGen Inc.");
	lb.fgcolor(nana::color_rgb(0x000000));
	//lb.bgcolor(nana::color_rgb(0xffaafc));

	alert::unlocked.icon(nana::msgbox::icon_information);
	alert::locked.icon(nana::msgbox::icon_information);
	alert::newfolder.icon(nana::msgbox::icon_warning);
	alert::incorrect.icon(nana::msgbox::icon_error);

	txt.mask(L'•');

	lock.bgcolor(nana::color_rgb(0xdadada));
	lock.borderless(true);
	lock.caption(L"Lock");
	lock.events().click([&]() {
		if (fs::exists("Private"))
		{
			//println("Locked");
			alert::locked.show();
			fs::rename("Private", "Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}");
			system("attrib +h +s \"Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}\"");
		}
		});
	unlock.bgcolor(nana::color_rgb(0xdadada));
	unlock.borderless(true);
	unlock.caption(L"Unlock");
	unlock.events().click([&]() {
		if (fs::exists("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}"))
		{
			std::string pwd = txt.text();

			if (pwd == "laam") //Set your password
			{
				system("attrib -h -s \"Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}\"");
				fs::rename("Control Panel.{21EC2020-3AEA-1069-A2DD-08002B30309D}", "Private");
				//println("Folder Unlocked");
				alert::unlocked.show();
			}
			else
			{
				//println("Incorrect password");
				alert::incorrect.show();
			}
		}
		});

	fm.show();
	nana::exec();
}

void WinMain()
{
	run();
	init();
}