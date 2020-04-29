#ifndef H_basicText
#define H_basicText
#include "headerInclude.h"
#include "checkfilename.h"
#define FILESIZE 50

void createFileT(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	string filename;
	cout << "\n\t\tcreate file in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	file.open(filename, ios::out);
	cout << " file " << filename << " is created successfully " << endl;
	system("pause");
}

void writeDataToFileT(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	string filename;
	cout << "\n\t\twrite to file in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	file.open(filename, ios::out);
	if (!file.is_open()){
		cout << " error can not open file " << endl;
		system("pause");
		return;
	}
	else
	{
		char ch;
		cout << "please entre your data in file\n" << endl;
		cout << "#### data stop write in file if you writ dot '.' then press entre ####\n" << endl;
		cin >> ch;

		while (ch != '.') {
			file.put(ch);
			cin >> ch;
		}
		file.close();

	}
	system("pause");
}

void readDataFromFileT(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	string filename;
	cout << "\n\t\tread from file in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	file.open(filename, ios::in);

	if (!file.is_open()) {
		cout << " error can not open file " << endl;
		system("pause");
		return;
	}
	else
	{
		char ch;
		while (file) {
			file.get(ch);
			cout << ch;
		}
		file.close();


	}
	system("pause");
}

void UsingSeekInFileTfrombeg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	string filename;
	cout << "\n\t\t Using Seek In File T from beg text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	int x;
	char ch;
	file.open(filename, ios::out);
	if (!file.is_open()) {
		cout << " error can not open file " << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "please entre number of byte you want to seek" << endl;
		cin >> x;
		file.seekg(x, ios::beg);
		file.get(ch);
		cout << " byte  " << x << "  from begiinning = " << ch << endl;
	}

	system("pause");
}

void UsingSeekInFileTcur(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	string filename;
	cout << "\n\t\t Using Seek In File T cur in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	int x;
	char ch;
	file.open(filename, ios::out);
	if (!file.is_open()) {
		cout << " error can not open file " << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "please entre number of byte you want to seek" << endl;
		cin >> x;
		file.seekg(x, ios::cur);
		file.get(ch);
		cout << " byte  " << x << "  from current = " << ch << endl;
	}

	system("pause");
}

void  UsingSeekInFileTend(){

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	string filename;
	cout << "\n\t\t Using Seek In File T cur in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	int x;
	char ch;
	file.open(filename, ios::out);
	if (!file.is_open()) {
		cout << " error can not open file " << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "please entre number of byte you want to seek" << endl;
		cin >> x;
		file.seekg(x, ios::end);
		file.get(ch);
		cout << " byte  " << x << "  from end = " << ch << endl;
	}
}
#endif 