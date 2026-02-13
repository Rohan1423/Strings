#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

int lengthOfLongestSubstringUsingSet(string s) {  // Brute Force T.C O(n x n) S.C O(n)
    int n = s.length();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<char> st;

        for (int j = i; j < n; j++) {
            if (st.find(s[j]) != st.end())
                break;

            st.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

int lengthOfLongestSubstringUsingIndexMap(string s) {  // Optimal Approach (Sliding Window) T.C O(n) S.C O(n)
    unordered_map<char, int> mp;
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
            left = mp[s[right]] + 1;
        }

        mp[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int lengthOfLongestSubstringIfASCII(string s) {  // Even Faster Version (ASCII Only) T.C O(n)  S.C O(1)
    vector<int> last(256, -1);
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        if (last[s[right]] >= left) {
            left = last[s[right]] + 1;
        }
        last[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;   // For single word input
    // getline(cin, s);  // Use this if input may contain spaces

    cout << "\nBrute Force Result: "
         << lengthOfLongestSubstringUsingSet(s) << endl;

    cout << "Sliding Window Result: "
         << lengthOfLongestSubstringUsingIndexMap(s) << endl;

    cout << "ASCII Optimized Result: "
         << lengthOfLongestSubstringIfASCII(s) << endl;

    return 0;
}
