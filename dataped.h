#ifndef DATAPED_H_INCLUDED
#define DATAPED_H_INCLUDED
#include "datapedcirc.h"
#include "datapeddobel.h"
#include <iostream>

#define parent(P) (P) -> parent
#define child(P) (P) -> child
#define firstrel(L) L.firstrel
#define last(L) L.last
#define next(P) (P)->next

using namespace std;

typedef struct elmlistr *address_relasi;


struct elmlistr{
    address_relasi next;
    address_parent parent;
    address_child child;
};

struct Listr{
    address_relasi firstrel;
    address_relasi last;
};

void createlist(Listr &L);
address_relasi alokasi(address_child c,address_parent e);
void dealokasi(address_relasi &p);
void insertlast(Listr &L,address_relasi P);
void carirelasinama(Listr L,string x);
void carirelasipendidikan(Listr L, string x);
void printall(Listr L,Listp Lp);
/*void deletefirstR(Listr &L,address_relasi &P);
void deletelastR(Listr &L,address_relasi &P);
void deleteafterR(Listr &L,address_relasi &P,address_relasi prec);
void deleteR(Listr &L,address_relasi &P);
void findR(Listr &L, string x);*/
int findmany(Listr L,string x);
void deleterelasi(Listr &L,address_relasi R);
void deleterelC(Listr &L, string x);
void deleterelP(Listr &L, string x);

#endif // DATAPED_H_INCLUDED
