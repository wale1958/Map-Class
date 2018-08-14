//Adebowale Ojetola CISC 3130
//This file declares a Map class
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Entry.h"
#include <list>
using namespace std;
class Map{
private:
    int count;
    vector<list<Entry> > table;
    int mHash(string key);
    list<Entry>::iterator find(const string& key);
public:
    Map(int size);
    void insert (const string& key, int value);
    bool containsKey(const string& key);
    bool containsValue(int value);
    void erase (const string& key);
    int getValueOf(const string& key);
    int& operator [] (const string& key);
    int size();
    bool empty();
};

#endif // MAP_H_INCLUDED
