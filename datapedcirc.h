#ifndef DATAPEDCIRC_H_INCLUDED
#define DATAPEDCIRC_H_INCLUDED
#include <iostream>
#define  Nama(P) info(P).Nama
#define TTL(P) info(P).TTL
#define HP(P) info(P).HP
#define firstpar(L) L.firstpar
#define last(L) L.last
#define info(P) (P)->info
#define next(P) (P)->next
using namespace std;

struct infotype_parent{
    string Nama;
    string TTL;
    string HP;
};

typedef struct elmlistp *address_parent;

struct elmlistp{
    infotype_parent info;
    address_parent next;
    address_parent last;
};

struct Listp{
    address_parent firstpar;
    address_parent last;
};

void createlist(Listp &L);
address_parent alokasi(string Nama,string TTL,string HP);
void dealokasi(address_parent &p);
void insertfirst(Listp &L, address_parent p);
void printinfo(Listp L);
address_parent carinama(Listp L,string x);
void deletefirstP(Listp &L,address_parent P);
void deletelastP(Listp &L,address_parent P);
void deleteafterP(Listp &L,address_parent &P,address_parent prec);
void deleteP(Listp &L,address_parent &P,string x);
void findP(Listp &L,string x);

#endif // DATAPEDCIRC_H_INCLUDED
