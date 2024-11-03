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
                lazy[k*2+1] += lazy[k]/2;
                lazy[k*2+2] += lazy[k]/2;
            }
            lazy[k] = 0;
        }
    }
    void add(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1){
        if(r < 0)r = N;
        eval(k,l,r);
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            lazy[k] += (r-l)*x;
            eval(k,l,r);
        }else{
            add(a,b,x,k*2+1,l,(l+r)/2);
            add(a,b,x,k*2+2,(l+r)/2,r);
            node[k] = node[k*2+1] + node[k*2+2];
        }
    }
    ll getnumber(ll a, ll b, ll k = 0, ll l = 0, ll r = -1){
        if(r < 0)r = N;
        eval(k,l,r);
        if(b <= l || r <= a)return 0;
        if(a <= l && r <= b)return node[k];
        ll vl = getnumber(a,b,k*2+1,l,(l+r)/2);
        ll vr = getnumber(a,b,k*2+2,(l+r)/2,r);
        return vl + vr;
    }
};
int main(){
    ll N,M;cin >> N >> M;
    vector<ll> A(N),B(M);
    rep(i,N)cin >> A[i];
    rep(i,M)cin >> B[i];
    LazySegmentTree seg(A);
    rep(i,M){
        ll cur = seg.getnumber(B[i],B[i]+1);
        seg.add(B[i],B[i]+1,-cur);
        if(cur > N){
            seg.add(0,N,cur/N);
            cur%=N;
        }
        if(B[i] + cur + 1 <= N){
            seg.add(B[i]+1,B[i]+cur+1,1);
        }else{
            if(N == 1&&cur == 1){
                seg.add(0,1,1);
                continue;
            }
            seg.add(B[i]+1,N,1);
            seg.add(0,(B[i]+cur+1)%N,1);
        }
    }
    rep(i,N){
        cout << seg.getnumber(i,i+1) << " ";
    }
}