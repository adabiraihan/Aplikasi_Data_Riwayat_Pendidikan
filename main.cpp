#include <iostream>
#include "datapeddobel.h"
#include "datapedcirc.h"
#include "dataped.h"

using namespace std;

int main()
{
    Listp Lp;
    Listr Lr;
    Listc Lc;
    address_parent p,cn,e;
    address_child cj,c,prec;
    address_relasi r,cr;

    int menu;
    string datapen;
    string x;
    string car;
    string jenjang;
    string Nama;
    string TTL;
    string HP;
    createlist(Lc);
    createlist(Lp);
    createlist(Lr);

    cout<<"DATA RIWAYAT PENDIDIKAN"<<endl;
    cout<<"1. Tambah Data Orang"<<endl;
    cout<<"2. Tambah Data Pendidikan"<<endl;
    cout<<"3. Penggabungan Relasi"<<endl;
    cout<<"4. Hapus Data Seseorang"<<endl;
    cout<<"5. Hapus Data Pendidikan"<<endl;
    cout<<"6. Menampilkan Data"<<endl;
    cout<<"7. Tampilkan Data Pendidikan Orang Tertentu"<<endl;
    cout<<"8. Tampilkan Data Orang Sesuai Pendidikan"<<endl;
    cout<<"9. Tampilkan Pendidikan Terbanyak Hingga Terkecil"<<endl;

    while(menu != 0){
    cout<<"PILIHAN : ";
    cin>>menu;
    cout<<endl;
    switch (menu){
    case 1 :
        cout<<"Nama : ";
        cin.ignore();
        getline(cin,Nama);
        cout<<"Tempat Tanggal Lahir : ";
        cin.ignore();
        getline(cin,TTL);
        cout<<"HP : ";
        cin>>HP;
        p = alokasi(Nama,TTL,HP);
        insertfirst(Lp,p);
        break;

    case 2 :
        cout<<"Pendidikan : ";
        cin>>jenjang;
        c = alokasi(jenjang);
        inserterurut(Lc,c);
        break;

    case 3 :
        cout<<"Nama : ";
        cin>>Nama;
        cn = carinama(Lp,Nama);
        cout<<"Pendidikan : ";
        cin>>jenjang;
        cj = caripendidikan(Lc,jenjang);
        if((cn != NULL) && (cj != NULL)){
            cr = alokasi(cj,cn);
            insertlast(Lr,cr);
            cout<<"TELAH DIGABUNG"<<endl;
        }
        else{
            cout<<"TAK ADEU"<<endl;
        }
        break;

    case 6 :
        printall(Lr,Lp);
        break;

    case 7 :
        cout<<"DATA RIWAYAT PENDIDIKAN ORANG ";
        cin>>x;
        carirelasinama(Lr,x);
        break;

    case 8 :
        cout<<"DATA PENDIDIKAN ORANG";
        cin>>x;
        carirelasipendidikan(Lr,x);
        break;

    }


}
return 0;
}
