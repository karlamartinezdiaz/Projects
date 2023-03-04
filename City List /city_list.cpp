//Name : Karla Martinez
//The purpose of this file 
//to use my ADT in the background
//while allowing the user to add a new
//city and information about that city 
//without having to deal with the actual
//ADT.

#include "city_list.h"

city_list :: city_list()        //constructor, all to zero
{
    head = nullptr;
}

int city_list :: ~city_list     //release all memory, site node and
                                //city node
{
    //city node destructor
    city_node * temp = nullptr;
        while(city_head)
        {
            temp = city_head -> next;
            delete city_head;
            city_head = temp;
        }
    //site node destructor
/*    site_node * tempo = nullptr;
        while(site_node)
        {
            tempo = site_node -> next;
            delete site_node;
            site_node = tempo;
        }
*/
}

//removing a city 
int city_list :: remove_city(char city_name[] )
{
    city_node * front = head -> next;
    city_node * back = head;
    if (head == nullptr)
    {
        return 0;
    }
    else
    {
        while(front != nullptr && (strcmp(front-> city_name, city_name)))
        {
            back = front;
            front = front -> next;
        }
        back = front -> next;
    }
}

//displays just the sites 
int city_list :: display_sites(site & city)
{
    city_node * city_head = head;
    if (head == nullptr)
    {
        return 0;
    }
    else
    {
        while(city_head != nullptr && (strcmp(city_head.city_name)))
        {
            city_head = city_head ->next;
            site_node * head = city_head -> head;

            if(head == nullptr)
            {
                return 0;
            }
            else
            {
                while(city_head != nullptr)
                {
                    cout<< head -> info. site_name;
                    head = city_head -> next;

                }
            }
}

//inserting a city 
int city_list :: insert_city(char city[]) //inserting a city 
{
    //head is holding site so not nullptr here
    city_node * temp = new city_node;   //temp node created
    temp -> city_name = new char [strlen(city)+1];   //dynamiclly allocated array 
                                                     //setting aside memory of size 
                                                     //city plus 1 memory
    strcpy(temp -> city_name, city); //city will be copied into temp city_name!!!
    temp -> next = nullptr; //next is null for now
                        
    if (head == nullptr)    //check if head is empty
    {
        head = temp;
    }
    else 
    {
        city_node * ptr = head;
        while (ptr -> next != nullptr)
        {
            ptr = ptr -> next;      //ptr checking next LLL
        }
        ptr -> next = temp; 
    }
    return 1;       //something to display return 1 
}

//displaying a city 
int city_list :: display_city()  //Display all cities
                            //note to self:
                            //show me your purse 
{
    city_node * ptr = head;     //ptr at list
    
    if (head == nullptr)    //check if head is connected 
    {
        return 0;
    }
    else
    {
        while (ptr != nullptr)  //print cities names, goes through whole list 
        {
            cout<< "City: " << ptr -> city_name<< endl;
            ptr = ptr -> next;
        }
    return 1;       //something to display 

    }
}

//inserting a site 
int city_list :: insert_site(char city_name[], site & a_site)      //insert a site 
{
    site_node * temp = new site_node;   //temp node created
    temp -> info.site_name = new char [strlen(a_site.site_name) +1];
    strcpy(temp -> info.site_name, a_site.site_name); //site name
    temp -> next = nullptr; //next is null for now
/*    temp -> info.time = a_site.time;
    temp -> info.cost = a_site.cost;
    temp -> info.reservation= a_site.reservation;
*/  
    city_node * city_head = head;

    
    if (head == nullptr)
    {
        return 0;       //not attaching anything so no head = temp 
    }
    
    else 
    {
        //only do == 0 if you want to go inside if loop 
        //it will remian true but we want while loop to kick out 
        //after finding match 
        while (city_head -> next != nullptr && (strcmp(city_head -> city_name, city_name)))
        {
            city_head = city_head -> next;
        }
        site_node * site_head = city_head -> head;      //site head is point to what city head was pointing to 
        if(site_head == nullptr)
        {
            site_head = temp;
        }
        else 
        {
            while(site_head -> next != nullptr)
            {
                site_head = site_head -> next;
            }
            site_head -> next = temp;           //attach head to node 
        }
    }
    return 1;       //something to display return 1 
}

//city_list :: order() 
//give use choice of order
//not sure if to put in here or in insert_site


