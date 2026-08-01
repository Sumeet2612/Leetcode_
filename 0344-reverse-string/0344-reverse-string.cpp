class Solution {
public:
    void reverseString(vector<char>& s) {

        stack<char> st;
        vector<int> res ;
        
        for(int i=0; i<s.size(); i++){
            st.push(s[i]);
        }

        int idx = 0;
         

        while(!st.empty()){
            s[idx] = st.top();
            st.pop();
            idx++;
        }

        
        
    }
};