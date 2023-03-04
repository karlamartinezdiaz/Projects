#include <cctype> 
#include <cstring> 
#include <iostream>

using namespace std;
//Name: Karla Martinez
//This is the header file(draft) that will serve
//to hold the my structs and classes both public
//and private to be used in a program that will 
//aide the user in viewing, adding, and removing
//cities visited and cities they'd like to 
//visit. 


//const int CITY{41};     // constant to be used for city name
                        // and tours name, tours may recieve
                        // its own constant but for now just 
                        // one shared constant 

struct site             //my background data for my sites
                        //creating a data type of site
{
    char * site_name;        //The site to visits name 
    int time;       //Tourists site time needed to visit 
    int cost;       //how much will it cost to visit
    char reservation;        //is a reservation needed?
};

struct site_node        //my node to create a list for my sites
{
    //site * site_name;          //holds the name of the city 
    site info;          //variable info to hold the information related
                        //to the site visiting
    site_node * head;   //pointer for my head node    
    site_node * next;   //pointer node to be used in list 

};


struct city_node 
{
    char * city_name;       //note to self: inserting city only 
                            //needs char* for name of city being added
    site_node * head;       //head node in city pointing 
                            //to the site node info
    city_node * next;       //next node pointer 
};

class city_list
{
    public:             //client interface
        city_list();    //defaul constructor, initialize to zero
        ~city_list();   //deallocate dynamic memory, 
                        //reset data members to zero
        //int add(char city[], char sites[], int time, int cost, 
        // int res)         //Can I use this?
        //int order(char choice[]);           //what order client wants to
                                            //arrange list 
        
        int insert_city(char city[]);        //Will add a city name
        int insert_site(char city[], site & a_site);    //to_add? ask       
        int display_city();          //Displays all the cities in the list        
        int remove_city(char matching[]);   //Move a city matching to the users input 
                                          //to a seperate list holding cities visited, 
                                          //might change to removing a city 
        int display_sites(site & city);        //Will display the tours for all cities 
//        int match(site_name, city_name) const;       //Will find site matching user request 
        //int display_city() const;

    private: 

        city_node * head;           //head of list
//        city_node * tail;           //tail of list 
};









