#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[M],B[M],X[M],Y[M];
    map<P,P> relation;
    map<ll,vector<ll>> connection;
    rep(i,M){
        cin >> A[i] >> B[i] >> X[i] >> Y[i];
        connection[A[i]].push_back(B[i]);
        connection[B[i]].push_back(A[i]);
        relation[{A[i],B[i]}]={X[i],Y[i]};
        relation[{B[i],A[i]}]={-X[i],-Y[i]};
    }
    queue<ll> Q;
    bool searched[N+1];
    P position[N+1];
    rep(i,N+1){
        position[i] = {1LL<<42,1LL<<42};
        searched[i] = false;
    }
    position[1] = {0,0};
    Q.push(1);
    while(!Q.empty()){
        ll searchNum = Q.front();
        Q.pop();
        if(searched[searchNum]){
            continue;
        }else{
            searched[searchNum] = true;
        }
        for(ll x:connection[searchNum]){
            if(!searched[x]){
                Q.push(x);
                position[x] = {position[searchNum].first + relation[{searchNum, x}].first,position[searchNum].second+relation[{searchNum,x}].second};
            }
        }
    }
    repp(i,1,N+1){
        if(position[i].first == 1LL<<42||position[i].second == 1LL<<42){
            cout << "undecidable" << endl;
        }else{
            cout << position[i].first << " "<< position[i].second << endl;
        }
    }
}