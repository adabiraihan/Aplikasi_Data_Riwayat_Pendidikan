#include "datapedcirc.h"
#include <iostream>


using namespace std;

void createlist(Listp &L) {
    firstpar(L) = NULL;
    last(L) = firstpar(L);
}

address_parent alokasi(string Nama,string TTL,string HP) {
    address_parent p = new elmlistp;
    Nama(p) = Nama;
    TTL(p) = TTL;
    HP(p) = HP;
    next(p) = NULL;
    return p;
}

void dealokasi(address_parent &p) {
    delete p;
}

void insertfirst(Listp &L, address_parent p) {
    if(firstpar(L) == NULL) {
        firstpar(L) = p;
        last(L) = p;
        next(last(L)) = firstpar(L);
    }
    else {
        next(p) = firstpar(L);
        firstpar(L) = p;
        next(last(L)) = firstpar(L);
    }
}

void printinfo(Listp L) {
    address_parent p = firstpar(L);
    while(p != last(L)) {
        cout <<"NAMA :  "<<Nama(p)<<endl;
        cout <<"Tempat Tanggal Lahir :  "<<TTL(p)<<endl;
        cout <<"NO HP :  "<<HP(p)<<endl;
        cout<<endl;
        p = next(p);
    }
        cout <<"NAMA :  "<<Nama(p)<<endl;
        cout <<"Tempat Tanggal Lahir :  "<<TTL(p)<<endl;
        cout<<"NO HP :  "<<HP(p)<<endl;
    cout << endl;
}

address_parent carinama(Listp L,string x){

    address_parent P = firstpar(L);
    while((info(P).Nama != x) && (next(P) != firstpar(L))){
        P = next(P);
    }
    if(info(P).Nama == x){
        return P;
    }
    else{
        return NULL;
    }
}

void deletefirstP(Listp &L,address_parent P){
    address_parent Q = firstpar(L);
    if(firstpar(L) = last(L)){
        P = firstpar(L);
        firstpar(L) = NULL;
        last(L) = NULL;
    }
    else{
        while(next(Q) != firstpar(L)){
            Q = next(Q);
        }
        Q = next(Q);
        P = firstpar(L);
        firstpar(L) = next(P);
        next(Q) = firstpar(L);
    }
}

void deletelastP(Listp &L,address_parent P){
    address_parent Q;
    P = firstpar(L);
    while(next(P) != firstpar(L)){
        Q = P;
        P = next(P);
    }
    next(Q) = firstpar(L);
    next(P) = NULL;
    last(L) = Q;
}

void deleteafterP(Listp &L,address_parent &P,address_parent prec){
    P = next(prec);
    next(prec) = next(P);
    next(P) = NULL;
}

void deleteP(Listp &L,address_parent &P){
    address_parent prec;
    if(firstpar(L) == NULL){
        cout<<"TIDAK ADA LIST";
    }
    else if(firstpar(L) == last(L)){
            P = firstpar(L);
            firstpar(L) = NULL;
            last(L) = NULL;
        }
    else if(next(P) == NULL){
        deletelastP(L,P);
    }
    else{
        while(next(prec) != P){
            prec = next(prec);
        }
        deleteafterP(L,P,prec);
    }
}

void findP(Listp &L,string x){
    address_parent P = firstpar(L);
    while(P != NULL){
        if(Nama(P) == x){
            deleteP(L,P);
        }
    P = next(P);
    }
}
