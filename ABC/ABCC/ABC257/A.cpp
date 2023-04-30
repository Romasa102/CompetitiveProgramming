#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,X;
    cin >> N >> X;
    string S =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(X%N == 0){
        cout << S[X/N] << endl;
    }else{
        cout << S[X/N+1] << endl;
    }
}