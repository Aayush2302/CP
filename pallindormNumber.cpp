#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int rev(int n){
    int temp =0 ;
    int rem;
    while(n>0){
        rem = n%10;
        n=n/10;
        temp = temp*10 + rem;
    }
    cout<<temp<<endl;
    return temp;
}


int main(){
    int n;
    cout<< " Enter number : ";
    cin>>n;

    string num = to_string(n);
    // string temp = num;
    // reverse(temp.begin(),temp.end());
    int x;
    x = rev(n);

    if(n == x){
        cout<<"It's Pallindrom"<<endl;
    }else{
        cout<<"Not a pallindrom";
    }
}