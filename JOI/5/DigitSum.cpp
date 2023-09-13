#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    set<ll> possiblity;
    possiblity.insert(N);
    queue<ll> Q;
    Q.push(N);
    while (!Q.empty()){
        ll search = Q.front();
        Q.pop();
        repp(i,1,57){
            ll cash = search - i;
            if(cash <= 0){
                break;
            }
            ll DigSum = 0;
            while(cash > 0){
                DigSum+=cash%10;
                cash /= 10;
            }
            if(DigSum == i){
                possiblity.insert(search - i);
                Q.push(search - i);
            }
        }
    }
    cout << possiblity.size() << endl;
}