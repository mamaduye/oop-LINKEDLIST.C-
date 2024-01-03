#include <iostream>
using namespace std;

struct Buku{

    //komponen
    string judul, pengarang;
    int tahunTerbit;

    Buku *next;

};

Buku *head, *tail, *cur, *newNode, *del, *before;
void createSingleLinkedList(string judul, string pengarang, int tB){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

//count linked list
int countSingleLinkedList(){
        cur = head;
        int jumlah = 0;
        while (cur!=NULL){
            jumlah++;
            cur = cur->next;
        } 
        return jumlah;   
}

//tambah awal single linked list
void addFirst(string judul, string pengarang, int tB){
   newNode = new Buku();
   newNode->judul = judul;
   newNode->pengarang = pengarang;
   newNode->tahunTerbit = tB;
   newNode->next = NULL;
   newNode = head;
   head = newNode;
}

//tambah akhir single linked list
void addLast(string judul, string pengarang, int tB){
   newNode = new Buku();
   newNode->judul = judul;
   newNode->pengarang = pengarang;
   newNode->tahunTerbit = tB;
   newNode->next = NULL;
   tail->next = newNode;
   tail = newNode;
}

//tambah tengah single linked list
void addMiddle(string judul, string pengarang, int tB, int posisi){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;

    //transversing
    cur = head;
    int nomor = 1;
    while( nomor < posisi - 1 ){
            cur = cur->next;
            nomor++;
    }

    newNode->next = cur->next;
    cur->next = newNode;
}

//remove first
void removeFirst(){
    del = head;
    head = head->next;
    delete del;
}

//remove Last
void removeLast(){
        del = tail;
        cur = head;
        while( cur->next != tail){
            cur = cur->next;
        } 
        tail = cur;
        tail->next = NULL;
        delete del;
    }

// REMOVE MIDDLE
void removeMiddle(int posisi){
        if( posisi < 1 || posisi > countSingleLinkedList () ){
            cout << "Posisi diluar jangkauan " << endl;
        }else if( posisi== 1){
            cout << "Posisi bukan tengah" << endl;
        }else{
        int nomor = 1;
        cur = head;
        while( nomor <= posisi ){
            if (nomor == posisi - 1){
                before = cur;
        }
        if( nomor == posisi ){
            del = cur;
        }
        cur = cur->next;
        nomor++; 
    }
    before->next = cur;
    delete del;
    }
}

//ubah awal single linked list
void changeFirst(string judul, string pengarang, int tB){
  head->judul = judul;
  head->pengarang = pengarang;
  head->tahunTerbit = tB;
}

//ubah akhir single linked list
void changeLast(string judul, string pengarang, int tB){
  tail->judul = judul;
  tail->pengarang = pengarang;
  tail->tahunTerbit = tB;
}

//ubah tengah single linked list
void changeMiddle(string judul, string pengarang, int tB, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList () ){
            cout << "Posisi diluar jangkauan " << endl;
        }else if( posisi== 1 || posisi == countSingleLinkedList ()){
            cout << "Posisi bukan tengah" << endl;
        }else{
            cur = head;
            int nomor = 1;
            while( nomor < posisi ){
                cur = cur->next;
                nomor++;
            }
            cur->judul = judul;
            cur->pengarang = pengarang;
            cur->tahunTerbit = tB;
    }
} 

// print single linked list
void printSingleLinkedList(){
    cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
    cur = head;
    while (cur!=NULL){
            cout << "Judul Buku : " << cur->judul << endl;
            cout << "Pengarang Buku : " << cur->pengarang << endl;
            cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

            cur = cur->next;
        }    
}



int main(){

     createSingleLinkedList("Kata", "Geez & Aan", 2018);
     printSingleLinkedList();
     cout << "\n\n" << endl;

     addFirst("Dia Adalah Kakakku", "Tere Liye", 2009);
     printSingleLinkedList();
     cout << "\n\n" << endl;
     
     addLast("Dia cucu kecilku", "Kakek kuat", 2019);
     printSingleLinkedList();
     cout << "\n\n" << endl;

     removeFirst();
     printSingleLinkedList();
     cout << "\n\n" << endl;

     addLast("Dia simpananku", "Kakek muscular", 2119);
     printSingleLinkedList();
     cout << "\n\n" << endl;

     removeLast();
     printSingleLinkedList();
     cout << "\n\n" << endl;

     changeFirst("berhenti onani", "fadhil", 2018);
     printSingleLinkedList();
     cout << "\n\n" << endl;

     addMiddle("GENDURUO AIR PAYAW", "INCAN", 2011, 2);
     printSingleLinkedList();
     cout << "\n\n" << endl;
    
     addMiddle("sibuta agama", "wanchan", 2007, 2);
     printSingleLinkedList();
     cout << "\n\n" << endl;

     removeMiddle(3);
     printSingleLinkedList();
     cout << "\n\n" << endl;

     changeMiddle("berhenti disini", "fadlan", 2012, 2);
     printSingleLinkedList();
     cout << "\n\n" << endl;


}