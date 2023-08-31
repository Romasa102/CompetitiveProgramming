#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    string sign[N];
    ll ans = 0;
    rep(i,N){
        cin >> sign[i];
        vector<ll> startP;
        vector<ll> endP;
        ll counter = 0;
        for(char j: sign[i]){
            if(j == S[0]){
                startP.push_back(counter);
            }
            if(j == S[S.size()-1]){
                endP.push_back(counter);
            }
            counter++;
        }
        ll end = false;
        for(int j:startP){
            for(int k:endP){
                if(j>=k)continue;
                if((k-j)%(S.size()-1)!=0)continue;
                ll currentC = 1;
                ll now = j;
                bool fail = false;
                rep(m,S.size()-2){
                    now+=(k-j)/(S.size()-1);
                    if(sign[i][now] != S[currentC]){
                        fail = true;
                        break;
                    }
                    currentC++;
                }
                if(!fail){
                    ans += 1;
                    end = true;
                    break;
                }
            }
            if(end){
                break;
            }
        }
    }
    cout << ans << endl;
}