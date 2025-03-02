#include <iostream>
#include <fstream>
#include <map>
#include <cctype> 
using namespace std;

void printBarChart(const map<char, int>& freqMap) {
    cout << "\nCharacter Frequency Bar Chart:\n";
    freqMap
    for (const auto& pair : freqMap) {
        cout << pair.first << " : " << string(pair.second, '*') << " (" << pair.second << ")\n";
    }
}

int main() {
    ifstream file("example.txt");
    if (!file) {
        cerr << "Error: Could not open the file!\n";
        return 1;
    }

    map<char, int> charCount;
    char ch;

    while (file.get(ch)) {
        if (isalpha(ch)) { 
            ch = tolower(ch); 
            charCount[ch]++;
        }
    }

    file.close();

    printBarChart(charCount);

    return 0;
}
