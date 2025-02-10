# 🚀 Mastering Linked Lists in C++ 🪖

Welcome to the **Mastering Linked Lists in C++** repository! This project provides a comprehensive implementation of a **singly linked list** in C++, including essential operations and solutions to popular coding interview questions. Whether you're preparing for interviews or aiming to deepen your data structure knowledge, this repo is for you!
---

## 📝 Features

### 🔹 **Core Linked List Operations**
- **Insertion**: Append, prepend, and insert at any index.
- **Deletion**: Remove by value, index, head, or tail.
- **Traversal**: Access nodes by index and print the list.
- **Reverse**: In-place reversal of the entire list.
- **Edge Case Handling**: Manages head/tail pointers, list length, and memory safety.

### 🔹 **Solutions to Common Interview Questions**
1. **Find the Middle Node**  
2. **Detect a Loop**  
3. **Find k-th Node from End**  
4. **Partition List Around Value X**  
5. **Remove Duplicates**  
6. **Convert Binary to Decimal**  
7. **Reverse Sublist Between Indices**

---

## 🖥️ Code Structure
The project is organized into a single C++ file (`main.cpp`) containing:
- **Node Class**: Represents a single element in the linked list.
- **LinkedList Class**: Manages the entire linked list and implements all operations.
- **Main Function**: Demonstrates usage with practical examples.

---

## ⚙️ How to Use

### **Prerequisites**
- A C++ compiler (e.g., `g++`).
- Basic understanding of C++ and linked lists.

### **Steps**
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/mastering-linked-lists.git
   cd mastering-linked-lists
---

## **Example Output**
```
Creating a new linked list with initial value 1:
1 
Head: 1
Tail: 1

Appending 2, 3, and 4:
1 2 3 4 
Tail: 4

Prepending 0:
0 1 2 3 4 
Head: 0

Inserting 100 at index 2:
0 1 100 2 3 4 

Getting node at index 3:
Value at index 3: 2

Updating value at index 3 to 200:
0 1 100 200 3 4 

Deleting node with value 100:
0 1 200 3 4 

Deleting node at index 0:
1 200 3 4 

Deleting the head:
200 3 4 
Head: 200

Deleting the tail:
200 3 
Tail: 3

Reversing the list:
3 200 

Finding the middle node:
Middle node value: 3

Checking if the list has a loop:
No loop

Finding the 1st node from the end:
1st node from end: 200

Partitioning the list around value 200:
3 200 

Appending 5, 1, 150, 250:
3 200 5 1 150 250 

Partitioning the list around value 100:
3 5 1 200 150 250 

Deleting all nodes:
Empty list

Appending 99 to an empty list:
99 
```

---

## **Key Highlights**
- **Efficient Operations**: Most operations (e.g., insertion/deletion at head/tail) run in *O(1)* time.
- **Memory Safety**: Properly deallocates memory to prevent leaks.
- **Interview-Ready**: Includes solutions to common linked list problems asked in technical interviews.

---

## **Contributing**
Contributions are welcome! If you find a bug or want to add a feature, please:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Open a pull request.

---

## **License**
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## **Acknowledgments**
- Inspired by common coding interview problems.
- Special thanks to the C++ community for their invaluable resources.

---

Happy coding! 🚀
```

You can copy and paste this into a `README.md` file in your GitHub repository. Make sure to replace `your-username` in the clone URL with your actual GitHub username. Let me know if you need further assistance! 😊
