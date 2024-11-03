#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q;cin >> N >> Q;
    string S;cin >> S;
    P ab[Q];rep(i,Q)cin >> ab[i].first >> ab[i].second;
    ll curCost = 0;
    vector<ll> weightB(26,0);
    vector<ll> weightE(26,0);
    vector<ll> sumB(N+1,0);
    vector<ll> sumE(N+1,0);
    rep(i,N){
        if(weightB[S[i]-'A']==0){
            weightB[S[i]-'A']++;
            curCost ++;
        }
        repp(j,S[i]-'A'+1,26){
            weightB[j]=0;
        }
        sumB[i+1] = curCost;
    }
    curCost = 0;
    for(ll i = N - 1; i >= 0; i--){
        if(weightE[S[i]-'A']==0){
            weightE[S[i]-'A']++;
            curCost++;
        }
        repp(j,S[i]-'A'+1,26){
            weightE[j]=0;
        }
        sumE[i] = curCost;
    }
    rep(i,N+1){
        cout << sumB[i] << " ";
    }cout << endl;
    rep(i,N+1){
        cout << sumE[i] << " ";
    }cout << endl;
    rep(i,Q){
        cout << sumB[ab[i].first-1] + sumE[ab[i].second] << endl;
    }
}