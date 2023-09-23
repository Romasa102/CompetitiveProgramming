#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll Jcount[N+1];
    ll Ocount[N+!];
    ll Icount[N+1];
    ll difJO[N+1];
    ll difOI[N+1];
    rep(i,N){
        if(S[i] == 'J') Jcount[i+1] = Jcount[i] + 1;
        else Jcount[i+1] = Jcount[i];
        
    }
}