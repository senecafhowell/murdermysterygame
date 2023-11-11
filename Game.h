// Game.h

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

//#include "Weapon.h"
//#include "Place.h"
//#include "Person.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Algorithm:
 * 1. Define the Game class
 * 2. Define all private and public class members, including the constructor
*/

class Game
{
    private:
    vector <int> guesses;
    vector <string> interviews;
    vector <string> discoveries;

    public:
    Game();
    int menuChoice();
    void finalGuess(string guessed_weapon, string guessed_place, string guessed_person, string actual_weapon, string actual_place, string actual_person, int num_lives, int lives_threshold, int num_weapons, int num_places, int num_people);
    void printKnownInformation();
    void addKnownInformation(string info);
    void sortGuesses(int weapon_guesses, int place_guesses, int person_guesses);
    void printTitle();
    void printMonologueOne(string monologue_one_file);
    void setInterviews(string interviews_file);
    void setDiscoveries(string discoveries_file);
    void displayInterview(int num);
    void displayDiscovery(int num);
    string getInterview(int num);
    string getDiscovery(int num);
    bool isHostile();
    // plus functions from other classes as needed
};