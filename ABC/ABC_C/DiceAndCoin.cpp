#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    double N,K;
    cin >> N >> K;
    double percentage = 0;
    rep(i,N){
        double score = i+1;
        double per = 1/N;
        while(score < K){
            per/=2;
            score*=2;
        }
        percentage+=per;
    }
    cout << fixed << setprecision(12) <<percentage << endl;
}