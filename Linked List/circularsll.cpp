#include <iostream>
#include <string>
using namespace std;
//circular single linked list, circular meaning threre is no null at the end of the list.
//tail menunjuk ke head kembali.

//deklarasi dan inisialisasi mirip dengan single linked list
struct Data{
    string nama, id;
    int umur;
    Data *next;
};
Data *head = nullptr;
Data *tail = nullptr;


// void create() {
//     head = new Data;

//     cout << "Masukkan nama: ";
//     getline(cin, head->nama);
//     cout << "Masukkan id: ";
//     cin >> head->id;
//     cout << "Masukkan umur: ";
//     cin >> head->umur;
//     tail = head;
//     tail->next = head; 
// } we can do this but I'll just put the logic in addFront with nullptr condition or no linked list created yet.

int count(){
    Data *current = head;
    int i = 0;
    do {
        i++;
        current = current->next;
    } while (current != head); 
    return i;
}

void addFront() {
    Data *node = new Data;
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, node->nama);
    cout << "Masukkan id: ";
    cin >> node->id;
    cout << "Masukkan umur: ";
    cin >> node->umur;
    if (head == nullptr) {
        head = tail = node;
        node->next = head;
    } else {
        node->next = head;
        head = node;
        tail->next = head; //perbarui agar tail selalu menunjuk ke head yang baru.
    }
}

void addBack(){
    Data *node = new Data;
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, node->nama);
    cout << "Masukkan id: ";
    cin >> node->id;
    cout << "Masukkan umur: ";
    cin >> node->umur;
    if (head == nullptr) {
        addFront();
    } else {
        tail->next = node; //tail yang lama, kita ganti next nya ke node yang baru
        tail = node; //ganti tail dengan node yang baru
        tail->next = head; //perbarui agar tail selalu menunjuk ke head yang baru.
    }
}

void addPosition(int position) {
    Data *current = head;
    Data *node = new Data;

    if (count() == position) {
        addBack();
        return;
    } else if (position == 1) {
        addFront();
        return;
    } else if (position < 1 && position > count()) {
        cout << "Invalid position!" << endl;
        return;
    }

    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, node->nama);
    cout << "Masukkan id: ";
    cin >> node->id;
    cout << "Masukkan umur: ";
    cin >> node->umur;

    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    
    node->next = current->next;
    current->next = node;

}

void deleteFront() {
    Data *del = head;
    //ubah headnya ke head->next atau head yang setelahnya.
    tail->next = head->next;
    head = head->next;
    delete del;
}

void deleteBack() {
    Data *del = tail;
    Data *current = head;
    //iterasi sampai sebelum tail
    while (current->next != tail) {
        current = current->next;
    }
    current->next = head; //current yang sebelum tail, kita ganti next nya ke head
    tail = current; //tail kita ganti dengan current
    delete del;
}

void deletePosition(int position) {
    Data *current = head;
    Data *del;

    if (count() == position) {
        deleteBack();
        return;
    } else if (position == 1) {
        deleteBack();
        return;
    } else if (position < 1 && position > count()) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    
    current->next = current->next->next; //kita ubah dulu si arah setelah current ke lompat dua, karena current->next nya yang mau kita hapus
    del = current->next; //yang mau kita hapus
    delete del;

}



void print(){
    Data *current = head;
    cout << "Total data: " << count() << endl;
    cout << "Nama             | ID          | Umur" << endl;
    cout << "-------------------------------------" << endl;
    do {
        cout << current->nama << " | " << current->id << " | " << current->umur << endl;
    cout << "-------------------------------------" << endl;
        current = current->next;
    } while (current != head); //jadi head yang pertama di print juga.
}


int main() {
    addFront();
    addFront();
    addFront();
    print();
    addBack();
    addBack();
    print();
    deleteFront();
    deleteBack();
    print();
    addFront();
    addFront();
    print();
    addPosition(2);
    print();
    deletePosition(2);
    print();
}