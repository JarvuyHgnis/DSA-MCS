void insertAtN(int data, int n){ // insert a node at nth position
    node* temp = new node();
    temp->data = data;
    if(n==1){
        temp->next = head;
        head = temp;
    }
    else {
        node* location = head;
        n = n-2;
        while(n--){
            location = location->next; 
        } 
        temp->next = location->next;
        location->next = temp;
    }
}