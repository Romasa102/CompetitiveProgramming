#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<P> Taxi(N+1);
    repp(i,1,N+1){
        ll a,b;
        cin >> a >> b;
        Taxi[i].first = a;
        Taxi[i].second = b;
    }
    map<ll,vector<ll>> connection;
    repp(i,1,K+1){
        ll c,d;
        cin >> c >> d;
        connection[c].push_back(d);
        connection[d].push_back(c);
    }
    map<ll,vector<ll>> TrueConnection;
    repp(i,1,N+1){
        queue<ll> Q;
        vector<ll> length;
        vector<bool> searched;
        length.resize(N+1,1LL << 60);
        searched.resize(N+1,false);
        Q.push(i);
        length[i] = 0;
        while(Q.size()){
            ll Now = Q.front();
            Q.pop();
            if(searched[Now])continue;
            searched[Now] = true;
            for(int j : connection[Now]){
                if(searched[j])continue;
                if(length[j] != 1LL<<60)continue;
                Q.push(j);
                length[j] = length[Now] + 1;
            }
        }
        repp(j,1,N+1){
            if(length[j] <= Taxi[i].second){
                if(j == i)continue;
                TrueConnection[i].push_back(j);
            }
        }
    }
    priority_queue<P,vector<P>,greater<P>> PQ;
    PQ.push({0,1});
    vector<ll> length;
    vector<ll> searched;
    length.resize(N+1,1LL << 60);
    searched.resize(N+1,false);
    length[1] = 0;
    while(PQ.size()){
        P Now = PQ.top();
        PQ.pop();
        if(searched[Now.second])continue;
        for(int i : TrueConnection[Now.second]){
            //cout << Now.second << "   " << i << endl;
            if(searched[i])continue;
            if(length[i] > length[Now.second] + Taxi[Now.second].first){
                length[i] = length[Now.second] + Taxi[Now.second].first;
                if(i == N)continue;
                PQ.push({length[i], i});
            }
        }
    }
    //cout << (1LL << 60) << endl;
    cout << length[N] << endl;
}