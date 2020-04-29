#ifndef H_basicBinary
#define H_basicBinary
#include "headerInclude.h"
#include "checkfilename.h"
#define FILESIZE 50

void createFileB(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	string filename;
	/*char extension[5];
	int Lenght;*/
	cout << "\n\t\tcreate file in binary mode\n";
	cin.ignore();

	filename = checkName();
	fstream file;
	file.open(filename, ios::out | ios::binary);
	cout << " file " << filename << " is created successfully " << endl;
	system("pause");
}

void writeDataToFileB(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	string filename;
	cout << "\n\t\twrite using seek file in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	char ch;
	file.open(filename, ios::out);
	if (!file.is_open()) {
		cout << "error can not open file" << endl;
		system("pause");
		return;
	}
	else {
		cout << "please entre your data in file\n" << endl;
		cout << "#### data stop write in file if you writ dot '.' then press entre ####\n" << endl;
		cin >> ch;

		while (ch != '.') {
			file.write((char*)&ch, sizeof(ch));
			cin >> ch;
		}

	}
	file.close();
	system("pause");
}

void readDataFromFileB(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	string filename;
	cout << "\n\t\twrite using seek file in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	char ch;
	file.open(filename, ios::out);
	if (!file.is_open()) {
		cout << "error can not open file" << endl;
		system("pause");
		return;
	}
	else {
		while (file) {
			file.read((char*)&ch, sizeof(ch));
			cout << ch;
		}
	}

	system("pause");
}


void UsingSeekInFileBfrombeg() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	string filename;
	cout << "\n\t\t Using Seek In File B from beg text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	int x;
	char ch;
	file.open(filename, ios::out | ios::binary);
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

void UsingSeekInFileBcur() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	string filename;
	cout << "\n\t\t Using Seek In File B cur in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	int x;
	char ch;
	file.open(filename, ios::out | ios::binary);
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

void  UsingSeekInFileBend() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	string filename;
	cout << "\n\t\t Using Seek In File B cur in text mode\n";
	cin.ignore();
	filename = checkName();
	fstream file;
	int x;
	char ch;
	file.open(filename, ios::out | ios::binary);
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