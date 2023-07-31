#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
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
    vector<pair<string,string>> FlipI(N);
    Comp comp_functor;
    rep(i,N){
        cin >> FlipI[i].first >> FlipI[i].second;
    }
    vector<pair<double,double>> Flip(N);
    rep(i,N){
        string ADDV;
        ADDV = "0.";
        rep(j,12-FlipI[i].first.size()){
            ADDV = ADDV + "0";
        }
        FlipI[i].first = ADDV + FlipI[i].first;
        Flip[i].first = stod(FlipI[i].first);
    }
    rep(i,N){
        string ADDV;
        ADDV = "0.";
        rep(j,12-FlipI[i].second.size()){
            ADDV = ADDV + "0";
        }
        FlipI[i].second = ADDV + FlipI[i].second;
        Flip[i].second = stod(FlipI[i].second);
    }
    vector<pair<double,ll>> possibility(N);
    rep(i,N){
        possibility[i].first = (double)Flip[i].first/(Flip[i].first+Flip[i].second);
        possibility[i].second = i;
    }
    sort(possibility.begin(),possibility.end(), comp_functor);
    rep(i,N){
        cout << possibility[N-i-1].second + 1 << " ";
    }cout << endl;
}