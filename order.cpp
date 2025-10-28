#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

#define MAX 10

int countOrders = 0;

class Node {
public:
    int orderId;
    Node* next;

    Node(int id) {
        orderId = id;
        next = NULL;   // ? replaced nullptr with NULL
    }
};

class PizzaOrder {
public:
    Node* head;

    PizzaOrder() {
        head = NULL;   // ? replaced nullptr with NULL
    }

    void acceptOrder();
    void serveOrder();
    void displayOrder();
};

void PizzaOrder::acceptOrder() {
    if (countOrders == MAX) {
        cout << "Order limit reached!" << endl;
        return;
    }

    int randomId = rand() % 1000;
    Node* newNode = new Node(randomId);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    countOrders++;
    cout << "Order accepted! Order ID: " << randomId << endl;
    displayOrder();
}

void PizzaOrder::serveOrder() {
    if (head == NULL) {
        cout << "No orders to serve." << endl;
        return;
    }

    cout << "Serving order ID: " << head->orderId << endl;

    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        Node* last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete temp;
    }

    countOrders--;
    displayOrder();
}

void PizzaOrder::displayOrder() {
    if (head == NULL) {
        cout << "No pending orders." << endl;
        return;
    }

    cout << "Pending Orders: ";
    Node* ptr = head;
    do {
        cout << ptr->orderId << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

int main() {
    srand(time(0));
    PizzaOrder p;
    int choice;

    cout << "=== Pizza Order Management System ===" << endl;

    while (true) {
        cout << "\n1. Accept Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.acceptOrder();
                break;
            case 2:
                p.serveOrder();
                break;
            case 3:
                p.displayOrder();
                break;
            case 4:
                cout << "Exiting system..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
