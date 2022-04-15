#include "Header.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "usage: #.exe in_file out_file" << endl;
        exit(1);
    }

    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    Container C;

    C.in(ifst);
    ofst << "Container filled." << endl;
    cout << "Container filled." << endl;
    C.out(ofst);
    C.sort();
    ofst << "Container sorted." << endl;
    cout << "Container sorted." << endl;
    C.out(ofst);
    C.outFilter(ofst);
    C.clear();
    ofst << "Container cleared." << endl;
    cout << "Container cleared." << endl;
    C.out(ofst);
    cout << "Done!" << endl;
    system("pause");
    return 0;
}