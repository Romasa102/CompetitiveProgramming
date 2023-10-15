#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
bool compare(P a, P b) {
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}
int main(){
    ll N;
    cin >> N;
    P score[N];
    rep(i,N){
        string S;
        cin >> S;
        score[i].second = i+1;
        score[i].first = 0;
        rep(j,N){
            if(S[j] == 'o'){
                score[i].first++;
            }
        }
    }
    sort(score,score+N, compare);
    rep(i,N){
        cout << score[i].second << " ";
    }cout << endl;
}