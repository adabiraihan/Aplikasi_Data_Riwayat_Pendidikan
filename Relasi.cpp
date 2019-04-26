#include "dataped.h"
#include "datapeddobel.h"
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
                    cout << jenjang(child(r)) <<", "<<endl;
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
                cout << jenjang(child(r)) <<", "<<endl;
            r = next(r);
        }
    } else
        cout <<"Tidak Ada Data" << endl;
}

void deletefirstR(Listr &L,address_relasi &P){
    if(firstrel(L) != NULL){
        P = firstrel(L);
        firstrel(L) = next(P);
        next(P) = NULL;
    }
    else{
        cout<<"LIST KOSONG";
    }
}

void deletelastR(Listr &L,address_relasi &P){
    if(firstrel(L) != NULL){
        P = firstrel(L);
        if(next(firstrel(L)) ==  NULL){
           deletefirstR(L,P);
        }
        else{
            while(next(P) != last(L)){
                P = next(P);
            }
            address_relasi Q = P;
            P = next(P);
            next(Q) = NULL;
        }
    }
}

void deleteafterR(Listr &L,address_relasi &P,address_relasi prec){
    P = next(prec);
    next(prec) = next(P);
    next(P) = NULL;
}

void deleteR(Listr &L,address_relasi &P){
    address_relasi prec;
    if(firstrel(L) == NULL){
        cout<<"TIDAK ADA LIST";
    }
    else if(next(P) == NULL){
            deletelastR(L,P);
        }
    else{
        while(next(prec) != P){
            prec = next(prec);
        }
        deleteafterR(L,P,prec);
    }
}

void findR(Listr &L,string &x){
    address_relasi Q = firstrel(L);
    while(Q != NULL){
        if(Nama(parent(Q)) == x){
            deleteR(L,Q);
        }
    Q = next(Q);
    }
}

int findmany(Listr L,string x){
    address_relasi P = firstrel(L);
    int temp = 0;
    while(P != NULL){
        if(Nama(parent(P)) == x){
            temp++;
        }
        P = next(P);
    }
    return temp;
}
