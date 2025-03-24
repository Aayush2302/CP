#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int rev(int n){
    int temp =0 ;
    int rem;
    while(n>0){
        rem = n%10;
        n=n/10;
        temp = temp*10 + rem;
    }

    return temp;
}

int intoNum(string s){
int sum = 0;
    for(int i = 0;i<s.size();i++){
        int x = s[i]-'0';
        sum += pow(2,i)*x;
    }
    return sum;

}
void octal(string s){
    // cout<<"original"<<s<<endl;
    reverse(s.begin(),s.end());
    // cout<<"Reverse:"<<s<<endl;
    int size = s.size();
   
    string res="";
    for(int i = 0; i<=size;i++){
        string temp = s.substr(i, 3);
        i+=2;
    
        int z = intoNum(temp);
        res.append(to_string(z));
        
    }
    reverse(res.begin(),res.end());
    cout<<res;
}
int main(){
int n = 11111;
// cout<<rev(n);
string s = to_string(n);
octal(s);
// binToOct(n);
}