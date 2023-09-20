#include <iostream>
#include "Header.h"
#include <math.h>

vect::vect(){}
vect::vect(int a, int b, int c) {
	x = a;
	y = b;
	z = c;
}

vect vect::operator+(const vect& v){
	vect tmp;
	tmp.x = x + v.x;
	tmp.y = y + v.y;
	tmp.z = z + v.z;
	return tmp;
}
vect vect::operator-(const vect& v) {
	vect tmp;
	tmp.x = x - v.x;
	tmp.y = y - v.y;
	tmp.z = z - v.z;
	return tmp;
}
vect vect::operator=(const vect& v) {
	if ((x != v.x) && (y != v.y) && (z != v.z)) {
		x = v.x;
		y = v.y;
		z = v.z;
	}
	return *this;
}
double vect::length() const {
	return sqrt((x * x + y * y + z * z));
}
double vect::operator*(const vect& v) const {
	return(x * v.x + y * v.y + z * v.z);
}
double vect::cosine(vect& v) const {
	double tmp = length() * v.length();
	return ((x * v.x + y * v.y + z * v.z) / (length() * v.length()));
}

lib::lib(){}
lib::lib(int a) {
	n = a;
	vectors = new vect[a];
	for (int i = 0; i < a; i++) {
		cout << "enter " << i << " vector: ";
		cin >> vectors[i];
	}
}
lib::~lib() {
	delete[] vectors;
}

vect& lib::operator[](int ind) {
	return vectors[ind];
}