#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<P> pos(N);
    vector<ll> num(N);
    rep(i,N){
        ll a,b;
        num[i] = i;
        cin >> a >> b;
        pos[i] = {a,b};
    }
    sort(pos.begin(),pos.end());
    double sum = 0;
    ll time = 0;
    do{
        double len = 0;
        rep(i,N-1){
            len += sqrt((pos[num[i+1]].first - pos[num[i]].first) * (pos[num[i+1]].first - pos[num[i]].first) + (pos[num[i+1]].second - pos[num[i]].second) * (pos[num[i+1]].second - pos[num[i]].second));
        }
        time++;
        sum += len;
    }while(next_permutation(num.begin(),num.end()));
    cout << fixed << setprecision(8) << sum << endl;
}