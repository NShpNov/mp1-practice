#ifndef HEADER_H
#define HEADER_H

using namespace std;

typedef class TDate {
private:
	int day;
	int month;
	int year;
public:
	void find_date();
	void get_date(int* day_dest, int* month_dest, int* year_dest);
} date;

class TTime {
private:
	int hour;
	int min;
	int sec;
public:
	void find_time();
	void get_time(int* hour_dest, int* min_dest, int* sec_dest);
};

typedef class TProduct {
private:
	string code;
	string name;
	double price;
public:
	void get_info(string* code_dest, string* name_dest, double* price_dest);
} product;

template <class T>
class TCrate {
private:
	void resize(int app = 1,int from = -1) {
		T* old = storage;
		storage = new T[](capacity + app);
		if (from == -1)
			this->shift(0, 0, old);
		else
			this->shift(from, 1, old);

		capacity += app;
		delete[] old;
	};


	void shift(int from, int direction=0, T* source=NULL)
	{
		if (!source)
			source = this->storage;

		for (int i = (source == storage ? from : 0); i < size; i++ ) 
		{
			int pos = (direction && i < from) ? i : i + direction;
			storage[pos] = source[i];
		}
		size += direction;
	}

protected:
	unsigned short capacity;
	unsigned short size;
	T* storage;
public:
	TCrate(int n = 0);
	~TCrate();
	
	void append(const T& obj)
	{
		insert(size, obj);
	}

	void undo() {
		remove(size)
	}

	void remove(int i)
	{
		shift(i, -1);
	}

	void insert(int i, const T& item) {
		if (size == capacity)
			resize(1, i);
		else
			shift(i, 1);

		storage[i] = item;
	}

};

class TCheck: public TCrate <product> {
private:
	string list_number;
	date creation_date;
	TTime creation_time;
public:
	void add_prod(product added_prod);
	void change_prod(product new_prod, int n);
	void delete_prod(int n);
	product show_prod_info(string entered_code);
};

#endif // !HEADER_H
