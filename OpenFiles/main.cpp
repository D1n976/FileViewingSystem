#include <iostream>
#include "client.h"
#include <Windows.h>
#include <conio.h>
using namespace std;

const int ESC = 27;

int main(int argc, char *argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		system("cls");

		Client client;
		cout << "��� ����, ����� ������������ ������� ����� - ������� " << static_cast<int>(Client::ActionOfClient::USE_WORKING_FOLDER) << endl
			<< "��� ����, ����� ������������ �������� ��������� ������ - ������� " << static_cast<int>(Client::ActionOfClient::USE_COMMAND_LINE) << endl
			<< "��� ����, ����� ������ �������� ����� � ���������� - ������� " << static_cast<int>(Client::ActionOfClient::ENTERING_FROM_KEYBOARD) << endl;
		int choice = -1;
		cout << "> ";
		cin >> choice;
		cin.ignore();

		allUserActions(client, argc, argv, choice);

		cout << endl << "����� ����� ������� esc" << endl
			<< "����� ���������� - ������� ����� ������ ������� " << endl << "> ";

		int x = _getch();
		if (x == ESC)
			break;
	}
}