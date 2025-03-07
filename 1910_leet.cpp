#include<bits/stdc++.h>

using namespace std;

string removeOccurrences(string s, string sub) {
    int n = sub.size();
    string ans = "";
        while(s.find(sub) != string::npos){
            size_t found = s.find(sub);
            s.erase(s.begin()+found,s.begin()+found+n);
        }
        return s;
}

int main(){
    string str = "axxxxyyyyb";
    string sub = "xy";
    cout<<removeOccurrences(str,sub);
}