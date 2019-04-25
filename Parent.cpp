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
