#ifndef DATAPEDDOBEL_H_INCLUDED
#define DATAPEDDOBEL_H_INCLUDED
#include <iostream>
#include <cstdlib>

#define next(P) (P)->next
#define prev(P) (P)->prev
#define jenjang(P) (P)->jenjang
#define child(P) (P)->child
#define firstchi(L) L.firstchi
#define last(L) L.last

using namespace std;

typedef struct elmlistc *address_child;

struct elmlistc{
    string jenjang;
    address_child next;
    address_child prev;
};

struct Listc {
    address_child firstchi;
    address_child last;
};

void createlist(Listc &L);
address_child alokasi(string jenjang);
void dealokasi(address_child &p);
void insertlast(Listc &L,address_child p);
void insertfirst(Listc &L,address_child p);
void insertafter(Listc &L,address_child prec,address_child p);
void inserterurut(Listc &L,address_child p);
void printinfo(Listc L);
address_child caripendidikan(Listc L,string x);
void deletefirstC(Listc &L,address_child &P);
void deletelastC(Listc &L,address_child &P);
void deletelastC(Listc &L,address_child &P);
void deleteR(Listc &L,address_child &P);
void findC(Listc &L,string x);

#endif // DATAPEDDOBEL_H_INCLUDED
