#include <iostream>
using namespace std;

int main(){
    
    struct Node{
        int value;
        Node* next;
    };

    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

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

    delete head;
    delete second;
    delete third;

    return 0;
}