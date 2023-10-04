#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
bool visited[300000];
ll minD[300000];
map<ll,set<ll>> MA;
vector<ll> ans;
ll dfs(ll o){
    if(visited[o])return minD[o];
    visited[o] = true;
    ll minV = 0;
    if(MA.find(o) == MA.end()){
        ans.push_back(o);
        return 1;
    }
    for(ll j : MA[o]){
        minV = max(minV,dfs(j));
    }
    ans.push_back(o);
    return minD[o] = minV+1;
}
int main(){
    ll N,M;
    cin >> N >> M;
    ll X[M],Y[M];
    set<ll> PO;
    rep(i,N){
        PO.insert(i+1);
        visited[i+1] = false;
    }
    rep(i,M){
        cin >> X[i] >> Y[i];
        MA[Y[i]].insert(X[i]);
        PO.erase(X[i]);
    }
    ll K = *PO.begin();
    vector<ll> ANSWER(N);
    if(dfs(K) == N){
        cout << "Yes" << endl;
        rep(i,N){
            ANSWER[ans[i]-1] = i+1;
        }
        rep(i,N){
            cout << ANSWER[i] << " ";
        }cout << endl;
        return 0;
    }
    cout << "No" << endl;
}