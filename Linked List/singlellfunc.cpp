#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Movie {
    string title, director;
    int year;
    Movie *next;
};

Movie *head = nullptr; //head pointer to the first node
Movie *tail = nullptr; //jangan pakai array pointer, karena kita alokasikan di memorinya satu satu bukan array. Instead tarok head nya dimana dan tail nya dimana sebagai penanada.

void createLinkedlist(int jumlahnode) {
    
    for (int i = 0; i < jumlahnode; i++) { //make sures it's less than or equal to jumlahnode because nntik jadinya misal mau input 3 tapi cumak 2 yang diinput karena yang ke-3 nya itu udah null.
        Movie *node = new Movie; //create node based on the input and store it in the array of pointer
        cout << "Enter the title of the " << i+1 << " Movie: ";
        cin.ignore();
        getline(cin, node->title);

        cout << "Enter the director of the " << i+1 << " Movie: ";
        getline(cin, node->director);
        
        cout << "Enter the year of the " << i+1 << " Movie: ";
        cin >> node->year;
        node->next = nullptr; //default value of next is null tapi kita atur kemudian hubungannya dengan node lain di if berikkut

        if (head == nullptr) { //jika node tidak ada
            head = node; // Set the head to the first node
            tail = node; // Set the tail to the first node
        } else { //Jika linked list tidak kosong, node baru harus ditambahkan ke akhir linked list. Dalam hal ini, tail->next diatur ke node baru, dan kemudian tail diperbarui untuk menunjuk ke node baru.
            tail->next = node; // set the latest node as a tail->next
            tail = node; // set latest node as a tail
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

void addfront(){
    Movie *newNode = new Movie;
        cout << "Enter the title of the Movie: ";
        cin.ignore();
        getline(cin, newNode->title);

        cout << "Enter the director of the Movie: ";
        getline(cin, newNode->director);
        
        cout << "Enter the year of the Movie: ";
        cin >> newNode->year;
        newNode->next = head; //set the next of the new node to the head
        head = newNode; //dan ubah head sekarang jadi newNode
}

void addBack(){
    Movie *newNode = new Movie;
        cout << "Enter the title of the Movie: ";
        cin.ignore();
        getline(cin, newNode->title);

        cout << "Enter the director of the Movie: ";
        getline(cin, newNode->director);
        
        cout << "Enter the year of the Movie: ";
        cin >> newNode->year;
        newNode->next = nullptr; //set the next of the new node to the head
        tail->next = newNode; //dan ubah next nya tail sebelum jadi newNode
        tail = newNode; //lastly jangan lupa ubah tail sekarang jadi newNode
}

void deletFront(){
    Movie *del;
    del = head; //del mengcopy dan menunjuk ke head currently
    head = head -> next; //ganti head jadi ke node yang selanjutnya
    delete del; //otomatis delete head awal jugak karena ditunjuk pointer
}

void deleteBack(){
    Movie *del, *current;
    del = tail; //yang mau kita hapus, kita connect nya itu ke next node terakhir yaiut nullptr, ingat kalau diakses pointer bisa akses seluruh isinya.
    current = head; //perlu untuk tranverse
    
    //Unlike delete front, because we need to change the tail to the node-1, we need to traverse through the linked list

    while (current->next != tail) {
        current = current->next; 

        //logika
        // In the first iteration, current points to A, and current->next points to B. Since B is not tail, the loop continues.
        // In the second iteration, current points to B, and current->next points to C. Since C is not tail, the loop continues.
        // In the third iteration, current points to C, and current->next points to D. Since D is tail, the loop exits. jadi dia current nya tetap di c tapi point nya udah nunjuk ke D.

    }
    current->next = nullptr;
    tail = current; //ubah tail jadi yang current /sekarang.
    delete del; //delete the last node
}


int main() {
// Inisialisasi
    int n; //jumlah node
    cout << "How many first node do you want to create? ";
    cin >> n;
    createLinkedlist(n);
    print();

    cout << "\n\n\n";
    addfront();
    print();

    cout << "\n\n\n";
    addBack();
    print();

    cout << "\n\n\n";
    deletFront();
    print();

    cout << "\n\n\n";
    deleteBack();
    print();
}    



