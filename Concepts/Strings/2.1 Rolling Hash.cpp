/*
Polynomial Rolling hash

    hash(s) = (s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + ..... + s[n-1]*p^n-1) mod m
            
            =   (from i = 0 to i = n-1) summation(s[i]*p^i) mod m

where p is a prime number > |character set|
*/

#include<bits/stdc++.h>
#include<string.h>
#define mod 1000000007
#define lli long long int

lli getHash(string key){
    
    lli p_power = 1;
    lli p = 31, hash_value = 0;

    for(char c: key){
        hash_value += ((ch - 'a' + 1) * p_power) % mod ;
        p_power = (p_power * p) % mod;
    }

    // Another implementation
    // for(int i = 0; i < key.size(); ++i)
    // {
    //     hash_value += (key[i] - 'a' + 1) * pow(p,i);
    // }


    return hash_value;
}

using namespace std;

int main(){

    string key;

    cin >> key;
    cout << getHash(key);
    
    return 0;
}