#include <iostream>
using namespace std;

int compareStrings(string s1, string s2) { // T.C O(min(n, m)) S.C : O(1)
    int n1 = s1.length();
    int n2 = s2.length();
    int minLen = min(n1, n2);

    for (int i = 0; i < minLen; i++) {
        if (s1[i] < s2[i])
            return -1;  // s1 comes before
        else if (s1[i] > s2[i])
            return 1;   // s1 comes after
    }

    // If all characters same so far
    if (n1 < n2) return -1;
    if (n1 > n2) return 1;

    return 0; // Equal
}

int main() {
    string s1 = "cat";
    string s2 = "car";

    int result = compareStrings(s1, s2);

    if (result == 0)
        cout << "Equal\n";
    else if (result < 0)
        cout << "s1 comes before s2\n";
    else
        cout << "s1 comes after s2\n";

    return 0;
}
