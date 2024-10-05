#include <iostream>
#include <string>
using namespace std;

struct Movie {
    string title, director;
    int year;
    Movie *next, *prev;
};
Movie *head = nullptr;
Movie *tail = nullptr;

int countFronttoBack() {
    Movie *current = head; //nggak perlu new Movie karena kita bukan mau buat new node. cumak untuk referensi aja.
    int i = 0;
    while (current != nullptr) {
        current = current->next;
        i++;
    }
    return i;
}

void printFronttoBack() {
    Movie *current = head; //nggak perlu new Movie karena kita bukan mau buat new node. cumak untuk referensi aja.
    int i = 1;
    cout << "Total Movie: " << countFronttoBack() << "\n";
    while (current != nullptr) {
        cout << "Title " << i << ": " << current->title << "\n";
        cout << "Director " << i << ": " << current->director << "\n";
        cout << "Year " << i << ": " << current->year << "\n";
        current = current->next;
        i++;
    }
}

void addFront(){
    Movie *node = new Movie;
    cout << "Enter the title of the Movie: ";
    cin.ignore();
    getline(cin, node->title);
    cout << "Enter the director of the Movie: ";
    getline(cin, node->director);
    cout << "Enter the year of the Movie: ";
    cin >> node->year;
    node->next = head; //ingat kita ubah yang next nya dengan head yang sebelumnya
    node->prev = nullptr; //karena node baru, maka prev nya null
    // head = node;
    if (head == nullptr) {
        head = tail = node;
    } else {
        head->prev = node; //head yang lalu, prev nya kita ubah jadi node yang baru.
        head = node;
    }
}

void addBack() {
    Movie *node = new Movie;
    cout << "Enter the title of the Movie: ";
    cin.ignore();
    getline(cin, node->title);
    cout << "Enter the director of the Movie: ";
    getline(cin, node->director);
    cout << "Enter the year of the Movie: ";
    cin >> node->year;
    node->prev = tail; //ingat kita ubah yang sebelumnya dengan node tail yang sebelumnya
    node->next = nullptr; //karena node baru, maka next nya null
    if (tail == nullptr) {
        head = tail = node;
    } else {
        tail->next = node; //tail yang lalu, next nya kita ubah jadi node yang baru.
        tail = node;
    }
}

void addPosition(int position) {
    Movie *node = new Movie;
    Movie *current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    } 

    cout << "Enter the title of the Movie: ";
    cin.ignore();
    getline(cin, node->title);
    cout << "Enter the director of the Movie: ";
    getline(cin, node->director);
    cout << "Enter the year of the Movie: ";
    cin >> node->year;
    node->prev = current;
    node->next = current->next;
    current->next = node;
}

void deleteFront() {
    Movie *del = head;
    head->prev = nullptr;
    head = head->next;
    delete del;
}

void deleteBack() {
    Movie *del = tail;
    Movie *current = tail->prev; //enaknya double linked list nggak perlu tranversing karena ada prev
    current->next = nullptr;
    delete del;
}

void deletePosition(int position) {
    Movie *current = head;
    Movie *del;

    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    } else if (position == 1) {
        deleteFront();
        return;
    } else if (position >= countFronttoBack()) {
        cout << "Invalid position! (HINT: OUT OF RANGE)" << endl;
        return;
    } else if (position == countFronttoBack()) {
        deleteBack();
        return;
    }

    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    del = current->next;
    current->next = del->next; 
    if (del->next != nullptr) {
        current->next->prev = current; //bacanya node setelah current, kita ubah prev nya atau nunjuk langsung ke current.
    }
    delete del;
}



int main() {
    addFront();
    addFront();
    addFront();
    printFronttoBack();
    addBack();
    printFronttoBack();
    deleteFront();
    deleteBack();
    printFronttoBack();
    addFront();
    addPosition(2);
    printFronttoBack();
    deletePosition(2);
    printFronttoBack();
}