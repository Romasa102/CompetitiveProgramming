#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;

vector<P> prime_factorize(ll N) {
    vector<P> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
int main(){
    vector<ll> prime;
    ll N;
    cin >> N;

    vector<P> factor;
    factor = prime_factorize(N);
    ll Atleast = 0;
    rep(i,factor.size()){
        ll cash = factor[i].second;
        repp(j,1,factor[i].second+1){
            if(j%factor[i].first != 0){
                cash--;
            }else{
                ll divC = j;
                ll subA = 0;
                while(divC % factor[i].first == 0){
                    divC/=factor[i].first;
                    subA++;
                }
                cash-=subA;
            }
            if(cash <= 0){
                Atleast = max(Atleast,factor[i].first*j);
                break;
            }
        }
    }
    cout << Atleast << endl;
}