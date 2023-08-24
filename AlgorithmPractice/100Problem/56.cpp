#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll V,E,r;
    cin >> V >> E >> r;
    bool searched[V];
    ll length[V];
    rep(i,V){
        searched[i] = false;
        length[i] = 1 << 50;
    }
    ll s,t,d;
    map<ll,vector<P>> connection;
    rep(i,E){
        cin >> s >> t >> d;
        connection[s].push_back(make_pair(t,d));
    }
    queue<ll> Q;
    Q.push(r);
    length[r] = 0;
    while(Q.size()){
        ll Now = Q.front();
        if(searched[Now]){
            Q.pop();
            continue;
        }
        searched[Now] = true;

        rep(i,connection[Now].size()){
            Q.push(connection[Now][i].first);
            length[connection[Now][i].second]
        }
    }
}