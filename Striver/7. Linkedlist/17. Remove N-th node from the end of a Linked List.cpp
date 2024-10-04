// Link : https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/

// video : https://www.youtube.com/watch?v=3kMKYQ2wNIU

/*
1. Brute

class Node {
public:
    int data;
    Node* next;

    // Constructor for Node with data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for Node with 
    //only data (next set to nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to delete the Nth node
// from the end of the linked list
Node* DeleteNthNodefromEnd(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - N;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}

Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.

Space Complexity:  O(1), as we have not used any extra space.*/

// 2. Optimal 

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor 
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to delete the Nth node
// from the end of the linked list
Node* DeleteNthNodefromEnd(Node* head, int N) {
    // Create two pointers, fastp and slowp
    Node* fastp = head;
    Node* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end 
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}

//Time Complexity: O(N) since the fast pointer will traverse the entire linked list, where N is the length of the linked list.

// Space Complexity: O(1), as we have not used any extra space.