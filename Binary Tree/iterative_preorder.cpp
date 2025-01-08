sol(Node* root ){
    vector<int> ans;
    stack<Node*> s;
    if(root==NULL) return ans;
    s.push(root);
    while(!s.empty()){
        Node *temp=s.top();
        s.pop();
        ans.push_back(remp->val);
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
        }
    return ans;
}