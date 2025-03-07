#include<bits/stdc++.h>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    string s1="";
    string s2="";
    unordered_map<string,int>mp;

    for(int i = 0; i< grid.size();i++){
        for(int j = 0;j<grid.size(); j++){
            s1.append(to_string(grid[i][j]));
            s2.append(to_string(grid[j][i]));
            s1.append("_");
            s2.append("_");
        }
        mp[s1]++;
        mp[s2]++;
        s1="";
        s2="";
    }
    int count = 0;
    int mx = INT_MIN;
    for(auto x:mp){
        // cout<<x.first<<" "<<x.second<<endl;
        mx = max(x.second,mx);
        if(x.second > 1){
            count += x.second-1;
            
        }else{
            continue;
        }
    }
    // cout<<mx<<endl;
    // cout<<grid.size()<<endl;
    return (mx==grid.size()*grid.size())?mx:count ;
}

int main()
{
    vector<vector<int>>grid = {{13,13},{13,13}};
    cout<<equalPairs(grid);
}