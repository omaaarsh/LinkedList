#include <iostream>
using namespace std;

// Node class represents a single element in the linked list
class Node {
public:
    int value;      // Value of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

// LinkedList class manages the entire linked list
class LinkedList {
private:
    Node* head;     // Pointer to the first node
    Node* tail;     // Pointer to the last node
    int length;     // Number of elements in the list

public:
    // Constructor to initialize the linked list with a single node
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    LinkedList() {
    }

    // Destructor to free memory allocated for the linked list
    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Add a new node at the end of the list
    void append(int val) {
        Node* newNode = new Node(val);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // Add a new node at the beginning of the list
    void prepend(int val) {
        Node* newNode = new Node(val);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    // Insert a new node at a specific index
    bool insert(int index, int value) {
        if (index < 0 || index > length) {
            return false; // Index out of bounds
        }
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = getByIndex(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    // Get a node by its index
    Node* getByIndex(int index) {
        if (index < 0 || index >= length) {
            return nullptr; // Index out of bounds
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    // Update the value of a node at a specific index
    bool set(int index, int value) {
        Node* temp = getByIndex(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    // Delete a node by its value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "Empty list!\n";
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;

        // If the node to delete is the head
        if (temp->value == value) {
            head = temp->next;
            if (temp == tail) {
                tail = nullptr; // Update tail if it was the only node
            }
            delete temp;
            length--;
            return;
        }

        // Traverse the list to find the node to delete
        while (temp && temp->value != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << value << " not found.\n";
            return;
        }

        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp;
        length--;
    }

    // Delete a node by its index
    void deleteByIndex(int index) {
        if (index < 0 || index >= length) {
            return; // Index out of bounds
        }
        if (index == 0) {
            deleteHead();
            return;
        }
        if (index == length - 1) {
            deleteTail();
            return;
        }
        Node* prev = getByIndex(index - 1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    // Delete the first node in the list
    void deleteHead() {
        if (length == 0) {
            return; // List is empty
        }
        Node* temp = head;
        head = head->next;
        if (length == 1) {
            tail = nullptr; // If there was only one node
        }
        delete temp;
        length--;
    }

    // Delete the last node in the list
    void deleteTail() {
        if (length == 0) {
            cout << "The list is already empty.\n";
            return;
        }
        if (length == 1) {
            deleteHead();
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        length--;
    }

    // Reverse the linked list
    void reverse() {
        Node* temp = head;
        Node* after = nullptr;
        Node* before = nullptr;
        head = tail;
        tail = temp;
        for (int i = 0; i < length; i++) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    // Print all elements in the list
    void printList() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Print the value of the head node
    void getHead() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        cout << "Head: " << head->value << endl;
    }

    // Print the value of the tail node
    void getTail() {
        if (tail == nullptr) {
            cout << "Empty list\n";
            return;
        }
        cout << "Tail: " << tail->value << endl;
    }
    
    // Find Middle Node ( ** Interview Question)
    Node * findMiddleNode(){
        Node* fast=head;
        Node* slow=head;
        while (fast && fast->next)
        {
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }

    // hasLoop ( ** Interview Question)
    bool hasLoop(){
        Node* fast=head;
        Node* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }

        }
        return false;
    }
    
    // findKthFromEnd ( ** Interview Question)
    Node* findKthFromEnd(int k) {
            Node* slow = head;
            Node* fast = head;
            for (int i = 0; i < k; ++i) {
                if (fast == nullptr) {
                    return nullptr;
                }
                fast = fast->next;
            }
            while (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    
    //LL: Partition List ( ** Interview Question)
    void partitionList(int x) {
        // Return if the list is empty
        if (head == nullptr) return;
        // Create dummy nodes for two lists
        Node dummy1(0);
        Node dummy2(0);
        // Initialize pointers for two lists
        Node* prev1 = &dummy1;
        Node* prev2 = &dummy2;
        // Initialize the current pointer
        Node* current = head;
        
        // Iterate through the list
        while (current != nullptr) {
            // If the value is less than x
            if (current->value < x) {
                prev1->next = current;
                prev1 = current;
            } else { // If the value is >= x
                prev2->next = current;
                prev2 = current;
            }
            // Move to the next node
            current = current->next;
        }
        
        // Terminate the second list
        prev2->next = nullptr;
        // Connect the two lists
        prev1->next = dummy2.next;
        // Update the head of the list
        head = dummy1.next;
    }        

    //LL: Remove Duplicates ( ** Interview Question)
    void removeDuplicates() {
        Node* current = head; // Start at the head of the list
        while (current != nullptr) { // Iterate through the list
            Node* runner = current; // Secondary iterator
            // Check all subsequent nodes
            while (runner->next != nullptr) { 
                // If a duplicate is found
                if (runner->next->value == current->value) {
                    Node* temp = runner->next; // Temp node for deletion
                    // Bypass the node to be deleted
                    runner->next = runner->next->next;
                    delete temp; // Delete the node
                    length -= 1; // Decrement length
                } else {
                    runner = runner->next; // Move to next node
                }
            }
            current = current->next; // Move to next node
        }
    }

};
int main() {
    // Initialize a linked list with one node (value = 1)
    cout << "Creating a new linked list with initial value 1:\n";
    LinkedList* myList = new LinkedList(1);
    myList->printList(); // Output: 1
    myList->getHead();   // Head: 1
    myList->getTail();   // Tail: 1

    // Append nodes to the end
    cout << "\nAppending 2, 3, and 4:\n";
    myList->append(2);
    myList->append(3);
    myList->append(4);
    myList->printList(); // Output: 1 2 3 4
    myList->getTail();   // Tail: 4

    // Prepend a node to the beginning
    cout << "\nPrepending 0:\n";
    myList->prepend(0);
    myList->printList(); // Output: 0 1 2 3 4
    myList->getHead();   // Head: 0

    // Insert a node at index 2
    cout << "\nInserting 100 at index 2:\n";
    myList->insert(2, 100);
    myList->printList(); // Output: 0 1 100 2 3 4

    // Get the node at index 3 and print its value
    cout << "\nGetting node at index 3:\n";
    Node* nodeAtIndex3 = myList->getByIndex(3);
    if (nodeAtIndex3) {
        cout << "Value at index 3: " << nodeAtIndex3->value << endl;
    } else {
        cout << "Invalid index.\n";
    }

    // Update the value of the node at index 3 to 200
    cout << "\nUpdating value at index 3 to 200:\n";
    myList->set(3, 200);
    myList->printList(); // Output: 0 1 100 200 3 4

    // Delete the node with value 100
    cout << "\nDeleting node with value 100:\n";
    myList->deleteNode(100);
    myList->printList(); // Output: 0 1 200 3 4

    // Delete the node at index 0
    cout << "\nDeleting node at index 0:\n";
    myList->deleteByIndex(0);
    myList->printList(); // Output: 1 200 3 4

    // Delete the head node
    cout << "\nDeleting the head:\n";
    myList->deleteHead();
    myList->printList(); // Output: 200 3 4
    myList->getHead();   // Head: 200

    // Delete the tail node
    cout << "\nDeleting the tail:\n";
    myList->deleteTail();
    myList->printList(); // Output: 200 3
    myList->getTail();   // Tail: 3

    // Reverse the linked list
    cout << "\nReversing the list:\n";
    myList->reverse();
    myList->printList(); // Output: 3 200

    // Find the middle node
    cout << "\nFinding the middle node:\n";
    Node* middleNode = myList->findMiddleNode();
    if (middleNode) {
        cout << "Middle node value: " << middleNode->value << endl;
    }

    // Check if the list has a loop (should be false)
    cout << "\nChecking if the list has a loop:\n";
    cout << (myList->hasLoop() ? "Loop exists" : "No loop") << endl;

    // Find the 1st node from the end (k=1)
    cout << "\nFinding the 1st node from the end:\n";
    Node* kthFromEnd = myList->findKthFromEnd(1);
    if (kthFromEnd) {
        cout << "1st node from end: " << kthFromEnd->value << endl;
    }

    // Partition the list around value 200
    cout << "\nPartitioning the list around value 200:\n";
    myList->partitionList(200);
    myList->printList(); // Output: 3 200

    // Append additional nodes to demonstrate partitioning
    cout << "\nAppending 5, 1, 150, 250:\n";
    myList->append(5);
    myList->append(1);
    myList->append(150);
    myList->append(250);
    myList->printList(); // Output: 3 200 5 1 150 250

    // Partition around 100 (split into <100 and >=100)
    cout << "\nPartitioning the list around value 100:\n";
    myList->partitionList(100);
    myList->printList(); // Output: 3 5 1 200 150 250

    // Delete all nodes to empty the list
    cout << "\nDeleting all nodes:\n";
    while (myList->getByIndex(0)) {
        myList->deleteHead();
    }
    myList->printList(); // Output: Empty list

    // Append to an empty list
    cout << "\nAppending 99 to an empty list:\n";
    myList->append(99);
    myList->printList(); // Output: 99

    // Initialize a linked list with one node (value = 1)
    LinkedList* myList2 = new LinkedList(1);
    cout << "Creating a new linked list with initial value 1:\n";
    // add duplicates numbers to the list to use removeDuplicates functions list=1->2->2->7
    cout << "\nadd duplicates numbers to the list\n";
    myList2->append(2);
    myList2->append(2);
    myList2->append(7);
    myList2->append(1);
    myList2->append(7);
    myList2->append(5);
    cout << " \nThe list Befor remove Duplicates= \n";
    myList2->printList();
    cout << " \nThe list After remove Duplicates= \n";
    myList2->removeDuplicates();
    myList2->printList();// 1->2->7
    // Cleanup
    delete myList;

    return 0;
}