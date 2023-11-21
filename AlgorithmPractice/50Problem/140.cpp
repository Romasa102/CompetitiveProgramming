#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;

int N, Q;
int const INF = INT_MAX;

struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};
int main(){
    ll n,xn;
    cin >> n >> xn;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    SegmentTree seg( a );
    ll ansF = 1LL<<60;
    rep(i,n){
        ll ans = i*xn;
        rep(j,n){
            if(j-i<0){
                ans+=min(seg.getmin(0,j+1),seg.getmin(n+(j-i),n));
            }else{
                ans += seg.getmin(j-i,j+1);
            }
        }
        ansF=min(ans,ansF);
    }
    cout<<ansF<<endl;
}