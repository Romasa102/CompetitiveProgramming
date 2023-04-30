#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int len = S.length();
    int counter = 0;
    bool ans = true;
    bool odeta = false;
    int xcount = 0;
    for (int i = 0; i < len; i++)
    {        
        if(S[i] == 'o'){
            counter += 2;
            if(odeta == false){
                odeta = true;
            }
        }else if(S[i] == 'x'){
            if(odeta == false){
                xcount++;
            }else{
                counter--;
            }
        }
        if(counter > 2 || counter < 0 || xcount > 2){
            ans = false;
            break;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}