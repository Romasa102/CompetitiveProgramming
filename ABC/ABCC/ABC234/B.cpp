#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
#include <math.h>
int main(){
    int N;
    cin >> N;
    vector<P> M;
    M.resize(N + 10);
    rep(i,N){
        cin >> M[i].first >> M[i].second;
    }
    double max = 0;
    rep(i,N){
        for (int j = i; j < N; j++)
        {
            ll le = pow((M[i].first - M[j].first),2.0) + pow((M[i].second - M[j].second),2.0);
            if(max < le){
                max = le;
            }
        }
    }
    double ans = sqrt(max);
    printf("%.15f\n", ans);
}