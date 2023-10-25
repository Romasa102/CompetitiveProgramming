#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll N;
vector<ll> A;
vector<ll> B;
map<ll,vector<ll>> connection;
bool visited[200000];
void dfs(ll a,bool cur){
    visited[a]=true;
    if(cur){
        A.push_back(a);
    }else{
        B.push_back(a);
    }
    for(ll i:connection[a]){
        if(visited[i])continue;
        dfs(i,!cur);
    }
}
int main(){
    cin >> N;
    rep(i,N-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    memset(visited,false,sizeof (visited));
    dfs(0,true);
    if(A.size()>B.size()){
        rep(i,N/2){
            cout << A[i]+1 << " ";
        }
    }else{
        rep(i,N/2){
            cout << B[i]+1 << " ";
        }
    }cout<<endl;
}