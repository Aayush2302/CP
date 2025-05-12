#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    string category;
    int num;

    unordered_map<string,int>mp;

    while(1){
        cout<<"Enter Category: ";
        getline(cin, category);
        cout<<endl;
        if(category=="done"){
            break;
        }
        cout<<"Enter Expanse: ";
        cin>>num;
        cin.ignore();
        mp[category] = num;
    }

    for(auto x:mp){
        cout<<"Category: "<<x.first<<"  Expanse: "<<x.second<<endl;
    }
}