#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello World";
    int vowels = 0, consonants = 0;

    for (char ch : s) {  // T.C O(n) S.C O(1)

        // Check if character is an alphabet
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {

            // Convert to lowercase for easy comparison
            char c = tolower(ch);

            // Check vowel
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    return 0;
}
