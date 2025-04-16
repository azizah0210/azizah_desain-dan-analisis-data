#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
	public :
	 	mahasiswa (string nama, int umur)
	 		: nama_(nama), umur_(umur){
	 			
			 }
			~mahasiswa () {
				cout << "==Contoh Destructor Mahasiswa==" << endl;
			}
			
			void tampilkanbiodata() {
				cout << "Nama : " << nama_ << endl;
				cout << "Umur : " << umur_ << endl;
			}
			
		private :
			string nama_;
			int umur_;
};

int main ()
{
	{
	mahasiswa mhs("Katarina", 20);
	mhs.tampilkanbiodata();
	}
	
}
