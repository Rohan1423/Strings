// The Knuth–Morris–Pratt Algorithm (KMP) is an efficient pattern matching algorithm used to find a substring inside a string.
// It avoids re-checking characters by using previous match information.


// 1 Problem
// Find pattern P inside text T.

// Example:

// Text:    ABABDABACDABABCABAB
// Pattern: ABABCABAB
// Output → index 10


// 2 Idea Behind KMP

// Normal matching (brute force):
// Text:    ABABDABACDABABCABAB
// Pattern: ABABCABAB
// If mismatch happens, brute force moves pattern by 1 and starts again.
// KMP instead uses a prefix table (LPS array) to skip unnecessary comparisons.


// 3 LPS Array (Longest Prefix Suffix)

// LPS means:
// Longest Proper Prefix which is also a Suffix

// Example pattern:

// Pattern = ABABCABAB
// Index	Char	LPS
// 0	A	0
// 1	B	0
// 2	A	1
// 3	B	2
// 4	C	0
// 5	A	1
// 6	B	2
// 7	A	3
// 8	B	4

// Meaning:
// ABAB
// has prefix "AB" and suffix "AB" → length 2


// 4 KMP Algorithm Steps:
// Build LPS array from pattern
// Compare text and pattern
// If mismatch → use LPS to shift pattern

#include <iostream>
#include <vector>
using namespace std;

void computeLPS(string pattern, vector <int> &lps){
    int len=0; // length of previous longest prefix suffix
    lps[0]=0;  // Because single character has no prefix-suffix.

    int i=1; // current index in pattern
    while(i<pattern.length()){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len !=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMPSearch(string text, string pattern) {

    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);

    computeLPS(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {

        if (text[i] == pattern[j]) { // If characters match: Move both pointers forward.
            i++;
            j++;
        }

        if (j == m) { // j reached pattern length, So the entire pattern matched.
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // Instead of resetting j = 0, we reuse prefix info.
        }

        else if (i < n && text[i] != pattern[j]) { // Mismatch occurred.

            if (j != 0)
                j = lps[j - 1];
            else
                i++; // If mismatch happens at the first character, nothing matches, So move text pointer.
        }
    }
}

int main() { 
    string text = "ABABDABACDABABCABAB"; 
    string pattern = "ABABCABAB"; 
    KMPSearch(text, pattern); 
    return 0; 
}

// ==> Complexity
//  Metric	Value
//  Time	O(n + m)
//  Space	O(m)

// Where:
// n = text length
// m = pattern length

// 5 Why KMP Is Powerful

// Normal search:
// Worst case = O(n × m)

// Example worst case:
// Text:    AAAAAAAAAAAAA
// Pattern: AAAAB
// KMP avoids rechecking characters → O(n + m).

// 6 Real-World Use Cases

// KMP is used in:
// Text editors (Find feature)
// DNA sequence search
// Search engines
// Plagiarism detection