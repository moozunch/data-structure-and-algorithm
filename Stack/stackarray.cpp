#include <iostream>
#include <string>
using namespace std;

int maximal = 5;
int top = 0; //karena stack, maka patokannya adalah top() yaitu yang paling terakhir dimasukkan, makanya pertama di set ke 0 untuk yang paling bawah.
string arraybuku[5];

bool isFull() {
    if (top >= maximal) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (top == 0) {
        //nggak boleh di set top <= maximal karena kalau data ditambahkan maka top++ dan masih dibawah maximal jadi tampilan masih kosong masih akan ditampikan.
        return true;
    } else {
        return false;
    }
}

void push (string data) {
    if (isFull()) {
        cout << "Data sudah penuh!\n";
        cout << "-----------------\n";
    } else {
        arraybuku[top] = data;
        top++;
    }
}

void pop () {
    if (isEmpty()) {
        cout << "Data masih kosong!\n";
        cout << "-----------------\n";
    } else {
        //Ingat karena stack, maka yang di pop adalah yang paling terakhir dimasukkan (top).
        arraybuku[top-1] = ""; //ingat karena dimulai dari 0, maka top-1 dan di set kosong.
        top--; //jangan lupa decrement, biar bisa diisi lagi di index yang kosong itu dan tidak melangkahi.
    }
}

int count () {
    if (isEmpty()) {
        cout <<"Data masih kosong!\n";
        cout << "-----------------\n";
    }
    // int count = 0;
    // for (int i = maximal - 1; i >= 0; i--){
    //     if (arraybuku[i] != "" ) { 
    //         count++; return count;
    //     } cara tradisional, bisa aja langsung panggil top
    return top;
}

void display () {
    if (isEmpty()) {
        cout <<"Data masih kosong!\n";
        cout << "-----------------\n";
    }
    cout << "Data buku yang tersimpan: " << count() << "\n";
    for (int i = maximal - 1; i >= 0; i--){
        // ingat karena stack, maka kita print dari yang terakhir dimasukkan alias paling depan jadi descending.
        if (arraybuku[i] != "" ) { 
            cout << "\t\t"; //tab atau indentasi
            cout << "Data: " << arraybuku[i] << endl;
        } //karena kita udah set batas kan 5, jadi walaupun belum di push tapi memory tetap ada dan terbaca, makanya dibuat kondisi lagi biar cuma yang terisi aja yang di print
    }
    cout << "\n\n";
}

void peek(int position) {
    if (isEmpty()) {
        cout <<"Data masih kosong!\n";
        cout << "-----------------\n";
    } else {
        int index = top;
        for (int i = 0; i < position; i++) {
            index--;
        }
        cout << "Posisi " << position << " disimpan array pada index " << index << " adalah " << arraybuku[index] << endl;
    }
    //kalau posisi, beda dengan index yang dari 0, posisi dari 1 jadi nanti kita index + 1
    //nah gini, kan stack kita masukin data nya dari paling bawah itu index nya 0 sampai penuh index 4, 
    //push("hujan") -> index array 0 -> posisi ke 5 alias paling bawah 
    //push("matahari") -> index array 1 -> posisi ke 4
    //push("si anak pemberani") -> index array 2 -> posisi ke 3
    //push("si anak cerdas") -> index array 3 -> posisi ke 2
    //dan begitu seterusnya, ini kebalikannya kan, makanya kita pakai ascending karena push descending.
}

void change(string data, int position) {
    if (isEmpty()) {
        cout <<"Data masih kosong!\n";
        cout << "-----------------\n";
    } else {
        int index = top;
        for (int i = 0; i < position; i++) {
            index--; //logika yang sama dengan peak
        }
        arraybuku[index] = data;
    }

}

void destroy() {
    for (int i = 0; i < top; i++) {
        arraybuku[i] = "";
    }
    top = 0; //inisialisasikan ulang ke 0
    cout << (isEmpty() ? "Data masih kosong!\n" : "Data masih ada!\n");
} 



int main() {
    push("hujan");
    push("matahari");
    push("si anak pemberani");
    push("si anak cerdas");
    push("bulan");
    display();
    peek(2); //posisi ke2 berarti index ke 3
    display();
    pop();
    display();
    change ("bumi", 2); //ubah posisi ke 2 jadi bumi
    display();
    destroy();
    display();
}