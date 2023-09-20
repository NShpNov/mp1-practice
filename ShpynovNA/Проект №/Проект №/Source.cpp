#include <iostream>
#include "Header.h"
#include <math.h>

int main() {
	int n, num, num1;
	cout << "vectors: ";
	cin >> n;
	lib libary = lib(n);
	do {
		char a;
		cout << "action: ";
		cin >> a;
		vect tmp;
		double tmpd;
		switch (a) {
		case'l':
		case'L':
			cout << "choose vector: ";
			cin >> num;
			if (num < n) {
				cout << libary[num] << "'s length: " << libary[num].length() << endl;
			}
			else cout << "not found";
			break;
		case'A':
		case'a':
			cout << "choose vectors: ";
			cin >> num >> num1;
			if ((num < n) && (num1 < n)) {
				tmp = (libary[num] + libary[num1]);
				cout << libary[num] << "'s and "
					<< libary[num1] << "'s sum is "
					<< tmp << endl;
			}
			else cout << "not found";
			break;
		case'S':
		case's':
			cout << "choose vectors: ";
			cin >> num >> num1;
			if ((num < n) && (num1 < n)) {
				tmp = (libary[num] - libary[num1]);
				cout << libary[num] << "'s and "
					<< libary[num1] << "'s difference is "
					<< tmp << endl;
			}
			else cout << "not found";
			break;
		case'M':
		case'm':
			cout << "choose vectors: ";
			cin >> num >> num1;
			if ((num < n) && (num1 < n)) {
				tmpd = (libary[num] * libary[num1]);
				cout << libary[num] << "'s and "
					<< libary[num1] << "'s dot product is "
					<< tmpd << endl;
			}
			else cout << "not found";
			break;
		case'C':
		case'c':
			cout << "choose vectors: ";
			cin >> num >> num1;
			if ((num < n) && (num1 < n)) {
				tmpd = (libary[num].cosine(libary[num1]));
				cout <<"cosine between" << libary[num] << " and "
					<< libary[num1] << " is "
					<< libary[num].cosine(libary[num1]) << endl;
			}
			else cout << "not found";
			break;
		case 'v':
		case 'V':
			cout << "choose vector: ";
			cin >> num;
			if (num < n) {
				cout << "it's " << libary[num] << endl;
			}
			else cout << "not found";
			break;
		case'e':
		case'E':
			return 0;
		}

	} while (1);
}