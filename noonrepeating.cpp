#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int function(vector<int>nums,int n){
    unordered_map<int,int>mp;
    for(int i = 0; i< n;i++){
        mp[nums[i]]++;
    }

    for(auto x:mp){
        if(x.second == 1){
            return x.first;
        }
    }
    return 0;
}

int main(){
    int n;
    cout<<"Enter length:";
    cin>>n;

    vector<int> array(n);

    for(int i = 0; i<n; i++){
        cin>>array[i];
    }
    cout<<"Answer"<<function(array,n);
}