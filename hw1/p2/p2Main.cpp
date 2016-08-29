#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  // Table table;

  string filename;
  cout << "Please enter the file name: ";
  cin >> filename;

  ifstream ifs(filename);

  if (!ifs) {
    cout << "Read file failed" << endl;
    return 1;
  }

  while (!ifs.eof()) {
    string line; 
    getline(ifs, line);
    cout << line << endl;
  }

  ifs.close();

  cout << "File “" << filename << "” was read in successfully." << endl; 
 
  while (true) { 
    string command;
    getline(cin, command);
    cout << command;
  }

  return 0;
}
