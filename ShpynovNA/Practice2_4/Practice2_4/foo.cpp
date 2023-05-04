#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>

TCrate::TCrate(int n) {
	this->capacity = n;
	this->size = 0;
	this->elem = new product[n];
}
TCrate::~TCrate() {
	delete[] this->elem;
}
TList::TList() {
	this->prods = new product[this->max_len];
}
TList::~TList() {
	delete[] this->prods;
}
void TCrate::append_crate(int app) {
	unsigned short tmp = this->max_len;
	TCrate::~TCrate();

}