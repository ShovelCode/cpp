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
  
  cout << "ENTER YOUR MESSAGE";

  //taking in put from user to write to test.dat file
  
  cin >> message;
  
  for(int i = 0; i < 10000; i++ ){
    
  file << message << i << endl;
}
  //We need to close every file which you open.
  file.close();

  cout << "file written!";

}
