#include <bits/stdc++.h>
using namespace std;

void backtrack(string &s, int index, int partCount, string path, vector<string>& ans, int depth) {
    // indent to visualize recursion depth
    string indent(depth * 2, ' ');

    // print the current state
    cout << indent << "index=" << index 
         << ", partCount=" << partCount 
         << ", path=" << path << endl;

    // base case
    if (partCount == 4 && index == s.size()) {
        ans.push_back(path.substr(0, path.size()-1)); // remove last '.'
        cout << indent << "✅ valid: " << path << endl;
        return;
    }

    if (partCount >= 4 || index >= s.size()) return;

    // try 1, 2, 3 digits
    for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
        string segment = s.substr(index, len);

        // skip invalid parts
        if ((segment.size() > 1 && segment[0] == '0') || stoi(segment) > 255) continue;

        // recurse
        backtrack(s, index + len, partCount + 1, path + segment + ".", ans, depth + 1);
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    backtrack(s, 0, 0, "", ans, 0);
    return ans;
}

int main() {
    string s = "25525511135";
    vector<string> res = restoreIpAddresses(s);

    cout << "\nAll Valid IPs:\n";
    for (auto &ip : res) cout << ip << endl;
}
