#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K,S;
    cin >> N >> M >> K >> S; //S = dangerous range;
    ll DangerousC,SafeC;
    cin >> DangerousC >> SafeC;
    map<ll,vector<ll>> connection;
    ll Zomb[K];
    rep(i,K){
        cin >> Zomb[i];
    }
    rep(i,M){
        ll A,B;
        cin >> A >> B;
        connection[A].push_back(B);
        connection[B].push_back(A);
    }
    ll length[N+1];
    bool searched[N+1];
    rep(i,N+1){
        length[i] = 1LL << 60;
        searched[i] = false;
    }
    queue<ll> Q;
    rep(i,K){
        Q.push(Zomb[i]);
        length[Zomb[i]] = 0;
    }
    while(Q.size()){
        ll Now = Q.front();
        Q.pop();
        if(searched[Now])continue;
        searched[Now] = true;
        for(ll i : connection[Now]){
            if(searched[i])continue;
            Q.push(i);
            if(length[i] > length[Now]+1)length[i] = length[Now] + 1;
        }
    }
    ll cost[N+1];
    repp(i,1,N+1){
        if(length[i] <= S){
            cost[i] = SafeC;
        }else{
            cost[i] = DangerousC;
        }
        if(length[i] == 0){
            cost[i] = 1LL << 60;
        }
    }
    priority_queue<P,vector<P>,greater<P>> PQ;
    bool searchedDS[N];
    ll lengthDS[N];
    rep(i,N){
        searchedDS[i] = false;
        lengthDS[i] = 1LL << 60;
    }
    PQ.push({0,1});
    while(PQ.size()){
        P Now = PQ.top();
        PQ.pop();
        if(searchedDS[Now.second])continue;
        searchedDS[Now.second] = true;
        for(int i : connection[Now.second]){
            if(i == N){
                lengthDS[N] = min(lengthDS[N],Now.first);
                break;
            }
            if(searchedDS[i])continue;
            if(lengthDS[i] > Now.first + cost[i]){
                lengthDS[i] = Now.first + cost[i];
                //cout << "changed " << i << " to " << lengthDS[i] << endl;
                PQ.push({lengthDS[i],i});
            }
        }
    }
    cout << lengthDS[N] << endl;
}