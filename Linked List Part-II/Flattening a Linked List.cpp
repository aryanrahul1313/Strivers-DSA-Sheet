Node *mergeTwoLists(Node* a, Node* b){
    Node* temp = new Node(-1);
    Node* res = temp;
    
    while(a != NULL && b != NULL){
        if(a->data <= b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    //if elements left in any list
    if(a != NULL){
        temp->bottom = a;
    }
    else{
        temp->bottom = b;
    }
    
    return res->bottom; 
}    

Node *flatten(Node *root)
{
   if(root == NULL || root->next == NULL){
       return root;
   }
   
   //recursive calls for the list on right side
   root->next = flatten(root->next);
   
   //now merge
   mergeTwoLists(root, root->next);
   
   return root;
}
