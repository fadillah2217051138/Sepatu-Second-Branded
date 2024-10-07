#include <iostream>
#include <cmath> 
using namespace std;

struct shoe{
    string name;
    int price;
    int stock;
}

void displayShoes(Shoe, Shoes[],int size){
    cout << "\n--- Daftar Sepatu dan Stok ---" << endl;
    cout << setw(5) << left << "No" << setw(20) << left << "Nama Sepatu" 
         << setw(10) << left << "Harga" << setw(10) << left << "Stok" << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(5) << left << i + 1 << setw(20) << left << shoes[i].name 
             << "Rp " << setw(10) << left << shoes[i].price 
             << setw(10) << left << shoes[i].stock << endl;
    }
    cout << "0. Selesai dan Hitung Total" << endl;    
}

void displayReceipt(Shoe shoes[], int itemIndex[], int quantity[], int itemCount) {
    int subtotal = 0;
    const double TAX_RATE = 0.10;  // Pajak 10%
    int discount = 0;

    cout << "\n--- Struk Pembelian ---" << endl;
    cout << setw(20) << left << "Nama Sepatu" << setw(10) << left << "Jumlah" 
         << setw(10) << left << "Harga" << setw(10) << left << "Total" << endl;

