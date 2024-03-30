/*😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎
  😎 Filename: Pokemon.cpp                                         😎
  😎 Author:   John Herron & Matthew Love                          😎
  😎 Date:     March 28 2024                                       😎
  😎 Purpose:  Allowing the user to add pokemon to their pokedex   😎
  😎           through the use of binary trees                     😎
  😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 */

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <iomanip>
using namespace std;

class Pokemon {
private:
    int pokemonIndex;
    string pokeName;

public:
    // Default name and ID for the pokemon
    Pokemon(int Index = 0, string Name = "None") {
        pokemonIndex = Index;
        pokeName = Name;
    }

    // To set the pokemon's ID
    void setID(int pokeID) {
        pokemonIndex = pokeID;
    }

    // To set the pokemon's name
    void setName(string Name) {
        pokeName = Name;
    }

    // To get the pokemon's ID
    int getID() const {
        return pokemonIndex;
    }

    // To get the pokemon's name
    string getName() const {
        return pokeName;
    }


    // overloaded < operator to compare pokemon by index
    bool operator<(const Pokemon &p) const {
        // return true if the pokemon before the < sign is less than the pokemon after
        if (this->pokemonIndex < p.pokemonIndex) {
            return true;
        }
        // return false otherwise
        return false;
    }

    // overloaded == operator to compare pokemon by index
    bool operator==(const Pokemon &p) const {
        // return true if they have the same index
        if (this->pokemonIndex == p.pokemonIndex) {
            return true;
        }
        // false if they do not have the same index
        return false;
    }

    // overloaded << operator to print out a pokemon's index and name
    friend ostream &operator<<(ostream &os, const Pokemon &p) {
        os << "Pokemon Index Number: " << left << setw(10) << p.pokemonIndex << "Name: " << p.pokeName;
        return os;
    }
};

#endif