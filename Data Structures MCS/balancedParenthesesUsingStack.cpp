#include<bits/stdc++.h>
using namespace std;

// scan from left to right
// if opening symbol, add it to the list(push it into the stack)
// if closing symbol, remove last opening symbol in list(pop it from the stack)

bool balancedParentheses(char *c, int n) {
    stack<char> st;
    for(int i=0; i<n; i++) {

        if(c[i] == '(' || c[i] == '{' || c[i] == '[') {
            st.push(c[i]);
        }
        else if(c[i] == ')' || c[i] == '}' || c[i] == ']') {
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty()? true : false;
}
int main() {
    char c[10];
    cout<<"Enter Expression ";
    gets(c);
    cout<<"Result "<<balancedParentheses(c,strlen(c))<<endl;
}