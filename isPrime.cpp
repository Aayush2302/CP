#include<iostream>
#include<algorithm>

using namespace std;

bool isPrime(int n){
    int count = 0;
    for(int i = 1; i<= n; i++){
        if(n%i==0){
            count++;
        }else{continue;}
    }
    return count==2?true:false;
}
int main(){
    int n = 2;
    if(isPrime(n)){
        cout<<"yes";
    }else{cout<<"Noooo";}
}