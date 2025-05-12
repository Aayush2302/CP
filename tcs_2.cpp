#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

char firstNonRep(unordered_map<char,int>&mp,string str) 
{
    for(int i = 0; i<str.size(); i++){
        if(mp[str[i]] == 1){
            return str[i];
        }
    }
    return '\0';
}

char maxRep(unordered_map<char,int>&mp, string str){
    int maxFreq = -1;
    char maxChar = '\0';
    for (int i = str.size() - 1; i >= 0; i--) {
        if (mp[str[i]] > maxFreq) {
            maxFreq = mp[str[i]];
            maxChar = str[i];
        }
    }
    return maxChar;
}

bool isAllSame(unordered_map<char, int>& mp, string str) {
    int sum = 0, d = -1;
    for (auto x : mp) {
        if (d == -1) {
            d = x.second;
        }
        if (x.second != d) {
            return false;
        }
    }
    return true;
}

int main(){
    string str;
    cout<<"Enter String: ";
    getline(cin,str);
    unordered_map<char,int>mp;
    for(int i = 0; i< str.size(); i++){
        mp[str[i]]++;
    }
    for(auto x:mp){
        cout<<x.first<<"  "<<x.second<<endl;
    }
    cout<<firstNonRep(mp,str);
    
    if(isAllSame(mp,str)){
        cout<<"None"<<endl;
        cout<<maxRep(mp,str)<<endl;
        return 0;
    }else{
        cout<<maxRep(mp,str)<<endl;
    }
}
