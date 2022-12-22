#include <iostream>
#include "Container.h"
#include "File.h"

using namespace std;

int Container::getFileCount() {
	return fileCount;
}

void Container::printFilesAndFolders() const {


	for (int i = 0; i < folderCount; i++) {

		folders[i].printName();
		cout << "---> folder\n";
	}
	for (int i = 0; i < fileCount; i++) {

		files[i].printFileName();
		cout << "---> file" << endl;
	}
}
int Container::getCapacity() {
	return capacity;
}

void Container::printName()const {
	cout << name;
}


void Container::addFile(File &f) {
	if (isAFile(f.getName()))
		cout << "the file '" << f.getName() << "' exists" << endl;
	else if (getFileCount() == getCapacity() - 1)
		cout << "insufficient memory" << endl;
	
	else {
		files[fileCount] = f;
		fileCount++;
	}


	


}

