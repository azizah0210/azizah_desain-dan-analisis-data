#include <iostream>
using namespace std;

class silsilah {
protected:
    string orangtua = "Albert Wijaya dan Jenny Lin";
    string anakanak = "Agatha Wijaya dan Jonathan Widjaja";

public:
    string cekSilsilah() {
        // Mengubah teks statis menjadi teks yang mengekstrak nama orangtua dari variabel yang sudah ada
        return "Ayah bernama " + orangtua.substr(0, orangtua.find(" ")) +
               " dan Ibu bernama " + orangtua.substr(orangtua.find(" ") + 4);
    }
};

class cucu : public silsilah {
protected:
    string cucu = "Wilbert Tan dan Rayanza Wijaya";

public:
    string cekAnak() {
        // Mengubah teks statis menjadi teks yang mengekstrak nama anak-anak dari variabel yang sudah ada
        return "Anak pertama keluarga Wijaya adalah " + anakanak.substr(0, anakanak.find(" ")) +
               " dan anak kedua dari keluarga Wijaya adalah " + anakanak.substr(anakanak.find(" ") + 4);
    }
};

class anak : public cucu {
public:
    string lihatSilsilah() {
        return "Silsilah Keluarga Wijaya";
    }

    string cekCucu() {
        // Mengubah teks statis menjadi teks yang mengekstrak nama cucu dari variabel yang sudah ada
        return "Cucu pertama keluarga Wijaya adalah " + cucu.substr(0, cucu.find(" ")) +
               " dan cucu kedua dari keluarga Wijaya adalah " + cucu.substr(cucu.find(" ") + 4);
    }
};

int main() {
    anak keluarga;
    cout << keluarga.lihatSilsilah() << endl;
    cout << keluarga.cekSilsilah() << endl;
    cout << keluarga.cekAnak() << endl;
    cout << keluarga.cekCucu() << endl;

    return 0;
}
