#include "InputMK.h"

void createList(mll &list_mk){
    first(list_mk) = NULL;
    last(list_mk) = NULL;
}

void newElmMk(mk info, adr_mk &P){
    P = new elm_mk;
    next(P) = NULL;
    prev(P) = NULL;
    nextMhs(P) = NULL;
    infoMK(P).namaMK = info.namaMK;
    infoMK(P).kelas = info.kelas;
    infoMK(P).kuotaMax = info.kuotaMax;
    infoMK(P).jumlah = info.jumlah;
    infoMK(P).jenisMhs = info.jenisMhs;
}

void newElmMhs(mhs info, adr_mhs &q){
    q = new elm_mhs;
    next(q) = NULL;
    prev(q) = NULL;
    infoMhs(q).namaMhs = info.namaMhs;
    infoMhs(q).nimMhs = info.nimMhs;
    infoMhs(q).asalKelas = info.asalKelas;
    infoMhs(q).jenisMhs = info.jenisMhs;
}

void insertMK(mll &list_mk, adr_mk P){
    if (first(list_mk) == NULL){
        first(list_mk) = P;
        last(list_mk) = P;
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(last(list_mk)) = P;
        prev(P) = last(list_mk);
        last(list_mk) = P;

    }
}

void insertMhs(mll &list_mk, adr_mk A, adr_mhs B){
    adr_mhs P;

    P = nextMhs(A);
    if (nextMhs(A) == NULL){
        nextMhs(A) = B;
        next(B) = NULL;
        prev(B) = NULL;
    } else{
        while (next(P) != NULL){
            P = next(P);
        }
        next(P) = B;
        prev(B) = P;
    }
}

void deleteFirstMK(mll &list_mk, adr_mk &A){
    A = first(list_mk);

    if (first(list_mk) == last(list_mk)){
        first(list_mk) = NULL;
        last(list_mk) = NULL;
    } else {
        first(list_mk) = next(A);
        prev(first(list_mk)) = NULL;
        next(A) = NULL;
    }
}

void deleteLastMK(mll &list_mk, adr_mk &A){
    adr_mk p;
    p = last(list_mk);
    A = prev(p);
    last(list_mk) = A;
    prev(p) = NULL;
    next(A) = NULL;
}

void deleteAfterMK(mll &list_mk, adr_mk prec, adr_mk &P ){
    P = next(prec);
    next(prec) = next(P);
    prev(next(P)) = prec;
    next(P) = NULL;
    prev(P) = NULL;
}

void deleteFirstMhs(mll &list_mk, adr_mk A, adr_mhs &B){
    B = nextMhs(A);
    nextMhs(A) = next(B);
    prev(next(B)) = NULL;
    next(B) = NULL;

}

void deleteLastMhs(mll &list_mk, adr_mk A, adr_mhs &B){
    adr_mhs p;

    B = nextMhs(A);
    while (next(B) != NULL){
        B = next(B);
    }
    p = prev(B);
    next(p) = NULL;
    prev(B) = NULL;
}

void deleteAfterMhs(mll &list_mk, adr_mk A, adr_mhs prec, adr_mhs &B){
    B = next(prec);
    next(prec) = next(B);
    next(B) = NULL;
}

adr_mk searchMK(mll list_mk, string matakuliah){
    adr_mk p;
    adr_mk q = NULL;
    int found = 1;
    p = first(list_mk);
    while (found == 1 && p != NULL ){
        if (infoMK(p).namaMK == matakuliah){
            q = p;
            found = 0;
        }
        p = next(p);
    }
    return q;
}

int jumlahMhs(mll list_mk,string nim){
    adr_mhs q;
    adr_mk p;
    int jumlah = 0;

    p = first(list_mk);
    while (p != NULL){
        q = nextMhs(p);
        while (q != NULL) {
            if (infoMhs(q).nimMhs == nim){
                jumlah = jumlah + 1;
            }
            q = next(q);
        }
        p = next(p);
    }
    return jumlah;
}

int menu(){
    int input;

    cout << "#========================= MENU ====================================#" << endl;
    cout << "|| "<< "1. Menambah Mata Kuliah Baru" <<"                                    ||" << endl;
    cout << "|| "<< "2. Menghapus Mata Kuliah" <<"                                        ||" << endl;
    cout << "|| "<<"3. Menambah Data Mahasiswa" <<"                                      ||" << endl;
    cout << "|| "<<"4. Menghapus Data Mahasiswa" <<"                                     ||" << endl;
    cout << "|| "<<"5. Menampilkan Data Mata Kuliah yang Tersedia" <<"                   ||" << endl;
    cout << "|| "<<"6. Menampilkan Data Mahasiswa di Mata Kuliah dan Kelas tertentu" <<" ||" << endl;
    cout << "|| "<<"7. Menampilkan seluruh mata kuliah dan data mahasiswa" <<"           ||" << endl;
    cout << "|| "<<"8. Mencari Mata Kuliah dengan kuota masih tersedia" <<"              ||" << endl;
    cout << "|| "<<"9. Mencari Nama Mahasiswa pada Mata Kuliah tertentu" <<"             ||" << endl;
    cout << "|| "<<"0. EXIT" <<"                                                         ||" << endl;
    cout << "#===================================================================#" << endl;
    cout << "Pilih Menu: ";
    cin >> input;
    cout << endl;

    return input;
}

 mk addMK(string namaMK, string kelas, int kuotamax, string jenisMhs){
    mk info;

    info.namaMK = namaMK;
    info.kelas = kelas;
    info.kuotaMax = kuotamax;
    info.jenisMhs = jenisMhs;
    info.jumlah = 0;

    return info;
 }

 mhs addMhs(string namaMhs, string nimMhs, string asalKelas, string jenisMhs){
    mhs info;

    info.namaMhs = namaMhs;
    info.asalKelas = asalKelas;
    info.nimMhs = nimMhs;
    info.jenisMhs = jenisMhs;

    return info;
 }

 void deleteMK(mll &list_mk, adr_mk &P){
    adr_mk q;

    if (P == first(list_mk)){
        deleteFirstMK(list_mk, P);
    } else if (P == last(list_mk)){
        deleteLastMK(list_mk, P);
    } else {
        q = first(list_mk);
        while(next(q) != P){
            q = next(q);
        }
        deleteAfterMK(list_mk,q,P);
    }

 }

 void deleteMhs(mll &list_mk, adr_mk &A, adr_mhs &B){
    adr_mhs p;
    p = nextMhs(A);
    while (next(p) != NULL){
        p = next(p);
    }
    if (B == nextMhs(A)){
        deleteFirstMhs(list_mk,A,B);
    } else if (p == B){
        deleteLastMhs(list_mk,A,B);
    } else{
        p = nextMhs(A);
        while (next(p) != B){
            p = next(p);
        }
        deleteAfterMhs(list_mk,A,p,B);
    }
 }

 adr_mk searchMkKelas(mll list_mk, mk info){
    bool found = false;
    adr_mk A;
    A = first(list_mk);
    if (first(list_mk) != NULL){
        while(!found && A != NULL){
            if (infoMK(A).namaMK == info.namaMK && infoMK(A).kelas == info.kelas){
                found = true;
            } else {
                A = next(A);
            }
        }
    } else {
        cout << "List kosong" << endl;
    }
    return A;
}


void showMK_tertentu(mll list_mk){
    adr_mk A;
    adr_mhs B;
    mk info;
    cout << "Mata Kuliah : ";
    cin >> info.namaMK;
    cout << "Kelas : ";
    cin >> info.kelas;
    A = searchMkKelas(list_mk, info);
    if (A != NULL){
        B = nextMhs(A);
        while (B != NULL){
            cout << "Nama mahasiswa : " << infoMhs(B).namaMhs << endl;
            cout << "NIM mahasiswa  : " << infoMhs(B).nimMhs << endl;
            cout << "Asal kelas     : " << infoMhs(B).asalKelas << endl;
            cout << "Jenis mahasiswa: " << infoMhs(B).jenisMhs << endl;
            cout << endl;
            B = next(B);
        }
    } else {
        cout << "Mata Kuliah tidak ditemukan" << endl;
    }
 }


//Menu1
 void tambahMK(mll &list_mk){
    int N,i;
    string namaMK, kelas, jenisMhs;
    int kuotamax;
    mk info;
    adr_mk A;

    i = 1;
    cout << "Jumlah data yang ingin di Inputkan: ";
    cin >> N;
    cout << endl;
    while (i <= N) {
        cout << "[" << i << "]" << endl;
        cout << "Mata Kuliah: ";
        cin >> namaMK;
        cout << "Kelas: ";
        cin >> kelas;
        cout << "Kuota maksimal: ";
        cin >> kuotamax;
        cout << "Jenis Mahasiswa: ";
        cin >> jenisMhs;
        info = addMK(namaMK, kelas, kuotamax, jenisMhs);
        newElmMk(info,A);
        insertMK(list_mk, A);
        cout << endl;

        i = i + 1;
    }

 }


//Menu2
 void hapusMK(mll &list_mk){
    adr_mk A;
    string matakuliah;


    cout << "Mata kuliah yang dihapus: ";
    cin >> matakuliah;

    A = searchMK(list_mk, matakuliah);
    deleteMK(list_mk,A);
 }

//Menu3
 void tambahMhs(mll &list_mk){
    int N, i;
    adr_mk p;
    adr_mhs q;
    i = 1;
    int jumlah = 1;
    mk infomk;
    string nama, nim, kelas, jenis;
    mhs info;

    cout << "Jumlah Mahasiswa yang akan diinput: ";
    cin >> N;
    cout << endl;
    while (i <= N){
        cout << "[" << i << "]" << endl;
        cout << "Mata kuliah yang dituju: ";
        cin >> infomk.namaMK;
        cout << "Kelas: ";
        cin >> infomk.kelas;
        p = searchMkKelas(list_mk,infomk);
        if (p != NULL){
            if (infoMK(p).jumlah != infoMK(p).kuotaMax){
                cout << "Nama: ";
                cin >> nama;
                cout << "Nim: ";
                cin >> nim;
                jumlah = jumlahMhs(list_mk,nim);
                if (jumlah <= 3){
                    cout << "Kelas: ";
                    cin >> kelas;
                    cout << "Jenis Mahasiswa: ";
                    cin >> jenis;
                    if (infoMK(p).jenisMhs == jenis){
                        info = addMhs(nama,nim,kelas,jenis);
                        newElmMhs(info,q);
                        insertMhs(list_mk,p,q);
                        infoMK(p).jumlah = infoMK(p).jumlah + 1;
                    } else {
                        cout << "Jenis Mahasiswa Tidak Sesuai!" << endl;
                        i = i - 1;
                    }
                } else {
                    cout << "Anda sudah mencapai batas registrasi" << endl;
                    i = i - 1;
                }

            } else {
                cout << "Maaf Kuota Sudah Penuh !" << endl;
                i = i - 1;
            }
        } else {
            cout << "Mata Kuliah belum terdaftar!" << endl;
            i = i - 1;
        }
        i = i + 1;
        cout << endl;
    }
 }

 //Menu4
 void hapusMhs(mll &list_mk){
    adr_mk A;
    adr_mhs B;
    mk info;
    mhs infomhs;

    cout << "Nama Mahasiswa: ";
    cin >> infomhs.namaMhs;
    cout << "NIM: ";
    cin >> infomhs.nimMhs;
    cout << "Mata Kuliah: ";
    cin >> info.namaMK;
    cout << "Kelas: ";
    cin >> info.kelas;

    A = searchMkKelas(list_mk,info);
    B = nextMhs(A);

    while (B != NULL) {
        if (infoMhs(B).nimMhs == infomhs.nimMhs){
            deleteMhs(list_mk,A,B);
            infoMK(A).jumlah = infoMK(A).jumlah - 1;
        }
        B = next(B);
    }


 }

 //Menu5
void MKtersedia(mll &list_mk){
    adr_mk A;
    int i = 1;

    A = first(list_mk);
    while (A != NULL){
        cout << endl;
        cout << "[" << i << "]";
        cout << "Mata Kuliah: " << infoMK(A).namaMK << endl;
        cout << "Kelas: " << infoMK(A).kelas << endl;
        cout << "Kuota Maksimal: " << infoMK(A).kuotaMax << endl;
        cout << "Jenis Mahasiswa: " << infoMK(A).jenisMhs << endl;
        cout << "Jumlah: " << infoMK(A).jumlah << endl;
        cout << endl;
        A = next(A);
        i++;
    }
}

//Menu6
void MK_kelas(mll &list_mk){
    showMK_tertentu(list_mk);
}

//Menu7
void seluruhMK(mll &list_mk){
    adr_mk A;
    adr_mhs B;
    int i = 1;
    int j;
    A = first(list_mk);
    while (A != NULL){
        cout << endl;
        cout << "[" << i << "]" << endl;
        cout << "Mata Kuliah: " << infoMK(A).namaMK << endl;
        cout << "Kelas: " << infoMK(A).kelas << endl;
        cout << "Kuota Maksimal: " << infoMK(A).kuotaMax << endl;
        cout << "Jenis Mahasiswa: " << infoMK(A).jenisMhs << endl;
        cout << "Jumlah: " << infoMK(A).jumlah << endl;
        cout << endl;
        B = nextMhs(A);
        j = 1;
        while (B != NULL){
            cout << "[" << j << "]" << endl;
            cout << "Nama: " << infoMhs(B).namaMhs << endl;
            cout << "NIM: " << infoMhs(B).nimMhs << endl;
            cout << "Kelas: " << infoMhs(B).asalKelas << endl;
            cout << "Jenis Mahasiswa: " << infoMhs(B).jenisMhs << endl;
            cout << endl;
            j = j + 1;
            B = next(B);
        }
        i = i + 1;
        A = next(A);

    }
}

//Menu8
void cariNamaMK_kuota(mll &list_mk){
    adr_mk A;
    string MK;


    cout<<"masukkan MK yang ingin dicari: ";
    cin>>MK;

    A = searchMK(list_mk,MK);

    if (infoMK(A).kuotaMax != infoMK(A).jumlah){
        cout << "Mata Kuliah: " << infoMK(A).namaMK << endl;
        cout << "Kelas: " << infoMK(A).kelas << endl;
        cout << "Kuota Maksimal: " << infoMK(A).kuotaMax << endl;
        cout << "Jenis Mahasiswa: " << infoMK(A).jenisMhs << endl;
        cout << "Jumlah: " << infoMK(A).jumlah << endl;
        cout << endl;
    }else{
        cout<<"Mata Kuliah tersebut sudah mencapai kuota Maksimal"<<endl;
    }
}

//Menu9
void mhs_tertentu(mll &list_mk){
    adr_mk A;
    adr_mhs B;
    mk info;
    mhs infoM;
    bool found = false;
    cout << "Masukan Mata Kuliah : ";
    cin >> info.namaMK;
    cout << "Masukan nama mahasiswa yang ingin dicari : ";
    cin >> infoM.namaMhs;
    A = searchMK(list_mk, info.namaMK);
    B = nextMhs(A);
    while ( !found && B != NULL){
        if (infoMhs(B).namaMhs == infoM.namaMhs){
            found = true;
            cout << "Mahasiswa ditemukan : " << infoM.namaMhs << endl;
        }else {
            cout << "Mahasiswa tidak ditemukan" << endl;
        }
        B = next(B);
    }
}

void exit(mll &list_mk){
    adr_mk A;

    A = first(list_mk);
    while (A != NULL) {
        if (nextMhs(A) == NULL){
            deleteMK(list_mk,A);
        }
        A = next(A);
    }
    cout<<"Data Semester Bayangan :"<<endl;
    seluruhMK(list_mk);
}
