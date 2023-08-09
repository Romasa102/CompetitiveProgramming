#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;

    ll M;
    cin >> N >> M;
    ll P[N+1];
    P[0] = 0;
    rep(i,N){
        cin >> P[i+1];
    }
    sort(P,P+N+1);
    vector<ll> Comb;
    rep(i,N+1){
        rep(j,N+1){
            Comb.push_back(P[i]+P[j]);
        }
    }
    sort(Comb.begin(),Comb.end());
    ll currentMax = 0;
    rep(i,Comb.size()){
        ll Remain = M-Comb[i];
        if(Remain < 0)continue;
        auto m = upper_bound(Comb.begin(),Comb.end(),Remain);
        if(m == Comb.end()){
            currentMax = max(currentMax,Comb[i] + Comb[N]);
        }
        else{
            currentMax = max(currentMax,Comb[i]+*(m-1));
        }
    }
    cout << currentMax << endl;
}