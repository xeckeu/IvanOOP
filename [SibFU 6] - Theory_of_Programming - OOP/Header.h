#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class Text {
    string text;
    int mark;
public:
    string getText();
    int textCounter();
    bool Compare(Text* T);
    int getMark();
    static Text* inText(ifstream& ifst);
    virtual void inData(ifstream& ifst) = 0;
    virtual void outFilter(string text, int mark, ofstream& ofst) = 0;
    virtual void outData(string text, int mark, ofstream& ofst) = 0;
protected:
    Text() {};
};

class Aphorism : public Text {
    string author;
public:
    void inData(ifstream& ifst);
    void outFilter(string text, int mark, ofstream& ofst);
    void outData(string text, int mark, ofstream& ofst);
    Aphorism() {};
};

class Saying : public Text {
    string country;
public:
    void inData(ifstream& ifst);
    void outFilter(string text, int mark, ofstream& ofst);
    void outData(string text, int mark, ofstream& ofst);
    Saying() {};
};

struct Node {
    Node *next, *prev;
    Text* current;
};

class Container {
    Node *head, *tail;
    int length;
public:
    void in(ifstream& ifst);
    void out(ofstream& ofst);
    void clear();
    void outFilter(ofstream& ofst);
    void sort();
    Container();
    ~Container() {
        clear(); 
    }
};

#endif //HEADER_H