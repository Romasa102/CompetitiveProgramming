#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    rep(i,N){
        if(i%3==2){
            cout << "x";
        }else{
            cout << "o";
        }
    }cout << endl;
}