vector<int> sol(Node * root){
    stack<Node*> s;
    vector<int> ans;
    Node *node=root
    s.push(node);
    while(true){
        if(node){
            s.push(node);
            node=node->left;
        }    
        else{
            if(s.empty()) break;
            node=s.top();
            s.pop();
            ans.push_back(node->val);
            node=node->right;
        }
        
    }
    return ans;
}