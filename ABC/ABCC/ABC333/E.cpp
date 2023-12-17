#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll t[N];
    ll x[N];
    rep(i,N){
        cin >> t[i] >> x[i];
    }
    //dp from the back;
    vector<ll>need(200100,0);
    ll cur =0;
    ll ans = 0;
    vector<ll>move;
    for(ll i = N-1;i>=0;i--){
        if(t[i]==2){
            need[x[i]]++;
            cur++;
        }
        if(t[i]==1){
            if(need[x[i]]!=0){
                need[x[i]]--;
                move.push_back(1);
                cur--;
            }else{
                move.push_back(0);
            }
        }
        ans = max(ans,cur);
    }
    if(cur!=0){
        cout << -1 << endl;
        return 0;
    }
    reverse(move.begin(),move.end());
    cout << ans << endl;
    rep(i,move.size()){
        cout << move[i] << " ";
    }cout << endl;
}