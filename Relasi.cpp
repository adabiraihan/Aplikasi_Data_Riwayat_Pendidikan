#include "dataped.h"
#include <iostream>

using namespace std;

void createlist(Listr &L) {
    firstrel(L) = NULL;
    last(L) = firstrel(L);
}

address_relasi alokasi(address_child c,address_parent e) {
    address_relasi p = new elmlistr;
    parent(p) = e;
    child(p) = c;
    next(p) = NULL;
    return p;
}

void dealokasi(address_relasi &p) {
    delete p;
}

void insertlast(Listr &L, address_relasi p) {
    if(firstrel(L) == NULL){
        firstrel(L) = p;
        last(L) = p;
    }
    else {
        next(last(L)) = p;
        last(L) = p;
    }
}

void carirelasipendidikan(Listr L, string x){
    address_relasi q = firstrel(L);
    int i = 1;
    while (q != NULL){
        if(jenjang(child(q)) == x){
            cout << i << ". " <<  Nama(parent(q)) << endl;
        }
        i++;
        q = next(q);
    }
}

void carirelasinama(Listr L,string x){
    address_relasi q = firstrel(L);
    int ii = 1;
    while(q != NULL){
        if(Nama(parent(q)) == x){
            cout << ii << ". " <<  jenjang(child(q)) << endl;
        }
        ii++;
        q = next(q);
    }
}

void printall(Listr L,Listp Lp){
    address_parent P = firstpar(Lp);
    address_relasi r;
    if(P != NULL){
        while(next(P)!=firstpar(Lp)){
            cout << "Nama    : " << Nama(P) << endl;
            cout << "TTL     : " << TTL(P) << endl;
            cout << "HP      : " << HP(P) << endl;
            cout << "Jenjang : ";
            r = firstrel(L);
            while(r != NULL){
                if(Nama(parent(r)) == Nama(P)){
                    cout << jenjang(child(r)) <<", ";
                }
                r = next(r);
            }
            cout << endl << endl;
            P = next(P);
        }

        cout << "Nama    : " << Nama(P) << endl;
        cout << "TTL     : " << TTL(P) << endl;
        cout << "HP      : " << HP(P) << endl;
        cout << "Jenjang : ";
        r = firstrel(L);
        while(r != NULL){
            if(Nama(parent(r)) == Nama(P))
                cout << jenjang(child(r)) <<", ";
            r = next(r);
        }
    } else
        cout <<"Tidak Ada Data" << endl;

}
