#include <iostream>
#include <string>
using namespace std;

//array global
int maximal = 5, front = 0, back = 0;
//ruang antrian
int queue[5];

bool isFull() {
    if (back == maximal) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueue() {
    int data;
    if(isFull()) {
        cout << "\nAntrian sudah penuh!\n";
    } else {
        cout << "\nMasukkan angka: ";
        cin >>data;
        if(isEmpty()) {
            //menambahkan data awal jika kosong, pertama ngantri
            queue[0] = data;
            front++; //front akan tetap di yang pertama atau indeks 0.
            back++;
        } else {
            queue[back] = data;
            back++;
            //yang akan gerak cuma back, dan back akan terus dibolehin mengisi selaama < maximal.
        }
    }
}

void dequeue() {
        if(isEmpty()) {
        cout << "\nAntrian kosong!\n"; }
        else {
            //logikanya kan kita buang yang top alias index[0] tapi kita ganti aja langsung dengan yang posisi selanjutnya dan yang lainnya geser kedepan juga
            //queue[0] = queue[1];
            //queue[1] = queue[2];
            //queue[2] = queue[3];
            //queue[3] = queue[4];
            //queue[4] = 0; //karena yang terakhir kan udah di geser ke depan, jadi yang terakhir diisi 0.
            for (int i = 0; i < back; i++) {
                queue[i] = queue[i + 1];
                back--; //back akan terus berkurang, karena yang di depan terus dihapus.
            }
        }
}

int count() {
            if (isEmpty()) {
                return 0; // yang kosong dilewati aja nggak usah dihitung.
            } else {
                return back; //back akan terus berkurang, karena yang di depan terus dihapus.
            }
}

void display() {
    if(isEmpty()) {
        cout << "\nAntrian kosong!\n";
    } else {
        cout << "\nJumlah antrian: " << count();
        cout << "\nAntrian: ";
        for (int i = 0; i < maximal; i++) {
            if (queue[i] == 0) {
                cout << "kosong "; //untuk yang nggak ada isi alias ""
            } else {
                cout << queue[i] << " ";
            }
        }
    }
}

void destroy() {
    if(isEmpty()) {
        cout << "\nAntrian kosong!\n";
    } else {
        for (int i = 0; i < maximal; i++) {
            if  (back > 1) {
                queue[back-1] = 0;
                back--; //bakal sisa sampai back = 1 dan front = 1; makanya kita lanjutin ke else
            } else {
                //kalo yang terakhir, yang dihapus cuma satu, karena yang lain udah dihapus semua.
                queue[0] = 0;
                back = 0;
                front = 0; 
            }
        }
    }
}



int main() {
    enqueue();
    enqueue();
    display();
    dequeue();
    enqueue();
    display();
    enqueue();
    enqueue();
    display();
    destroy();
    display();
}