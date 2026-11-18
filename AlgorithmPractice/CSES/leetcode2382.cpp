#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    
}
using ll = long long;
class Solution {

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return (a + b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


struct TreeMax {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMax(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


struct TreeMin {
	typedef ll T;
	static constexpr T unit = -1;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMin(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        set<ll> removedLine;
        ll N = nums.size();
        TreeMax treeM(N,N);
        TreeMin treem(N);
        Tree tree(N);
        multiset<ll> mp;
        for(int i = 0; i < N; i++){
            tree.update(i,nums[i]);
        }
        mp.insert(tree.query(0,N));
        vector<ll> fans;
        for(int i = 0; i < removeQueries.size(); i++){
            removedLine.insert(removeQueries[i]);

            ll a = treeM.query(0,removeQueries[i]-1);
            ll b = treem.query(removeQueries[i],N);
            ll ans = tree.query(a,b);
            mp.erase(ans);
            ans = tree.query(a+1,removeQueries[i]);
            ll ans2 = tree.query(removeQueries[i]+1, b);
            mp.insert(ans);
            mp.insert(ans2);
            treeM.update(removeQueries[i],removeQueries[i]);
            treem.update(removeQueries[i],removeQueries[i]);
            cout << *mp.rbegin() << endl;
            fans.push_back(*mp.rbegin());
        }
        return fans;
    }
};