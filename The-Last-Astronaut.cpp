#include <iostream>
using namespace std;
 
struct Node {
    int nomor;
    Node* next;
};
 
int main() {
    int n, k;
 
    cout << "astronotnya mau berapa? ";
    cin >> n;
    cout << "K nya berapa? ";
    cin >> k;
 
    if (n <= 0) {
        cout << "gimana sih aikamu, masa astronotnya <0 :v." << endl;
        return 0;
    }

    Node* head = new Node{1, nullptr};
    Node* current = head;
    for (int i = 2; i <= n; i++) {
        Node* baru = new Node{i, nullptr};
        current->next = baru;
        current = baru;
    }
    current->next = head; 

    Node* prev = current;
    current = head; 
 
    int sisa = n;
 
    cout << "\nurutan nomor astronot yang out:\n";
 
    while (sisa > 1) {
        for (int langkah = 1; langkah < k; langkah++) {
            prev = current;
            current = current->next;
        }
 
        int nomorEliminasi = current->nomor;
        cout << nomorEliminasi << " ";
        Node* dihapus = current;
        prev->next = current->next;
        current = current->next;
        delete dihapus;
 
        sisa--;z
 
        if (nomorEliminasi % 2 == 0) {
            k += 2;
        } else {
            k -= 1;
        }
        if (k < 2) {
            k = 2;
        }
    }
 
    cout << "\n\nlast astronaut standing: " << current->nomor << endl;
 
    delete current;
    return 0;
}