#include <iostream>
#include <fstream>
#include <string>
#include "p2Table.h"


using namespace std;


// Implement member functions of class Row and Table here
Row::Row(vector<int>& ints) {
	int length = ints.size();
	_data = new int[length];
	for (int i = 0; i < length; i++)
	{
		_data[i] = ints.at(i);
	}
}

Row::Row(int *ints) {
	_data = ints;
}

const int
Row::operator[] (size_t i) const {
	return _data[i];
}

bool
Table::read(const string& csvFile)
{
	ifstream ifs(csvFile);

	if (!ifs) return false;

 	while (!ifs.eof()) {
 		string line;

 		safeGetline(ifs, line);
 		cout << line << endl;

 		vector<string> splitValue = split(line, ',');
 	// 	for (decltype(splitValue.size()) i = 0; i < splitValue.size(); ++i)
	//  {
  	//   	cout << splitValue[i] << endl;
	//  }
		int *ints = new int[splitValue.size()];
		for (int i = 0, len = splitValue.size(); i < len; i++) {
			cout << splitValue.at(i) << endl;
			int num = atoi(splitValue.at(i).c_str());
			ints[i] = num;
		}
		// for (decltype(ints.size()) i = 0; i < ints.size(); ++i)
		// {
  //   		cout << ints[i] << endl;
		// }
		Row row(ints);
		_rows.push_back(row);
	}

	ifs.close();

  	return true;
}


void
Table::print()
{
	cout << "123" << endl;
}

int
Table::sum()
{
	return 1;
}

double
Table::ave()
{
	return 1;
}

int
Table::max()
{
	return 1;
}

int
Table::min()
{
	return 1;
}

int
Table::count()
{
	return 1;
}

void
Table::add(string left, string right)
{

}

void
Table::exit()
{
	std::exit(0);
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

// From http://stackoverflow.com/a/236803/3012290
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

void stringToInt(const vector<string> &strings) {
	// cout << "size: " << strings.size() << endl;
	// int *ints = new int[1];
	// for (int i = 0, len = strings.size(); i < len; i++) {
	// 	cout << strings.at(i) << endl;
	// 	int num = atoi(strings.at(i).c_str());
	// 	ints[i] = num;
	// }
	// return ints;
};
