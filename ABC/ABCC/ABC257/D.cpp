#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll x[N];
    ll y[N];
    ll p[N];
    rep(i,N){
        cin >> x[i] >> y[i] >> p[i];
    }
    ll minT = 0;
    ll maxT = 0;
    rep(i,N){
        rep(j,N){
            if(i != j){
                if((abs(x[i] - x[j]) + abs(y[i] - y[j]))%p[i] != 0){
                    minT = (abs(x[i] - x[j]) + abs(y[i] - y[j]))/p[i];
                }else{
                    minT = (abs(x[i] - x[j]) + abs(y[i] - y[j]))/p[i]+1;
                }
                if((abs(x[i] - x[j]) + abs(y[i] - y[j]))%p[j] != 0){
                    minT = min(minT,(abs(x[i] - x[j]) + abs(y[i] - y[j]))/p[j]);
                }else{
                    minT = min(minT,(abs(x[i] - x[j]) + abs(y[i] - y[j]))/p[j]+1);
                }

                if(minT > maxT){
                    maxT = minT;

                }
            }
        }
    }
    cout << maxT << endl;
}