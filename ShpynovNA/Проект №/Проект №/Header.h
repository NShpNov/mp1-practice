#ifndef HEADER_H
#define HEADER_H

using namespace std;

class vect {
private:
	double x;
	double y;
	double z;
public:
	vect();
	vect(int a, int b, int c);
	vect operator+(const vect& v);
	vect operator-(const vect& v);
	vect operator=(const vect& v);
	double operator*(const vect& v) const;
	friend istream& operator>>(istream& in,vect& l) {
		in >> l.x >> l.y >> l.z;
		return in;
	}
	friend ostream& operator<<(ostream& out, const vect& l) {
			out <<"(" << l.x << ", " << l.y << ", " << l.z <<")";
		return out;
	}

	double length() const;
	double cosine(vect& v) const;
};

class lib {
private:
	vect* vectors;
	int n;
public:
	lib();
	lib(int a);
	~lib();

	vect& operator[](int ind);
	friend ostream& operator<<(ostream& out, const lib& l) {
		for (int i = 0; i < l.n; i++) {
			out << endl << l.vectors[i];
		}
		out << endl;
		return out;
	}
};

#endif // !HEADER_H
