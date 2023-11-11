// Weapon.cpp

// CSCI 1300 Fall 2022
// Author: Seneca Howell & Sam Jarzembowski
// Project 3

#include "Weapon.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Weapon::Weapon()
{
    chosen_weapon = " ";
}

string Weapon::getWeapon()
{
    return chosen_weapon;
}

/*
Algorithm:
1. go through weapon_list and check for a match
2. return true/false accordingly
*/
bool Weapon::validateWeapon(string weapon)
{
    int valid = 0;
    
    // while the counter is smaller than the weapons_list vector
    for(int i = 0; i < weapon_list.size(); i++)
    {
        // if the guessed weapon is one of the weapons in the list
        if(weapon == weapon_list.at(i))
        {
            // add to the valid counter
            valid++;
        }
    }
    
    // if no valid weapon was found
    if(valid == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Weapon::getWeaponList()
{
    // for the size of the weapons list, print out each individual weapon
    for(int i = 0; i < weapon_list.size(); i++)
    {
        cout << weapon_list.at(i) << endl;
    }
}

/*
Algorithm:
1. open file
2. store data from file into vector
3. close file
*/
void Weapon::setWeaponList(string weapons_of_decade_file_name)
{
    string line = " ";
    int count = 0;
    
    // open the weapons file
    ifstream weapons_file;
    weapons_file.open(weapons_of_decade_file_name);

    // if the file did not open, print an error
    if(weapons_file.fail())
    {
        cout << "The weapons file did not open properly." << endl;
    }
    else
    {
        // otherwise, populate the weapons list vector with the weapons listed in the file
        while(!weapons_file.eof())
        {
            getline(weapons_file, line);

            weapon_list.push_back(line);
        }

        weapons_file.close();
    }
}

void Weapon::setWeapon()
{
    // set the chosen_weapon to the first weapon in the list
    chosen_weapon = weapon_list.at(0);
}

/*
Algorithm:
1. check that input is valid
2. store guessed weapon
3. return true/false accordingly
*/
bool Weapon::guessWeapon(string guessed_weapon)
{
    int valid = 0;
    
    // while the counter is smaller than the weapons_list vector
    for(int i = 0; i < weapon_list.size(); i++)
    {
        // if the guessed weapon is one of the weapons in the list
        if(guessed_weapon == weapon_list.at(i))
        {
            // add to the valid counter
            valid++;
        }
    }
    
    // if no valid weapon was found
    if(valid == 0)
    {
        cout << "The weapon you guessed was not a valid weapon." << endl;
        return false;
    }
    else
    {
        Weapon vector;
        vector.storeGuessedWeapon(guessed_weapon);

        // if the guessed_weapon was the chosen_weapon, print a correct message and add to the lives count
        if(guessed_weapon == chosen_weapon)
        {
            cout << "Correct! The weapon used was in fact the " << guessed_weapon << ". You've gained a random amount of lives!" << endl;
            return true;
        }
        // otherwise, print an incorrect message and subtract from the lives count
        else
        {
            cout << "Incorrect. The weapon used was not the " << guessed_weapon << ". You have lost a random amount of lives." << endl;
            return false;
        }
    }

    // add one to the weapon guesses counter
    weapon_guesses++;
}

void Weapon::storeGuessedWeapon(string guessed_weapon)
{
    // add the guessed weapon to the end of the guessed weapons vector
    guessed_weapons.push_back(guessed_weapon);
}

/*
Algorithm:
Ensure the vector has data, then print all guesses for weapon
*/
void Weapon::getGuessedWeapon()
{
    int size = guessed_weapons.size();

    if(size == 0)
    {
        cout << "You made no simple guesses for the person category." << endl;
    }
    else
    {
        for(int i = 0; i < guessed_weapons.size(); i++)
        {
            cout << guessed_weapons.at(i) << endl;
        }
    }
}

/*
Algorithm:
Return the number of guesses made for weapon
*/
int Weapon::getNumGuessedWeapon()
{
    int size = guessed_weapons.size();
    return size;
}


/*
Algorithm:
Sets number of lives for weapon
*/
void Weapon::setNumLivesW(int lives)
{
    lives_w = lives;
}

/*
Algorithm:
Return the number of lives stored inside the weapon
*/
int Weapon::getNumLivesW()
{
    return lives_w;
}