#include<bits/stdc++.h>

using namespace std;


    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = 0;
        int mult;
        for(int i = 0; i < nums.size() ; i++){
            for(int j = i+1; j< nums.size() ; j++){
              mult = nums[i]*nums[j];
              mp[mult]++;
            }
        }

        for(auto x:mp){
            // cout<<x.first<<" "<<x.second<<endl;
            int temp = x.second;
            if(temp>1){
                for(int i = 0; i<temp;i++){
                    ans = ans + pow(2,temp);
                    //  cout<<ans<<endl;
                }
               
            }
            else
            continue;
        }
        return ans;
    }

int main(){
    vector<int> nums = {2,3,4,6,8,12};
    cout << tupleSameProduct(nums) << endl;
    return 0;
}