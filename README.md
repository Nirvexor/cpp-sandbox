# C++ Sandbox

This repository serves as a designated environment for testing core C++ concepts, specifically focusing on manual memory management, pointer logic, and fundamental data structures.

The code within this repository is experimental and intended for educational purposes to verify syntax and behavior before implementation in production-level projects.

## Contents

### Gladiator Arena (v1.0) 
A text-based turn-based combat system using OOP. File version is the monolith one.

**File:** `Gladiator_Arena_Monolith.cpp`

### Rock Paper Scissors (v1.0)
A console-based game implementing modern RNG (Mersenne Twister).

**File:** `Rock-Paper-Scissors.cpp`

### Number Guessing Game(v0.5)
A simple C++ number guessing game that you try to guess a randomşy generated number.

**File:** `guess.cpp`

### 1. Heap Memory Management
* **File:** `heap_memory.cpp`
* **Focus:** Demonstrates the difference between stack and heap allocation.
* **Key Concepts:** `new`, `delete`, pointer dereferencing, and avoiding memory leaks by properly releasing dynamic arrays.

### 2. Linked List Implementation
* **File:** `linked_list_intro.cpp`
* **Focus:** Manual implementation of a singly linked list.
* **Key Concepts:** Node structure, dynamic node allocation, linking nodes via pointers, and traversing the list until `nullptr`.

### 3. Object-Oriented Basics
* **File:** `oop_basics.cpp`
* **Focus:** Introduction to Classes and Object Lifecycle.
* **Key Concepts:** Encapsulation (Private/Public), Constructors for initialization, Destructors for memory cleanup, and scope-based object lifetime.

### 4. Pointer Arithmetic
* **File:** `pointer_arithmetic.cpp`
* **Focus:** Navigating arrays using raw pointers instead of indices.
* **Key Concepts:** Pointer incrementation, struct pointers, and the arrow operator (`->`) for accessing struct members via pointers.

### 5. Polymorphism & Inheritance
* **File:** `polymorphism_intro.cpp`
* **Focus:** Derived classes and dynamic dispatch.
* **Key Concepts:** Base and Derived classes, `protected` access specifier, `virtual` functions, and `virtual` destructors to prevent memory leaks when deleting derived objects via base pointers.

## Usage

Each file is a standalone executable. Compile using a standard C++ compiler:

```bash
g++ heap_memory.cpp -o heap
./heap
```
## Author
Nirvexor