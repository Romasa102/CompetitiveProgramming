#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
#define sz(x) x.size()

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
    string origS,t;cin >> origS >> t;
    string s = "";
    while(s.size() < t.size()){
        s.append(origS);
    }
    s.append(s + s);
    ll low = 0;
    ll high = (s.size()/t.size()+1); //[low,high) //include low excude high
    string hSd[20];
    hSd[0]=t;
    repp(i,1,20){
        hSd[i] = hSd[i-1] + hSd[i-1];

        if(hSd[i].size() > 10100100)break;
    }
    string largeS = s+s;
    HashInterval hashInt = HashInterval(largeS);
    while(high - low > 1){
        ll mid = (low+high)/2;
        //cout << mid << endl;
        bool condition = false;

        string newT = "";
        rep(i,20){
            if(1<<i & mid){
                newT.append(hSd[i]);
            }
        }
        H cur = hashString(newT);
        //cout << s << " and " << endl << newT << " is tested" << endl;
        rep(j,s.size()-(newT.size())+1){
            if(hashInt.hashInterval(j,j+newT.size()).get()==cur.get()){
                //cout << "worked!!" << endl;
                condition=true;
                break;
            }
        }
        if(condition){
            //cout << mid << " worked!" << endl;
            low = mid;
        }else{
            high = mid;
        }
    }
    //cout << "original iteration finished " << endl;
    string newT = "";
    rep(i,20){
        if(1<<i & (low+1)){
            newT.append(hSd[i]);
        }
    }
    H cur = hashString(newT);
    rep(j,s.size()*2-newT.size()+1){
        if(hashInt.hashInterval(j,j+newT.size()).get()==cur.get()){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << low << endl;
}