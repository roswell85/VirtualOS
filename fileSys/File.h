#pragma once
#include <iostream>
using namespace std;
class File 
 
{

private:

    string name, extension, content;


public:
    File() {
        content = "";
    }
    File(string n, string ext) :name(n), extension(ext) {
        content = "";
    }

  

      


    string getName() const {
        return name;
    }

    void  operator=(const File& f) {
        //*this = f;
        //this->name = f.name;
        //this->extension = f.extension;
        //this->content = f.content;
        name = f.name;
        extension = f.extension;
        content = f.content;
        //cout << content << endl;
        //cout << name << "NAME\n";
    }
    
    void appendToContent(string s);
    void eraseAndWrite(string s);
    void printFileName() const;
    void printContent() const;




};

