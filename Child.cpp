#include "datapeddobel.h"
#include <iostream>


using namespace std;
void createlist(Listc &L) {
    firstchi(L) = NULL;
    last(L) = firstchi(L);
}

address_child alokasi(string jenjang) {
    address_child p = new elmlistc;
    jenjang(p) = jenjang;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}

void dealokasi(address_child &p) {
    delete p;
}

void insertlast(Listc &L, address_child p) {
    if(firstchi(L) == NULL){
        firstchi(L) = p;
        last(L) = p;
    }
    else {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

void insertfirst(Listc &L, address_child p) {
    if(firstchi(L) == NULL) {
        firstchi(L) = p;
        last(L) = p;
    }
    else {
        next(p) = firstchi(L);
        prev(firstchi(L)) = p;
        firstchi(L) = p;
    }
}

void insertafter(Listc &L, address_child prec,address_child p){

    prev(next(prec)) = p;
    next(p) = next(prec);
    prev(p) = prec;
    next(prec) = p;
    }

void inserterurut(Listc &L, address_child p){
    if(firstchi(L)==NULL){
        last(L) = p;
        firstchi(L) = p;
    }else{
        address_child q = firstchi(L);
        while(next(q)!= NULL && jenjang(next(q))<= jenjang(p)){
            q = next(q);
        }
        if(jenjang(p)<= jenjang(firstchi(L))){
            insertfirst(L,p);
        }else if(jenjang(p)>jenjang(last(L))){
            insertlast(L,p);
        }else{
            insertafter(L,q,p);
        }
    }
}

    void printinfo(Listc L) {
    address_child P = firstchi(L);
    while(P != last(L)) {
        cout <<jenjang(P)<<" - ";
        P = next(P);
    }
    cout<<jenjang(P);
    cout<<endl;
}

address_child caripendidikan(Listc L,string x){
    address_child P = firstchi(L);
    while((jenjang(P) != x) && (P != last(L))){
        P = next(P);
    }
    if(jenjang(P) == x){
        return P;
    }
    else{
        return NULL;
    }
}
