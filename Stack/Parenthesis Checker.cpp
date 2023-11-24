bool ispar(string x)
    {
        int n = x.length();
        stack<int> st;
        
        for(int i=0; i<n; i++){
            if(x[i] == '[' || x[i] == '{' || x[i] == '('){
                st.push(x[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                
                char ch = st.top();
                st.pop();
                if(x[i] == ']' && ch == '[' || x[i] == '}' && ch == '{' || x[i] == ')' && ch == '(')
                {
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
