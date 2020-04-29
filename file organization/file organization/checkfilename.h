#ifndef H_checkfilename
#define H_checkfilename
#include "headerInclude.h"
#define FILESIZE 50 

string checkName(){
	int Lenght;
	char filename[FILESIZE];
	char extension[5];
	do{
		cout << "please entre file name or full path for your file " << endl;
		cin.getline(filename, FILESIZE);
		Lenght = strlen(filename);
		for (int i = Lenght - 4, j = 0; i <= Lenght; i++, j++)
			extension[j] = filename[i];
		if (strcmp(extension, ".txt") == 0){
			return filename;
		}
		cout << "file extension is not correct .txt is allowed only\n";
		cout << "reinter file name\n";
		system("pause");
		system("cls");
	} while (1);
}
#endif