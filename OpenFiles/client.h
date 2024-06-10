#pragma once
#include "Tree.h"
/*
 * У клиента присутствует интерфейс :
 * Использовать рабочую папку
 * Использовать аргумент командной строки
 * Ввести название папки с клавиатуры
*/

class IClient {
public:
	virtual void useTheWorkingFolder() const  = 0;
	virtual void  useCommandLineArgument(int argc, char * argv[]) const = 0;
	virtual void enteringFolderFromTheKeyboard() const = 0;
};

class Client
	: public IClient
{
public:
	enum class ActionOfClient {
		USE_WORKING_FOLDER = 1, USE_COMMAND_LINE = 2, ENTERING_FROM_KEYBOARD = 3
	};
public:
	void useTheWorkingFolder() const override;
	void useCommandLineArgument (int argc, char * argv[]) const override;
	void enteringFolderFromTheKeyboard() const override;
	friend void allUserActions(const Client &client, int argc, char * argv[], int choice);
private:
	void actionsWithFilesystem(const std::string folder) const;
};