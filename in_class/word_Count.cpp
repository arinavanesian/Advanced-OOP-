#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

int main(){
string myText;

// Read from the text file
ifstream MyReadFile("two_gang.txt");

// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
  cout << myText;
}

// Close the file
MyReadFile.close();
}
