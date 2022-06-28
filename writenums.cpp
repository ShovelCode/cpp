#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
  //opening a file in writing mode which is default.
  ofstream file;
  string message;
  
  file.open("nums.txt");
  int j = 99;
  
  //may want to remove the endl
  for(int i = 0; i < 1000; i++){
    file << j + i << " " << endl;
  }  
  

  //We need to close every file which you open.
  file.close();

  cout << "file written!";

}
