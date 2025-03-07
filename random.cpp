#include<bits/stdc++.h>

using namespace std;

string solution(string s){
    string ans="";
    unordered_map<string,string>data;
    data.insert({
        {"One","1"},
        {"Two","2"},
        {"Three","3"},
        {"Four","4"},
        {"Five","5"},
        {"Six","6"},
        {"Seven","7"},
        {"Eight","8"},
        {"Nine","9"},
        {"Ten","10"},
        {"Hundred","00"},
        {"Thousand",",000"},
        {"Million",",000,000"}
    });
    stringstream ss(s);
    string word;
    vector<string> v;

    while (ss >> word) {
        v.push_back(word);
    }

    for(int i = 0; i< v.size();i++){
        string temp = v[i];
        // cout<<v[i]<<endl;
        if(data.find(v[i])==data.end()){
            cout<<"Invalid"<<endl;
            // cout<<v[i];
        }else{
            ans.append(data[temp]);
        //    int temp = data[v[i]];
        //    ans *= temp;
        //    cout<<ans<<endl;
        }
    }
    return ans;
}

int main(){

string s = "Three Hundred Million";
cout << solution(s);
}