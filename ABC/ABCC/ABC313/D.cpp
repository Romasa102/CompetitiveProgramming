#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll o[N];
    rep(i,N){
        cout << "?" << " ";
        rep(j,K){
            cout << i+1  << " ";
        }cout << endl;
        ll T;
        cin >> T;
        if(!T){
            o[i] = 0;
        }else{
            o[i] = 1;
        }
    }
    cout << "! ";
    rep(i,N){
        cout << o[i] << " ";
    }return 0;
}