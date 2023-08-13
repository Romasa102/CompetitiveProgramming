#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    map<ll,vector<ll>> mp;
    ll betC[N];
    rep(i,N){
        ll C;
        cin >> C;
        betC[i] = C;
        ll A[C];
        rep(j,C){
            cin >> A[j];
            mp[A[j]].push_back(i);
        }
    }
    ll X;
    cin >> X;
    if(mp.find(X) == mp.end()){
        cout << 0 << endl;
        return 0;
    }
    vector<P> ans;
    rep(i,mp[X].size()){
        ans.push_back({betC[mp[X][i]],mp[X][i]});
    }
    sort(ans.begin(),ans.end());
    vector<ll> ansPPL;
    ansPPL.push_back(ans[0].second);
    rep(i,ans.size()-1){
        if(ans[i].first == ans[i+1].first){
            ansPPL.push_back(ans[i+1].second);
        }else{
            break;
        }
    }
    cout << ansPPL.size() << endl;
    rep(i,ansPPL.size()){
        cout << ansPPL[i]+1 << " ";
    }cout << endl;
}