/*😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎
  😎 Filename: Program3.cpp                                       😎
  😎 Author:   John Herron & Matthew Love                         😎
  😎 Date:     March 28 2024                                      😎
  😎 Purpose:  Allowing the user to add pokemon to their pokedex  😎
  😎           through the use of binary trees                    😎
  😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 */

#include "BinaryTree.h"
#include "Pokemon.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    BinaryTree<Pokemon *> pokedex;

    // TEST
    Pokemon *poke1 = new Pokemon(45, "Pikachu");
    Pokemon *poke2 = new Pokemon(20, "Bulbasaur");
    Pokemon *poke3 = new Pokemon(20, "Tom");

    cout << (poke2 < poke1) << endl;
    bool b1 = (poke1 == poke2);
    cout << b1 << endl;
    bool b2 = (poke3 == poke2);
    cout << b2 << endl;

    cout << "Hello trainer, Master Vandergriff" << endl
         << endl;

    ifstream inPokeFile;
    inPokeFile.open("pokedex.txt");

    int pokedexCount;

    string stringPokeIndex;
    int pokeIndex;
    string pokeName;
    if (inPokeFile.good()) {
        while (getline(inPokeFile, stringPokeIndex, '#')) {
            pokeIndex = stoi(stringPokeIndex);

            getline(inPokeFile, pokeName, '#');

            Pokemon *newPokemon = new Pokemon(pokeIndex, pokeName);

            if (pokedex.searchNode(newPokemon)) {
                cout << "Oops!\tThe Pokemon with index " << pokeIndex << " is already in the Pokedex." << endl;
            } else {
                pokedex.insertNode(newPokemon);
                cout << "Inserting Pokemon with index " << pokeIndex << " into the Pokedex." << endl;
                pokedexCount++;
            }
        }

        cout << endl
             << pokedexCount << " Pokemon have been added to the Pokedex!" << endl
             << endl;

        cout << setw(20) << setfill('*') << "";
        cout << "POKEDEX:";
        cout << setw(20) << setfill('*') << "";
        cout << setfill(' ') << endl;

        pokedex.displayInOrder();

        cout << endl
             << "Goodbye!" << endl;

    } else {
        cout << "Could not open file pokedex.txt" << endl;
    }
    return 0;
}