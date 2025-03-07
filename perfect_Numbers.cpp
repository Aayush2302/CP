#include<bits/stdc++.h>

using namespace std;

int divisor(int n){
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
    int sum = 0;
    for(auto n:num){
        cout<<n<<" ";
       sum = sum + n;

    }
    cout<<sum;
    return sum - n;
}

bool isPerfect(int n){
    return (divisor(n)==n)?true:false;
}
int main(){

    int n = 225;
    if(isPerfect(n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

}