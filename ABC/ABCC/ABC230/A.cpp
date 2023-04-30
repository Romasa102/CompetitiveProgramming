#include <bits/stdc++.h>
using namespace std;
int main(){
    int S;
    cin >> S;
    if(100 > S && S >= 42){
        cout <<  "AGC" << 0 << S + 1 << endl;
        return(0);
    }else if(S >= 10){
        cout << "AGC0" << S << endl;
        return(0);
    }else if(S < 10){
        cout << "AGC00" << S << endl;
        return(0);
    }else if(S >= 100){
        cout << "AGC" << S << endl;
    }
}