#include<bits/stdc++.h>

using namespace std;

int check(string s){
    int count=0;
    for(char c:s){
        if(c=='W'){
            count++;
        }
    }
    // cout<<count<<endl;
    return count;
}

int minimumRecolors(string blocks, int k) {
    int min = INT_MAX;
    for(int i = 0; i<=blocks.size()-k; i++){
        string temp = blocks.substr(i,k);
        // cout<<temp<<endl;
        int word = check(temp);
        // cout<<"Word = "<<word<<endl;
        if(min > word){
            min = word;
        }
    }
    return min;
}

int main()
{
    string s = "WBBWWBBWBW";
    int x = minimumRecolors(s,7);
    cout<<x;
}