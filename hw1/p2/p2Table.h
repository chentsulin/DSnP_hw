#ifndef P2_TABLE_H
#define P2_TABLE_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Row
{
public:
   const int operator[] (size_t i) const { } // TODO
   int& operator[] (size_t i) { } // TODO

private:
   int  *_data;
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
   vector<Row>  _rows;
};

istream& safeGetline(istream& is, string& t);

vector<string> split(const string &s, char delim);

vector<int> string2Int(const vector<string> strings, char defaultValue);

#endif // P2_TABLE_H
