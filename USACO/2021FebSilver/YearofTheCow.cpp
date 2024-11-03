#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;cin >> N >> K;
    ll anc[N];rep(i,N)cin >> anc[i];
    priority_queue<ll,vector<ll>,greater<ll>>jump;
    map<ll,ll> floor;
    ll requiredJ = 0;
    ll ans = 0;
    rep(i,N){
        floor[(anc[i]+11)/12]++;
    }
    if(floor.find(0)==floor.end()){
        requiredJ++;
        jump.push(12);
    }
    floor[0]++;
    for(auto i = floor.begin(); i != floor.end(); i++){
        auto nextI = i;++nextI;
        if(nextI == floor.end())break;
        if((nextI->first-i->first)!=1){
            jump.push((nextI->first-i->first - 1) * 12);
            requiredJ++;
        }
        ans+=12;
    }
    rep(i,requiredJ-K){
        cout << ans << endl;
        ans+=jump.top();
        jump.pop();
    }
    cout << ans << endl;
}