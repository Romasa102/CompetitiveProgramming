#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
using vd = vector<double>;
using vi = vector<double>;

double eps = 0.0000001;
int solveLinear(vector<vd>& A, vd& b, vd& x) {
        int n = (A).size(), m = (x).size(), rank = 0, br, bc;
        if (n) assert((A[0]).size() == m);
        vi col(m); iota((col).begin(),col.end(), 0);

        repp(i,0,n) {
                double v, bv = 0;
                repp(r,i,n) repp(c,i,m)
                        if ((v = fabs(A[r][c])) > bv)
                                br = r, bc = c, bv = v;
                if (bv <= eps) {
                        repp(j,i,n) if (fabs(b[j]) > eps) return -1;
                        break;
                }
                swap(A[i], A[br]);
                swap(b[i], b[br]);
                swap(col[i], col[bc]);
                repp(j,0,n) swap(A[j][i], A[j][bc]);
                bv = 1/A[i][i];
                repp(j,i+1,n) {
                        double fac = A[j][i] * bv;
                        b[j] -= fac * b[i];
                        repp(k,i+1,m) A[j][k] -= fac*A[i][k];
                }
                rank++;
        }

        x.assign(m, 0);
        for (int i = rank; i--;) {
                b[i] /= A[i][i];
                x[col[i]] = b[i];
                repp(j,0,i) b[j] -= A[j][i] * b[i];
        }
        return rank; // (multiple solutions if rank < m)
}

struct Tree {
        typedef double T;
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
int main(){
    ll n;cin >> n;
    Tree xsqrS(n);
    Tree xS(n);
    Tree yS(n);
    Tree xyS(n);
    double x[n],y[n];
    rep(i,n){
        cin >> x[i] >> y[i];
        xS.update(i,x[i]);
        yS.update(i,y[i]);
        xyS.update(i,x[i]*y[i]);
        xsqrS.update(i,x[i]*x[i]);
    }
    ll m;cin >> m;
    rep(_,m){
        double l,r,lambda,xin;
        cin >> l  >> r >> lambda >> xin;
        l--;r--;
        
        //aK+bB = c
        double a = xsqrS.query(l,r+1) +  lambda;
        double b =  xS.query(l,r+1);
        double c =  xyS.query(l,r+1);

        //dK+eB = f
        double d =  xS.query(l,r+1);
        double e =  lambda + (r-l+1);
        double f =  yS.query(l,r+1);
        //cout <<fixed <<setprecision(10);
        //cout << a << "K +  " << b << "B = " << c << endl;
        //cout << d << "K +  " << e << "B = " << f << endl;
        vector<vector<double>> A = {{a,b},{d,e}};
        vector<double> B = {c,f};
        vector<double> ans(2);
        solveLinear(A,B,ans);
        //cout << ans[0] << " " << ans[1] << endl;

        cout <<fixed <<setprecision(10)<< ans[0] * xin + ans[1] << endl;
    }
}