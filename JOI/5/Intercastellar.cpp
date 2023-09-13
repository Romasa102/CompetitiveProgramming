#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    deque<P> castellar;
    rep(i,N){
        ll cash = A[i];
        ll count = 1;
        while (cash % 2 == 0){
            cash /= 2;
            count*=2;
        }
        castellar.push_back({cash,count});
    }
    ll Q;
    cin >> Q;
    ll current = 0;
    rep(i,Q){
        ll que;
        cin >> que;
        que-=current;
        current+=que;
        while(que > castellar.front().second){
            que -= castellar.front().second;
            castellar.pop_front();
        }
        castellar.front().second -= que;
        cout << castellar.front().first << endl;
    }
}