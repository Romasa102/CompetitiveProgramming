#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
bool compare(P a,P b){
    return a.second < b.second;
}
int main(){
    //freopen("helpcross.in","r",stdin);
    //freopen("helpcross.out","w",stdout);
    ll C,N;cin >> C >> N;
    ll T[C];rep(i,C)cin >> T[i];
    vector<P> AB(N);rep(i,N)cin >> AB[i].first >> AB[i].second;
    sort(T,T+C);
    sort(AB.begin(),AB.end(),compare);
    ll ans = 0;
    ll cur;
    rep(i,C){
        cur = 0;
        while(cur<=AB.size()){
            if(AB[cur].first <= T[i] && T[i] <= AB[cur].second){
                AB.erase(AB.begin()+cur);
                cout << AB.size() << endl;
                ans++;
                break;
            }
            cur++;
        }
    }
    cout << ans << endl;
}