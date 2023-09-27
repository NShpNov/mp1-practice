#ifndef HEADER_H
#define HEADER_H

using namespace std;

struct names {
	string fname;
	string midname;
	string surname;
	names();
	const names& operator= (const names& e);
	bool operator== (const names& e) const;
	friend istream& operator>>(istream& in, names& d) {
		in >> d.midname >> d.fname >> d.surname;
		return in;
	};
	friend ostream& operator<<(ostream& out, const names& d) {
		out << d.midname << " " << d.fname << " " << d.surname;
		return out;
	};
};

struct date {
	int day;
	int month;
	int year;
	date();
	date(const string& str);
	const date& operator= (const date& e);
	bool operator== (const date& e) const;
	friend istream& operator>>(istream& in, date& d) {
		in >> d.day >> d.month >> d.year;
		return in;
	};
	friend ostream& operator<<(ostream& out, const date& d) {
		if (d.day <= 9) out << "0";
		out << d.day <<".";
		if (d.month <= 9) out << "0";
		out << d.month<<".";
		if (d.year <= 9) out << "0";
		out << d.year;
		return out;
	};
};

class student {
private:
	names name;
	date birth;
	string number;

public:
	student();
	student(const string& v);
	const student& operator= (const student& e);
	bool operator==(const names n) const;
	bool operator==(const date n) const;
	bool operator==(const string n) const;
	friend ostream& operator<<(ostream& out, const student& l) {
		out << l.name << ", " << l.birth << "; " << l.number;
		return out;
	}
};

class lib {
private:
	student* elems;
	int amount;
public:
	lib();
	lib(int a);
	lib(const string& filename);
	~lib();
	template <typename T> student find_stud(const T n);
	student& operator[](int ind);
	friend ostream& operator<<(ostream& out, const lib& l) {
		for (int i = 0; i < l.amount; i++) {
			out << endl << l.elems[i];
		}
		out << endl;
		return out;
	}
};

string* divider(int n, const string s, const string del);
string get_string(ifstream& file);
template <typename T> student lib::find_stud(const T n) {
	student tmp;
	bool flag = true;
	for (int i = 0; i < amount; i++) {
		if (elems[i] == n) {
			tmp = elems[i];
			flag = false;
			break;
		}
	}
	if (flag) throw "no such student found";
	return tmp;
}
#endif // !HEADER_H
