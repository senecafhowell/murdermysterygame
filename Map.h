// Map.h

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std;

class Map
{
private:
    const char SPACE = ' ';            // marker for unexplored spaces
    const char WALLS = '|';
    const char WALLS2 = '-';
    const char EXPLORED = ' ';         // marker for explored spaces
    const char DISCOVERYPOINT = 'o';   // marker for unexplored discovery points
    const char CHARACTER = 'C';        // marker for NPC locations
    const char PLAYER = 'X';
    const char DOOR = '~';

    static const int num_rows_ = 15; // number of rows in map
    static const int num_cols_ = 32; // number of columns in map

    int player_position_[2];              // player position (row,col)
    int char_positions_[6][3];            // stores the (row,col) positions of NPCs present on map and if they have been found
    int door_positions_[6][2];
    int disc_points_[8][3];                // stores the (row,col) positions of discovery points on map and if they have been found
    char map_data_[num_rows_][num_cols_];  // stores the character that will be shown at a given (row,col)

    char blank_map[15][32] = {{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'|', ' ', 'C', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', '~', ' ', ' ', ' ', '~', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', 'o', ' ', ' ', ' ', ' ', ' ', '|', 'o', ' ', ' ', '|', ' ', ' ', ' ', ' ', 'o', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', 'o', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'-', '-', '-', '-', '-', '-', ' ', '~', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', ' ', '|'},
    {'-', '-', '-', '-', '-', '-', ' ', '~', ' ', '-', '-', '-', '-', '-', '-', '-', ' ', '~', ' ', '-', '-', '-', ' ', '~', ' ', '-', '-', '-', '-', '-', '-', '|'},
    {'|', ' ', 'o', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', ' ', '|'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', ' ', '|'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};

    int rand_encounters_;  // stores number of misfortunes currently on map

public:
    Map();

    void resetMap();

    // getters
    int getPlayerRow();
    int getPlayerCol();
    int getCharCount();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col);
    bool isWallLocation(int row, int col);
    bool isCharLocation(int row, int col);
    bool isDoorLocation(int row, int col);
    bool isExplored(int row, int col);
    bool isFreeSpace(int row, int col);
    bool isDiscPoint(int row, int col);

    // setters
    void setPlayerPosition(int row, int col);

    // other
    void displayMap();
    bool move(char);
    void removePoint(int row, int col);
    void exploreSpace(int row, int col);
};

#endif