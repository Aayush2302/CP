#include<bits/stdc++.h>

using namespace std;

int fun(string s, int k){

    unordered_map<char, int>mp;
    for(int i = 0; i< s.size(); i++){
        mp[s[i]]++;
    }
    vector<pair<char, int>>v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), [](pair<char, int>&a, pair<char, int>&b){
        return a.second < b.second;
    });

    for(auto it: v){
        cout<<it.first<<" "<<it.second<<endl;
    }cout<<endl;
    if(mp.size() == k){
        return 0;
    }
// in case of s=cekci and k = 1, we have to remove the one i, one k , one e so that minimum distinct character will be removed 
// and we will be left with c and c. So the answer will be 3. give the code


    if(mp.size()>k){
       int ans = 0;
       cout<<v[1].first<<" "<<v[1].second<<endl;
        for(int i = 0; v.size() > k; i++){
            cout<<"i="<< i <<endl;
            cout<<v[i].first<<" "<<v[i].second<<endl;
            ans += v[i].second;
            v.erase(v.begin() + i);
        }
        return ans;
    }

};


int main(){
    string s="cekci";
    int k = 1;
    int x = fun(s, k);
    cout<<x<<endl;
}