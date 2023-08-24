#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> connection;
int main(){
    ll N,M;
    cin >> N >> M;
    ll A,B;
    vector<ll> ans;
    vector<bool> searched;
    searched.resize(N+1,false);
    ans.resize(N+1,-1);
    rep(i,M){
        cin >> A >> B;
        connection[A].push_back(B);
        connection[B].push_back(A);
    }
    queue<ll> Q;
    Q.push(1);
    while(Q.size()){
        ll SearchNum = Q.front();
        for(int i : connection[SearchNum]){
            if(searched[i]){
                continue;
            }
            searched[i] = true;
            ans[i] = SearchNum;
            Q.push(i);
        }
        Q.pop();
    }
    repp(i,2,N+1){
        if(ans[i] == -1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    repp(i,2,N+1){
        cout << ans[i] << endl;
    }
}