#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    stack<string> st;

    for (int i=0; i<n; i++) {
        char ch = s[i];

        if (ch == '(') st.push("(");
        else if (ch == ')' && !st.empty() && st.top()[0] == '(') st.pop();
        else if (!st.empty()) st.top() += ch;
        else {
            string tmp = ""; tmp += ch;
            st.push(tmp);
        }
    }

    string ans = "";
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }

    cout << ans << '\n';
}