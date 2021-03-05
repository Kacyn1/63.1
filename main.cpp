#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ciagi {
	ifstream plik;
	
	public:
		ciagi();
		~ciagi();
		void wczyt();
		bool sprawdzenie(string s);
};
ciagi::ciagi() {
	plik.open("ciagi.txt");
}
void ciagi::wczyt() {
	string ciag;
	if(plik.good()) {
		while(!plik.eof()) {
		plik>>ciag;
			if(this->sprawdzenie(ciag)) {
			cout<<ciag<<"\n";
			}
		}		
	}
}
bool ciagi::sprawdzenie(string ciag) {
	if(ciag.length()%2==0) {
	string s1 = ciag.substr(0, ciag.length()/2);
	string s2 = ciag.substr(ciag.length()/2, ciag.length()/2);
		if(s1==s2) {
		return true;
		}
			else {
			return false;
		}
	}
		else{
		return false;
	}
}
ciagi::~ciagi() {
	plik.close();
}




int main(int argc, char** argv) {
	ciagi c;
	c.wczyt();
	return 0;
}
