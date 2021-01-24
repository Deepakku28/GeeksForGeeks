void findData(Node* root,Node* &prev,Node* &start,Node* &middle,Node* &end){
    if(root==NULL){
        return;
    }
    findData(root->left,prev,start,middle,end);
    if(prev!=NULL && root->data<prev->data){
        if(start==NULL){
            start=prev;
            middle=root;
        }
        else{
            end=root;
        }
    }
    prev=root;
    findData(root->right,prev,start,middle,end);
}

struct Node *correctBST(struct Node* root){
    Node* prev=NULL;
    Node* start=NULL;
    Node* middle=NULL;
    Node* end=NULL;
    findData(root,prev,start,middle,end);
    if(start!=NULL && end!=NULL){
        swap(start->data,end->data);
    }
    else if(start!=NULL && middle!=NULL){
        swap(start->data,middle->data);
    }
    return root;
}
