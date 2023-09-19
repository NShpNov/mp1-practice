#include <iostream>
#include "Header.h"
#include <math.h>

vect::vect(){}
vect::vect(int a, int b, int c) {
	x = a;
	y = b;
	z = c;
}

vect& vect::operator+(const vect& v){
	vect tmp;
	tmp.x = x + v.x;
	tmp.y = y + v.y;
	tmp.z = z + v.z;
	return tmp;
}
vect& vect::operator-(const vect& v) {
	vect tmp;
	tmp.x = x - v.x;
	tmp.y = y - v.y;
	tmp.z = z - v.z;
	return tmp;
}
double vect::length() {
	return sqrt((x * x + y * y + z * z));
}
double vect::operator*(const vect& v) {
	return(x * v.x + y * v.y + z * v.z);
}
double vect::cosine(vect& v) {
	double tmp = length() * v.length();
	return ((x * v.x + y * v.y + z * v.z) / (length() * v.length()));
}

lib::lib(){}
lib::lib(int a) {
	n = a;
	vectors = new vect[a];
	for (int i = 0; i < a; i++) {
		cout << "enter " << i << " vector: ";
		int x, y, z;
		cin >> x >> y >> z;
		vectors[i] = vect(x, y, z);
	}
}
lib::~lib() {
	delete[] vectors;
}

vect& lib::operator[](int ind) {
	return vectors[ind];
}