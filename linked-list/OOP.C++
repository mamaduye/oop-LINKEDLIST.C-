#include <iostream>
using namespace std;

// Deklarasi kelas Buku
class Buku {
public:
    // Komponen
    string judul, pengarang;
    int tahunTerbit;
    Buku *next;

    // Konstruktor
    Buku(string judul, string pengarang, int tahunTerbit) {
        this->judul = judul;
        this->pengarang = pengarang;
        this->tahunTerbit = tahunTerbit;
        this->next = nullptr;
    }
};

// Kelas untuk LinkedList
class LinkedList {
public:
    Buku *head, *tail;

    // Konstruktor
    LinkedList() {
        head = tail = nullptr;
    }

    // Menambahkan node di awal
    void addFirst(string judul, string pengarang, int tahunTerbit) {
        Buku *newNode = new Buku(judul, pengarang, tahunTerbit);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Menambahkan node di akhir
    void addLast(string judul, string pengarang, int tahunTerbit) {
        Buku *newNode = new Buku(judul, pengarang, tahunTerbit);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Menambahkan node di tengah pada posisi tertentu
    void addMiddle(string judul, string pengarang, int tahunTerbit, int posisi) {
        Buku *newNode = new Buku(judul, pengarang, tahunTerbit);
        Buku *cur = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            cur = cur->next;
            nomor++;
        }

        newNode->next = cur->next;
        cur->next = newNode;
    }

    // Menghapus node di awal
    void removeFirst() {
        if (head) {
            Buku *del = head;
            head = head->next;
            delete del;
        }
    }

    // Menghapus node di akhir
    void removeLast() {
        if (head) {
            Buku *cur = head;
            Buku *del = tail;

            if (head == tail) {
                head = tail = nullptr;
            } else {
                while (cur->next != tail) {
                    cur = cur->next;
                }

                tail = cur;
                tail->next = nullptr;
            }

            delete del;
        }
    }

    // Menghapus node di tengah pada posisi tertentu
    void removeMiddle(int posisi) {
        if (head && posisi > 1 && posisi <= countLinkedList()) {
            Buku *cur = head;
            Buku *del = nullptr;
            int nomor = 1;

            while (nomor <= posisi) {
                if (nomor == posisi - 1) {
                    del = cur;
                }
                if (nomor == posisi) {
                    del = cur->next;
                    cur->next = del->next;
                }
                cur = cur->next;
                nomor++;
            }

            delete del;
        }
    }

    // Mengubah data node di awal
    void changeFirst(string judul, string pengarang, int tahunTerbit) {
        if (head) {
            head->judul = judul;
            head->pengarang = pengarang;
            head->tahunTerbit = tahunTerbit;
        }
    }

    // Mengubah data node di akhir
    void changeLast(string judul, string pengarang, int tahunTerbit) {
        if (tail) {
            tail->judul = judul;
            tail->pengarang = pengarang;
            tail->tahunTerbit = tahunTerbit;
        }
    }

    // Mengubah data node di tengah pada posisi tertentu
    void changeMiddle(string judul, string pengarang, int tahunTerbit, int posisi) {
        if (head && posisi > 1 && posisi <= countLinkedList()) {
            Buku *cur = head;
            int nomor = 1;

            while (nomor < posisi) {
                cur = cur->next;
                nomor++;
            }

            cur->judul = judul;
            cur->pengarang = pengarang;
            cur->tahunTerbit = tahunTerbit;
        }
    }

    // Menghitung jumlah node dalam linked list
    int countLinkedList() {
        Buku *cur = head;
        int jumlah = 0;

        while (cur) {
            jumlah++;
            cur = cur->next;
        }

        return jumlah;
    }

    // Menampilkan seluruh linked list
    void printLinkedList() {
        cout << "Jumlah data ada : " << countLinkedList() << endl;
        Buku *cur = head;

        while (cur) {
            cout << "Judul Buku : " << cur->judul << endl;
            cout << "Pengarang Buku : " << cur->pengarang << endl;
            cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

            cur = cur->next;
        }
    }
};

int main() {
    // Membuat objek dari kelas LinkedList
    LinkedList linkedList;

    linkedList.addFirst("Kata", "Geez & Aan", 2018);
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList.addFirst("Dia Adalah Kakakku", "Tere Liye", 2009);
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList.addLast("Dia cucu kecilku", "Kakek kuat", 2019);
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList.removeFirst();
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList.addLast("Dia simpananku", "Kakek muscular", 2119);
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList.removeLast();
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList.changeFirst("berhenti onani", "fadhil", 2018);
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList.addMiddle("GENDURUO AIR PAYAW", "INCAN", 2011, 2);
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList.addMiddle("sibuta agama", "wanchan", 2007, 2);
    linkedList.printLinkedList();
    cout << "\n\n" << endl;

    linkedList
