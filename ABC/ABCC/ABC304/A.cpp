#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    pair<ll,string> m[N];
    ll minN = 0;
    rep(i,N){
        cin >> m[i].second >> m[i].first;
        if(m[i].first < m[minN].first){
            minN = i;
        }
    }
    for(int i = minN; i < N; i++){
        cout << m[i].second << endl;
    }
    for(int i = 0; i < minN; i++){
        cout << m[i].second << endl;
    }
}