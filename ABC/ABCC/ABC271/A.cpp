#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
string sixteen(int i){
    if(i < 10){
        return to_string(i);
    }
    else if(i == 10){
        return "A";
    }else if(i == 11){
        return "B";
    }else if(i == 12){
        return "C";
    }else if(i == 13){
        return "D";
    }else if(i == 14){
        return "E";
    }else if(i == 15){
        return "F";
    }else if(i == 16){
        return "G";
    }
}
int main(){
    ll N;
    cin >> N;
    ll a = N%16;
    ll b = N/16;
    cout << sixteen(b) << sixteen(a) << endl;
}