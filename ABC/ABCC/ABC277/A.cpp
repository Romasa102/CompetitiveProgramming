#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,X;
    cin >> N >> X;
    ll L;
    rep(i,N){
        cin >> L;
        if(L == X){
            cout << i +1 << endl;
        }
    }
}