#include <iostream>
 using namespace std;
 
 class bangundatar {
 	protected:
 		int lebar, tinggi;
 		
 	public:
 		void setvalue(int a, int b) {
 			lebar = a;
 			tinggi = b;
 		}
 };
 
 class persegipanjang : public bangundatar {
 	public:
 		int getvalue() {
 			return (lebar * tinggi);
 		}
 };
 
 class segitiga : public bangundatar {
 	public :
 		int getvalue() {
 			return (lebar * tinggi / 2);
 		}
 };
 
 int main () 
 {
 	persegipanjang pp;
 	segitiga tiga;
 	
 	pp.setvalue(4,5);
 	tiga.setvalue(10,5);
 	
 	cout << pp.getvalue() << endl;
 	cout << tiga.getvalue() << endl;
 	
 }
