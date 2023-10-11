class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(temp->val) + ',');
            }

            if(temp != NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        // stringstream --> it converts the string data into a stream, 
        // allowing you to read from it as if it were an input source.
        stringstream s(data);

        string str;
        // Use the getline function to extract a substring from 's' 
        // until the comma ',' delimiter is encountered.
        getline(s, str, ',');

        // stoi --> string to int conversion
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            // for creating left side
            getline(s, str, ',');
            if(str == "#"){
                temp->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                temp->left = leftNode;
                q.push(leftNode);
            }

            // for creating right side
            getline(s, str, ',');
            if(str == "#"){
                temp->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                temp->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
