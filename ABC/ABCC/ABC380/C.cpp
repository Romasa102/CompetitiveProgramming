#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<P> cluster;
    ll cur = 0;
    cluster.push_back({S[0] - '0',1});
    repp(i,1,N){
        if(S[i] == S[i-1]){
            cluster.back().second++;
        }else{
            cluster.push_back({S[i] - '0',1});
        }
    }
    if(cluster[0].first == 0){
        swap(cluster[2*K-1],cluster[2*K-2]);
    }else{//2k,2k-1
        swap(cluster[2*K-2],cluster[2*K-3]);
    }
    rep(i,cluster.size()){
        rep(j,cluster[i].second){
            cout << cluster[i].first;
        }
    }
    cout << endl;
}