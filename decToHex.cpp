#include <bits/stdc++.h>

using namespace std;

void decToHexInt(int n) { 
    string s = "";
    while (n != 0) {
        int temp = n % 16;
        if (temp > 9) {
            s += ('A' + (temp - 10)); 
        } else {
            s += to_string(temp); 
        }
        n = n / 16;
    }
    reverse(s.begin(), s.end()); 
    cout << s ;
}

void decToHexFrac(double n) {
    string s = "";
    int precision = 10; 

    while (n > 0 && precision--) { 
        double temp = n * 16;
        int intPart = static_cast<int>(temp); 
        double fra = temp - intPart; 

        if (intPart > 9) {
            s += ('A' + (intPart - 10)); // Convert 10-15 to A-F
        } else {
            s += to_string(intPart); // Convert 0-9 to string
        }

        n = fra; 
    }
    
    cout << "." << s << endl; 
}

int main() {
    double num = 36.00;
    int integer = static_cast<int>(num);
    double fraction = num - integer; 
    decToHexInt(integer);
    decToHexFrac(fraction);
}
