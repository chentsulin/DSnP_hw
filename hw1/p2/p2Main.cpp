#include <iostream>
#include <string>
#include "p2Table.h"

using namespace std;

vector<string> parseCommand(const string &command);

int main()
{
   Table table;

   // TODO: read in the csv file
   string csvFile;
   cout << "Please enter the file name: ";
   cin >> csvFile;
   if (table.read(csvFile))
      cout << "File \"" << csvFile << "\" was read in successfully." << endl;
   else exit(-1); // csvFile does not exist.

   cin.ignore(INT_MAX, '\n');

   while (true) {
   	cout << "Please enter your command (PRINT, SUM, AVE, MAX, MIN, COUNT, ADD, EXIT)" << endl;

   	string command;
    	getline(cin, command);

    	vector<string> args = parseCommand(command);
    	string arg1 = args.at(0);

   	if (arg1 == "PRINT")
   	{
   		table.print();
   	}
   	else if (arg1 == "SUM")
   	{
   		string columnIndex = args.at(1);
   		int result = table.sum(atoi(columnIndex.c_str()));
   		cout << "The summation of data in column #" << columnIndex << " is " << result << "." << endl;
   	}
   	else if (arg1 == "AVE")
   	{
   		string columnIndex = args.at(1);
   		double result = table.ave(atoi(columnIndex.c_str())); //
   		cout << "The average of data in column #" << columnIndex << " is " << result << "." << endl;
   	}
   	else if (arg1 == "MAX")
   	{
   		string columnIndex = args.at(1);
   		int result = table.max(atoi(columnIndex.c_str()));
   		cout << "The maximum of data in column #" << columnIndex << " is " << result << "." << endl;
   	}
   	else if (arg1 == "MIN")
   	{
   		string columnIndex = args.at(1);
   		int result = table.min(atoi(columnIndex.c_str()));
   		cout << "The minimum of data in column #" << columnIndex << " is " << result << "." << endl;
   	}
   	else if (arg1 == "COUNT")
   	{
   		string columnIndex = args.at(1);
   		int result = table.count(atoi(columnIndex.c_str()));
   		cout << "The distinct count of data in column #" << columnIndex << " is " << result << "." << endl;
   	}
   	else if (arg1 == "ADD")
   	{
   		args.erase(args.begin());
   		table.add(args);
   	}
   	else if (arg1 == "EXIT")
   	{
   		exit(0);
   	}
   }
}

vector<string> parseCommand(const string &command) {
	vector<string> args;
	int i = 0;
	int size = command.size();
	string arg;
	while (i < size)
	{
		char ch = command[i];
		if (isspace(ch))
		{
			args.push_back(arg);
			arg = "";
		}
		else
		{
			arg += ch;
		}
		i++;
	}
	args.push_back(arg);

	return args;
}
