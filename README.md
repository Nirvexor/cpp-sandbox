# C++ Sandbox

This repository serves as a designated environment for testing core C++ concepts, specifically focusing on manual memory management, pointer logic, and fundamental data structures.

The code within this repository is experimental and intended for educational purposes to verify syntax and behavior before implementation in production-level projects.

## Contents

### 1. Heap Memory Management
* **File:** `heap_memory.cpp`
* **Focus:** Demonstrates the difference between stack and heap allocation.
* **Key Concepts:** `new`, `delete`, pointer dereferencing, and avoiding memory leaks by properly releasing dynamic arrays.

### 2. Pointer Arithmetic
* **File:** `pointer_arithmetic.cpp`
* **Focus:** Navigating arrays using raw pointers instead of indices.
* **Key Concepts:** Pointer incrementation, struct pointers, and the arrow operator (`->`) for accessing struct members via pointers.

### 3. Linked List Implementation
* **File:** `linked_list_intro.cpp`
* **Focus:** Manual implementation of a singly linked list.
* **Key Concepts:** Node structure, dynamic node allocation, linking nodes via pointers, and traversing the list until `nullptr`.

## Usage

Each file is a standalone executable. Compile using a standard C++ compiler:

```bash
g++ heap_memory.cpp -o heap
./heap
```
## Author
Nirvexor