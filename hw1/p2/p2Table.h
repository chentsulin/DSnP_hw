#ifndef P2_TABLE_H
#define P2_TABLE_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Row
{
public:
	Row(vector<int>& ints);
	Row(int *data, int length);

	const int operator[] (size_t i) const;
	int& operator[] (size_t i);

	int size();

private:
	int *_data;
	int _length;
};

class Table
{
public:
	const Row& operator[] (size_t i) const;
	Row& operator[] (size_t i);

	bool read(const string&);

	void print();

	int sum();
	double ave();
	int max();
	int min();
	int count();

	void add(string left, string right);

	void exit();

private:
	vector<Row> _rows;
};

istream& safeGetline(istream& is, string& t);

vector<string> split(const string &s, char delim);

#endif // P2_TABLE_H
