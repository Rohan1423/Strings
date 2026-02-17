// Given a string s, compress it such that consecutive repeated characters are replaced by the character followed by the count.
// Example:
// "aaabbc" → "a3b2c1"

#include <iostream>
#include <string>
using namespace std;

string compressString(string s) {  // T.C O(n), S.C O(n)
    int n = s.length();
    string result = "";

    int i = 0;
    while (i < n) {
        char current = s[i];
        int count = 0;

        // Count consecutive same characters
        while (i < n && s[i] == current) {
            count++;
            i++;
        }

        result += current + to_string(count);
    }

    return result;
}

string compressStringOptimal(string s) {  // T.C O(n), S.C O(1) extra
    int n = s.length();
    if (n==0) return "";

    string result = "";
    int count = 1;

    for(int i=1; i<n; i++){
        if(i<n && s[i]==s[i-1]){
            count++;
        }
        else{
            result +=s[i-1];
            result += to_string(count);
            count = 1;
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    cout << "Compressed String: " << compressString(s) << endl;
    cout << "Compressed String: " << compressStringOptimal(s) << endl;
    return 0;
}


// “S.C O(1) extra”, they usually ignore the memory used to store the output string, only counting temporary memory for computation.