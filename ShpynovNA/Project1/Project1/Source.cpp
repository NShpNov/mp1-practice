#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>

int main() {
	string filename;
	cin >> filename;
	lib studs(filename);
	cout << "all students:"<< studs << endl;
	while (1) {
		char a;
		cout << "how to find?" << endl;
		cin >> a;
		names d;
		string b;
		date c;
		student tmp;
		switch (a) {
			case'n':
			case'N':
				cin >> d;
				try {
					tmp = studs.find_stud<names>(d);
					cout << tmp << endl;
				}
				catch (const char* s) { cout << s << endl; }
				break;
			case'p':
			case'P':
				cin >> b;
				try {
					tmp = studs.find_stud<string>(b);
					cout << tmp << endl;
				}
				catch (const char* s) { cout << s << endl; }
				break;
			case'B':
			case'b':
				cin >> c;
				try {
					tmp = studs.find_stud<date>(c);
					cout << tmp << endl;
				}
				catch (const char* s) { cout << s << endl; }
				break;
			case'e':
			case'E':
				return 0;
		}
	}
}