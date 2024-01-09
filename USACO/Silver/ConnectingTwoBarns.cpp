#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;cin >> T;
    rep(i,T){
        ll ans = 1LL<<60;
        ll N,M;
        cin >> N >> M;
        map<ll,vector<ll>> connection;
        rep(i,M){
            ll a,b;
            cin >> a >> b;
            connection[a].push_back(b);
            connection[b].push_back(a);
        }
        queue<ll> Q;
        vector<vector<ll>> Connects(N+1);//connected to 1
        rep(i,N+1){
            Connects[i].push_back(i);
        }
        repp(k,1,N+1){
            vector<bool> visited(N+1,false);
            Q.push(k);
            while(!Q.empty()){
                ll cur = Q.front();
                Connects[k].push_back(cur);
                Q.pop();
                visited[cur] = true;
                for(ll i:connection[cur]){
                    if(visited[i])continue;
                    Q.push(i);
                }
            }
        }
        for(ll i:Connects[N]){
            cout << i << " & " << N << " PARTS OF THE LAST COMPONENT IS  " << endl;
        }
        repp(k,1,N+1){
            for(ll i:Connects[k]){
                ll a = (*lower_bound(Connects[1].begin(),Connects[1].end(),k)-k)*(*lower_bound(Connects[1].begin(),Connects[1].end(),k)-k);
                ll b = (*(lower_bound(Connects[1].begin(),Connects[1].end(),k)-1)-k)*(*(lower_bound(Connects[1].begin(),Connects[1].end(),k)-1)-k);
                ll c = 30000;
                if(lower_bound(Connects[N].begin(),Connects[N].end(),i)!=Connects[N].end()){
                    c = (*lower_bound(Connects[N].begin(),Connects[N].end(),i)-i)*(*lower_bound(Connects[N].begin(),Connects[N].end(),i)-i);
                }
                ll d = 30000;
                if(lower_bound(Connects[N].begin(),Connects[N].end(),i)!=Connects[N].begin()){
                    d=(*(lower_bound(Connects[N].begin(),Connects[N].end(),i)-1)-i)*(*(lower_bound(Connects[N].begin(),Connects[N].end(),i)-1)-i);
                }
                ans = min(ans,min(a,b)+min(c,d));
                cout << k << " " << i << "    min from 0 is " << min(a,b) << " min from the last is " << min(c,d) << endl;
            }
        }
        cout << ans << endl;
    }
}