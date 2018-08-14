//Adebowale Ojetola CISC 3130
//Tests the map class
#include "Entry.h"
#include "Entry.cpp"
#include "Map.h"
#include "Map.cpp"
#include <iostream>
#include <fstream>
using namespace std;
int main(){

    string squad [5] ={"Rooney", "Ronaldo", "Messi", "Pogba", "Zlatan"};
    vector<string> player(squad, squad+5); //vector of players
    Map myMap(10);
    string str;
    bool done=false;

    //insert the vector into the map
    myMap.insert(player[0], 78);
    myMap.insert(player[1], 59);
    myMap.insert(player[2], 99);
    myMap.insert(player[3], 89);
    myMap.insert(player[4], 95);

    //print out the map by using the [] operator
    cout<<"This is the squad:"<<endl;
    for(int i=0; i<myMap.size(); i++){
        cout<<player[i]<<" has "<<myMap[player[i]]<<" rating"<<endl;
    }
    cout<<endl;

    //change the value of two players using insert()
    myMap.insert("Rooney", 100);
    myMap.insert("Ronaldo", 85);
    cout<<"Changed Rooney's and Ronaldo's ratings."<<endl;
    cout<<"This is the squad:"<<endl;
    for(int i=0; i<myMap.size(); i++){
        cout<<player[i]<<" has "<<myMap[player[i]]<<" rating"<<endl;
    }
    cout<<endl;

    cout<<"Removed "<<player[3]<<" from the squad, wasn't keeping up."<<endl;
    myMap.erase(player[3]);//remove a player from the list
    player.erase(player.begin()+3); //remove it from the vector
                        //to prevent it from being created again when the map is printed
    cout<<"This is the squad:"<<endl;
    for(int i=0; i<myMap.size(); i++){
        cout<<player[i]<<" has "<<myMap[player[i]]<<" rating"<<endl;
    }
    cout<<"Enter a name of a player to get and change his ratings"<<endl;
    cin>>str;
    //Quick loop to test etValueOf() and if the [] operator can change the value
    while(!done){
    if(myMap.containsKey(str)){
    int rating=myMap.getValueOf(str);
    cout<<"Ok "<<str<<" has "<<rating<<" ratings"<<endl;
    cout<<"Enter new Ratings> ";
    cin>>rating;
    myMap[str]=rating;
    cout<<"Ok "<<str<<" now has "<<rating<<" ratings"<<endl;
    done=true;
    }
    else{
        cout<<"Sorry "<<str<<" is not on this squad. Try again"<<endl;
        cin>>str;
    }
    }
    cout<<endl;
    //test the containsValue() method
    if(myMap.containsValue(100)){
        cout<<"This squad also has a player rated 100, the best player in the world"<<endl;
    }

return 0;
}
