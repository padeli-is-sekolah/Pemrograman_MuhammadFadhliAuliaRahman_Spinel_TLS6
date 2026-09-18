#include <iostream>
using namespace std;
 
int hurufKeNilai(char c) {
    return (c - 'A') + 1;
}
 
char nilaiKeHuruf(int nilai) {
    int nilaiTerwrap = (nilai - 1) % 26 + 1;
    return 'A' + (nilaiTerwrap - 1);
}
 
int main() {
    const int MAX_PANJANG = 1000;
    char pesan[MAX_PANJANG];
 
    cout << "Pesan huruf kaptal, no spasi : ";
    cin >> pesan;
 
    int panjang = 0;
    while (pesan[panjang] != '\0') {
        panjang++;
    }
 
    char hasil[MAX_PANJANG];
 
    hasil[0] = pesan[0];
 
    for (int i = 1; i < panjang; i++) {
        int nilaiSekarang   = hurufKeNilai(pesan[i]);
        int nilaiSebelumnya = hurufKeNilai(pesan[i - 1]);
        int nilaiBaru       = nilaiSekarang + nilaiSebelumnya;
        hasil[i] = nilaiKeHuruf(nilaiBaru);
    }
    hasil[panjang] = '\0';
 
    cout << "\nPesan yang dienkripsi: ";
    for (int i = 0; i < panjang; i++) {
        cout << hasil[i];
    }
    cout << endl;
 
    return 0;
}