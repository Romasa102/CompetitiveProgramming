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
       if(searched[cur.second])continue;
       dis[cur.second]=cur.first;
       searched[cur.second]=true;
       for(P i:map[cur.second]){
           PQ.push({cur.first+i.second,i.first});
       }
    }
    rep(i,N){
        cout << dis[i] << endl;
    }
    cout << endl << endl;
    rep(i,N)searched[i]=false;
    priority_queue<P,vector<P>,greater<P>> PQB;
    PQB.push({0,N-1});
    ll disB[N];
    rep(i,N)disB[i]=0;
    while(!PQB.empty()){
        P cur = PQB.top();
        PQB.pop();
        if(searched[cur.second])continue;
        disB[cur.second]=cur.first;
        searched[cur.second]=true;
        for(P i:map[cur.second]){
            PQB.push({cur.first+i.second,i.first});
        }
    }
    rep(i,N){
        cout << disB[i] << endl;
    }
}