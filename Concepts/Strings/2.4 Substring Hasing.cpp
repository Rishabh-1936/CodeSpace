#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

lli power(lli a, lli n){
    lli result = 1;
    while(n)
    {
        if(n&1){
            result = (result * a) % mod;
        }
        n >>= 1;
        a = (a * a) % mod;
    }
    return result;
}

void init(string input, vector<lli> &inv, vector<lli> &dp)
{
    lli p = 31;
    lli p_power = 1;
    inv[0] = 1;
    dp[0] = (input[0] - 'a' + 1);

    for(int i = 1; i < input.size(); ++i)
    {
        char ch = input[i];
        p_power = (p * p_power) % mod;
        
        inv[i] = power(p_power, mod - 2);

        dp[i] = dp[i-1] + ((ch - 'a' + 1) * p_power) % mod;
    }
}

lli substringHash(string input, int L, int R, vector<lli> &inv, vector<lli> &dp){
    lli result = dp[R];
    if(L>0){
        result -= dp[L-1];
    }
    result = (result * inv[L]) % mod;
    return result;
}

int main()
{
    int tc, L, R;
    string input;

    cin >> input;
    cin >> tc;
    
    vector<lli> dp(input.size());
    vector<lli> inv(input.size());
    
    init(input, dp, inv);

    while(tc--){
        cin >> L >> R;
        cout << substringHash(input, L, R, dp, inv) << endl;
    }


    return 0;
}