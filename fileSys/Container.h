#pragma once

#include <iostream>
#include "File.h"
using namespace std;


enum ContainerType {ROOT,FOLDER};
class Container {



private:
	const int CAPACITY = 10;

	ContainerType type;
	string  name;
	int fileCount, folderCount, capacity;
	Container* folders;
	File* files;
	//int* x;
public :
	Container() {
		//cout << "entered constructor" << endl;
		//x = new int[CAPACITY];
		//folders = new Container[CAPACITY];
		//cout << "here" << endl;
		files = new File[CAPACITY];
		fileCount = 0;
		folderCount = 0;
		capacity = CAPACITY;

		type = ROOT;
		name = "root";
		//cout << "done" << endl;

	}
	Container(ContainerType t, string n, int c) : type(t), name(n), capacity(c) {
		folders = new Container[capacity];
		files = new File[capacity];
		fileCount = 0;
		folderCount = 0;
		
	}

	void printFilesAndFolders() const;

	void printFiles() const {
		//cout << fileCount << "fc" << endl;
		if (fileCount == 0) {
			
			cout << "there are no files in this folder" << endl;
			return;
		}
		for (int i = 0; i < fileCount; i++) {
			files[i].printFileName(); cout << endl;
		}
	}
	bool printFolders() const {

		if (folderCount == 0) {
			cout << "there are no folders" << endl;
			return false;
		}
		for (int i = 0; i < folderCount; i++)
			folders[i].printName(); cout << endl;

		return true;
	}
	void printName() const;
	void operator=(const Container& other) {
		//*this = other;
		type = other.type;
		name = other.name;
		fileCount = other.fileCount;
		folderCount = other.folderCount;
		capacity = other.capacity;
		for (int i = 0; i < fileCount; i++)
			files[i] = other.files[i];

		for (int i = 0; i < folderCount; i++)
			folders[i] = other.folders[i];

	}

	void retrieveFile(File& f, int idx) {
		f = files[idx];
	}

	void createFolder(const Container & cont) {
		if (isAFolder(cont.getName()))
			cout << "the folder '" << cont.getName() << "' exists" << endl;
		if (folderCount == capacity - 1) {

			cout << "bad memory" << endl;
			return;
		}

		else if (folderCount == 0)
		{
			folders = new Container[capacity];
		}

		

		
		folders[folderCount] = cont;
		folderCount++;
		cout << "created new folder " << folders[folderCount - 1].name << endl;
		
	}

	int getFolderCount() const{
		return folderCount;
	}

	

	int getCapacity();

	void addFile(File &f);

	bool isAFile(string name, File* f) {

		for (int i = 0; i < fileCount; i++) {
			if (files[i].getName().compare(name) == 0) {
				//f = files[i];
				f = &files[i];
				return true;
			}
		}
		return false;
	}
	bool isAFile(string name, File& f, int& x) {

		for (int i = 0; i < fileCount; i++) {
			if (files[i].getName().compare(name) == 0) {
				f = files[i];
				x = i;

				return true;
			}
		}
		return false;
	}

	void put(File& f, int x) {
		files[x] = f;

	}
	bool isAFile(string name,File & f) {
		for (int i = 0; i < fileCount; i++) {
			if (files[i].getName().compare(name) == 0) {
				f = files[i];

				return true;
			}
		}
		return false;
	}
	bool isAFile(string name) {
		for (int i = 0; i < fileCount; i++) {
			if (files[i].getName().compare(name) == 0)
				return true;
		}
		return false;
	}

	
	void retrieveFolder(Container & folder,int idx){
		folder = folders[idx];
	
	}

	void retrieveFolder(Container* folder, int idx) {
		folder = &folders[idx];
	}

	string getName() const {
		return name;
	}
	int getFileCount();
	bool isAFolder(string name) const {
		for (int i = 0; i < folderCount; i++) {
			if (folders[i].getName().compare(name) == 0) {
				return true;
			}
		}

		return false;

	}


};