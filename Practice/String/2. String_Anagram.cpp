Ques:
-----
Write a function to check whether two given strings are anagram of each other or not. 
An anagram of a string is another string that contains the same characters, only the order of characters can be different. 
For example, "abcd" and "dabc" are an anagram of each other.

Solution:

Method 1 (Use Sorting)  

    Sort both strings
    Compare the sorted strings


Method 2 (Count characters) 
    This method assumes that the set of possible characters in both strings is small. In the following implementation, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters. 

    Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
    Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
    Compare count arrays. If both count arrays are same, then return true.


Method 3 (count characters using one array) 
    The above implementation can be further to use only one count array instead of two. 
    We can increment the value in count array for characters in str1 and decrement for characters in str2. 
    Finally, if all count values are 0, then the two strings are anagram of each other.


Method 4 (Put all characters in HashMap)

    In above implementation we are using extra space as we are creating array of 256 characters but we can optimise it using 
    HashMap where we can store character and count of character in HashMap. 
    Idea is to put all characters of one String in HashMap and reducing them as we encounter while looping over other String.