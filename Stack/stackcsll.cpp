#include <iostream>
using namespace std;

//Terkadang instead of array, kita mau punya strujtur data yang bisa narok sekali banyak tipe data, misalnya string dan integer, maka kita bisa pakai struct dan penglogikaan linked list.

struct Buku {
    string judul, pengarang;
    Buku *next, *prev;
};
int maximal = 5;
//Menggunakan circular double linked list
Buku *head = NULL, *tail = NULL;

int count() {
    Buku *current = head;
    int count = 0;
    while (current != tail) {
        count++;
        current = current->next;
    }
    return count;
}

void print() {
    Buku *current = head;
    while (current != tail) {
        cout << "Judul: " << current->judul << endl;
        cout << "Pengarang: " << current->pengarang << endl;
        current = current->next;
    } 
    cout << "\n\n";
}

//ingat logika stack itu FIFO, maka kita push dari depan, pop dari depan, dan peek dari depan.
void push() {

    if (count() == maximal) {
        head->prev = nullptr;
        tail->next = nullptr;
        cout << "Data sudah penuh!\n";  
        return;
    }

    Buku *newNode = new Buku;
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, newNode->judul);
    cout << "Masukkan pengarang buku: ";
    getline(cin, newNode->pengarang);
    if (head == NULL) {
        head = tail = newNode;
        head->next = head;
        head->prev = tail;
        tail->next = head;
        tail->prev = tail;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        head = newNode;
        tail->next = head;
    }
}

void pop() {
    if (head == nullptr) {
        cout << "Data masih kosong!\n";
        return;
    }
    Buku *del = head;
    head = head->next;
    head->prev = tail;
    delete del;
}

int main() {
    push();
    push();
    push();
    push();
    push();
    push();
    push();
    print();
    pop();
    return 0;
}

