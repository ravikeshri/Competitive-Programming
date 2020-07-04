/*
"Knuth - Morris - Pratt (KMP)" Algorithm for
pattern searching, O(n + m)

Impementation of strStr()

*/

#include<bits/stdc++.h>

using namespace std;

int kmp(string str, string pat, vector<int> &lps) {
    int m = str.length(), n = pat.length();
    
    int i = 0, j = 0;
    while(i < m) {
        
        if(str[i] == pat[j]) {
            i++, j++;
        } else {
            if(j == 0) {
                i++;
            } else {
                j = lps[j-1];
            }
        }
        if(j >= n) {
            return i-n;
        }
    }
    
    return -1;
}

vector<int> findLPS(string pat) {
    int n = pat.size();
    vector<int> lps(n);
    
    lps[0] = 0;
    
    int i = 0, j = 1;
    while(j < n) {
        
        if(pat[i] == pat[j]) {
            lps[j] = i+1;
            i++, j++;
        } else {
            
            if(i == 0) {
                lps[j] = 0;
                j++;
            } else {
                i = lps[i-1];
            }
        }
    }
    return lps;
}

int main() {
    string str = "aabaaabaaac";
    string pat = "aabaaac";
    // string str = "ABAABCXABCXABXA";
    // string pat = "ABCXABX";
    int n = pat.size();
    
    // LPS = longest suffix which is also a prefix
    vector<int> lps = findLPS(pat);
    
    cout << kmp(str, pat, lps);

    return 0;
}