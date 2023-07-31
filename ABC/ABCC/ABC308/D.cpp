#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
string S[600];
bool visited[600][600];
ll H,W;
void dfs(ll pos1,ll pos2){
    char charN;
    visited[pos1][pos2] = true;
    if(S[pos1][pos2] == 's'){
        charN = 'n';
    }else if(S[pos1][pos2] == 'n'){
        charN = 'u';
    }else if(S[pos1][pos2] == 'u'){
        charN = 'k';
    }else if(S[pos1][pos2] == 'k'){
        charN = 'e';
    }else if(S[pos1][pos2] == 'e'){
        charN = 's';
    }
    if(pos1>=W-1 && visited[pos1+1][pos2] == false && S[pos1+1][pos2] == charN){
        dfs(pos1+1,pos2);
    }
    if(pos1<=0 && visited[pos1-1][pos2] == false && S[pos1-1][pos2] == charN){
        dfs(pos1-1,pos2);
    }
    if(pos2>=H-1 && visited[pos1][pos2+1] == false && S[pos1][pos2+1] == charN){
        dfs(pos1,pos2+1);
    }
    if(pos2<=0 && visited[pos1][pos2-1] == false && S[pos1][pos2-1] == charN){
        dfs(pos1,pos2-1);
    }return;
}
int main(){
    cin >> H >> W;
    rep(i,H){
        cin >> S[i];
    }
    dfs(0,0);
    if(visited[H-1][W-1] == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}