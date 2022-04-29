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
    int textCounter(string text);
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
    string getAuthor();
    void setAuthor(string author);
    void inData(ifstream& ifst);
    void outFilter(string text, int mark, ofstream& ofst);
    void outData(string text, int mark, ofstream& ofst);
    Aphorism() {};
};

class Saying : public Text {
    string country;
public:
    string getCountry();
    void setCountry(string country);
    void inData(ifstream& ifst);
    void outFilter(string text, int mark, ofstream& ofst);
    void outData(string text, int mark, ofstream& ofst);
    Saying() {};
};

class Riddle : public Text {
    string answer;
public:
    string getAnswer();
    void setAnswer(string answer);
    void inData(ifstream& ifst);
    void outFilter(string text, int mark, ofstream& ofst);
    void outData(string text, int mark, ofstream& ofst);
    Riddle() {};
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