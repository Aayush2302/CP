#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n*fact(n-1);
}

int fibbo(int n){
    if(n<=1){
        return n;
    }
    int last = fibbo(n-1);
    int slast = fibbo(n-2);
    return last+slast;
}

int main(){
    int n = 4;
    // cout<<fact(n);
    cout<<fibbo(n);
}