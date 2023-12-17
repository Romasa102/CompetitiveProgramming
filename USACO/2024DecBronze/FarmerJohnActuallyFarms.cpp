#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(i,T){
        ll N;
        cin >> N;
        pair<P,ll> hat[N];//height,acceleration,conditon
        rep(j,N){
            cin >> hat[j].first.first;
        }
        rep(j,N){
            cin >> hat[j].first.second;
        }
        rep(j,N){
            cin >> hat[j].second;
        }
        sort(hat,hat+N);
        vector<vector<P>> time(N);
        rep(j,N-1){
            repp(k,j+1,N){
                if(hat[j].first.second<=hat[k].first.second)continue;//impossible to beat
                if((hat[k].first.first - hat[j].first.first) % (hat[j].first.second - hat[k].first.second)==0){
                    time[j].push_back({(hat[k].first.first - hat[j].first.first) / (hat[j].first.second - hat[k].first.second),-1});
                }else{
                    time[j].push_back({(hat[k].first.first - hat[j].first.first) / (hat[j].first.second - hat[k].first.second)+1,-1});
                }
                time[k].push_back({(hat[k].first.first - hat[j].first.first) / (hat[j].first.second - hat[k].first.second) + 1,1});
            }
        }
        rep(j,N){
            time[j].push_back({0,0});
            sort(time[j].begin(),time[j].end());
        }
        ll ans = 1LL<<60;
        vector<P> imos;
        rep(j,N){
            ll cur = N-j-1;
            rep(o,time[j].size()){
                cur+=time[j][o].second;
                if(cur == hat[j].second){
                    imos.push_back({time[j][o].first,1});
                    if(o!=time[j].size()-1){
                        imos.push_back({time[j][o+1].first,-1});
                    }
                }
            }
        }
        sort(imos.begin(),imos.end());
        ll current = 0;
        rep(j,imos.size()){
            current+=imos[j].second;
            if(j!=N-1){
                if(imos[j].first==imos[j+1].first)continue;
            }
            if(current==N){
                ans = min(ans,imos[j].first);
            }
        }
        if(ans == 1LL<<60){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
}