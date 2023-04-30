#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<double,double>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll A[K];
    vector<P> Npos(N);
    rep(i,K){
        cin >> A[i];
    }
    rep(i,N){
        cin >> Npos[i].first >> Npos[i].second;
    }
    double maxN[N];
    rep(i,N){
        maxN[i] = 10000000;
    }
    rep(i,N){
        rep(j,K){
            if(maxN[i] >= sqrt(pow((Npos[i].first - Npos[A[j]-1].first),2) + pow((Npos[i].second - Npos[A[j]-1].second),2))){
                maxN[i] = sqrt(pow((Npos[i].first - Npos[A[j]-1].first),2) + pow((Npos[i].second - Npos[A[j]-1].second),2));
            }
        }
    }
    double maxAns = 0;
    rep(i,N){
        cout << maxN[i] << endl;
        if(maxAns <= maxN[i]){
            maxAns = maxN[i];
        }
    }
    cout << fixed << setprecision(8)<< maxAns << endl;
}