#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<pair<P,ll>> tops(N);
    vector<ll> X = {0};
    vector<ll> Y = {0};
    vector<ll> Z = {0};
    vector<pair<P,ll>> bottoms(N);
    rep(i,N){
        cin >> tops[i].first.first >> tops[i].first.second >> tops[i].second;
        cin >> bottoms[i].first.first >> bottoms[i].first.second >> bottoms[i].second;
        X.push_back(tops[i].first.first);X.push_back(bottoms[i].first.first);
        Y.push_back(tops[i].first.second);Y.push_back(bottoms[i].first.second);
        Z.push_back(tops[i].second);Z.push_back(bottoms[i].second);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(Z.begin(),Z.end());
    unique(X.begin(), X.end());
    unique(Y.begin(),Y.end());
    unique(Z.begin(),Z.end());
    rep(i,N){
        tops[i].first.first = lower_bound(X.begin(), X.end(),tops[i].first.first)-X.begin();
        tops[i].first.second = lower_bound(Y.begin(), Y.end(),tops[i].first.second)-Y.begin();
        tops[i].second = lower_bound(Z.begin(),Z.end(),tops[i].second)-Z.begin();
        bottoms[i].first.first = lower_bound(X.begin(),X.end(),bottoms[i].first.first)-X.begin();
        bottoms[i].first.second = lower_bound(Y.begin(),Y.end(),bottoms[i].first.second)-Y.begin();
        bottoms[i].second = lower_bound(Z.begin(),Z.end(),bottoms[i].second)-Z.begin();
    }
    ll preS[X.size()][Y.size()][Z.size()];
    rep(j,X.size())rep(k,Y.size())rep(l,Z.size())preS[j][k][l]=0;
    rep(i,N){
        rep(j,X.size()){
            rep(k,Y.size()){
                rep(l,Z.size()){
                    if(tops[i].first.first <= j
                    && bottoms[i].first.first > j
                    && tops[i].first.second <= k
                    && bottoms[i].first.second > k
                    && tops[i].second <= l
                    && bottoms[i].second > l
                    ){
                        preS[j][k][l]++;
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(j,X.size()){
        rep(k,Y.size()){
            rep(l,Z.size()){
                if(preS[j][k][l] >= K){
                    ans += (X[j+1]-X[j])*(Y[k+1]-Y[k])*(Z[l+1]-Z[l]);
                }
            }
        }
    }
    cout << ans << endl;
}