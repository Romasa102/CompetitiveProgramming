#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll V,E,r;
    cin >> V >> E >> r;
    ll length[V];
    bool searched[V];
    rep(i,V){
        length[i] = 1LL << 60;
        searched[i] = false;
    }
    ll s,t,d;
    map<ll,vector<P>> connection;
    rep(i,E){
        cin >> s >> t >> d;
        connection[s].push_back(make_pair(t,d));
    }
    length[r] = 0;
    priority_queue<P,vector<P>,greater<P>> PQ;
    PQ.push({0,r});
    while(PQ.size()){
        P Now = PQ.top();
        PQ.pop();
        if(searched[Now.second])continue;
        searched[Now.second] = true;
        rep(i,connection[Now.second].size()){
            if(length[connection[Now.second][i].first] > length[Now.second] + connection[Now.second][i].second){
                length[connection[Now.second][i].first] = length[Now.second] + connection[Now.second][i].second;
                PQ.push(make_pair(length[connection[Now.second][i].first],connection[Now.second][i].first));
            }
        }
    }
    rep(i,V){
        if(length[i] == 1LL << 60){
            cout << "INF" << endl;
            continue;
        }
        cout << length[i] << endl;
    }
}