class Solution {
public:
    string removeDuplicates(string s) {

        
        stack<char> st;
       
        for (char ch : s){
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        string res(st.size() , ' ') ;
        int idx = st.size() - 1;

        while(!st.empty()){
            res[idx--] = st.top();
            st.pop();
        }

        return res ;
        
    }
};