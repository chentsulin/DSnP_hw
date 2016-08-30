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
 		cout << "1" << endl;
 		string line;
 		getline(ifs, line);
		cout << line << endl;
	}

	ifs.close();

  	return true; // TODO
}
