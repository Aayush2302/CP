#include <bits/stdc++.h>

using namespace std;

string decodeString(string s) {
    stack<int>st;
    string res = "";
    string temp = "";

    for(int i = 0; i< s.size(); i++){
        if(s[i] != ']'){
            st.push(s[i]);
        }
        else(
            while(s[i]!='['){
                temp.append(s[i]);
            }
            int n = st.top();
            for(int j = 0; j< n;j++){
                
            }
        )
    }
    
}

int main(){

}