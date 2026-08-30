class Solution {
public:
    string removeKdigits(string num, int k) {


        int n = num.size();
        stack<char> st;
        st.push(num[0]);
        string ns;

        for (int i=1; i<n; i++){
            while (!st.empty() && st.top() > num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while (k>0){
            st.pop();
            k--;
        }

        while(!st.empty()){
            ns += st.top();
            st.pop();
        }

        reverse(ns.begin() , ns.end());

        int i=0 ;
        while (i<ns.size() && ns[i] == '0'){
            i++;
        }
        if (i== ns.size()){
            return "0";
        }
        else {
            return ns.substr(i);
        }
        
    }
};