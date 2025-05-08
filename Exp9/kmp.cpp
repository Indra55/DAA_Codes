#include <bits/stdc++.h>
using namespace std;

// Function to build LPS (Longest Prefix Suffix) array
vector<int> buildLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0; // length of the previous longest prefix suffix

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // try the previous longest
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to search pattern in text using KMP
void KMP(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lps = buildLPS(pattern);

    int i = 0, j = 0; // i for text, j for pattern
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // continue searching
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    KMP(text, pattern);
    return 0;
}
