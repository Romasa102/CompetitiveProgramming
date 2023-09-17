#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,L;
    cin >> N >> L;
    ll A[N];
    ll timeT[N];
    rep(i,N){
        cin >> A[i];
        timeT[i] = L-A[i];
    }
    ll count[N];
    rep(i,N)count[i]=0;
    priority_queue<P,vector<P>,greater<P>> Q;
    if(A[0]<A[1])count[0]++;
    if(A[N-1]<A[N-2])count[N-1]++;
    if(count[0]==0)Q.push({timeT[0],0});
    if(count[N-1]==0)Q.push({timeT[N-1],N-1});
    repp(i,1,N-1){
        if(A[i]<A[i+1])count[i]++;
        if(A[i]<A[i-1])count[i]++;
        if(count[i] == 0)Q.push({timeT[i], i});
    }
    ll ans =0;
    while(!Q.empty()){
        P O = Q.top();
        Q.pop();
        if(O.second+1<N&&count[O.second+1]>0){
            count[O.second+1]--;
            if(count[O.second+1]==0){
                Q.push({timeT[O.second+1]+O.first,O.second+1});
            }
        }
        if(O.second-1>=0&&count[O.second-1]>0){
            count[O.second-1]--;
            if(count[O.second-1]==0){
                Q.push({timeT[O.second-1]+O.first,O.second-1});
            }
        }
        ans = max(ans,O.first);
    }cout << ans << endl;
}