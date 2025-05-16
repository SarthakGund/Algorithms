#include <bits/stdc++.h>
using namespace std;

// Build the LPS (Longest Prefix Suffix) array
vector<int> buildLPS(string pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;

    // string text = "abxabcaabcaby";
    // string pattern = "aabcaby";

    for (int i = 1; i < n; ) {
        cout << pattern[i] << " " << pattern[len] << " " << lps[i] << endl; 
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }

    return lps;
}

// KMP search function
void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = buildLPS(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text = "abxabcaabcaby";
    string pattern = "aabcaby";

    vector<int>v = buildLPS(pattern);

    for(auto &i: v) cout << i << " ";
    cout << endl;

    KMPSearch(text, pattern);

    return 0;
}
