#include<bits/stdc++.h>

using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries){
    unordered_map<int,int>mp;
    set<int>st;
    vector<int>ans;
    for(auto x:queries){
        mp.insert({x[0],x[1]});
        st.insert(x[1]);

        int mpLen=mp.size();
        int stLen=st.size();

        if(stLen<=mpLen){
          ans.push_back(stLen); 
        }else{
            ans.push_back(mpLen);
        }
    }
    for(auto x:ans){
        cout<<x<<endl;
    }   
}

int main(){
    vector<vector<int>> queries = {{0,1},{1,2},{2,2},{3,4},{4,5}};
    int limit = 4;  
    queryResults(limit, queries);
    return 0;
}