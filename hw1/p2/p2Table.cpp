#include <iostream>
#include <fstream>
#include <string>
#include "p2Table.h"


using namespace std;

// Implement member functions of class Row and Table here

bool
Table::read(const string& csvFile)
{
	ifstream ifs(csvFile);

	if (!ifs) return false;

 	while (!ifs.eof()) {
 		string line;
 		safeGetline(ifs, line);
		split(line, ',');
	}

	ifs.close();

  	return true; // TODO
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
