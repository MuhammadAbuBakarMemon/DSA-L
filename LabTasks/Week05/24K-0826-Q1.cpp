#include <iostream>
#include <string>
using namespace std;

int countChar(const string& str, char target, int index = 0) {
    if (index >= str.length()) {
        return 0;
    }
    
    if (str[index] == target) {
        return 1 + countChar(str, target, index + 1);
    } else {
        return countChar(str, target, index + 1);
    }
}

int countCharSubstring(const string& str, char target) {
    if (str.empty()) {
        return 0;
    }
    
    if (str[0] == target) {
        return 1 + countCharSubstring(str.substr(1), target);
    } else {
        return countCharSubstring(str.substr(1), target);
    }
}

int main() {
    string text = "assalam u alaikum";
    char target = 'l';
    
    cout << countChar(text, target) << endl;
    cout << countCharSubstring(text, target) << endl;
    
    return 0;
}