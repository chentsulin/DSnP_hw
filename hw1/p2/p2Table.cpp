#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "p2Table.h"


using namespace std;


/*********
 *
 * Row
 *
 *********/

/* Constructor */

Row::Row(int *data, int length) {
	_data = data;
	_length= length;
}

/* Operator Overloading */

const int
Row::operator[] (size_t i) const {
	return _data[i];
}

int& Row::operator[] (size_t i) {
	return _data[i];
}

/* Instance Method */

int Row::size() {
	return _length;
}

/*********
 *
 * Table
 *
 *********/

/* Class Method */

bool
Table::read(const string& csvFile)
{
	ifstream ifs(csvFile);

	if (!ifs) return false;

 	while (!ifs.eof()) {
 		string line;

 		safeGetline(ifs, line);
 		if (line.empty()) continue;

 		vector<string> splitValue = split(line, ',');

 		int length = splitValue.size();
		int *ints = new int[length];
		for (int i = 0, len = length; i < len; i++) {
			cout << splitValue.at(i) << endl;
			int num = atoi(splitValue.at(i).c_str());
			ints[i] = num;
		}

		Row row(ints, length);
		_rows.push_back(row);
	}

	ifs.close();

  	return true;
}

/* Operator Overloading */

const Row&
Table::operator[] (size_t i) const {
	return _rows[i];
}

Row& Table::operator[] (size_t i) {
	return _rows[i];
}


void
Table::print()
{
	for (int i = 0, len = _rows.size(); i < len; i++) {
		Row row = _rows[i];
		for (int j = 0; j < row.size(); j++)
		{
			if (row[j] == -100)
			{
				cout << setw(4) << right << "";
			}
			else
			{
				cout << setw(4) << right << row[j];
			}
		}
		cout << endl;
	}
}

int
Table::sum(int index)
{
	int acc = 0;
	for (int i = 0, len = _rows.size(); i < len; i++) {
		Row row = _rows[i];
		if (row[index] != -100) acc += row[index];
	}
	return acc;
}

double
Table::ave(int index)
{
	int size = _rows.size();
	return (double) sum(index) / size;
}

int
Table::max(int index)
{
	int maxValue = -100;
	for (int i = 0, len = _rows.size(); i < len; i++) {
		Row row = _rows[i];
		if (row[index] != -100 && row[index] > maxValue) {
			maxValue = row[index];
		}
	}
	return maxValue;
}

int
Table::min(int index)
{
	int minValue = 101;
	for (int i = 0, len = _rows.size(); i < len; i++) {
		Row row = _rows[i];
		if (row[index] != -100 && row[index] < minValue) {
			minValue = row[index];
		}
	}
	return minValue;
}

int
Table::count(int index)
{
	vector<int> ints;

	for (int i = 0, len = _rows.size(); i < len; i++) {
		Row row = _rows[i];
		if (row[index] != -100) {
			bool same = false;
			for (int j = 0; j < ints.size(); j++)
			{
				if (ints.at(j) == row[index])
				{
					same = true;
				}
			}
			if (!same) {
				ints.push_back(row[index]);
			}
		}
	}
	return ints.size();
}

void
Table::add(vector<string> &args)
{
	int length = args.size();
	int *ints = new int[length];

	for (int i = 0; i < length; i++)
	{
		ints[i] = args.at(i) == "-" ?
			-100 : atoi(args.at(i).c_str());
	}

	Row row(ints, length);
	_rows.push_back(row);
}


// From http://stackoverflow.com/a/6089413/3012290
istream& safeGetline(istream& is, string& t)
{
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.

    istream::sentry se(is, true);
    streambuf* sb = is.rdbuf();

    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
        case '\n':
            return is;
        case '\r':
            if(sb->sgetc() == '\n')
                sb->sbumpc();
            return is;
        case EOF:
            // Also handle the case when the last line has no line ending
            if(t.empty())
                is.setstate(ios::eofbit);
            return is;
        default:
            t += (char)c;
        }
    }
}

// From http://stackoverflow.com/a/2025273/3012290
vector<string> split(const string &s, char delim) {
	vector<string> words;
    int i = 0;
    char ch = s[i];
    string word;
    while (ch) {
    	if (isspace(ch)) {
    		if (!word.empty())
			{
				words.push_back(word);
				word = "";
			}
    	}
    	else if (ch == delim)
    	{
    		if (word.empty())
			{
				word = "-100";
			}
			words.push_back(word);
			word = "";
    	}
    	else
    	{
    		word += ch;
    	}
    	i++;
    	ch = s[i];
    }
    if (word.empty())
	{
		word = "-100";
	}
	words.push_back(word);
	return words;
}
