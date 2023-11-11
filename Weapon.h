// Weapon.h

// CSCI 1300 Fall 2022
// Author: Seneca Howell & Sam Jarzembowski
// Project 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Algorithm:
 * 1. Define the Weapon class
 * 2. Define all private and public class members, including the constructors
*/

// define Weapon class
class Weapon
{
    // protected
    private:
    string chosen_weapon;
    vector <string> guessed_weapons;
    vector <string> weapon_list;
    int weapon_guesses = 0;
    int lives_w = 0;
    
    // public
    public:
    // default constructor
    Weapon();
    // getters
    string getWeapon();
    void getWeaponList();
    bool validateWeapon(string weapon);
    // setters
    void setWeaponList(string weapons_of_decade_file_name);
    void setWeapon();
    // extra
    bool guessWeapon(string guessed_weapon);
    void storeGuessedWeapon(string guessed_weapon);
    void getGuessedWeapon();
    int getNumGuessedWeapon();
    void setNumLivesW(int lives);
    int getNumLivesW();
}; 