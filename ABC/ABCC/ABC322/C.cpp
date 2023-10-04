#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[M];
    map<ll,bool> fire;
    rep(i,M){
        cin >> A[i];
        fire[A[i]-1] = true;
    }
    ll table[N];
    table[N-1] = 0;
    for(ll i = N-2; i >= 0; i--){
        if(fire.find(i) == fire.end()){
            table[i] = table[i+1]+1;
        }else{
            table[i] = 0;
        }
    }
    rep(i,N){
        cout << table[i] << endl;
    }
}