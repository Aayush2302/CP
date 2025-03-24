#include<iostream>
#include<algorithm>
using namespace std;
bool isPerfect(int n){
    int temp = 0;
    for(int i = 1; i< n; i++){
        if(n%i==0){
            temp += i;
        }else{
            continue;
        }
    }
    return temp==n?true:false;
}
int main(){
    int n=15;
    if(isPerfect(n)){
        cout<<"Yesss";
    }else{
        cout<<"Nooo";
    }
}