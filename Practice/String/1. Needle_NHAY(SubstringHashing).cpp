/*
    SPOJ Problem : NHAY : https://www.spoj.com/problems/NHAY/

    Approach:
    1. Efficient approach can be KMP algorithm
    2. Brute Force: Compare by using the sliding window
    3. Implemented Approach:
    The current approach is the combination of sliding window, hashing and substring hashing.
    Instead of comparing the each character of needle with the each character of haystack, we are comparing the hash value.
    If the hash values are equal then we found the substrung needle pattern inside the haystack string.
*/

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

lli power(lli a, lli n)
{
    lli result = 1;
    while(n)
    {
        if(n & 1){
            result = (result * a) % mod ;
        }
        n >>= 1;
        a = (a * a) % mod ;
    }
    return result;
}

lli getHash(string key)
{
    lli p_power = 1, p = 31, result = 0;

    for(auto ch: key){
        result = (result + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }
    return result;
}

void init(string haystack, vector<lli> &dp, vector<lli> &inv, int len){
    lli p = 31, p_power = 1;
    inv[0] = 1;
    dp[0] = haystack[0] - 'a' + 1;

    for(int i = 1; i < len; ++i)
    {
        p_power =  power(p , i);
        dp[i] = (dp[i-1] + (haystack[i] - 'a' + 1) * p_power) % mod;
        inv[i] = power(p_power, mod - 2);
    }
}

lli getSubstringHash(int L, int R, vector<lli> &dp, vector<lli> &inv)
{
    lli result = dp[R];
    if(L > 0)
    {
        result = (result - dp[L-1] + mod) % mod;
    }
    result = (result * inv[L]) % mod;
    return result;
}

int main(){
    int n, HL, NL;
    string needle, haystack;

    while(cin >> NL)
    {
        cin >> needle;
        cin >> haystack;
        HL = haystack.size();
        vector<lli> dp(HL + 1, 0);
        vector<lli> inv(HL + 1, 0);

        init(haystack, dp, inv, HL);
        lli needleHash = getHash(needle);

        for(int L = 0, R = NL-1; R < HL; ++L, ++R){
            if(needleHash == getSubstringHash(L, R, dp, inv)){
                cout << L << endl;
            }
        }
        cout << endl;
    }
}