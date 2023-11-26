/*
    KMP works over the concept of proper prefix(in which prefix != string). It has the overall TC O(n+m). In it there is no need to re-iterate the main string,
    and instead of re-iterating the pattern string completely, we are maintaining the longest common prefix array.

    pattern : a b c d a b c
    pos:      1 2 3 4 5 6 7 

    prefix: a, ab, abc, abcd, abcda, abcdab, abcdabc
    suffix: c, bc, abc, dabc, cdabc, bcdabc, abcdabc

    so at any point if there is a common proper prefix and proper suffix exist then whenever there is a mismatch between the
    characters of the pattern and string, then in that case there is no need to start from the next-to--the-previous-index.

    The 'pi' or LPS(longest prefix substring) array is created, which stores the index of longest prefix upto the current index.

    P1:  a b c d a b e a b f
    LPS: 0 0 0 0 1 2 0 1 2 0

    P2:  a b c d e a b f a b c
    LPS: 0 0 0 0 0 1 2 0 1 2 3

    P3:  a a b c a d a a b e
    LPS: 0 1 0 0 1 0 1 2 3 0

    From the functional point of view, the value at 'i'th index indicates that whenever there is a mismatch with the jth character
    of the test string so instead of matching from the starting character, just start matching from the index mentioned at the LPS 
    array at that index. 
    
    It is so because that value confirms that the string is having the common prefix and suffix for that index.


    EXAMPLE:
    
    i
    string   : a b a b c a b c a b a b a b d
    
    j
    Pattern  : a b a b d
    LPS      : 0 0 1 2 0

    1. Initialize j = 0 and i = 0;
    2. 
    While(i < S.size())
    {
        if (P[j+1] == S[i])
                ++j, ++i
        else
            j = P[j] - 1
    }

    Inshort the basic idea behind this is Given string "S" and pattern "P". We are maintaining the 'Pi' array for the "P".
    In the 'Pi' array, we are maintaining the starting point from which we need start comparing the S and P again when there is a
    mismatch between the current character of "S" and "P". In the navie algorithm we don't know the point upto which the string
    "P" is matching from starting with the given point.

    The Pi array is prepared with the concept of common proper suffix and prefix. So at any point of time when there is a mismatch
    we are checking the upto what length of the string of S (by the suffix) with the starting length of "P" (by the prefix). So
    because of this there is no need to compare those characters which are already equal.

*/

---------------------------------

/*

The prefix function for this string is defined as an array 'pi' of length 'n', where 'pi[i]' is the length of the longest proper 
prefix of the substring 's[0....i]' which is also a suffix of this substring.
A proper prefix of a string is a prefix that is not equal to the string itself. By definition, 'pi[i] = 0'.

Generally, pi stores the length of longest prefix upto that point and the value at each index also denotes the location of 
the next character which is to be compared when searching for prefix.

Trivial Algorithm
------------------
An algorithm which follows the definition of prefix function exactly is the following:


vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i-k+1, k))
                pi[i] = k;
    return pi;
}
It is easy to see that its complexity is O(n^3), which has room for improvement.

Efficient Algorithm(Optimization made in reference of the above approach)
-------------------
First optimization
The first important observation is, that the values of the prefix function can only increase by at most one.
    pi[i+1] <= pi[i] + 1 

Thus when moving to the next position, the value of the prefix function can either increase by one, stay the same, 
or decrease by some amount. This fact already allows us to reduce the complexity of the algorithm to O(n^2)
, because in one step the prefix function can grow at most by one. In total the function can grow at most 'n' steps,
 and therefore also only can decrease a total of n steps. This means we only have to perform O(n) string comparisons, 
 and reach the complexity O(n^2).

--------------------------------------------------------------
Second optimization
To 
if( S[pi[i-1]] == S[i] ){
    pi[i] = pi[i-1] + 1
}

But if( S[pi[i-1]] != S[i] )
    in this case we try to find the longest prefix which is also a suffix by 
    while(j>0 && s[j] != s[i]){
        j = p[j-1] 
    }

Like,
    idx:    0 1 2 3  4 5 6 7 8
    str:    a a b a  a a b a x
    pi      0 1 0 1  2 2 3 4 _

    for x i = 8 and j = p[i-1] = 4, as s[i] != s[j]
    so we try to find the longest prefix which is a suffix for 
    a a b a x
      a b a x
        b a x
          a x
            x 

    So, for the above, it goes backward 2 times: 1st compare for 'aabax' and 2nd compare for 'ax'
    The backward journey i.e j = p[j-1] or j = p[i-1] can be understood as,
    we are searching for the occurrence of the i-1th character of the string which is associated as a prefix and a suffix till i-1
    
    like for above, at the time of i=8
    we are searching for all the strings whose prefix ends at i-1th character i.e 'a'. It is so because in that case only
    there might be the possibility of getting at least 1 prefix with longest length whose next character might be 'x'.
    
    like for above, the possible 2 prefixes of 'aabaaaba' which are ending at 'a' are 'aaba' and 'a' whose next character might be 'x'


-------------------------------

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

*/