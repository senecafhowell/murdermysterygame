// Lives.h

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Algorithm:
 * 1. Define the Lives class
 * 2. Define all private and public class members, including the constructors
*/

class Lives {

    public:

        Lives();

        void setLives();
        int getLives();
        void updateLives(int lives);

        int getLivesThreshold();

        bool evaluateLives();

        void incrementLives1();
        void incrementLives5();
        void decrementLives1();
        void decrementLives5();
        void incrementLivesRand();
        void decrementLivesRand();

    private:

        int playerLives;
        const static int livesThreshold = 10;

};