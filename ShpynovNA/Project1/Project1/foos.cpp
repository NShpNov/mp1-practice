#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>

string get_string(ifstream& file) {
	string tmp;
	getline(file, tmp);
	return tmp;
}
string* divider(int n, const string s, const string del) {
	string* Stmp = new string[n];
	string delim = del;
	size_t last = 0;
	size_t next;
	int i = 0;
	while ((next = s.find(delim, last)) != string::npos) {
		Stmp[i] = s.substr(last, next - last);
		i++;
		last = next + delim.length();
	}
	return Stmp;
}

lib::lib() {};
lib::lib(int n) {
	amount = n;
	elems = new student[amount];
}
lib::lib(const string& filename) {
	string* strtmp = new string[50];
	ifstream file(filename);
	int n = 0;
	while ((strtmp[n] = get_string(file)) != "")
		n++;
	amount = n;
	elems = new student[amount];
	for (int i = 0; i < amount; i++)
		elems[i] = student(strtmp[i]);
	file.close();
	delete[] strtmp;
}
lib::~lib() {
	delete[] this->elems;
}
student& lib::operator[](int ind) {
	return elems[ind];
}


student::student() {};
student::student(const string& str) {
	string* stmp = new string[3];
	string* stmp1 = new string[3];
	stmp = divider(3, str, ";");
	stmp1 = divider(3, stmp[0], " ");
	name.midname = stmp1[0];
	name.fname = stmp1[1];
	name.surname = stmp1[2];
	number = stmp[2];
	birth = date(stmp[1]);
	delete[]stmp;
	delete[]stmp1;
}
bool student::operator==(const names n) const  {
	if (name == n) return true;
	else return false;
}
bool student::operator==(const date n) const  {
	if (birth == n) return true;
	else return false;
}
bool student::operator==(const string n) const  {
	if (number == n) return true;
	else return false;
}
const student& student::operator= (const student& e) {
	number = e.number;
	name = e.name;
	birth = e.birth;
	return *this;
}

const date& date::operator= (const date& e) {
	day = e.day;
	month = e.month;
	year = e.year;
	return *this;
}
bool date::operator== (const date& e) const {
	if ((day == e.day) && (month == e.month) && (year == e.year)) return true;
	else return false;
}
date::date() {};
date::date(const string& str) {
	string tmp;
	tmp = str.substr(0, 2);
	this->day = atoi(tmp.c_str());
	tmp = str.substr(3, 2);
	this->month = atoi(tmp.c_str());
	tmp = str.substr(8, 2);
	this->year = atoi(tmp.c_str());
}

names::names() {};
const names& names::operator= (const names& e) {
	midname = e.midname;
	fname = e.fname;
	surname = e.surname;
	return *this;
}
bool names::operator== (const names& e) const {
	if ((midname == e.midname) && (fname == e.fname) && (surname == e.surname)) return true;
	else return false;
}