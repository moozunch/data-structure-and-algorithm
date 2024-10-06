#include <iostream>
#include <string>
using namespace std;

//Double punya 2 pointer next dan prev, next nya menunjuk ke node selanjutnya dan prev nya menunjuk ke node sebelumnya.


struct Data{
    string nama, id;
    int age;
    Data *next, *prev;
};

Data *head = nullptr;
Data *tail = nullptr;

int count(){
    if (head == nullptr) return 0;
    Data *current = head;
    int i = 0;
    do {
        i++;
        current = current->next;
    } while (current != head); 
    return i;
}

void print(){
    Data *current = head;
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "Total data: " << count() << endl;
    cout << "Nama             | ID          | Umur" << endl;
    cout << "-------------------------------------" << endl;
    do {
        cout << current->nama << " | " << current->id << " | " << current->age << endl;
    cout << "-------------------------------------" << endl;
        current = current->next;
    } while (current != head); //jadi head yang pertama di print juga.
}

void addFront() {
    Data *node = new Data;
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, node->nama);
    cout << "Masukkan id: ";
    cin >> node->id;
    cout << "Masukkan age: ";
    cin >> node->age;
    if (head == nullptr) {
        head = tail = node;
        node->next = node->prev = head;
    } else {
        //yang penting urus prev dan next si node, juga prev head dan next tail.
        node->next = head;
        node->prev = tail;
        head->prev = node;
        tail->next = node; //perbarui agar tail selalu menunjuk ke node yang baru.
        head = node;
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
    cin >> node->age;
    if (head == nullptr) {
        addFront();
    } else {
        node->prev = tail;
        tail->next = node; //tail yang lama, kita ganti next nya ke node yang baru
        node->next = head;
        head->prev = node; //perbarui agar head prev selalu menunjuk ke node yang baru.
        tail = node; //ganti tail dengan node yang baru
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
    cin >> node->age;

    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    
    node->next = current->next;
    node->prev = current;
    current->next->prev = node;
    current->next = node;
}

void deleteFront() {
    Data *del = head;
    //ubah headnya ke head->next atau head yang setelahnya.
    tail->next = head->next;
    head = head->next;
    head->prev = tail;
    delete del;
}

void deleteBack() {
    Data *del = tail;
    Data *current = head;

    tail = tail->prev;
    //nggak perlu iterasi karena ada prev
    tail->next = head; //karena kita mau hapus tail, maka sebelum tail kita ganti next nya ke head
    head->prev = tail;
    delete del;
}

void deletePosition(int position) {
    Data *current = head;
    Data *del;

    if (count() == position) {
        deleteBack();
        return;
    } else if (position == 1) {
        deleteFront();
        return;
    } else if (position < 1 || position > count()) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    
    del = current->next; //yang mau kita hapus
    current->next = del->next;
    del->next->prev = current; //prev nya setelah node del kita ganti ke current
    delete del;

}

int main() {
    addFront();
    addFront();
    addBack();
    addPosition(2);
    print();
    deleteFront();
    deleteBack();
    print();
    addFront();
    print();
    deletePosition(2);
    print();
    return 0;
}

