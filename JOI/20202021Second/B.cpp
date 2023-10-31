#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll vertex[2594323];
vector<string> StartV;
bool searched[2594323];
ll N,Q;
int encode(const string &S) {
    int res = 0;
    for (auto c: S) res = res * 3 + (c - 'A');
    return res;
}

// 整数値から文字列へ
string decode(int n, int val) {
    string res = "";
    while (val) {
        res += (char)('A' + (val%3));
        val /= 3;
    }
    while (res.size() < n) res += 'A';
    reverse(res.begin(), res.end());
    return res;
}
bool check(string S){
    ll Adone=false;
    ll Bdone=false;
    rep(i,S.size()){
        if(S[i]=='A'){
            if(Adone){
                return false;
            }
        }else if(S[i]=='B'){
            Adone=true;
            if(Bdone){
                return false;
            }
        }else{
            Adone=true;
            Bdone=true;
        }
    }
    return true;
}
void addV(ll a,string b){
    if(a == N){
        vertex[encode(b)]=1LL<<32;
        searched[encode(b)]=false;
        if(check(b)){
            vertex[encode(b)]=0;
            StartV.push_back(b);
        }
    }else{
        addV(a+1,b+'A');
        addV(a+1,b+'B');
        addV(a+1,b+'C');
    }
}
int main(){
    cin >> N >> Q;
    string S[Q];
    queue<P> Qp;
    addV(0,"");
    rep(i,StartV.size()){
        Qp.push({0,encode(StartV[i])});
    }
    while(!Qp.empty()){
        string cur = decode(N,Qp.front().second);
        ll dis = Qp.front().first;
        Qp.pop();
        if(searched[encode(cur)])continue;
        searched[encode(cur)]=true;
        vertex[encode(cur)]=min(vertex[encode(cur)],dis);
        repp(i,1,N+1){
            string nstr = cur;
            reverse(nstr.begin(),nstr.begin()+i);
            if(!searched[encode(nstr)]){
                Qp.push({dis+1,encode(nstr)});
            }
        }
    }
    rep(i,Q){
        cin >> S[i];
        cout << vertex[encode(S[i])] << endl;
    }
}