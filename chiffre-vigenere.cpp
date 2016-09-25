/*
 * 2. Chiffre de Vigenère
 *
 * Auteurs:
 * RANDRIANJATOVO NANTENAINA Yves Patrick
 * RAKOTOARIVONY Herinjaka Antonio
 *
 * Application pour chiffrer un clair donné sur l'entrée standard et sortir le chiffré sur la sortie standard.
 */

#include <iostream>
#include <stdlib.h>
#include "utils.h"
#include "freqs.h"

using namespace std;

int main(int argc, char** argv) {
	cout << "Chiffrement de Vigenere: " << endl;
	string texte = readInput( cin );
	string cle =  argv[1];
	string texteClair = filter_AZ(texte);
	cout << "texte clair: " << endl;
	string texteCrypte = chiffreVigenere(texteClair, cle);
	cout << "texte crypte: " + texteCrypte << endl;

}
