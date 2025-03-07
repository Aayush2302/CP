#include<bits/stdc++.h>

using namespace std;


void divisor(int n){
    set<int>num;
    for(int i=1; i< n/2 ; i++){
        if(n%i==0){
            num.insert(i);
            num.insert(n/i);
        }else{
            continue;
        }
    }
    // sort(num.begin(),num.end());
    for(auto n:num){
        cout<<n<<" ";
    }
}
int main(){
    divisor(13);
}