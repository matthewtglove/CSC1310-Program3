/*😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎
  😎 Filename: Program3.cpp                                        😎
  😎 Author:   John Herron & Matthew Love                          😎
  😎 Date:     March 28 2024                                       😎
  😎 Purpose:  Allowing the user to add pokemon to their pokedex   😎
  😎           through the use of binary trees                     😎
  😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 */

#include "BinaryTree.h"
#include "Pokemon.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    BinaryTree<Pokemon *> pokedex; // make a binary tree of data type pokemon pointer and name it pokedex

    cout << "\nHello trainer, Master Vandergriff\n"
         << endl;

    ifstream inPokeFile;
    inPokeFile.open("pokedex.txt");

    int pokedexCount = 0; // keeps count of total pokemon in the pokedex

    string stringPokeIndex; // read in number from file must first be a string
    int pokeIndex;          // Transform the string to an int for pokeIndex after reading it from the file
    string pokeName;        // holds name for the pokemon from the file

    if (inPokeFile.good()) {                                // make sure the file can be opened
        while (getline(inPokeFile, stringPokeIndex, '#')) { // make a while loop and read in the pokeindex until the #
            pokeIndex = stoi(stringPokeIndex);              // convert the poke index from a string to an integer

            getline(inPokeFile, pokeName, '#'); // read in pokemon's name

            Pokemon *newPokemon = new Pokemon(pokeIndex, pokeName); // dynamically allocate a pokemon object and send in the variables we just collected

            // if searchNode finds the pokemon within the tree then tell the user that that pokemon is already in the pokedex
            if (pokedex.searchNode(newPokemon)) {
                cout << "Oops!\tThe Pokemon with index " << pokeIndex << " is already in the Pokedex." << endl;
            } else { // else means the pokemon isn't a duplicate and can be inserted
                pokedex.insertNode(newPokemon);
                cout << "Inserting Pokemon with index " << pokeIndex << " into the Pokedex." << endl;
                pokedexCount++; // increment the counter since a pokemon has been inserted
            }
        }
        inPokeFile.close(); // after the file has read in the pokemon from the file then close the file

        cout << endl
             << pokedexCount << " Pokemon have been added to the Pokedex!\n"
             << endl
             << endl;

        cout << setw(20) << setfill('*') << "";
        cout << "POKEDEX:";
        cout << setw(20) << setfill('*') << "" << endl;
        cout << setfill(' ') << endl;

        // call display order to print the pokedex to the user
        pokedex.displayInOrder();
    } else {
        cout << "ERROR: Could not open file pokedex.txt" << endl;
    }

    cout << endl
         << "Goodbye!" << endl;

    return 0;
}