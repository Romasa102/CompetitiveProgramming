#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll A,B;
    cin >> A >> B;
    if(A+B*7 <= 30){
        cout << "1" << endl;
    }else{
        cout << "0" << endl;
    }
}