#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void krotaion(vector<int>&nums,int k,int n){
    
    // k--;
   reverse(nums.begin(),nums.end());

   reverse(nums.begin(),nums.begin()+k);

   reverse(nums.begin()+k,nums.end());


}

int main(){
    vector<int>nums={1,2,3,4,5,6,7};
    int n=7;
    int k = 3;
    krotaion(nums,k,n);

    for(auto x: nums){
        cout<<x<<" ";
    }

}