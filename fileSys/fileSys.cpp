// fileSys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stack>
#include "File.h"
#include "Container.h"
using namespace std;
int main()
{

    stack<Container> path;
    //stack<string> p;
    cout << "Welcome to my OS" << endl;



    int userInput;
    //Container root(ROOT,"root",123);
    Container* r = new Container();
    Container root = *r;
    path.push(root);
    //p.push(root.getName() + "/");
    //Container* wd = NULL;
    Container* workingDirectory = new Container;
    int counter = 0;
    while (!path.empty()) {



        //Container workingDirectory = (path.top());
        workingDirectory = &(path.top());
        //cout << (workingDirectory -> getName() << "sdasd" << endl;
        cout << "1.create new file\n2.create new folder\n3.ls\n4.cd\n5.read file\n6.write to file\n7.back" << endl;
        cout << "-->";
        //cout << endl;
        cin >> userInput;
        cout << endl;
        string fname, ext, s;
        File* f = new File();
        bool found = false;
        int x = -1;

        Container* newFolder = new Container();
        //Container c;

        switch (userInput) {
        case 1:
            cout << "CREATE FILE" << endl;
            cout << "enter file name and extension ..." << endl << "------------------------" << endl;
            cout << "name: ";

            cin >> fname;
            cout << endl << "ext: ";
            cin >> ext;
            cout << endl;
            f = new File(fname, ext);
            workingDirectory->addFile(*f);
            cout << workingDirectory->getName() << endl;
            cout << "created file " << f->getName() << endl;
            //workingDirectory ->printFilesAndFolders();
            break;
        case 2:

            int capacity;
            cout << "CREATE DIRECTORY" << endl;
            cout << "enter folder name and capacity ..." << endl << "------------------------" << endl;
            cout << "folder name: ";
            cin >> fname;
            cout << endl << "capacity: ";
            cin >> capacity;
            cout << endl;
            newFolder = new Container(FOLDER, fname, capacity);
            workingDirectory->createFolder(*newFolder);
            cout << "created directory " << newFolder->getName() << " of capacity " << newFolder->getCapacity() << endl;

            break;
        case 3:
            cout << "$ls" << endl;
            workingDirectory->printFilesAndFolders();
            break;

        case 4:
            cout << "CHANGE DIRECTORY " << endl;
            cout << "choose directory to move to:" << endl << "------------------------" << endl;
            cout << "folders: " << endl;
            //workingDirectory->printFolders();
            if (!(workingDirectory->printFolders()))
                break;
            cout << endl;
            cout << "$cd ";
            //Container* c = NULL;
            cin >> fname;
            for (int i = 0; i < workingDirectory->getFolderCount(); i++) {
                if (workingDirectory->isAFolder(fname)) {

                    workingDirectory->retrieveFolder(*newFolder, i);
                    //workingDirectory->retrieveFolder(newFolder, i);
                    if (newFolder != 0) {

                        path.push(*newFolder);


                        found = true;
                        break;
                    }
                }

            }
            if (found)cout << "You have moved to directory " << newFolder->getName() << endl;

            else cout << "folder " << fname << " not found" << endl;
            break;
        case 5:
            //cout << workingDirectory ->getName() << "@2" << endl;
            cout << "READ" << endl;
            cout << "enter file name to read " << endl << "------------------------" << endl;
            cout << "Files: " << endl;
            workingDirectory->printFiles();
            cout << endl;
            cin >> fname;
            if ((f != 0) && (workingDirectory->isAFile(fname, *f)))
                //if (workingDirectory->isAFile(fname, f))
                if (f != 0)
                {
                    (*f).printContent();
                    //cout << "hahaha" << endl;

                }

                else cout << "file not found" << endl;
            break;

        case 6:
            cout << "WRITE" << endl;
            cout << "enter file name to write" << endl << "------------------------" << endl;
            cout << "Files:" << endl;
            workingDirectory->printFiles();
            cout << endl;
            cin >> fname;
            //if ((f!=NULL) &&(workingDirectory ->isAFile(fname, *f)))
            if ((f != NULL) && (workingDirectory->isAFile(fname, *f, x)))

            {
                cout << "1.Overwrite\n2.Append" << endl;

                cin >> userInput;
                cout << "write your content" << endl;
                cin >> s;
                cout << endl;
                switch (userInput) {
                case 1:
                    (*f).eraseAndWrite(s);

                    if (x != -1)
                        workingDirectory->put(*f, x);
                    cout << "Overwrite  " << f->getName() << "data = '" << s << "'" << endl;

                    break;
                case 2:
                    (*f).appendToContent(s);
                    if (x != -1)
                        workingDirectory->put(*f, x);
                    cout << "Append to  " << f->getName() << "data = '" << s << "'" << endl;

                    break;
                default:
                    cout << "incorrect input" << endl;

                }



            }
            break;
        case 7:
            path.pop();
            cout << "$cd .." << endl;
            if (!path.empty())
                cout << "BACK TO " << path.top().getName() << endl;
            else
                cout << "EXIT\n**\n";
            break;
        default:
            cout << "incorrect input : enter a number between 1 (inclusive) and 7 (inclusive)" << endl;



        }


        //counter++;
        if (!path.empty())
        {
            counter++;
            cout << "Your working directory is " << path.top().getName() << endl;
            cout << "\n\n##~~" << counter << "~~###\n\n";
        }
        else cout << "THE MACHINE IS EXITING\nBYE BYE" << endl << "###################################################";





        //File f("ali.txt", "c", 23323);
        //f.printFileInfo();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
