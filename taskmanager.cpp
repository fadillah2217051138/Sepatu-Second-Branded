#include <iostream>
#include <iomanip>
using namespace std;

struct Shoe{
    string name;
    int price;
    int stock;
};

void displayShoes(Shoe shoes[],int size){
    cout << "\n-------- Daftar Sepatu dan Stok --------" << endl;
    cout << "\n========================================" << endl;
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

    cout << "\n------------ Struk Pembelian ------------" << endl;
    cout << "\n=========================================" << endl;
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


int main() {
    // Daftar sepatu dengan stok
    const int SHOE_SIZE = 5;
    Shoe shoes[SHOE_SIZE] = {
        {"Nike Air Max", 750000, 10},
        {"Adidas Ultraboost", 850000, 8},
        {"Puma Running", 600000, 5},
        {"Vans Old Skool", 550000, 12},
        {"Converse Chuck Taylor", 500000, 7}
    };

    int itemIndex[SHOE_SIZE]; // Menyimpan indeks sepatu yang dibeli
    int quantity[SHOE_SIZE];  // Menyimpan jumlah pembelian setiap sepatu
    int itemCount = 0;        // Jumlah total item yang dibeli

    while (true) {
        displayShoes(shoes, SHOE_SIZE);
        
        int choice;
        cout << "\nPilih sepatu : ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > SHOE_SIZE) {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            continue;
        }

        int qty;
        cout << "Masukkan jumlah: ";
        cin >> qty;

        int index = choice - 1;

        // Validasi stok
        if (qty > shoes[index].stock) {
            cout << "Maaf, stok tidak mencukupi. Stok tersedia: " << shoes[index].stock << endl;
            continue;
        }

        // Update stok sepatu
        shoes[index].stock -= qty;

        // Simpan indeks dan jumlah sepatu yang dibeli
        itemIndex[itemCount] = index;
        quantity[itemCount] = qty;
        itemCount++;
    }
// Jika ada sepatu yang dibeli, tampilkan struk
    if (itemCount > 0) {
        displayReceipt(shoes, itemIndex, quantity, itemCount);
    } else {
        cout << "Tidak ada sepatu yang dibeli." << endl;
    }

    cout << "\n===================================================" << endl;
    cout << "Terima kasih telah berbelanja di toko sepatu kami!" << endl;
    cout << "\n===================================================" << endl;
    return 0;
}



