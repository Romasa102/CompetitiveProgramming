#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
struct LazySegmentTree{
    ll N;
    vector<ll> node, lazy;
    LazySegmentTree(vector<ll> v){
        N = 1;
        while(N < v.size()) N *= 2;
        node.resize(2*N-1, 0);
        lazy.resize(2*N-1, 0);
        for(ll i = 0; i < v.size(); ++i) node[i+N-1] = v[i];
        for(ll i = N-2; i >= 0; --i) node[i] = min(node[i*2+1], node[i*2+2]);
    }
    void eval(ll k, ll l, ll r){
        if(lazy[k] != 0){
            node[k] += lazy[k];
            if(r - l > 1){
                lazy[k*2+1] += lazy[k];
                lazy[k*2+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    void add(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1){
        if(r < 0)r = N;
        eval(k,l,r);
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            lazy[k] += x;
            eval(k,l,r);
        }else{
            add(a,b,x,k*2+1,l,(l+r)/2);
            add(a,b,x,k*2+2,(l+r)/2,r);
            node[k] = min(node[k*2+1],node[k*2+2]);
        }
    }
    ll getmin(ll a, ll b, ll k = 0, ll l = 0, ll r = -1){
        if(r < 0) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return LLONG_MAX; // return maximum possible value when out of range
        if(a <= l && r <= b) return node[k];
        ll vl = getmin(a, b, k*2+1, l, (l+r)/2);
        ll vr = getmin(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }
};
int main(){
    ll T;cin >> T;
    rep(i,T){
        ll N,M,K;cin >> N >> M >> K;
        vector<vector<ll>> A(M,vector<ll>(K));
        vector<ll> evenM(M,0);
        vector<ll> oddM(M,0);
        vector<ll> InitialChoice;
        vector<ll> currentState(M);
        bool done = false;
        ll baseC = 0;
        rep(j,M){
            ll evenm = 1LL<<30;ll oddm = 1LL<<30;
            rep(k,K){
                cin >> A[j][k];
                if(A[j][k]%2 == 1){
                    evenM[j] = max(evenM[j],A[j][k]);
                    evenm = min(evenm,A[j][k]);
                }else{
                    oddM[j] = max(oddM[j],A[j][k]);
                    oddm = min(oddm,A[j][k]);
                }
            }
            if(evenM[j] == 0)evenM[j] = -oddm;
            if(oddM[j] == 0)oddM[j] = -evenm;
            if(evenM[j] <= oddM[j]){
                InitialChoice.push_back(0);
                baseC += evenM[j];
            }else{
                InitialChoice.push_back(1);
                baseC += oddM[j];
            }
            currentState[j] = N-baseC;
            if(currentState[j] <= 0){
                cout << -1 << endl;
                done = true;
                break;
            }
        }
        if(done)continue;
        LazySegmentTree seg(currentState);
        ll remain = N-baseC;
        if(remain <= 0){
            cout << -1 << endl;
            continue;
        }
        rep(j,M){
            if(InitialChoice[j] == 0){
                if(j == M-1){
                    cout << "Even";
                }else{
                    cout << "Even ";
                }
            }else{
                ll change = (evenM[j] - oddM[j]);
                ll cur = seg.getmin(j,M);
                if(cur > change){
                    if(j == M-1){
                        cout << "Even";
                    }else{
                        cout << "Even ";
                    }
                    seg.add(j,M,-change);
                }else{
                    if(j == M-1){
                        cout << "Odd";
                    }else{
                        cout << "Odd ";
                    }
                }
            }
        }
        cout << endl;
    }
}