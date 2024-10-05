#include <iostream>
#include <string>

using namespace std;

struct Movie {
    string title, director;
    int year;
    Movie *next;
};

Movie *head = nullptr; // Head pointer to the first node

void createLinkedList(int jumlahnode) {
    Movie *newNode, *tail = nullptr;

    for (int i = 0; i < jumlahnode; i++) {
        newNode = new Movie;

        cout << "Enter the title of the " << i + 1 << " Movie: ";
        cin.ignore();
        getline(cin, newNode->title);

        cout << "Enter the director of the " << i + 1 << " Movie: ";
        getline(cin, newNode->director);

        cout << "Enter the year of the " << i + 1 << " Movie: ";
        cin >> newNode->year;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "\nAll nodes are created successfully!\n";
}

void print() {
    Movie *current = head;
    int count = 1;

    while (current != nullptr) {
        cout << "Title " << count << ": " << current->title << "\n";
        cout << "Director " << count << ": " << current->director << "\n";
        cout << "Year " << count << ": " << current->year << "\n";
        count++;
        current = current->next;
    }
}

int main() {
    int n;
    cout << "How many first node do you want to create? ";
    cin >> n;
    createLinkedList(n);
    print();

    return 0;
}