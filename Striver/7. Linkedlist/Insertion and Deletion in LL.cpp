// video : https://www.youtube.com/watch?v=VaECK03Dz-g&t=1614s

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1)  : data(data1), next(next1) {}
    Node(int data) : data(data1) , next(nullptr) {}
};

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, T* next)
    {
        this->data = data;
        this->next = next;
    }
};

int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
}

// in c++ we can use NULL and nullptr, interchangebly

Node* convertArray2LL(vector<int> &a){
   Node* head = new Node(a[0]);
   Node* mover = head;
   for(int i=1 ; i<a.size(); i++){
    Node* temp = new Node(a[i]);
    mover->next = temp;
    mover = temp;
   }
   return head;
}

void printLL(Node* head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    } 
    cout << endl;
}

int lengthOfLL(Node* head){
 int cnt = 0;
 Node* temp = head;
 while(temp){
    cnt++;
    temp = temp->next;
 }
 return cnt;
}

int check(Node* head, int val){
 Node* temp = head;
 while(temp){
   if(temp->data == val) return 1;
   temp = temp->next;
 }
 return 0;
}

Node* removeHead(Node* head){
 if(head == NULL) return head;

 Node* temp = head;
 head = head->next;
 delete temp;

 return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL; // as there is no tail

    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    } 
    delete temp->next;
    temp->next = NULL;

    return head;
}

Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
    	prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeEle(Node* head, int el){
    if(head == NULL) return head;
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
    	prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int val){
   return new Node(val, head);
}

Node* insertTail(Node* head, int val){
    if(head == NULL){
       return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){  // with this we will reach last node
       temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head; 
}

Node* insertPosition(Node* head, int el, int k){
    if(head == NULL){ // empty 
        if(K == 1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k == 1){ // insertion at head
        return new Node(el, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == (k-1)){  // for after insertion, it will (cntt == k)
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next
    }
    return head;
}

Node* insertBeforeValue(Node* head, int el, int val){
    if(head == NULL){ // empty , not possible to find the value in empty LL
        return NULL;
    }
    if(head->data == val){ // insertion at head
        return new Node(el, head);
    }
    Node* temp = head;
    bool found = false;
    while(temp != NULL){
        if(temp->next->data == val){   // for after insertion, if(temp-data == val)
            Node* x = new Node(el, temp->next);
            temp->next = x;
            found = 1;
            break;
        }
        temp = temp->next
    }
    if(found == 1) {
        cout << "value not found in LL" << endl;
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,7,8};
    Node* head = convertArray2LL(arr);
    printLL(head); // traversal in LL
    int length = lengthOfLL(head);
    int found = check(head, 2);
    head = removeHead(head);
    head = removeTail(head);
    head = removeK(head,3); // 7 will remove 
    head = removeEle(head, 7);
    head = insertHead(head, 100);
    head = insertTail(head, 11);
    head = insertPosition(head, 11, 1) // insert at head
    head = insertBeforeValue(head,11, 7) // insert before 7
    printLL(head);

}