#include<bits/stdc++.h>

using namespace std;

int distinctCount(vector<int>temp){
    unordered_map<int, int> freq;
    for(int i = 0; i < temp.size(); i++){
        freq[temp[i]]++;
    }
    return freq.size();
}

int totalFruit(vector<int>&fruits){
    int windowstart = 0;
    int maxLength = 0 ;


    for(int i = windowstart; i < fruits.size(); i++){
        vector<int> temp;
        temp.push_back(fruits[i]);
        int distinct = distinctCount(temp);
        int j = i + 1;
        while(j < fruits.size() && distinct <= 2){
            temp.push_back( fruits[j]);
            distinct = distinctCount(temp);
            if (distinct <= 2) {
                int tempLength = j - windowstart + 1;
                maxLength = max(maxLength, tempLength);
            }
            j++;
        }
        windowstart++;
    }
    return maxLength;
}

int main(){
    vector<int> fruits = {1,2,3,2,2};
    cout<<totalFruit(fruits);
}