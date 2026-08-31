class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string temp;

        for (int i = 0; i <= path.size(); i++) {

            // We use '/' OR end of string as delimiter
            if (i == path.size() || path[i] == '/') {

                if (temp == "" || temp == ".") {
                    // Ignore empty parts and "."
                }
                else if (temp == "..") {
                    // Go to parent directory
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else {
                    // Valid directory name
                    st.push(temp);
                }

                temp = "";
            }
            else {
                temp += path[i];
            }
        }

        // Construct answer
        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if (ans == "") {
            return "/";
        }

        return ans;
    }
};