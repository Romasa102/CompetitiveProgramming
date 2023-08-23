#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll N,X,Y;
vector<ll> ans;
map<ll,vector<ll>> connection;
vector<bool> searched;
bool dfs(ll IN){
    if(searched[IN])return false;
    searched[IN] = true;
    if(IN == Y){
        return true;
    }
    rep(i , connection[IN].size()){
        if(searched[connection[IN][i]])continue;
        if(dfs(connection[IN][i])){
            ans.push_back(connection[IN][i]);
            return true;
        }
    }
    return false;
}
int main(){
    cin >> N >> X >> Y;
    ll U,V;
    searched.resize(N + 1, false);
    rep(i,N-1){
        cin >> U >> V;
        connection[U].push_back(V);
        connection[V].push_back(U);
    }
    dfs(X);
    ans.push_back(X);
    rep(i,ans.size()){
        cout << ans[ans.size()-1-i] << " ";
    }cout << endl;
}