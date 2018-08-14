//implements the Map class
#include "Map.h"
#include "Entry.h"

Map::Map(int size): table(size), count(0){}

int Map::mHash(string key){
    int total=0;
    for(int i=0; i<key.length(); i++){
       total+=(int) key[i];
    }
    return total%table.size();
}

list<Entry>::iterator Map::find(const string& key){ //helper private function
    int hashCode= mHash(key);
    list<Entry>& searchList=table[hashCode]; //list to be searched
    for(list<Entry>::iterator it=searchList.begin(); it!= searchList.end(); it++){
        if(it->getKey()==key){
            return it;
        }
    }
    return searchList.end();//return the end of the list if the key is not in the lit
}

void Map::erase(const string& key){
    if(containsKey(key)){ //if the key is in the table
        int hasCode=mHash(key);
        list<Entry>::iterator it=find(key);
        table[hasCode].erase(it); //remove it
        count--;//reduce the size of the element counter by 1
    }
 return; //or else do nothing
}


void Map::insert(const string& key, int value){
    if(!containsKey(key)){ //if the key isn't already in the table
        int hashCode=mHash(key);
        Entry temp(key, value);//make a new pair
        table[hashCode].push_front(temp);//add it to it's appropriate place on the table
        count++; //increase the size of the element counter by 1
    }
    else{
        list<Entry>::iterator it=find(key); //else find the key
        it->setValue(value);//and update it's value
    }
}

bool Map::containsKey(const string& key){
    for(list<Entry>::iterator it=table[mHash(key)].begin(); it!=table[mHash(key)].end(); it++){
        if(it->getKey() == key){
            return true;
        }
    }
return false;
}

bool Map::containsValue(int value){
    for(int i=0; i<table.size(); i++){//for every list in the table
        for(list<Entry>::iterator it=table[i].begin(); it!=table[i].end(); it++){//for every element in the lists
            if(it->getValue() == value){//if there's a value matching the one received
                return true; //return true
            }
        }
    }
return false;
}

int Map::getValueOf(const string& key){
    if(containsKey(key)){//if the key exists
        list<Entry>::iterator temp=find(key); //get it's iterator
        return temp->getValue(); //return it's value
    }
    else{
        throw exception(); //otherwise, throw an exception
    }
}

int& Map::operator[](const string& key){
    if(containsKey(key)){ //if the key exists in the table
        list<Entry>::iterator it=find(key);
        return it->getValue(); //return its value
    }
    else{
        insert(key, 0);//otherwise create the key with a value of 0
        list<Entry>::iterator it=find(key);
        return it->getValue();//return the 0
    }
}

int Map::size(){return count;}

bool Map::empty(){return count==0;}


