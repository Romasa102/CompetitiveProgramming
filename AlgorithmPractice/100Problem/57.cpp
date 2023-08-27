#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    map<ll,vector<P>> connection;
    rep(i,K){
        ll task;
        cin >> task;
        if(task == 0){
            ll a,b;
            cin >> a >> b;
            ll length[N+1];
            bool searched[N+1];
            rep(j,N+1){
                length[j] = 1LL << 60;
                searched[j] = false;
            }
            //get the minimum cost between a to b;
            priority_queue<P,vector<P>,greater<P>> PQ;
            PQ.push({0,a});
            length[a] = 0;
            while(PQ.size()){
                ll NowLen = PQ.top().first;
                ll NowInd = PQ.top().second;
                PQ.pop();
                if(searched[NowInd])continue;
                searched[NowInd];
                for(P k : connection[NowInd]){
                    if(!searched[k.first] && length[k.first] > NowLen + k.second){
                        length[k.first] = NowLen + k.second;
                        PQ.push({length[k.first],k.first});
                    }
                }
            }
            if(length[b] == 1LL<<60){
                cout << -1 << endl;
                continue;
            }else{
                cout << length[b] << endl;
            }
        }else{
            ll c,d,e;
            cin >> c >> d >> e;
            connection[c].push_back({d,e});
            connection[d].push_back({c,e});
        }
    }
}