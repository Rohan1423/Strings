
#include <iostream>
#include <algorithm>
using namespace std;


bool isAnagram(string s1, string s2 ){  // Sorting T.C O(n log n) S.C O(1)
    if(s1.length() != s2.length()){
        return false;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    return s1 == s2;
}

bool isAnagramOptimal(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    int freq[256] = {0};
    
    for(int i=0; i<s1.length(); i++){  // After full loop:Every character incremented once and decremented once.
        freq[s1[i]]++;                 // So all freq values become 0.
        freq[s2[i]]--;                 // It actually becomes --> freq[(int)s1[i]]++;
    }                                  // s1[0] = 'a' ASCII of 'a' = 97 So:freq[97]++

    for(int i=0; i<s1.length(); i++){  // If ANY frequency is not 0 → mismatch exists.
        if(freq[s1[i]] !=0){
            return false;
        }
    }
    return true;

}


int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (isAnagramOptimal(s1, s2))
        cout << "Anagram";
    else
        cout << "Not Anagram";

    return 0;
}

// What is an Anagram?

// Two strings are anagrams if:

// They contain the same characters

// With the same frequency

// Order does NOT matter
