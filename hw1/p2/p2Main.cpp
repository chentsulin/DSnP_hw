#include <iostream>
#include <string>
#include "p2Table.h"

using namespace std;

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

   // TODO: read and execute commands
   while (true) {
   	string command;
    	getline(cin, command);
   	cout << command;
   	if (command == "PRINT")
   	{
   		table.print();
   	}
   	else if (command == "SUM")
   	{
   		table.sum();
   	}
   	else if (command == "AVE")
   	{
   		table.ave();
   	}
   	else if (command == "MAX")
   	{
   		table.max();
   	}
   	else if (command == "MIN")
   	{
   		table.min();
   	}
   	else if (command == "COUNT")
   	{
   		table.count();
   	}
   	else if (command == "ADD")
   	{
   		table.add("-", "10");
   	}
   }
}
