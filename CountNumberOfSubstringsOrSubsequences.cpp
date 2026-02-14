#include <iostream>
using namespace std;

long long countSubstrings(string s) {  // T.C O(1) S.C O(1)
    long long n = s.length();
    return n * (n + 1) / 2;
}

long long countSubsequences(string s) {  // T.C O(1) S.C O(1)
    long long n = s.length();
    return pow(2, n) - 1;  // excluding empty
}

int main() {
    string s;
    cin >> s;
    cout << "Total Substrings: " << countSubstrings(s);
    cout << "Total Substrings: " << countSubsequences(s);
}


// Feature	            Substring	Subsequence
// Continuous?	        Yes	         No
// Formula	            n(n+1)/2	2^n
// Example for "abc"	6	        7