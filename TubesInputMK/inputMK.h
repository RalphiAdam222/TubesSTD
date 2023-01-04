#ifndef INPUTMK_H_INCLUDED
#define INPUTMK_H_INCLUDED

#include <iostream>
using namespace std;

#define infoMK(P) (P)->infoMK
#define infoMhs(P) (P)->infoMhs
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextMhs(A) (A)->nextMhs
#define first(mll) ((mll).first)
#define last(mll) ((mll).last)

typedef struct elm_mk *adr_mk;
typedef struct elm_mhs *adr_mhs;

struct mk {
    string namaMK;
    string kelas;
    int kuotaMax;
    int jumlah;
    string jenisMhs;
};

struct elm_mk{
    mk infoMK;
    adr_mk prev;
    adr_mk next;
    adr_mhs nextMhs;
};

struct mhs {
    string namaMhs;
    string nimMhs;
    string asalKelas;
    string jenisMhs;
};

struct elm_mhs{
    mhs infoMhs;
    adr_mhs next;
    adr_mhs prev;
};

struct mll{
    adr_mk first;
    adr_mk last;
};

void createList(mll &list_mk);
void newElmMk(mk info, adr_mk &P);
void newElmMhs(mhs info, adr_mhs &q);
void insertMK(mll &list_mk, adr_mk P);
void insertMhs(mll &list_mk, adr_mk A, adr_mhs B);
void deleteFirstMK(mll &list_mk, adr_mk &A);
void deleteLastMK(mll &list_mk, adr_mk &A);
void deleteAfterMK(mll &list_mk, adr_mk prec, adr_mk &P );
void deleteFirstMhs(mll &list_mk, adr_mk A, adr_mhs &B);
void deleteLastMhs(mll &list_mk, adr_mk A, adr_mhs &B);
void deleteAfterMhs(mll &list_mk, adr_mk A, adr_mhs prec, adr_mhs &B);
adr_mk searchMK(mll list_mk, string matakuliah);
int menu();
mk addMK(string namaMK, string kelas, int kuotamax, string jenisMhs);
void showMKTertentu(mll list_mk);
adr_mk searchMk_Kelas(mll list_mk, mk info);
void deleteMK(mll &list_mk, adr_mk &A);
void deleteMhs(mll &list_mk, adr_mk &A, adr_mhs &B);
void showDataMK(mll list_mk);
int jumlahMhs(mll list_mk,string nim);
mhs addMhs(string namaMhs, string nimMhs, string asalKelas, string jenisMhs);

void tambahMK(mll &list_mk);
void hapusMK(mll &list_mk);
void tambahMhs(mll &list_mk);
void hapusMhs(mll &list_mk);
void MKtersedia(mll &list_mk);
void MK_kelas(mll &list_mk);
void seluruhMK(mll &list_mk);
void cariNamaMK_kuota(mll &list_mk);
void mhs_tertentu(mll &list_mk);
void exit(mll &list_mk);

#endif // INPUTMK_H_INCLUDED
