#include <iostream>
using namespace std;

//Create structure
struct Movie {
    //component/member
    string title, director;
    int year;
    //pointer to next node, dengan tipe data struct itu sendiri karena next juga punya member yang sama
    Movie *next;
};


int main () {
//      create variable node/simpul
    Movie *node1, *node2, *node3; //create a pointer variable   cause di struct ada pointer and linked list is all about  pointer.

//    cara klasik inisialisasi atau procedural
//    node1 = (Movie*) malloc(sizeof(Movie));
//    cara 2 yang mengadopsi object oriented programming
//    node2 = new Movie(); //much simpler and we'll use this.

    node1 = new Movie();
    node2 = new Movie();
    node3 = new Movie();

//    assign value to the node, harus pakai -> bukan . karena pointer
      node1->title = "The Shawshank Redemption";
      node1->director = "Frank Darabont";
      node1->year = 1994;
      node1->next = node2;

      node2->title = "Falling in love like in movies";
      node2->director = "Yandi Laurens";
      node2->year = 2023;
      node2->next = node3;

      node3->title = "War for the planet of the apes";
      node3->director = "Matt Reeves";
      node3->year = 2017;
      node3->next = NULL;

//    print the linked list - tranversing (looping through the linked list)
    Movie *current; //create a pointer variable again to save the current
    current = node1; //assign the current to the address of first node so it can access all the members of the node
    //looping using while beacuse we don't know how many nodes we have if it's dinamycally allocated and using condition whether the current is null or not
    while (current != NULL) {
        cout << "Title: " << current->title << "\n";
        cout << "Director: " << current->director << "\n";
        cout << "Year: " << current->year << "\n";

        current = current->next; //set to the next node
    }


    //Dasar linked list itu menambahkan di awal, di akhir dan delete di awal dan di akhir.

    //Adding new node
    //Logika nya adalah kita create new node macam biasa kemudian kita set node itu jadi head atau tail dan ubah juga next nya.

    Movie *node4;
    node4 = new Movie();
    node4->title = "Movie 4";
    node4->director = "Director 4";
    node4->year = 4994;
    node4->next = node1;

    cout << "\n\nAfter adding new node\n";
    current = node4; //berarti kita harus assign head di node 4 kan 
    while (current != NULL) {
        cout << "Title: " << current->title << "\n";
        cout << "Director: " << current->director << "\n";
        cout << "Year: " << current->year << "\n";

        current = current->next; //set to the next node
    }


    //To delete
    //Logikanya adalah kita perlu buat new variable hasil copyan dari head atau tail kemudian delete, jangan lupa juga ubah kembali head dan tail nya. Ingat kita mainnya pointer, dengan variable baru kita bisa akses langsung node yang sudah ada dengan alamatanya.

    Movie *temp;
    temp = node4; //copy the head
    node4 = node4->next; //set the head to the next node, kalau susah bacanya, node4 = head, nah head nya sekarang diubah jadi yang selanjutnya. jadi namanya tetap node4 tapi isinya yang node1 dah.
    delete temp;


}