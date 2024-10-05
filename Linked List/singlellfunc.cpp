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


int count() {
    Movie *current = head;
    int count = 0;
    //logika yang sama dengan printing dan tranversing linked list
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

void print() {
    Movie *current = head;
    cout << "There are " << count() << " nodes in the linked list\n";
    int i = 1;
    while (current != nullptr) {
        cout << "Title " << i << ": " << current->title << "\n";
        cout << "Director " << i << ": " << current->director << "\n";
        cout << "Year " << i << ": " << current->year << "\n";
        current = current->next;
        i++;
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

void addPosition(int posisi) {
    //Logika nya kita bakal tranversing dulu ke posisi sebelum posisi, untuk ganti next node nya jadi ke ke node baru kita.

    Movie *current = head;
    int i = 1;
    while (i < posisi - 1) { //karena kita mau ke posisi sebelum posisi yang diinput
        current = current->next; //setelah dapat current nya
        i++;
    }
    Movie *newNode = new Movie; //buat node baru buat nyimpen data baru
    cout << "Enter the title of the Movie: ";
    cin.ignore();
    getline(cin, newNode->title);

    cout << "Enter the director of the Movie: ";
    getline(cin, newNode->director);
        
    cout << "Enter the year of the Movie: ";
    cin >> newNode->year; 
    newNode->next = current->next; 
    current->next = newNode; //next nya kita ke newNode
    //Logika nya adalah kan yang current posisi yang setelah nya mau kita sisipi new data/node, nah otomatis si current ini pointer nya nunjuk ke newNode dan newNode pointer nya nunjuk ke next node yang sebelumnya di pegang current. Ingat kita main pointer jadi perubahan di current langsung ke node yang dia tunjuk.
       
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

void deletePosition(int posisi) {
    //Handling error position
    if (posisi < 1) {
        cout << "Invalid position!" << endl;
        return;
    } else if (posisi == 1) {
        deletFront();
        return;
    } else if (posisi >= count()) {
        cout << "Invalid position! (HINT: OUT OF RANGE)" << endl;
        return;
    } else if (posisi == count()) {
        deleteBack();
        return;
    }

    Movie *del, *current = head;
    int i = 1; 
    //logika nya sama kayak addPosition dan deleteBack, kita tranverse dulu ke posisi sebelum posisi yang diinput, lalu kita delete node yang diinput.
    while (i < posisi - 1) {
        current = current->next; //current naik terus ke current selanjutnya
        i++;
    }
    del = current->next; //del nya di set ke node yang mau dihapus
    current->next = del->next; //karena del mau dihapus, maka penunjuk pointer dari del kita pindahin dulu ke current
    delete del; 
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

    cout << "\n\n\n";
    int posisi;
    cout << "Which position do you want to add the node? ";
    cin >> posisi;
    addPosition(posisi);
    print();

    cout << "\n\n\n";
    cout << "Which position do you want to add the node? ";
    cin >> posisi;
    deletePosition(posisi);
    print();

    //bisa juga buat function buat changes, ya logika nya sama kek create newnode tapi kita ubah langsung di current itu setelah di tranverse di posisi yang diinginkan.
}    



