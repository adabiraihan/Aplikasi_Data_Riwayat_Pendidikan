#include "datapeddobel.h"
#include <iostream>


using namespace std;
void createlist(Listc &L) {
    firstchi(L) = NULL;
    last(L) = firstchi(L);
}

address_child alokasi(string jenjang){
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

void deletefirstC(Listc &L,address_child &P){
    if(firstchi(L) != NULL && last(L) != NULL){
        P = firstchi(L);
        if(firstchi(L) == last(L)){
            firstchi(L) = NULL;
            last(L) = NULL;
        }else{
            firstchi(L) = next(P);
            prev(next(P)) = NULL;
            next(P) = NULL;
        }
    }
}

void deletelastC(Listc &L,address_child &P){
    P = last(L);
    last(L) = prev(P);
    prev(P) = NULL;
}

void deleteafterC(Listc &L,address_child &P,address_child prec){
    P = next(prec);
    next(prec) = next(P);
    prev(next(prec)) = prec;
    next(P) = NULL;
    prev(P) = NULL;
}

/*void deleteC(Listc &L,address_child &P){
    address_child prec;
    if(firstchi(L) == NULL){
        cout<<"TIDAK ADA LIST";
    }
    else if(next(P) == NULL){
            deletelastC(L,P);
        }
    else{
        while(next(prec) != P){
            prec = next(prec);
        }
        deleteafterC(L,P,prec);
    }
}
*/

void deleteC(Listc &L, address_child &P, string x){
    P = caripendidikan(L,x);
    if(firstchi(L)==NULL){
        cout<< x <<" Tidak Ditemukan"<<endl;
    }
    else if(firstchi(L) == last(L)){
        P = firstchi(L);
        firstchi(L) = NULL;
        last(L) = NULL;
    }
    else{
        if(P == NULL){
            cout<< x <<" Tidak Ditemukan"<<endl;
        }else{
            if(P == firstchi(L)){
                deletefirstC(L,P);
            }else if(P == last(L)){
                deletelastC(L,P);
            }else{
                address_child prec = prev(P);
                deleteafterC(L,prec,P);
            }
        }
    }
}

/*void findC(Listc &L,string x){
    address_child Q = firstchi(L);
    while(Q != NULL){
        if(jenjang(Q) == x){
            deleteC(L,Q,x);
        }
    Q = next(Q);
    }
}
*/
