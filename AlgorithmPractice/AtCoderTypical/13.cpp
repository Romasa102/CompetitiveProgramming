#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[M],B[M],C[M];
    map<ll,vector<P>> map;
    rep(i,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;B[i]--;
        map[A[i]].push_back({B[i],C[i]});
        map[B[i]].push_back({A[i],C[i]});
    }
    bool searched[N];
    rep(i,N)searched[i]=false;
    priority_queue<P,vector<P>,greater<P>> PQ;
    PQ.push({0,0});
    ll dis[N];
    rep(i,N)dis[i]=0;
    while(!PQ.empty()){
       P cur = PQ.top();
       PQ.pop();
       dis[cur.first]=cur.second;
       if(searched[cur.first])continue;
       searched[cur.first]=true;
       for(P i:map[cur.first]){
           PQ.push({i.first,cur.second+i.second});
       }
    }
    rep(i,N){
        cout << dis[i] << endl;
    }
    cout << dis[N-1] << endl;
}