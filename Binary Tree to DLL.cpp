void helper(Node* root,Node* &head){
    if(root==NULL){
        return ;
    }
    helper(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    helper(root->left,head);
}

Node * bToDLL(Node *root){
    Node* head=NULL;
    helper(root,head);
    return head;
}
