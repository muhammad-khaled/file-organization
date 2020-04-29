#ifndef H_fixedlength
#define H_fixedlength
#include "headerInclude.h"
void fixedlengthWrite(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	fstream file;
	file.open("data_studentFixedLength.txt", ios::out | ios::binary);
	if (!file.is_open()){
		cout << "\n\ncan not open data_studentFixedLength.txt file\n";
		system("pause");
		return;
	}
	cout << "write student data using fixed length field\n\n";
	int i, n;
	student st;
	cout << "enter number of student u have\t";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "enter the ID of student # " << (i + 1) << "\t";
		cin >> st.id;
		cout << "enter the fname of student # " << (i + 1) << "\t";
		cin >> st.fname;
		cout << "enter the lname of student # " << (i + 1) << "\t";
		cin >> st.lname;
		cout << "enter the degree of student # " << (i + 1) << "\t";
		cin >> st.degree;
		cout << "enter the City of student # " << (i + 1) << "\t";
		cin >> st.city;
		cout << "enter the Country of student # " << (i + 1) << "\t";
		cin >> st.country;
		if (file.good())
			file.write((char*)&st, sizeof(st));
		else{
			cout << "Error can not write to yor file\n";
			cout << "please check your file or hard disk space\n";
		}
		system("pause");
		system("cls");
	}
	file.close();
	cout << "your students data were wirrten successfully\n";
	system("pause");
}

void fixedlengthRead(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	fstream file;
	file.open("data_studentFixedLength.txt", ios::in | ios::binary);
	if (!file.is_open()){
		cout << "\n\ncan not open data_studentFixedLength.txt file\n";
		system("pause");
		return;
	}
	student st;
	cout << "reading student Data form fixed length Marker field\n\n";
	cout << left << setw(8) << "ID";
	cout << left << setw(10) << "fname";
	cout << left << setw(10) << "lname";
	cout << left << setw(15) << "degree";
	cout << left << setw(15) << "city";
	cout << left << setw(15) << "country" << "\n\n";
	while (!file.eof()){
		file.read((char*)&st, sizeof(st));
		if (file.fail())
			break;
		if (strcmp(st.id, "*") == 0)
		{
			continue;
		}
		cout << left << setw(8) << st.id;
		cout << left << setw(10) << st.fname;
		cout << left << setw(10) << st.lname;
		cout << left << setw(15) << st.degree;
		cout << left << setw(15) << st.city;
		cout << left << setw(15) << st.country << "\n\n";
	}
	file.close();
	cout << "\n\nyour students data were readed successfully\n";
	system("pause");
}

void fixedlengthupdate(){
	bool updated = false;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	fstream file, tfile;
	file.open("data_studentFixedLength.txt", ios::in | ios::binary);
	tfile.open("data_studentFixedLengthtemp.txt", ios::out | ios::binary);
	if (!file.is_open() && !tfile.is_open()){
		cout << "\n\ncan not open data_studentFixedLength.txt file\n";
		system("pause");
		return;
	}
	cout << "update student data using Fixed Length field \n\n";
	char id[8];
	student st;
	cout << "enter number of student id u want to update\t";
	cin >> id;
	while (!file.eof()){
		file.read((char*)&st, sizeof(st));
		if (file.fail())
			break;
		if (strcmp(id, st.id) == 0){
			if (tfile.good()){
				cout << "enter the ID of student # " << (atoi(id)) << "\t";
				cin >> st.id;
				cout << "enter the fname of student # " << (atoi(id)) << "\t";
				cin >> st.fname;
				cout << "enter the lname of student # " << (atoi(id)) << "\t";
				cin >> st.lname;
				cout << "enter the degree of student # " << (atoi(id)) << "\t";
				cin >> st.degree;
				cout << "enter the City of student # " << (atoi(id)) << "\t";
				cin >> st.city;
				cout << "enter the Country of student # " << (atoi(id)) << "\t";
				cin >> st.country;
				tfile.write((char*)&st, sizeof(st));
				updated = true;
			}
			else{
				cout << "Error can not write to your file\n";
				cout << "please check your file or hard disk space\n";
			}
		}
		else
			tfile.write((char*)&st, sizeof(st));
	}
	file.close();
	tfile.close();

	file.open("data_studentFixedLength.txt", ios::out | ios::binary);
	tfile.open("data_studentFixedLengthtemp.txt", ios::in | ios::binary);
	if (!file.is_open() && !tfile.is_open()){
		cout << "\n\ncan not open data_studentFixedLength.txt file\n";
		system("pause");
		return;
	}
	while (!tfile.eof()){
		tfile.read((char*)&st, sizeof(st));
		if (tfile.fail())
			break;
		file.write((char*)&st, sizeof(st));
	}
	file.close();
	tfile.close();
	remove("data_studentFixedLengthtemp.txt");
	if (updated)
		cout << "your students data were updated successfully\n";
	else
		cout << " your student id is not exist\n";
	system("pause");
}

void fixedlengthdelete(){
	bool deleted = false;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	fstream file, tfile;
	file.open("data_studentFixedLength.txt", ios::in | ios::binary);
	tfile.open("data_studentFixedLengthtemp.txt", ios::out | ios::binary);
	if (!file.is_open() && !tfile.is_open()){
		cout << "\n\ncan not open data_studentFixedLength.txt file\n";
		system("pause");
		return;
	}
	cout << "delete student data using Fixed Length field \n\n";
	char id[8];
	student st;
	cout << "enter number of student id u want to delete\t";
	cin >> id;
	while (!file.eof()){
		file.read((char*)&st, sizeof(st));
		if (file.fail())
			break;
		if (strcmp(id, st.id) == 0){
			deleted = true;
			continue;
		}
		tfile.write((char*)&st, sizeof(st));
	}
	file.close();
	tfile.close();

	file.open("data_studentFixedLength.txt", ios::out | ios::binary);
	tfile.open("data_studentFixedLengthtemp.txt", ios::in | ios::binary);
	if (!file.is_open() && !tfile.is_open()){
		cout << "\n\ncan not open data_studentFixedLength.txt file\n";
		system("pause");
		return;
	}
	while (!tfile.eof()){
		tfile.read((char*)&st, sizeof(st));
		if (tfile.fail())
			break;
		file.write((char*)&st, sizeof(st));
	}
	file.close();
	tfile.close();
	remove("data_studentFixedLengthtemp.txt");
	if (deleted)
		cout << "your students data were deleted successfully\n";
	else
		cout << " your student id is not exist\n";
	system("pause");
}

void fixedlengthdeleteMarker(){
	bool deleted = false;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	fstream file, tfile;
	file.open("data_studentFixedLength.txt", ios::in | ios::binary);
	tfile.open("data_studentFixedLengthtemp.txt", ios::out | ios::binary);
	if (!file.is_open() && !tfile.is_open()){
		cout << "\n\ncan not open data_studentFixedLength.txt file\n";
		system("pause");
		return;
	}
	cout << "delete student data using Fixed Length Marker \n\n";
	char id[8];
	student st;
	cout << "enter number of student id u want to delete\t";
	cin >> id;
	while (!file.eof()){
		file.read((char*)&st, sizeof(st));
		if (file.fail())
			break;
		if (strcmp(id, st.id) == 0){
			strcpy(st.id, "*");
			tfile.write((char*)&st, sizeof(st));
			deleted = true;
		}
		else
			tfile.write((char*)&st, sizeof(st));
	}
	file.close();
	tfile.close();

	file.open("data_studentFixedLength.txt", ios::out | ios::binary);
	tfile.open("data_studentFixedLengthtemp.txt", ios::in | ios::binary);
	if (!file.is_open() && !tfile.is_open()){
		cout << "\n\ncan not open data_studentFixedLength.txt file\n";
		system("pause");
		return;
	}
	while (!tfile.eof()){
		tfile.read((char*)&st, sizeof(st));
		if (tfile.fail())
			break;
		file.write((char*)&st, sizeof(st));
	}
	file.close();
	tfile.close();
	remove("data_studentFixedLengthtemp.txt");
	if (deleted)
		cout << "your students data were deleted successfully\n";
	else
		cout << " your student id is not exist\n";
	system("pause");
}


#endif 