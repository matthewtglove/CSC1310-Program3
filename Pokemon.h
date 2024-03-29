/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Filename: Pokemon.h                                           *
 * Author:   John Herron & Matthew Love                          *
 * Date:     March 28 2024                                       *
 * Purpose:  Allowing the user to add pokemon to their pokedex   *
 *           through the use of binary trees                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef POKEMON_H
#define POKEMON_H 

#include <iostream>
using namespace std;

class Pokemon
{
    private:
        int pokemonIndex;
        string pokeName;

    public:
        // Default name and ID for the pokemon
        Pokemon(int Index = 0, string Name = "None")
        {
            pokemonIndex = Index;
            pokeName = Name;
        }

        // To set the pokemon's ID
        void setID(int pokeID)
        {
            pokemonIndex = pokeID;
        }

        // To set the pokemon's name
        void setName(string Name)
        {
            pokeName = Name;
        }

        // To get the pokemon's ID
        int getID() const
        {
            return pokemonIndex;
        }

        // To get the pokemon's name
        string getName() const
        {
            return pokeName;
        }

        // FIXME:  
        // TODO:  overloaded < operator goes here
        // TODO:  overloaded == operator goes here
        // TODO:  overloaded > operator goes here




};

#endif