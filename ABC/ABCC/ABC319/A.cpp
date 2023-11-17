#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    map<string ,ll> ppl;
    ppl["tourist"]= 3858;
    ppl["ksun48"]= 3679;
    ppl["Benq"]= 3658;
    ppl["Um_nik"]= 3648;
    ppl["apiad"]= 3638;
    ppl["Stonefeang"]= 3630;
    ppl["ecnerwala"]= 3613;
    ppl["mnbvmar"]= 3555;
    ppl["newbiedmy"]= 3516;
    ppl["semiexp"]= 3481;
    string S;
    cin >> S;
    cout << ppl[S] << endl;
}