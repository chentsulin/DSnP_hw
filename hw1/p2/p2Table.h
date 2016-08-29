#include <vector>

using namespace std;

class Row {
  public:
    const int operator[] (size_t i) const;
    int& operator[] (size_t i); 
  
  private:
    int *_data; 
};

class Table { 
  public:
    const Row& operator[] (size_t i) const;
    Row& operator[] (size_t i); 
      
  private:
    vector<Row> _rows; 
};
