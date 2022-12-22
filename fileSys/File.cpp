#include <iostream>
#include "File.h"


using namespace std;


void File::printFileName() const {

	cout << name << "." << extension;
}


void File::eraseAndWrite(string s) {
	content = s;
	//cout << content << endl;

}

void File::appendToContent(string s) {
	content += s;
}
void File::printContent() const {
	cout << "CONTENT: ";
	cout << content << endl;
	
}
