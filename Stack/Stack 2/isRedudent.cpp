#include<iostream>
#include<Stack>
using namespace std;

bool checkRedudent(string s) {
    stack<int>st;

    for(int i= 0; i<s.length(); i++) {
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }

        //Jab close bracket aye
      
        else if(ch == ')') {
            bool isRedudent = true;

            // jab tak open brect  n mile check karte rho
            while(st.top() != '(') {
                char top = st.top();
                if(top == '(' || top == '+' || top == '-' || top == '*' || top == '/')
                      isRedudent = false;

                      st.pop();
                
            }


            if(isRedudent == true)
            return true;
            st.pop();
        }

    }

    return false;
}

int main()
{
 string s = "(c+((a+b)))";
 string s1 = "(a+ (b*c) - (e/f))";
 cout<<"redudent hai ya nhi  "<<checkRedudent(s)<<endl;
}