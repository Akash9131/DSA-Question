/*
Valid Parentheses
Easy

14275

669

Add to List

Share
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

#include<iostream>
#include<Stack>
using namespace std;
class Solution {
public:
    bool match(char close, char open) {
        if(close == ')' && open == '(')
           return true;
        
        if(close == '}' && open == '{')
            return true;
        if(close == ']' && open == '[')
             return true;
        
        return false;
    }
    bool isValid(string s) {
        stack<int>st;
        
        int len = s.length();
        
        if(len&1)
            return false;
        
        for(int i= 0; i<s.length(); i++) 
        {
            char ch = s[i];
            
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            
            else{
                // sare ke sare closing brackets
                
                if(!st.empty() && match(ch,st.top())) {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
            return true;
        else
           return  false;
    }
};