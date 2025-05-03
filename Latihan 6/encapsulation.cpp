#include <iostream>
 using namespace std;
 
 class karyawan {
 	private:
 		int gaji;
 	
 	public:
 		void setgaji(int s) {
 			gaji = s;
 		} 
 		int getgaji() {
 			return gaji;
 		}
 };
 
 int main () {
 	karyawan obj;
 	
 	obj.setgaji(5000);
 	cout << obj.getgaji();
 	
 	return 0;
 }
