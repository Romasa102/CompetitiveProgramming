#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;

//int N, Q;
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
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];

        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int main(){
    ll N,D;
    cin >> N >> D;
    ll A[N];rep(i,N)cin >> A[i];
    vector<ll> dp(N,1);
    SegmentTree st(vector<int>(600000,0));
    rep(i,N){
        dp[i] = dp[i] + st.getmax(max(0LL,A[i]-D),min(A[i]+D+1,600000LL));
        st.update(A[i],dp[i]);
    }
    cout << st.getmax(0,600000) <<  endl;
}