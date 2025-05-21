#include<bits/stdc++.h>

using namespace std;


    double findMaxAverage(vector<int>& nums, int k) {

        float avg = 0.0;
        for(int i = 0; i< nums.size()-k+1; i++){
            float tempSum = 0;
            for(int j = i;j<i+k;j++){
                tempSum+=nums[j];
                cout<<nums[j]<<" ";
            }
           
            cout<<endl;
            if((tempSum/k)>avg){
                avg=(tempSum/k);
            }else{
                continue;
            }
        }
        return avg;
    }
int main(){
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    double result = findMaxAverage(nums, k);
    cout << result << endl; // Output: 12.75
}