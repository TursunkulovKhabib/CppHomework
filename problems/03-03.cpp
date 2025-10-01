#include <iostream>

struct Node {
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}
    
    bool empty() const {
        return head == nullptr;
    }
    
    void show() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    void push_front(int value) {
        Node* new_node = new Node(value);
        if (empty()) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }
    
    void push_back(int value) {
        Node* new_node = new Node(value);
        if (empty()) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    
    void pop_front() {
        if (empty()) return;
        
        Node* temp = head;
        head = head->next;
        delete temp;
        
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    
    void pop_back() {
        if (empty()) return;
        
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    
    int get() const {
        if (empty()) return 0;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->value;
    }
    
    ~List() {
        while (!empty()) {
            pop_front();
        }
    }
};

int main() {
    return 0;
}
