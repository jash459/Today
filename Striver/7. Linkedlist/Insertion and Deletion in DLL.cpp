// video : https://www.youtube.com/watch?v=0eKMU10uEDI&t=3s

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node* next1, Node* back1)  : data(data1), next(next1) , back(back){}
    Node(int data) : data(data1) , next(nullptr) , back(nullptr) {}
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

Node* convertArray2DLL(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* prev = head;
    for(int i=1 ; i<a.size(); i++){
        Node* temp = new Node(a[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void* printDLL(Node* head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    } 
    cout << endl;
}

int lengthOfDLL(Node* head){
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
 if(head == NULL || head->next == NULL) return head;

 Node* prev = head;
 head = head->next;

 head->back = nullptr;
 prev->next = nullptr;
 delete prev;
 
 return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) {
        head = NULL;
        return NULL; // as there is no tail
    }

    Node* temp = head;
    while(temp->next!= NULL) {
        temp = temp->next;
    } 
    Node* newTail = temp->back;
    newTail->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}

Node* removeK(Node* head, int k){
    if(head == NULL) return head;

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){ // single element
        return NULL;  // just delete that i.e return NULL
    } 
    else if(prev == NULL){  // its head
        return removeHead(head); 
    }
    else if(front == NULL){ // it tail
        return removeTail(head);
    }
    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
    return;
}

Node* insertBeforeHead(Node* head, int val){
   Node* newHead = new Node(val, head, nullptr);
   head->back =  newHead;

   return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL){
       return insertBeforeHead(head, val);
    }
    Node* temp = head;
    while(temp->next != NULL){  // with this we will reach last node
       temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head; 
}

Node* insertAfterTail(Node* head, int val) {
    if (head == nullptr) { // empty list
        return insertBeforeHead(head, val); // insert as the only node in the list
    }
    Node* temp = head;
    while (temp->next != nullptr) { // traverse to the last node
        temp = temp->next;
    }
    Node* newNode = new Node(val); // create a new node with the given value
    temp->next = newNode; // insert the new node after the last node
    newNode->back = temp; // update the back pointer of the new node
    return head;
}

Node* insertBeforeKthPosition(Node* head, int val, int k){
    if(k == 1){ // insertion at head
        return insertBeforeHead(head, val);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* insertAfterKthPosition(Node* head, int val, int k) {
    if (head == nullptr) { // Empty list
        return nullptr;
    }
    int cnt = 0;
    Node* temp = head;
    // Traverse to the kth position
    while (temp != nullptr) {
        cnt++;
        if (cnt == k) {
            break;
        }
        temp = temp->next;
    }
    if (temp == nullptr) { // If k is greater than the length of the list
        cout << "Invalid position" << endl;
        return head;
    }
    Node* newNode = new Node(val, temp->next, temp); // Create a new node
    if (temp->next != nullptr) {
        temp->next->back = newNode; // Update the back pointer of the next node
    }
    temp->next = newNode; // Update the next pointer of the current node
    return head;
}


void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

void insertAfterNode(Node* node, int val) {
    Node* nextNode = node->next;
    Node* newNode = new Node(val, nextNode, node);
    if (nextNode != nullptr) {
        nextNode->back = newNode; // Update the back pointer of the next node
    }
    node->next = newNode; // Update the next pointer of the current node
}
int main(){
    vector<int> arr = {2,5,7,8};
    Node* head = convertArray2DLL(arr);
    printDLL(head); // traversal in LL
    int length = lengthOfDLL(head);
    int found = check(head, 2);
    head = removeHead(head);
    head = removeTail(head);
    head = removeK(head,3); // 7 will remove 
    head = deleteNode(head->next); // we never delete head, we delete other nodes
    // all the insertion are before one, you can also try for after
    head = insertBeforeHead(head, 100);
    head = insertBeforeTail(head, 11);
    head = insertBeforeKthPosition(head, 11, 1) // insert at head
    insertBeforeNode(head->next,11) // insert before 7 , and we never change the head, that's why we just do insertion
    printDLL(head);

}