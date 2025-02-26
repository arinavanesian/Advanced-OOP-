#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <map>
#include <ostringstream>
using namespace std;

int main(){
ifstream file("two_gang.txt");
string token;
map<string, int> hist;
ostringstream sentence;
vector<string> text;

while (file >> token){
if(token == ".") {
cout << sentence.str() << endl;
text.push_back(sentence.str());
sentence.str("");
}

else{
hist[token]++;
sentence << format(" {} ",token);
}
}

}
file.close()
