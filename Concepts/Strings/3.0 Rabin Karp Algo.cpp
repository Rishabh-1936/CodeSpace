/*
    Rabin Karp is similar to Substring Hashing algorithm, but it has the complexity of O(n+m-1).
    It is because there is no need to calculate the modulo inverse in it which has a complexity of log N and leads to O(nlogn + m - 1)
    of substring hashing algorithm.

As per substring hashing algo:
    hash("coding") = c*p^0 + o*p^1 + d*p^2 + i*p^3 + n*p^4 + g*p^5

Hash value of the substring "din" of string "coding"
    hash("din") = d*p^0 + i*p^1 + n*p^2

The realtion b/w the hash value of "din" with "coding" is 
    (d*p^2 + i*p^3 + n*p^4) / p^2

So as per Rabin Karp
    d*p^0 + i*p^1 + n*p^2 = (d*p^2 + i*p^3 + n*p^4) / p^2
=>  (d*p^0 + i*p^1 + n*p^2) * p^2 = (d*p^2 + i*p^3 + n*p^4)

So instead of dividing the hash of a part of the main string and comparing with the hash of substring, we are multiplying the hash of substring and 
direclty comparing it with the hash of a part of the main string. So there is no need to evaluate the inverse modulo.
And Hence the overall complexity reduces to O(n+m-1).

This algorithm is very useful and efficient in string seacrhing of single and multiple pattern also.

*/

#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int

using namespace std;

void init(string input, vector<lli> &dp, vector<lli> &pw)
{
    lli p = 31;
    lli p_power = 1;
    pw[0] = 1;
    dp[0] = (input[0] - 'a' + 1);

    for(int i = 1; i < input.size(); ++i)
    {
        char ch = input[i];
        p_power = (p * p_power) % mod;
        
        // to store the p^i for every index
        pw[i] = p_power;

        dp[i] = dp[i-1] + ((ch - 'a' + 1) * p_power) % mod;
    }
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

lli substringHash(int L, int R, vector<lli> &dp){
    lli result = dp[R];
    if(L>0){
        result -= dp[L-1];
    }
    result = (result) % mod;
    return result;
}

int main()
{
    int tc, L, R;
    string input, pattern;

    cin >> input;
    cin >> tc;
    
    vector<lli> dp(input.size());
    vector<lli> pw(input.size());
    
    init(input, dp, pw);

    while(tc--){
        cin >> pattern;
        lli patternHash = getHash(pattern);
        for(int L = 0, R = pattern.size() - 1; R < input.size(); ++L, ++R){
            if((patternHash * pw[L]) % mod == substringHash(L, R, dp)){
                cout << L << endl;
            }
        }
        cout << endl;
    }

    return 0;
}