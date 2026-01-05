#include <iostream>
using namespace std;

int main(){
    
    struct Node{
        int value;
        Node* next;
    };
    
    // I think this is not a linked list. it is a chain, don't say "no shit sherlock"
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    
    // We access to the memory with head -> next instead of (*head).next, why? because it is ugly.
    head ->next = second;
    second ->next = third;
    third ->next = nullptr;

    // The values
    head ->value = 100;
    second ->value = 200;
    third ->value = 50;

    Node* current = head;

    while (current != nullptr){
        cout << current->value << endl;
        current = current->next;
    }

    // Tell compiler to delete them after you have done with them. Prevent leaks.
    delete head;
    delete second;
    delete third;

    return 0;
}