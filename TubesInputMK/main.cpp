#include <iostream>
#include "InputMK.h"

using namespace std;

int main()
{
    int input;
    mll list_mk;
    createList(list_mk);

    input = menu();

    while (input != 0){
        switch(input){
        case 1:
            tambahMK(list_mk);
            input = menu();
            break;
        case 2:
            hapusMK(list_mk);
            input = menu();
            break;
        case 3:
            tambahMhs(list_mk);
            input = menu();
            break;
        case 4:
            hapusMhs(list_mk);
            input = menu();
            break;
        case 5:
            MKtersedia(list_mk);
            input = menu();
            break;
        case 6:
            MK_kelas(list_mk);
            input = menu();
            break;
        case 7:
            seluruhMK(list_mk);
            input = menu();
            break;
        case 8:
            cariNamaMK_kuota(list_mk);
            input = menu();
            break;
        case 9:
            mhs_tertentu(list_mk);
            input = menu();
            break;
        }

    }
    exit(list_mk);


    return 0;
}
