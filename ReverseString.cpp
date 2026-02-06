#include <iostream>
#include <string>
using namespace std;

void reverseString(string &str){  // Two Pointer T.C O(n) S.C O(1)
    int left=0;
    int right=str.length()-1;
    while(left<right){
        swap(str[left],str[right]); // Swap characters at left and right
        left++;
        right--;
    }
}

void reverseStringRec(string &s, int left, int right) {  // Recursion T.C O(n) S.C O(n) stack
    if (left >= right) return;  // Base case

    swap(s[left], s[right]);
    reverseStringRec(s, left + 1, right - 1);
}

int main() {
    string str = "hello";
    // reverseString(str);
    reverseStringRec(str, 0, str.length() - 1);
    cout << "Reversed string: " << str << endl;  // Output: olleh
    return 0;
}