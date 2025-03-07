#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> pascal (int n){
    vector<vector<int>>res;

    for(int i=0; i<n; i++){
        vector<int>temp;
        for(int j = 0; j< i+1; j++){
            if(j ==0 || j==i){
                temp.push_back(1);
            }else{
                temp.push_back(res[i-1][j-1] + res[i-1][j]);
            }
        }
        res.push_back(temp);
    }

    return res;
}

int main(){
    vector<vector<int>> res = pascal(5);

    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}