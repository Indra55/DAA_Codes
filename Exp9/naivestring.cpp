#include <iostream>
#include <string>
using namespace std;

void naiveSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text, pattern;
    
    cout << "Enter text: ";
    cout.flush();
    cin >> text;

    cout << "Enter pattern: ";
    cout.flush();
    cin >> pattern;

    naiveSearch(text, pattern);

    return 0;
}
