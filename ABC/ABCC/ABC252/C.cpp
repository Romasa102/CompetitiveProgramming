#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S[N];
    vector<vector<ll>> max(10);
    rep(i,N){
        cin >> S[i];
    }
    rep(i,N){
        rep(j,10){
            max[S[i][j]-'0'].push_back(j);
        }
    }
    vector<ll>maxc(10);
    rep(i,10){
        rep(j,10){
            ll r = count(max[i].begin(), max[i].end(),j);
            if(r!=0){
                if(maxc[i] < j+(r-1)*10){
                    maxc[i] = j+(r-1)*10;
                }
            }
        }
    }
    ll MaxAns = 1000000000;
    rep(i,10){
        if(maxc[i] < MaxAns){
            MaxAns = maxc[i];
        }
    }
    cout << MaxAns << endl;
}