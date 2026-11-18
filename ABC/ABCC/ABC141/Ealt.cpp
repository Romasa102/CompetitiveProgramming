#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
#define sz(x) (x).size()
typedef uint64_t ull;
struct H {
        ull x; H(ull x=0) : x(x) {}
        H operator+(H o) { return x + o.x + (x + o.x < x); }
        H operator-(H o) { return *this + ~o.x; }
        H operator*(H o) { auto m = (__uint128_t)x * o.x;
                return H((ull)m) + (ull)(m >> 64); }
        ull get() const { return x + !~x; }
        bool operator==(H o) const { return get() == o.get(); }
        bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
        vector<H> ha, pw;
        HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
                pw[0] = 1;
                repp(i,0,sz(str))
                        ha[i+1] = ha[i] * C + str[i],
                        pw[i+1] = pw[i] * C;
        }
        H hashInterval(int a, int b) { // hash [a, b)
                return ha[b] - ha[a] * pw[b - a];
        }
};

vector<H> getHashes(string& str, int length) {
        if (sz(str) < length) return {};
        H h = 0, pw = 1;
        repp(i,0,length)
                h = h * C + str[i], pw = pw * C;
        vector<H> ret = {h};
        repp(i,length,sz(str)) {
                ret.push_back(h = h * C + str[i] - pw * str[i-length]);
        }
        return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = 0;
    repp(i,1,N){
        unordered_map<ull,ll> mp;
        vector<H> Shash = getHashes(S,i);
        rep(j,Shash.size()){
            if(mp.find(Shash[j].get())!=mp.end()){
                if(j-mp[Shash[j].get()] >= i){
                    ans=i;
                    break;
                }
            }else{
                mp[Shash[j].get()]=j;
            }
        }
    }
    cout << ans << endl;
}