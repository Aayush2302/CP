#include<bits/stdc++.h>
#include<vector>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size()*grid.size();
    // cout<<n<<endl;
    unordered_map<int,int>mp;
    vector<int>ans;

    for(int i = 1;i<=n;i++){
        mp[i] = 0;
    }

    for(int i = 0; i< grid.size();i++){
        for(int j = 0; j< grid[0].size(); j++){
            mp[grid[i][j]]++;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        if(mp[i]>1){

            ans.push_back(i);
        }
    }
    for(int i = 1;i<=n;i++)
    {
        if(mp[i]==0){
            ans.push_back(i);
        }}
    return ans;

}


int main(){
    vector<vector<int>>que = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int>ans = findMissingAndRepeatedValues(que);
    for(auto x:ans){
        cout<<x<<endl;
    }
}