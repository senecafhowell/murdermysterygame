// Place.h

// CSCI 1300 Fall 2022
// Author: Seneca Howell & Sam Jarzembowski
// Project 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Algorithm:
 * 1. Define the Place class
 * 2. Define all private and public class members, including the constructors
*/

// define Place class
class Place
{
    // protected
    private:
    string chosen_place;
    vector <string> guessed_places;
    vector <string> place_list;
    int place_guesses = 0;
    
    // public
    public:
    // default constructor
    Place();
    // getters
    string getPlace();
    bool validatePlace(string place);
    void getPlaceList();
    // setters
    void setPlaceList(string places_of_decade_file_name);
    void setPlace();
    // extra
    bool guessPlace(string guessed_place);
    void storeGuessedPlace(string guessed_place);
    void getGuessedPlace();
    int getNumGuessedPlace();
};