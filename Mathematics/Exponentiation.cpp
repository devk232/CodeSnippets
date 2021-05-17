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

int main() {
    cout << power(2,10) << endl;
}
