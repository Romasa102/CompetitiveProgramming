#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    set<string> P;
    multiset<string> M;
    for (int i = 0; i < N; i++)
    {        
        string S;
        cin >> S;
        P.insert(S);
        M.insert(S);
    }
    long unsigned int biggest = 0;
    string ans;
    for(auto itr = P.begin(); itr != P.end(); ++itr) {        
        if(M.count(*itr) >= biggest){
            biggest = M.count(*itr);
            ans = *itr;
        }
    }
    cout << ans << endl;
}