#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
  //opening a file in writing mode which is default.
  ofstream file;
  string message;
  file.open("text.txt");
  
  cout << "ENTER YOUR MESSAGE: "; //avoid whitespace

  //taking in put from user to write to test.dat file
  
  cin >> message;
  file << message << endl;

  //We need to close every file which you open.
  file.close();

  cout << "file written!";

}
