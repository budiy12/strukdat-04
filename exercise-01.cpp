/**
 * Author       : Asep Budiyana Muharam
 * NPM          : 140810180029
 * Deskripsi    : Daftar Data Pegawai
 * Tahun        : 2019
**/
#include <iostream>
#include <conio.h>
using namespace std;

struct Elemtlist{
    char nama[21];
    string bidang;
    int gaji;
    Elemtlist* next;
};
typedef Elemtlist* pointer;
typedef pointer List;

void createList(List& First){
    First=NULL;
}

void createElemt(pointer& p){
    cout<<"INPUT=>\n";
    p = new Elemtlist;
    cin.ignore();
    cout<<"Nama     : ";cin.getline(p->nama,sizeof(p->nama));
    cout<<"Bidang   : ";cin>>p->bidang;
    cout<<"Gaji     : ";cin>>p->gaji;
    cout<<endl;
    p->next=NULL;
}

void traversal(List First){
    pointer pB;
    cout<<"\tDAFTAR PEGAWAI\n";
    cout<<"(NO  NAMA  BIDANG  GAJI  )\n\n";
    if (First==NULL){
        cout<<"\t*LIST KOSONG*\n";
    }
    else{
        pB=First;
        int i=1;
        while(pB!=NULL){
            cout<<i<<" "<<pB->nama<<" "<<pB->bidang<<" "<<pB->gaji<<endl;
            pB=pB->next;
            i++;
        }
    }
}

void insertFirst(List& First,pointer pBaru){
    if (First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast(List& First,pointer pBaru){
    pointer last;
    if (First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
}

void deleteFirst(List& First,pointer pHapus){
    if (First==NULL){
        pHapus=NULL;
        cout<<"**List Kosong, Tidak ada yang dihapus**\n\n";
    }
    else if (First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast(List& First,pointer pHapus){
    pointer last,pre;
       if (First==NULL){
        pHapus=NULL;
        cout<<"**List Kosong, Tidak ada yang dihapus**\n\n";
    }
    else if (First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        last=First;
        pre=NULL;
        while(last->next!=NULL){
            pre=last;
            last=last->next;
        }
        pHapus=last;
        pre->next=NULL;
    }
}

void menu(List& First,pointer p){
    int pilih;
    do{
        system("cls");
        traversal(First);
        cout<<"\nPilihan Edit Data:\n";
        cout<<"1. Insert First\n";
        cout<<"2. Insert Last\n";
        cout<<"3. Delete First\n";
        cout<<"4. Delete Last\n";
        cout<<"5. Traversal\n";
        cout<<"6. Exit\n";
        cout<<"Pilih (1-6): ";cin>>pilih;
        switch (pilih)
        {
            case 1:
            createElemt(p);
            insertFirst(First,p);
            break;

            case 2:
            createElemt(p);
            insertLast(First,p);
            break;

            case 3:
            deleteFirst(First,p);
            break;

            case 4:
            deleteLast(First,p);
            break;
            
            case 5:
            traversal(First);
            break;

            case 6:
            break;

            default:
            cout<<"*INPUT SALAH*\n";
            break;
        }
    }while(pilih!=6);
}

int main(){
    pointer p;
    List pegawai;
    createList(pegawai);
    menu(pegawai,p);
}
