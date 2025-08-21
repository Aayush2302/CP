#include <bits/stdc++.h>
using namespace std;

int finddistinct(const string& s){
    unordered_map<char, int> freq;
    for(char c : s){
        freq[c]++;
    }
    return freq.size();
}

int distChar(string s, int k){
    int windowstart = 0;
    int maxLength = 0 ;

    for(int i = windowstart; i < s.length(); i++){
        string temp = "";
        temp += s[i];
        int distinct = finddistinct(temp);
        int j = i + 1;
        while(j < s.length() && distinct <= k){
            temp += s[j];
            distinct = finddistinct(temp);
            if (distinct <= k) {
                int tempLength = j - windowstart + 1;
                maxLength = max(maxLength, tempLength);
            }
            j++;
        }
        windowstart++;
    }
    return maxLength;
}

int main()
{
    string s = "araaci";
    int k = 2;
    cout << distChar(s, k) << endl; // Output: 6
}
