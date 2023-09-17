#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll T[M],W[M],S[M];
    rep(i,M){
        cin >> T[i] >> W[i] >>S[i];
    }
    ll ans[N+1];
    rep(i,N+1){
        ans[i] = 0;
    }
    priority_queue<ll,vector<ll>,greater<ll>> peoples;
    priority_queue<P,vector<P>,greater<P>> waitList;
    rep(i,N){
        peoples.push(i);
    }
    rep(i,M){
        if(!waitList.empty()){
            while (!waitList.empty()&&waitList.top().first <= T[i]){
                peoples.push(waitList.top().second);
                waitList.pop();
            }
        }
        ll gotSomen = N;
        if(!peoples.empty()){
            gotSomen = peoples.top();
            peoples.pop();
            ans[gotSomen]+=W[i];
            waitList.push({T[i]+S[i],gotSomen});
        }
    }
    rep(i,N){
        cout << ans[i] << endl;
    }
}