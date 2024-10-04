// Link : https://takeuforward.org/linked-list/linked-list-introduction/

// video : https://www.youtube.com/watch?v=Nq7ok-OyEpg

class Node {
    public:
        int data;         // Data stored in the node
        Node* next;       // Pointer to the next node in the linked list
        // Constructors
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
int main() {
    vector<int> arr = {2, 5, 8, 7};
    // Create a Node 'x' with the first element of the vector and a null next reference
    Node x = Node(arr[0], nullptr);
    // Create a pointer 'y' pointing to the Node 'x'
    Node* y = &x;
    // Print the memory address of the Node 'x' using the pointer 'y'
    cout << y << '\n';

    Node* z= new Node(arr[0]);
    cout<<z<<'\n'; // returns the memory value
    cout<<z->data<<'\n'; // returns the data stored at that memory point
}