#include "client.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <memory>
#include <cctype>
using namespace std;
using namespace std::filesystem;

void Client::useTheWorkingFolder() const { actionsWithFilesystem(current_path().string()); }

void Client::useCommandLineArgument(int argc, char * argv[]) const {
	if (argc < 3) {
		std::runtime_error("Требуется указать 2 аргумента");
	}
	std::string folder;
	for (int i = 0; i < argc; i++)
		folder = argv[i];

	actionsWithFilesystem(folder);
}

void Client::enteringFolderFromTheKeyboard() const
{
	std::string myPath;
	cout << "Введите путь к папке " << endl << "> ";
	getline(std::cin, myPath);
	actionsWithFilesystem(myPath);
}

void Client::actionsWithFilesystem(const std::string folder) const
{
	Tree * sys = new Tree();
	sys->makeTreeFromFilesystem(folder);
	sys->sort();
	sys->print();
	sys->saveToFile("Filesystem.log");
	delete sys;
}

void allUserActions(const Client& client, int argc, char * argv[], int choice)
{
	try {
		switch (choice)
		{
		case (int)Client::ActionOfClient::USE_WORKING_FOLDER:
			client.useTheWorkingFolder();
			break;
		case (int)Client::ActionOfClient::USE_COMMAND_LINE:
			client.useCommandLineArgument(argc, argv);
			break;
		case (int)Client::ActionOfClient::ENTERING_FROM_KEYBOARD:
			client.enteringFolderFromTheKeyboard();
			break;
		default:
			cerr << "Извините, возможно, вы ошиблись, попробуйте снова" << endl;
			break;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}
