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
for (int i = 0; i < itemCount; i++) {
        int index = itemIndex[i];
        int totalPrice = shoes[index].price * quantity[i];
        subtotal += totalPrice;

        cout << setw(20) << left << shoes[index].name 
             << setw(10) << left << quantity[i] 
             << "Rp " << setw(10) << left << shoes[index].price 
             << "Rp " << totalPrice << endl;
    }

    // Diskon 5% jika subtotal lebih dari Rp 2.000.000
    if (subtotal > 2000000) {
        discount = 0.05 * subtotal;
        cout << "\nDiskon 5%: Rp " << discount << endl;
    }

    // Menghitung total dengan pajak dan diskon
    int totalAfterDiscount = subtotal - discount;
    int tax = TAX_RATE * totalAfterDiscount;
    int total = totalAfterDiscount + tax;

    cout << "\nSubtotal: Rp " << subtotal << endl;
    cout << "Pajak (10%): Rp " << tax << endl;
    cout << "Total Setelah Pajak: Rp " << total << endl;

    int bayar;
    cout << "Masukkan jumlah uang yang dibayarkan: Rp ";
    cin >> bayar;

    if (bayar >= total) {
        int kembalian = bayar - total;
        cout << "Kembalian: Rp " << kembalian << endl;
    } else {
        cout << "Uang tidak cukup!" << endl;
    }
}


