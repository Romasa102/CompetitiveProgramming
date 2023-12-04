#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;//N<=5
    string R,C;
    cin >> N >> R >> C;//R from the left, C is from the top.
    vector<ll> row;
    vector<char> cash={'A','B','C'};
    rep(i,N-3)cash.push_back('.');
    sort(cash.begin(),cash.end());
    vector<string> rows[3];
    do{
        rep(i,N){
            if(cash[i]=='A'){
                string lo;
                rep(j,N)lo.push_back(cash[j]);
                rows[0].push_back(lo);
                break;
            }
            if(cash[i]=='B'){
                string lo;
                rep(j,N)lo.push_back(cash[j]);
                rows[1].push_back(lo);
                break;
            }
            if(cash[i]=='C'){
                string lo;
                rep(j,N)lo.push_back(cash[j]);
                rows[2].push_back(lo);
                break;
            }
        }
    }while(next_permutation(cash.begin(),cash.end()));
    rep(i,rows[R[0]-'A'].size()){
        rep(j,rows[R[1]-'A'].size()){
            rep(k,rows[R[2]-'A'].size()){
                if(N>3){
                    rep(l,rows[R[3]-'A'].size()){
                        if(N>4){
                            rep(o,rows[R[4]-'A'].size()){
                                string hey;
                                vector<ll>numU;
                                bool doesnW = false;
                                rep(m,5){
                                    bool a = false;
                                    bool b = false;
                                    bool c = false;
                                    if(rows[R[0]-'A'][i][m]=='A'){
                                        a=true;
                                    }
                                    if(rows[R[1]-'A'][j][m]=='A'){
                                        if(a){
                                            doesnW=true;
                                        }
                                        a=true;
                                    }
                                    if(rows[R[2]-'A'][k][m]=='A'){
                                        if(a){
                                            doesnW=true;
                                        }
                                        a=true;
                                    }
                                    if(rows[R[3]-'A'][l][m]=='A'){
                                        if(a){
                                            doesnW=true;
                                        }
                                        a=true;
                                    }
                                    if(rows[R[4]-'A'][o][m]=='A'){
                                        if(a){
                                            doesnW=true;
                                        }
                                        a=true;
                                    }if(rows[R[0]-'A'][i][m]=='B'){
                                        b=true;
                                    }
                                    if(rows[R[1]-'A'][j][m]=='B'){
                                        if(b){
                                            doesnW=true;
                                        }
                                        b=true;
                                    }
                                    if(rows[R[2]-'A'][k][m]=='B'){
                                        if(b){
                                            doesnW=true;
                                        }
                                        b=true;
                                    }
                                    if(rows[R[3]-'A'][l][m]=='B'){
                                        if(b){
                                            doesnW=true;
                                        }
                                        b=true;
                                    }
                                    if(rows[R[4]-'A'][o][m]=='B'){
                                        if(b){
                                            doesnW=true;
                                        }
                                        b=true;
                                    }if(rows[R[0]-'A'][i][m]=='C'){
                                        c=true;
                                    }
                                    if(rows[R[1]-'A'][j][m]=='C'){
                                        if(c){
                                            doesnW=true;
                                        }
                                        c=true;
                                    }
                                    if(rows[R[2]-'A'][k][m]=='C'){
                                        if(c){
                                            doesnW=true;
                                        }
                                        c=true;
                                    }
                                    if(rows[R[3]-'A'][l][m]=='C'){
                                        if(c){
                                            doesnW=true;
                                        }
                                        c=true;
                                    }
                                    if(rows[R[4]-'A'][o][m]=='C'){
                                        if(c){
                                            doesnW=true;
                                        }
                                        c=true;
                                    }
                                }
                                rep(m,5){
                                    if(rows[R[0]-'A'][i][m]!='.'){
                                        hey.push_back(rows[R[0]-'A'][i][m]);
                                        numU.push_back(0);
                                        continue;
                                    }
                                    if(rows[R[1]-'A'][j][m]!='.'){
                                        hey.push_back(rows[R[1]-'A'][j][m]);
                                        numU.push_back(1);
                                        continue;
                                    }
                                    if(rows[R[2]-'A'][k][m]!='.'){
                                        hey.push_back(rows[R[2]-'A'][k][m]);
                                        numU.push_back(2);
                                        continue;
                                    }
                                    if(rows[R[3]-'A'][l][m]!='.'){
                                        hey.push_back(rows[R[3]-'A'][l][m]);
                                        numU.push_back(3);
                                        continue;
                                    }
                                    if(rows[R[4]-'A'][o][m]!='.'){
                                        hey.push_back(rows[R[4]-'A'][o][m]);
                                        numU.push_back(4);
                                        continue;
                                    }
                                    break;
                                }
                                if(hey == C&& !doesnW) {
                                    cout << "Yes" << endl;
                                    cout << rows[R[0]-'A'][i] << endl;
                                    cout << rows[R[1]-'A'][j] << endl;
                                    cout << rows[R[2]-'A'][k] << endl;
                                    cout << rows[R[3]-'A'][l] << endl;
                                    cout << rows[R[4]-'A'][o] << endl;
                                    return 0;
                                }
                            }
                        }else{ //if length is 4
                            string hey;
                            vector<ll>numU;
                            bool doesnW = false;
                            rep(m,4){
                                bool a = false;
                                bool b = false;
                                bool c = false;
                                if(rows[R[0]-'A'][i][m]=='A'){
                                    a=true;
                                }
                                if(rows[R[1]-'A'][j][m]=='A'){
                                    if(a){
                                        doesnW=true;
                                    }
                                    a=true;
                                }
                                if(rows[R[2]-'A'][k][m]=='A'){
                                    if(a){
                                        doesnW=true;
                                    }
                                    a=true;
                                }
                                if(rows[R[3]-'A'][l][m]=='A'){
                                    if(a){
                                        doesnW=true;
                                    }
                                    a=true;
                                }
                                if(rows[R[0]-'A'][i][m]=='B'){
                                    b=true;
                                }
                                if(rows[R[1]-'A'][j][m]=='B'){
                                    if(b){
                                        doesnW=true;
                                    }
                                    b=true;
                                }
                                if(rows[R[2]-'A'][k][m]=='B'){
                                    if(b){
                                        doesnW=true;
                                    }
                                    b=true;
                                }
                                if(rows[R[3]-'A'][l][m]=='B'){
                                    if(b){
                                        doesnW=true;
                                    }
                                    b=true;
                                }
                                if(rows[R[0]-'A'][i][m]=='C'){
                                    c=true;
                                }
                                if(rows[R[1]-'A'][j][m]=='C'){
                                    if(c){
                                        doesnW=true;
                                    }
                                    c=true;
                                }
                                if(rows[R[2]-'A'][k][m]=='C'){
                                    if(c){
                                        doesnW=true;
                                    }
                                    c=true;
                                }
                                if(rows[R[3]-'A'][l][m]=='C'){
                                    if(c){
                                        doesnW=true;
                                    }
                                    c=true;
                                }
                            }
                            rep(m,4){
                                if(rows[R[0]-'A'][i][m]!='.'){
                                    hey.push_back(rows[R[0]-'A'][i][m]);
                                    numU.push_back(0);
                                    continue;
                                }
                                if(rows[R[1]-'A'][j][m]!='.'){
                                    hey.push_back(rows[R[1]-'A'][j][m]);
                                    numU.push_back(1);
                                    continue;
                                }
                                if(rows[R[2]-'A'][k][m]!='.'){
                                    hey.push_back(rows[R[2]-'A'][k][m]);
                                    numU.push_back(2);
                                    continue;
                                }
                                if(rows[R[3]-'A'][l][m]!='.'){
                                    hey.push_back(rows[R[3]-'A'][l][m]);
                                    numU.push_back(3);
                                    continue;
                                }
                                break;
                            }
                            if(hey == C && !doesnW){
                                cout << "Yes" << endl;
                                cout << rows[R[0]-'A'][i] << endl;
                                cout << rows[R[1]-'A'][j] << endl;
                                cout << rows[R[2]-'A'][k] << endl;
                                cout << rows[R[3]-'A'][l] << endl;
                                return 0;
                            }
                        }
                    }
                }else{
                    string hey;
                    vector<ll>numU;
                    bool doesnW = false;
                    rep(m,3){
                        bool a = false;
                        bool b = false;
                        bool c = false;
                        if(rows[R[0]-'A'][i][m]=='A'){
                            a=true;
                        }
                        if(rows[R[1]-'A'][j][m]=='A'){
                            if(a){
                                doesnW=true;
                            }
                            a=true;
                        }
                        if(rows[R[2]-'A'][k][m]=='A'){
                            if(a){
                                doesnW=true;
                            }
                            a=true;
                        }
                        if(rows[R[0]-'A'][i][m]=='B'){
                            b=true;
                        }
                        if(rows[R[1]-'A'][j][m]=='B'){
                            if(b){
                                doesnW=true;
                            }
                            b=true;
                        }
                        if(rows[R[2]-'A'][k][m]=='B'){
                            if(b){
                                doesnW=true;
                            }
                            b=true;
                        }
                        if(rows[R[0]-'A'][i][m]=='C'){
                            c=true;
                        }
                        if(rows[R[1]-'A'][j][m]=='C'){
                            if(c){
                                doesnW=true;
                            }
                            c=true;
                        }
                        if(rows[R[2]-'A'][k][m]=='C'){
                            if(c){
                                doesnW=true;
                            }
                            c=true;
                        }
                    }
                    rep(m,N){
                        if(rows[R[0]-'A'][i][m]!='.'){
                            hey.push_back(rows[R[0]-'A'][i][m]);
                            numU.push_back(0);
                            continue;
                        }
                        if(rows[R[1]-'A'][j][m]!='.'){
                            hey.push_back(rows[R[1]-'A'][j][m]);
                            numU.push_back(1);
                            continue;
                        }
                        if(rows[R[2]-'A'][k][m]!='.'){
                            hey.push_back(rows[R[2]-'A'][k][m]);
                            numU.push_back(2);
                            continue;
                        }
                        break;
                    }
                    if(hey == C && !doesnW){
                        cout << "Yes" << endl;
                        cout << rows[R[0]-'A'][i] << endl;
                        cout << rows[R[1]-'A'][j] << endl;
                        cout << rows[R[2]-'A'][k] << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return  0;
}