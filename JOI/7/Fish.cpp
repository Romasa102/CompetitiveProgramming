#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<pair<P,ll>> tops(N);
    vector<ll> X;
    vector<ll> Y;
    vector<ll> Z;
    vector<pair<P,ll>> bottoms(N);
    rep(i,N){
        cin >> tops[i].first.first >> tops[i].first.second >> tops[i].second;
        cin >> bottoms[i].first.first >> bottoms[i].first.second >> bottoms[i].second;
        X.push_back(tops[i].first.first);X.push_back(botto[i].first.first);
    }

}