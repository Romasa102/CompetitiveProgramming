#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);
    ll N,M,R;cin >> N >> M >> R;
    deque<ll> cs(N);
    rep(i,N)cin >> cs[i];//milk to produce
    sort(cs.begin(),cs.end(),greater<ll>());

    vector<P> pq(M);
    rep(i,M)cin >> pq[i].second >> pq[i].first;//buy with p[i]/gallon up to q[i]
    sort(pq.begin(),pq.end(),greater<P>());
    pq.push_back({0,0});

    vector<ll> r(R);
    rep(i,R)cin >> r[i];//rent cow for r[i] per day
    sort(r.begin(),r.end(),greater<ll>());

    ll ans = 0;
    ll currentM = 0;//Milk we sold so far
    ll currentR = 0;//rental which have done so far.
    ll currentC = 0;
    while (currentC<N){
        ll moneyM = 0;
        ll cash = currentM;
        ll currentU = cs[currentC];
        ll last = 0;
        while (cash < M) {
            ll sold = min(currentU, pq[cash].second);
            moneyM += pq[cash].first * sold;
            currentU -= sold;
            if (currentU == 0) {
                last = sold;
                break;
            } else {
                cash++;
            }
        }
        if(currentR >= R || moneyM > r[currentR]){
            ans += moneyM;
            currentM = cash;
            if(currentM < M)pq[currentM].second-=last;
            currentC++;
        }else{
            ans += r[currentR];
            currentR++;
            N--;
        }
    }
    cout << ans << endl;
}