#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> parents;
ll find(ll x){
    if(parents[x] == x){
        return x;
    }
    return find(parents[x]);
}
void unite(ll a,ll b){
    parents[find(a)]=find(b);
}
int main(){
    ll N,K;cin >> N >> K;
    unordered_set<ll> visited[N];
    vector<P> ab(K);
    rep(i,K){
        cin >> ab[i].first >> ab[i].second;
        ab[i].first--;ab[i].second--;
    }
    parents.resize(N);
    rep(i,N)parents[i]=i;
    vector<ll> cows;
    rep(i,N){
        cows.push_back(i);
        visited[i].insert(i);
    }
    rep(i,K){
        visited[cows[ab[i].first]].insert(ab[i].first);
        visited[cows[ab[i].second]].insert(ab[i].second);
        swap(cows[ab[i].first],cows[ab[i].second]);
    }
    rep(i,N){
        unite(i,cows[i]);
     //   cout << cows[i] << " ";
    }//cout << endl;
    unordered_set<ll> final[N];
    rep(i,N){
        for(ll j : visited[i]){
            final[find(i)].insert(j);
        }
    }
    rep(i,N){
        cout << final[find(i)].size() << endl;
    }
}