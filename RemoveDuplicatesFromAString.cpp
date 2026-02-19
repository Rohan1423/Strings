#include <iostream>
#include <unordered_set>
using namespace std;

string removeDuplicatesBrute(string s) {  // T.C: O(n²) → because for each char we scan result   S.C : O(n) → for result string
    string result = "";
    for (char c : s) {
        bool found = false;
        for (char r : result) {
            if (r == c) {  // already stored in result skip
                found = true;
                break;
            }
        }
        if (!found)
            result += c;
    }
    return result;
}

string removeDuplicatesASCII(string s) {  // Faster than unordered_set because array lookup is O(1) Still O(n) time, O(1) extra space (256 is constant)
    bool freq[256] = {0}; // for all ASCII characters
    string result = "";

    for (char c : s) {
        if (!freq[c]) {
            result += c;
            freq[c] = true;
        }
    }

    return result;
}


string removeDuplicatesHash(string s) {  // T.C : O(n) → each char checked once S.C : O(1) → if only lowercase letters, we can use bool freq[256] instead of set
    unordered_set<char> seen;
    string result = "";

    for (char c : s) {
        if (seen.find(c) == seen.end()) { // if not seen before then only insert
            result += c;
            seen.insert(c);
        }
    }

    return result;
}

int main() {
    string s = "programming";
    cout << "After removing duplicates: " << removeDuplicatesBrute(s) << endl;
    return 0;
}
