/*
 * 2. Chiffre de Vigenère
 *
 * Auteurs:
 * RANDRIANJATOVO NANTENAINA Yves Patrick
 * RAKOTOARIVONY Herinjaka Antonio
 *
 * Application pour tester et déchiffrer un texte crypté et clé donné sur l'entrée standard et sortir le texte clair sur la sortie standard.
 */
#include <iostream>
#include <stdlib.h>
#include "utils.h"
#include "freqs.h"

using namespace std;

int main(int argc, char** argv) {
	cout << "Chiffrement de Vigenere: " << endl;
	string texteCrypte = readInput( cin );
	string cle =  argv[1];
	cout << "texte crypte: " << endl;
	string texteClair = dechiffreVigenere(texteCrypte, cle);
	cout << "texte clair: " + texteClair << endl;

}
