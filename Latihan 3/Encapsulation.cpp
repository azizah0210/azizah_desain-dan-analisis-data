#include <iostream>
#include <string>
using namespace std;

class Hewan {
	private :
		string nama;
		string spesies;
		
	public :
		void setNama(string n) {
			nama = n;
		}
		
		void setSpesies(string n) {
			spesies = n;
		}
		
		string getNama() {
			return nama;
		}
		
		string getSpesies() {
			return spesies;
		}
		
};

int main () 
{
	Hewan hewan;
	hewan.setNama("Kucing");
	hewan.setSpesies("Felis Catus");
	
	cout << "Nama : " << hewan.getNama() << endl;
	cout << "Spesies : " << hewan.getSpesies() << endl;
	
	hewan.setNama("Anjing");
	cout << "Nama : " << hewan.getNama() << endl;
	
	return 0;
	
}

