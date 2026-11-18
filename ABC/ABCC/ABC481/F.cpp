#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,set<P>> mp;
const ll mod = 998244353;
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[M],B[M],C[M];

    rep(i,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;B[i]--;
        mp[A[i]].insert({B[i],C[i]});
    }
    using D = pair<P,P>;
    priority_queue<D, vector<D>, greater<D>> pq; // rank, prevN, ind, dist(modded)
    pq.emplace(P(0,-1),P(0,0));
    vector<ll> dist(N,-1); // rank, val
    map<ll,ll> rankVal;
    ll rank = 0;
    P prev = {0,-1};
    while(!pq.empty()){
        D cur = pq.top();pq.pop();

        ll ind = cur.second.first;
        if(dist[ind]!=-1)continue;

        if(cur.first!=prev){
            //cout << prev.first << " " << prev.second << " is diff from " << cur.first.first << " " << cur.first.second << endl; 
            rank++;
        }
        prev = cur.first;
        
        dist[ind] = cur.second.second;
        //cout << ind << " have rank : " << rank << endl;
        for(auto i : mp[ind]){
            if(dist[i.first]==-1){
                pq.emplace(P(rank,i.second),P(i.first,(dist[ind]*10+i.second)%mod));
                //cout << "pushed " << rank << " " << i.second  << endl;
            }
        }
    }
    repp(i,1,N){
        cout << dist[i] << endl;
    }
}