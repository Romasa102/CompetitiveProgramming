#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<double,double>;
struct Comp {
  bool operator()(const std::pair<double, ll> &a, const std::pair<double, ll> &b) {
    if (a.first != b.first) {
      return a.first < b.first;
    }
    return a.second >= b.second;
  }

};
int main(){
    ll N;
    cin >> N;
    vector<P> Flip(N);
    Comp comp_functor;
    rep(i,N){
        cin >> Flip[i].first >> Flip[i].second;
    }
    vector<pair<double,ll>> possibility(N
    );
    rep(i,N){
        possibility[i].first = Flip[i].first/(Flip[i].first+Flip[i].second);
        possibility[i].second = i;
    }
    sort(possibility.begin(),possibility.end(), comp_functor);
    rep(i,N){
        cout << possibility[N-i-1].second + 1 << " ";
    }cout << endl;
}