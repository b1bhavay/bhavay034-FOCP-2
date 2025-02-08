#include <iostream>
using namespace std;

int main() {
    string str;
    
    cout << "Enter sentence: "<<endl;
  
    getline(cin, str);
    
    cout << "You'r entered string: " << str << endl;
    
    return 0;
}

int main() {
    
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string nwstrin = "";
    for (char c : str) {
        if (c != ' ') {
   
            if (c >= 'A' && c <= 'Z') {
            c += 32;
            nwstrin += c;
            }
        }
    }

    int n = nwstrin.length();
    bool palindrome = true;
    for (int i = 0; i < n / 2; i++) {
        if (nwstrin[i] != nwstrin[n - i - 1]) {
            palindrome = false;
            break;
        }
    }

    if (palindrome) {
        cout << "The string is palindrome" << endl;
    } else {
        cout << "The string is not palindrome";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter string ";
    getline(cin, str);

    int freq[256] = {0}; 

  
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') 
        freq[str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << char(i) << ": " << freq[i] << endl;
}
}

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter string ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        char c = tolower(str[i]); 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            str[i] = '*'; 
        }
    }

    cout << "new updated string after changes: " << str;

    return 0;
}