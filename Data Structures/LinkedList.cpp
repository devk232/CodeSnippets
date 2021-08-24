#include <iostream>
#include <vector>
using namespace std;


struct node {
    int data;
    node* next;
    node (int x) {
        this->data = x;
        this->next = NULL;
    }
}; 

struct LinkedList {
    int size = 0;
    node* head = new node(0);
    void printLinkedList () {
        node* temp = head->next;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void addAtTail (int val) {
        node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new node(val);
        size++;
    }
    void addAtStart(int val) {
        node* temp = head->next;
        head->next = new node(val);
        head->next->next = temp;
        size++;
    }
    void addAtIndex(int val, int x) {   
        if (x > size) return;
        node* temp = head;
        for (int i = 0; i < x; i++)
            temp = temp->next;
        node* temp1 = temp->next;
        temp->next = new node(val);
        temp->next->next = temp1;
        size++;
    }
    void deleteAtIndex (int val, int x) {
        if (x >= size) return;
        node* temp = head;
        for (int i = 0; i < x; i++) 
            temp  = temp->next;
        node* temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next = NULL;
        size--;
        delete temp1;
    }
    int getAtIndex (int x) {
        if (x >= size) return -1;
        node *temp = head;
        for (int i = 0; i <= x; i++) 
            temp = temp->next;
        return temp->data;
    }
    int showSize() {
        return size;
    }
};

int main() {
    LinkedList* obj = new LinkedList();
    obj->printLinkedList();
    return 0;
}
