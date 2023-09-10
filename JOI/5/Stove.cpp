#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll T[N];
    rep(i,N){
        cin >> T[i];
    }
    sort(T,T+N);
    vector<ll> interval;
    ll initial = T[N-1] + 1 - T[0];
    rep(i,N-1){
        interval.push_back(T[i+1]-T[i]-1);
    }
    sort(interval.begin(),interval.end(),greater<ll>());
    rep(i,K-1){
        initial -= interval[i];
    }
    cout << initial << endl;
}