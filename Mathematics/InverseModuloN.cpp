#include <bits/stdc++.h>
#define ll long long 
using namespace std;

// this function returns a^b in log(b) time complexity
ll power(int a, int b, int mod = 1e9 + 7) {
    ll ans = 1;
    while(b) {
        if(b%2)
            ans = (ans*a)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

// this fuunction calculates b^(-1) modulo n (based on fermat's first theorem)
ll inv(int b, int mod = 1e7 + 9) {
    return power(b, mod - 2);
}