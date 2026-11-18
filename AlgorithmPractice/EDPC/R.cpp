#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

const ll mod = 1e9+7;

template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		repp(i,0,N) repp(j,0,N)
			repp(k,0,N) a.d[i][k] =  (a.d[i][k] + d[i][j] * m.d[j][k])%mod;
		return a;
	}
	array<T, N> operator*(const array<T, N>& vec) const {
		array<T, N> ret{};
		repp(i,0,N) repp(j,0,N) ret[i] = (ret[i] + d[i][j] * vec[j])%mod;
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a, b(*this);
		repp(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = (a*b)%mod;
			b = (b*b)%mod;
			p >>= 1;
		}
		return a;
	}
};


Matrix<ll,50> pow(Matrix<ll,50> m, ll n){
    if(n==1)return m;
    if(n%2==0){
        return pow(m*m,n/2);
    }else{
        return pow(m*m,n/2) * m;
    }
}


int main(){
    ll N ,K;
    cin >> N >> K;
    ll a[N][N];
    rep(i,N)rep(j,N)cin >> a[i][j];
    Matrix<ll,50> M;
    rep(i,N){
        rep(j,N){
            M.d[i][j]=a[i][j];
        }
    }
    Matrix<ll,50> ans = pow(M,K);
    ll fans = 0;
    rep(i,50){
        rep(j,50){
            fans += (ans.d[i][j])%mod;
            fans %= mod;
        }
    }
    cout << fans << endl;
    
}