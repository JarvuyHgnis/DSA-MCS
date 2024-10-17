#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    // Returns true if the character is an operator
    return c == '+' || c == '-' || c == '*' || c == '/'
           || c == '^';
}

// double applyOp(double a, double b, char op)
// {
//     // Applies the operator to the operands and returns the
//     // result
//     switch (op) {
//     case '+':
//         return a + b;
//     case '-':
//         return a - b;
//     case '*':
//         return a * b;
//     case '/':
//         return a / b;
//     case '^':
//         return pow(a, b);
//     default:
//         return 0;
//     }
// }
double prefix(string S) {
    double len,x,y,op,res;
    reverse(S.begin(),S.end());
    len = S.length();
    // cout<<S<<endl;
    cout<<"String length = "<<len<<endl;
    stack<int> st;
    stringstream ss(S);
    string token;
    while(getline(ss,token,' ')) {
        if(token.empty()) {
            continue;
        }
        if(isdigit(token[0])) {
            double num;
            stringstream(token)>>num;
            st.push(num);
        }
        else if(isOperator(token[0])) {
            char op = token[0];
            y = st.top();
            st.pop();
            x = st.top();
            st.pop();
            if(op=='+'){
                res = y + x;
            } 
            else if(op=='-'){
                res = y - x;
            }
            else if(op=='*'){
                res = y * x;
            }
            else if(op=='/'){
                res = y / x;
            }
            else if(op=='^'){
                res = pow(y,x);
            }
            st.push(res);
        }
    }
    return st.top();
}

double postfix(string S) {
    double len,x,y,op,res;
    len = S.length();
    cout<<"String length = "<<len<<endl;
    stack<int> st;
    stringstream ss(S);
    string token;
    while(getline(ss,token,',')) { // ' ' parse karne pe 2 ans aa rha, ',' parse karne pe 17 ans aa rha
        if(token.empty()) {
            continue;
        }
        if(isdigit(token[0])) {
            double num;
            stringstream(token)>>num;
            st.push(num);
        }
        else if(isOperator(token[0])) {
            char op = token[0];
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            if(op=='+'){
                res = y + x;
            } 
            else if(op=='-'){
                res = y - x;
            }
            else if(op=='*'){
                res = y * x;
            }
            else if(op=='/'){
                res = y / x;
            }
            else if(op=='^'){
                res = pow(y,x);
            }
            st.push(res);
        }
    }
    return st.top();
}

int main() {
    string S1 = "2,3,*,5,4,*,+,9,-";
    double ans1 = postfix(S1);
    cout<<ans1<<endl;
    string S2 = "- + * 2 3 * 5 4 9";
    double ans2 = prefix(S2);
    cout<<ans2<<endl;
}

// postfix Input
// 2,3,*,5,4,*,+,9,-
// postfix output
// 17
// prefix Input
// - + * 2 3 + 5 4 9
// prefix output
// 17