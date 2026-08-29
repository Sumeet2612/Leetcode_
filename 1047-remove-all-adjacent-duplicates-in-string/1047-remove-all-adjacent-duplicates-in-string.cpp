class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;
        int n = s.size();
        string ns ;

        for (int i=0; i<n; i++){
            if (st.empty() || st.top() != s[i]){
                st.push(s[i]);
            }

            else if (st.top() == s[i]){
                st.pop();
            }
        }

        while (!st.empty()){
            char c = st.top();
            ns += c;
            st.pop();
        }

        string res ;

        for (int i= ns.size() - 1; i>=0; i--){
            res += ns[i];
        }

        return res ;
    }
};