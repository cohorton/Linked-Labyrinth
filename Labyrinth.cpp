// Chase Horton

#include <iostream>
#include "Labyrinth.hpp"

using namespace std;

bool isPathToFreedom(MazeCell* start, const std::string& moves) {


    bool hasSpellbook = false;
    bool hasPotion = false;
    bool hasWand = false;

    MazeCell *move = start;

    int movesLen = moves.length();

    if (moves.empty()) {
        return false;
    }

    else if (!moves.empty()) {
        while (hasSpellbook == false && hasPotion == false && hasWand == false) {
            for (int i = 0; i <= movesLen; i++) {

                if (moves[i] == 'N') {
                    move = move->north;

                    if (!move) {
                        cout << "INVALID MOVE." << endl;
                        return false;
                    }

                } else if (moves[i] == 'E') {
                    move = move->east;

                    if (!move) {
                        cout << "INVALID MOVE." << endl;
                        return false;
                    }

                } else if (moves[i] == 'S') {
                    move = move->south;

                    if (!move) {
                        cout << "INVALID MOVE." << endl;
                        return false;
                    }

                } else if (moves[i] == 'W') {
                    move = move->west;

                    if (!move) {
                        cout << "INVALID MOVE." << endl;
                        return false;
                    }

                }
                else {
                    continue;
                }

                if (move->whatsHere == Item::NOTHING) {
                    continue;
                } else if (move->whatsHere == Item::SPELLBOOK) {
                    hasSpellbook = (!hasSpellbook);
                } else if (move->whatsHere == Item::POTION) {
                    hasPotion = (!hasPotion);
                } else if (move->whatsHere == Item::WAND) {
                    hasWand = (!hasWand);
                }
                else {
                    continue;
                }
            }


        }

        if (hasSpellbook == false || hasPotion == false || hasWand == false){
            cout << "MISSING ONE OR MORE ITEMS." << endl;
            return false;
        }

        if (hasSpellbook != false && hasPotion != false && hasWand != false){
            if (!move){
                cout << "ALL ITEMS COLLECTED BUT INVALID MOVE." << endl;
            }
            return true;
        }

    }
    else {
        return false;
    }
}