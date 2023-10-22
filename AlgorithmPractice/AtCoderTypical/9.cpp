#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll X[N];
    ll Y[N];
    rep(i,N){
        cin >> X[i] >> Y[i];
    }

    rep(i,N){
        vector<ll> angle;
        rep(j,N){
            if(i==j)continue;
            ll An = atan2((Y[i]-Y[j]),(X[i]-X[j]));
            angle.push_back(An*180/M_PI);
            cout << i << " " << j << "    " << An*180/M_PI << endl;
        }
    }
}