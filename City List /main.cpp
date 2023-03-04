#include "city_list.h"
//Main


int main()
{
    char city_name [100];
    char tour_name [100];
    
    site info;      //Allows access to struct/ direct member access
                    //site= data type 
    city_list city;

    int i = 0;
    while (i < 2) 
    {
        cout<< "Enter city name: ";
        cin.get(city_name, 100, '\n');
        cin.ignore(100, '\n');
        
        city.insert_city(city_name);     //call member
        ++i;
    }
    city.display_city();
    cout<<"Here are the sites :3 : "; 
    cin.get(tour_name, 100, '\n');
    cin.ignore(100, '\n');
    info.site_name= new char [strlen(tour_name) + 1];
    strcpy(info.site_name, tour_name); //site name
    city.insert_site(city_name, info);      //filled info up
    
return 0;


}




