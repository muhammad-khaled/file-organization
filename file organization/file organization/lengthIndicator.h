#ifndef H_lengthIndicator
#define H_lengthIndicator
#include "headerInclude.h"

void lengthIndicatorWrite(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	fstream file;
	file.open("data_student_Length.txt", ios::out | ios::binary);
	if (!file.is_open()){
		cout << "\n\ncan not open data_student_Length.txt file\n";
		system("pause");
		return;
	}
	cout << "write student data using length indicator field\n\n";
	int i, n, length;
	student st;
	cout << "enter number of student u have\t";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		if (file.good()){
			cout << "enter the ID of student # " << (i + 1) << "\t";
			cin >> st.id;
			length = strlen(st.id);
			if (length < 10)
				file << "0";
			file << length << st.id;
			cout << "enter the fname of student # " << (i + 1) << "\t";
			cin >> st.fname;
			length = strlen(st.fname);
			if (length < 10)
				file << "0";
			file << length << st.fname;
			cout << "enter the lname of student # " << (i + 1) << "\t";
			cin >> st.lname;
			length = strlen(st.lname);
			if (length < 10)
				file << "0";
			file << length << st.lname;
			cout << "enter the degree of student # " << (i + 1) << "\t";
			cin >> st.degree;
			length = strlen(st.degree);
			if (length < 10)
				file << "0";
			file << length << st.degree;
			cout << "enter the City of student # " << (i + 1) << "\t";
			cin >> st.city;
			length = strlen(st.city);
			if (length < 10)
				file << "0";
			file << length << st.city;
			cout << "enter the Country of student # " << (i + 1) << "\t";
			cin >> st.country;
			length = strlen(st.country);
			if (length < 10)
				file << "0";
			file << length << st.country;
		}
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

void lengthIndicatorRead(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	fstream file;
	char temp[3];
	int n, i;
	file.open("data_student_Length.txt", ios::in | ios::binary);
	if (!file.is_open()){
		cout << "\n\ncan not open data_student_Length.txt file\n";
		system("pause");
		return;
	}
	student st;
	cout << "reading student Data form Length Indicator field\n\n";
	cout << left << setw(8) << "ID";
	cout << left << setw(10) << "fname";
	cout << left << setw(10) << "lname";
	cout << left << setw(15) << "degree";
	cout << left << setw(15) << "city";
	cout << left << setw(15) << "country" << "\n\n";
	while (!file.eof()){
		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		if (file.fail())
			break;
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.id[i];
		st.id[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.fname[i];
		st.fname[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.lname[i];
		st.lname[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.degree[i];
		st.degree[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.city[i];
		st.city[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.country[i];
		st.country[i] = '\0';
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

void lengthIndicatorupdate() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	fstream file, tempf;
	char temp[3], id[8];
	int n, i;
	file.open("data_student_Length.txt", ios::in | ios::binary);
	if (!file.is_open()) {
		cout << "\n\ncan not open data_student_Length.txt file\n";
		system("pause");
		return;
	}
	cout << "please entre  id  you want to update " << endl;
	cin >> id;
	student st;
	while (!file.eof()) {
		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		if (file.fail())
			break;
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.id[i];
		st.id[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.fname[i];
		st.fname[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.lname[i];
		st.lname[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.degree[i];
		st.degree[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.city[i];
		st.city[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.country[i];
		st.country[i] = '\0';
	}if (strcmp(st.id, id) == 0) {
		// update 
		if (tempf.good()) {
			cout << "enter the ID of student # " << (atoi(id)) << "\t";
			cin >> st.id;
			tempf << st.id;
			cout << "enter the fname of student # " << (atoi(id)) << "\t";
			cin >> st.fname;
			tempf << st.fname;
			cout << "enter the lname of student # " << (atoi(id)) << "\t";
			cin >> st.lname;
			tempf << st.lname;
			cout << "enter the degree of student # " << (atoi(id)) << "\t";
			cin >> st.degree;
			tempf << st.degree;
			cout << "enter the City of student # " << (atoi(id)) << "\t";
			cin >> st.city;
			tempf << st.city;
			cout << "enter the Country of student # " << (atoi(id)) << "\t";
			cin >> st.country;
			tempf << st.country;
		}
		else {
			cout << "Error can not write to yor file\n";
			cout << "please check your file or hard disk space\n";
		}
	}
	else {
		// not update
		tempf << st.id;
		tempf << st.fname;
		tempf << st.lname;
		tempf << st.degree;
		tempf << st.city;
		tempf << st.country;
	}
	tempf.close();
	file.close();
	file.open("data_student_Length.txt", ios::out | ios::binary);
	tempf.open("data_student_del_temp.txt", ios::in | ios::binary);

	while (!tempf.eof()) {

		i = 0;
		tempf >> st.id[i];
		if (tempf.fail())
			break;
		tempf >> st.id[++i];
		st.id[i] = '\0';
		file << st.id;

		i = 0;
		tempf >> st.fname[i];
		tempf >> st.fname[++i];
		st.fname[i] = '\0';
		file << st.fname;
		i = 0;
		tempf >> st.lname[i];
		tempf >> st.lname[++i];
		st.lname[i] = '\0';
		file << st.lname;
		i = 0;
		tempf >> st.degree[i];
		tempf >> st.degree[++i];
		st.degree[i] = '\0';
		file << st.degree;
		i = 0;
		tempf >> st.city[i];
		tempf >> st.city[++i];
		st.city[i] = '\0';
		file << st.city;
		i = 0;
		tempf >> st.country[i];
		tempf >> st.country[++i];
		st.country[i] = '\0';
		file << st.country;
	}
	file.close();
	tempf.close();
	remove("data_student_del_temp.txt");  // full path
	cout << "your students data were updated successfully\n";
	system("pause");
}
void lengthIndicatordelete() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	fstream file, tempf;
	char temp[3], id[8];
	int n, i;
	file.open("data_student_Length.txt", ios::in | ios::binary);
	if (!file.is_open()) {
		cout << "\n\ncan not open data_student_Length.txt file\n";
		system("pause");
		return;
	}
	cout << "please entre  id  you want to update " << endl;
	cin >> id;
	student st;
	while (!file.eof()) {
		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		if (file.fail())
			break;
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.id[i];
		st.id[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.fname[i];
		st.fname[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.lname[i];
		st.lname[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.degree[i];
		st.degree[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.city[i];
		st.city[i] = '\0';

		file >> temp[0] >> temp[1];
		temp[2] = '\0';
		n = atoi(temp);
		for (i = 0; i < n; i++)
			file >> st.country[i];
		st.country[i] = '\0';
		if (strcmp(st.id, id) == 0) {
			// update 
			continue;
		}
		else {
			// not update
			tempf << st.id;
			tempf << st.fname;
			tempf << st.lname;
			tempf << st.degree;
			tempf << st.city;
			tempf << st.country;
		}
	}
	tempf.close();
	file.close();
	file.open("data_student_Length.txt", ios::out | ios::binary);
	tempf.open("data_student_del_temp.txt", ios::in | ios::binary);

	while (!tempf.eof()) {
		i = 0;
		tempf >> st.id[i];
		if (tempf.fail())
			break;
		tempf >> st.id[++i];
		st.id[i] = '\0';
		file << st.id;

		i = 0;
		tempf >> st.fname[i];
		tempf >> st.fname[++i];
		st.fname[i] = '\0';
		file << st.fname;
		i = 0;
		tempf >> st.lname[i];
		tempf >> st.lname[++i];
		st.lname[i] = '\0';
		file << st.lname;
		i = 0;
		tempf >> st.degree[i];
		tempf >> st.degree[++i];
		st.degree[i] = '\0';
		file << st.degree;
		i = 0;
		tempf >> st.city[i];
		tempf >> st.city[++i];
		st.city[i] = '\0';
		file << st.city;
		i = 0;
		tempf >> st.country[i];
		tempf >> st.country[++i];
		st.country[i] = '\0';
		file << st.country;
	}
	file.close();
	tempf.close();
	remove("data_student_del_temp.txt");  // full path
	cout << "your students data were updated successfully\n";
	system("pause");
}

#endif