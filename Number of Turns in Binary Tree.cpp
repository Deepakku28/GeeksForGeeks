Node* lowestCommonAncestor(Node* root,int &first,int &second){
    if(root==NULL){
        return NULL;
    }
    if(root->data==first || root->data==second){
        return root;
    }
    Node *leftNode=lowestCommonAncestor(root->left,first,second);
    Node *rightNode=lowestCommonAncestor(root->right,first,second);
    if(leftNode!=NULL && rightNode!=NULL){
        return root;
    }
    return leftNode!=NULL?leftNode:rightNode;
}

void countTurns(Node* parent,int &target,bool leftOrRight,int &bend,int currBend){
    if(parent==NULL){
        return;
    }
    if(parent->data==target){
        bend=currBend;
        return;
    }
    if(leftOrRight==true){//true shows that we are in left direction
        countTurns(parent->left,target,true,bend,currBend);
        countTurns(parent->right,target,false,bend,currBend+1);
    }
    else{
        countTurns(parent->left,target,true,bend,currBend+1);
        countTurns(parent->right,target,false,bend,currBend);
    }
}

int NumberOFTurns(struct Node* root, int first, int second){
    Node *parent=lowestCommonAncestor(root,first,second);
    int bend1=0;
    countTurns(parent->left,first,true,bend1,0);
    countTurns(parent->right,first,false,bend1,0);
    int bend2=0;
    countTurns(parent->left,second,true,bend2,0);
    countTurns(parent->right,second,false,bend2,0);
    if(parent->data!=first && parent->data!=second){
        return (bend1+bend2+1);
    }
    if((bend1+bend2)==0){
        return -1;
    }
    return bend1+bend2;
}
