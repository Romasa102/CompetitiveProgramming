#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

// Either globally or in a single class:
static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const ll inf = 1LL<<50;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = -inf;
	Node(ll lo,ll hi):lo(lo),hi(hi){} // Large llerval of -inf
	Node(vector<ll>& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(ll L, ll R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main(){
    ll N,M;
    cin >> N >> M;
    ll l[M],r[M],a[M];
    vector<ll> vc(N,0);
    Node * tr = new Node(vc,0,vc.size());
    map<ll,vector<P>> rng;
    rep(i,M){
        cin >> l[i] >> r[i] >> a[i];
        l[i]--;r[i]--;
        rng[r[i]].push_back({l[i],a[i]});
    }
    rep(i,N){
        tr->set(i,i+1,max(0LL,i ? tr->query(0,i) : 0));
        
        for(auto rn : rng[i]){
            tr->add(rn.first,i+1,rn.second);
        }
    }
    cout << max(0LL,tr->query(0,N)) << endl;
}