#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll K,N,M;
    cin >> K >> N >> M;
    ll Point[K];
    ll worstCase[K];
    rep(i,K){
        cin >> Point[i];
        worstCase[i] = Point[i];
    }
    ll possibleWinner;
    if(K%12==0){
        possibleWinner = K/12;
    }else{
        possibleWinner = K/12+1;
    }
    ll maxPossible[K];
    rep(i,K){
        maxPossible[i] = Point[i] + 100 * (N-M);
    }
    sort(maxPossible,maxPossible+K,greater<ll>());
    rep(i,K){
        if(possibleWinner >= K){
            cout << i+1 << endl;
        }
        if(N!=M&&maxPossible[possibleWinner] <= Point[i]){
            cout << i+1 << endl;
        }else if(maxPossible[possibleWinner-1] <= Point[i]){
            cout << i + 1 << endl;
        }
    }
    cout << "--------" << endl;
    sort(worstCase,worstCase+K,greater<ll>());
    rep(i,K){
        if(worstCase[possibleWinner-1] <= Point[i] + 100*(N-M)){
            cout << i+1 << endl;
        }
    }
}