#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;cin >> N >> M;
    map<ll,vector<P>> change;
    ll a[M];
    rep(i,M){
        ll l,r;
        cin >> l >> r >> a[i];
        l--;r--;
        change[l].push_back({1,i}); //index, num, index.
        change[r+1].push_back({-1,i});
    } //10^5 max
    vector<tuple<ll,vector<ll>>> state(N);
     // score earned by that point,
     // list of index that occupy that spot
    ll curS = 0;
    set<ll> list;
    priority_queue<tuple<ll,set<ll>>> pq; //change and how much index it got.
    rep(i,N){
        if(change.find(i)==change.end())continue;
        rep(j,change[i].size()){
            if(change[i][j].first>0){
                curS += a[change[i][j].second];
                list.insert(change[i][j].second);
            }else{
                curS -= a[change[i][j].second];
                list.erase(change[i][j].second);
            }
        }
        pq.push({curS,list});
    }//10^5 max
    set<ll> removed;
    ll ans = 0;
    while(!pq.empty()){
        auto cur = pq.top();pq.pop();
        vector<ll> rm;
        for(auto i : get<1>(cur)){
            if(removed.find(i)!=removed.end()){
                rm.push_back(i);
            }
        }
        if(!rm.empty()){
            for(auto i : rm){
                get<0>(cur)-=a[i];
                get<1>(cur).erase(i);
            }
            pq.push(cur);
            continue;
        }
        if(get<0>(cur) < 0)break;
        ans += get<0>(cur);
        for(auto i : get<1>(cur)){
            removed.insert(i);
        }
    }
    cout << ans << endl;
}