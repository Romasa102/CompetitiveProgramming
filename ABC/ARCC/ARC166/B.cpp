#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
int main(){
    ll N;
    ll a,b,c;
    cin >>N >> a >> b >> c;
    ll Num[N];
    rep(i,N){
        cin >> Num[i];
    }

    priority_queue<P,vector<P>,greater<P>> A;
    priority_queue<P,vector<P>,greater<P>> B;
    priority_queue<P,vector<P>,greater<P>> C;
    priority_queue<P,vector<P>,greater<P>> AB;
    priority_queue<P,vector<P>,greater<P>> AC;
    priority_queue<P,vector<P>,greater<P>> BC;
    priority_queue<P,vector<P>,greater<P>> ABC;
    ll ab = lcm(a,b);
    ll ac = lcm(a,c);
    ll bc = lcm(b,c);
    ll abc = lcm(a,bc);
    rep(i,N){
        if(Num[i]%a == 0){
            A.push({0,i});
        }else{
            A.push({((Num[i]/a)+1)*a-Num[i],i});
        }
        if(Num[i]%b == 0){
            B.push({0,i});
        }else{
            B.push({((Num[i]/b)+1)*b-Num[i],i});
        }
        if(Num[i]%c == 0) {
            C.push({0, i});
        }else{
            C.push({((Num[i]/c)+1)*c-Num[i],i});
        }
        if(Num[i]%ab == 0) {
            AB.push({0, i});
        }else{
            AB.push({((Num[i]/ab)+1)*ab-Num[i],i});
        }
        if(Num[i]%ac == 0) {
            AC.push({0, i});
        }else{
            AC.push({((Num[i]/ac)+1)*ac-Num[i],i});
        }
        if(Num[i]%bc == 0) {
            BC.push({0, i});
        }else{
            BC.push({((Num[i]/bc)+1)*bc-Num[i],i});
        }
        if(Num[i]%abc == 0) {
            ABC.push({0, i});
        }else{
            ABC.push({((Num[i]/abc)+1)*abc-Num[i],i});
        }
    }
    ll indivisualMin = 1LL<<50;
    ll ABAC = 1LL<<50;
    ll ACAB = 1LL<<50;
    ll BCAA = 1LL<<50;
    ll ABCA = 1LL<<50;
    ABCA = ABC.top().first;
    if(N>=2){
        if(BC.top().second!=A.top().second){
            BCAA = BC.top().first+A.top().first;
        }else{
            P cash1 = BC.top();
            P cash2 = A.top();
            BC.pop();
            A.pop();
            BCAA = min(cash1.first+A.top().first,BC.top().first+cash2.first);
            BC.push(cash1);
            A.push(cash2);
        }
        if(AC.top().second!=B.top().second){
            ACAB = AC.top().first+B.top().first;
        }else{
            P cash1 = AC.top();
            P cash2 = B.top();
            AC.pop();
            B.pop();
            ACAB = min(cash1.first+B.top().first,AC.top().first+cash2.first);
            AC.push(cash1);
            B.push(cash2);
        }
        if(AB.top().second!=C.top().second){
            ABAC = AB.top().first+C.top().first;
        }else{
            P cash1 = AB.top();
            P cash2 = C.top();
            AB.pop();
            C.pop();
            ABAC = min(cash1.first+C.top().first,AB.top().first+cash2.first);
            AB.push(cash1);
            C.push(cash2);
        }
    }
    if(N>=3){

        if(A.top().second!=B.top().second && C.top().second!=A.top().second && A.top().second != C.top().second){
            indivisualMin = A.top().first+B.top().first+C.top().first;
        }
        else if(A.top().second == B.top().second && A.top().second != C.top().second){
            P cash1 = A.top();
            P cash2 = B.top();
            A.pop();
            B.pop();
            indivisualMin = min(cash1.first+B.top().first,A.top().first+cash2.first);
            A.push(cash1);
            B.push(cash2);
        }else if(A.top().second == C.top().second && A.top().second != B.top().second) {
            P cash1 = A.top();
            P cash2 = C.top();
            A.pop();
            C.pop();
            indivisualMin = min((cash1.first+C.top().first), (A.top().first+ cash2.first));
            A.push(cash1);
            C.push(cash2);
        }else if(B.top().second == C.top().second && A.top().second != B.top().second) {
            P cash1 = B.top();
            P cash2 = C.top();
            B.pop();
            C.pop();
            indivisualMin = min((cash1.first+ C.top().first), (B.top().first+cash2.first));
            B.push(cash1);
            C.push(cash2);
        }
    }

    cout << min({indivisualMin,ABAC,ACAB,BCAA,ABCA}) << endl;
}