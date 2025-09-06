// COMSC-210 | Lab 3A | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Restaurant{
    string address;
    string name;
    int reservedtables;
    int capacity;
    bool allowdelivery;
};
// RestaurantFiller() fills the resturant manually
// returns: a resturant struct named temp.
Restaurant RestaurantFiller(){
    Restaurant temp;
    cout<<"Manual Entry"<<endl;
    cout<<"Enter Address of Restaurant"<<endl;
    string addressh;
    getline(cin, addressh);
    temp.address = addressh;
    cout<<"Enter Name of Restaurant"<<endl;
    string nameh;
    getline(cin, nameh);
    temp.name = nameh;
    cout<<"Enter Capacity of Restaurant"<<endl;
    int capacityh;
    cin>>capacityh;
    temp.capacity = capacityh;
    cout<<"Enter Amount of Reserved tables"<<endl;
    int reservedtablesh;
    cin>>reservedtablesh;
    temp.reservedtables = reservedtablesh;
    cout<<"Allow Delivery? true or false"<<endl;
    string allowdeliveryh;
    cin>>allowdeliveryh;
    cin.ignore(1000, '\n');
    if(allowdeliveryh=="true"){
        temp.allowdelivery = true;
    }
    else{
        temp.allowdelivery = false;
    }
    return temp;
}
//RestaurantFiller() fills the struct but through a file
//Arguments: reference to the file ifstream
//returns:  a restaurant struct named temp.
Restaurant RestaurantFiller(ifstream &file){
      Restaurant temp;
      string hold;
      getline(file,temp.address);
      getline(file,temp.name);
      file>>temp.reservedtables;
      file>>temp.capacity;
      file>>temp.allowdelivery;
      file.close();
return temp;
}

void printRestaurantData(Restaurant &n){
    cout<<endl;
    cout<<"Address of Resturant: "<<n.address<<endl;
    cout<<"Name of Resturant: "<<n.name<<endl;
    cout<<"Capacity of Resturant:  "<<n.capacity<<endl;
    cout<<"Reserved Tables: "<<n.reservedtables<<endl;
    if(n.allowdelivery==1){
        cout<<"Allow Delivery: True"<<endl;
    }
    else{
        cout<<"Allow Delivery: False"<<endl;
    }
}


// use "C:\\Users\\hope4\\Desktop\\test file\\testing.txt" for testing file
int main(){
    string response;
    vector<Restaurant> restaurants;
    while(true){
        cout<<"Enter File Path (Enter X for manual entry or Enter L to output Restaurant Data or Enter Z to end program)"<<endl;
        getline(cin, response);
        if(response=="X"||response=="x"){
            restaurants.push_back(RestaurantFiller());
        }
        else if(response=="Z"||response=="z"){
            break;
        }
        else if(response=="L"||response=="l"){
            while(true){
                cout<<"There are "<< restaurants.size()<<" restaurants, which one would you like to print? Enter number"<<endl;
                int rep;
                cin>>rep;
                cin.ignore(1000, '\n');
                if(restaurants.empty()==true){
                  cout<<"There are no restaurants."<<endl;
                  break;
                  
                }
                else if(rep==0||rep>restaurants.size()){
                    cout<<"please enter a number inside of the range listed "<<endl;
                }
                else{
                    printRestaurantData(restaurants[rep-1]);
                    break;
                }
            }
        }
        else if(!response.empty()){
            ifstream file(response);
            if(!file){
                cout<<"error opening file"<<endl;
                cout<<"Please try again"<<endl;
            }
            else{
                cout<<"file opened"<<endl;
                restaurants.push_back(RestaurantFiller(file));
            }
        }
    }
    return 0;
}