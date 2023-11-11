// Place.cpp

// CSCI 1300 Fall 2022
// Author: Seneca Howell & Sam Jarzembowski
// Project 3

#include "Place.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Place::Place()
{
    chosen_place = " ";
}

string Place::getPlace()
{
    return chosen_place;
}

/*
Algorithm:
1. go through place_list and check for a match
2. return true/false accordingly
*/
bool Place::validatePlace(string place)
{
    int valid = 0;
    
    // while the counter is smaller than the place_list vector
    for(int i = 0; i < place_list.size(); i++)
    {
        // if the guessed place is one of the places in the list
        if(place == place_list.at(i))
        {
            // add to the valid counter
            valid++;
        }
    }
    
    // if no valid place was found
    if(valid == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Place::getPlaceList()
{
    // for the size of the place list, print out each individual place
    for(int i = 0; i < place_list.size(); i++)
    {
        cout << place_list.at(i) << endl;
    }
}

/*
Algorithm:
1. open file
2. store data from file into vector
3. close file
*/
void Place::setPlaceList(string places_of_decade_file_name)
{
    string line = " ";
    int count = 0;
    
    // open the places file
    ifstream places_file;
    places_file.open(places_of_decade_file_name);

    // if the file did not open, print an error
    if(places_file.fail())
    {
        cout << "The places file did not open properly." << endl;
    }
    else
    {
        // othwerise, populate the place list vector with the places listed in the file
        while(!places_file.eof())
        {
            getline(places_file, line);

            place_list.push_back(line);
        }

        places_file.close();
    }
}

void Place::setPlace()
{
    // set the chosen_place to the first place in the list
    chosen_place = place_list.at(0);
}

/*
Algorithm:
1. check that input is valid
2. store guessed place
3. return true/false accordingly
*/
bool Place::guessPlace(string guessed_place)
{
    int valid = 0;
    
    // while the counter is smaller than the place_list vector
    for(int i = 0; i < place_list.size(); i++)
    {
        // if the guessed place is one of the places in the list
        if(guessed_place == place_list.at(i))
        {
            // add to the valid counter
            valid++;
        }
    }
    
    // if no valid place was found
    if(valid == 0)
    {
        cout << "The place you guessed was not a valid place." << endl;
        return false;
    }
    else
    {
        Place vector;
        vector.storeGuessedPlace(guessed_place);

        // if the guessed_place was the chosen_place, print a correct message and add to the lives count
        if(guessed_place == chosen_place)
        {
            cout << "Correct! The place used was in fact the " << guessed_place << ". You have gained a random amount of lives!" << endl;
            return true;
        }
        // otherwise, print an incorrect message and subtract from the lives count
        else
        {
            cout << "Incorrect. The place used was not the " << guessed_place << ". You have lost a random amount of lives." << endl;
            return false;
        }
    }

    // add one to the place guesses counter
    place_guesses++;
}

void Place::storeGuessedPlace(string guessed_place)
{
    // add the guessed place to the end of the guessed places vector
    guessed_places.push_back(guessed_place);
}

/*
Algorithm:
Ensure the vector has data, then print all guesses for place
*/
void Place::getGuessedPlace()
{
    int size = guessed_places.size();

    if(size == 0)
    {
        cout << "You made no simple guesses for the person category." << endl;
    }
    else
    {
        for(int i = 0; i < guessed_places.size(); i++)
        {
            cout << guessed_places.at(i) << endl;
        }
    }
}

/*
Algorithm:
Return the number of guesses made for place
*/
int Place::getNumGuessedPlace()
{
    int size = guessed_places.size();
    return size;
}