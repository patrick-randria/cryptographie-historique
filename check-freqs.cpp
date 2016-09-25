/*
 * 4. Cryptanalyse du chiffre de Vigenère
 *
 * Auteurs:
 * RANDRIANJATOVO NANTENAINA Yves Patrick
 * RAKOTOARIVONY Herinjaka Antonio
 *
 * Application qui prends en entrée standard:
 * - une chaine cryptée,
 * - deux paramètres (k et r donc)
 * puis affiche :
 * - les fréquences de chaque lettres dans la sous-chaine
 * - les indices de coïncidences de la sous-chaîne
 * - l'indice de coïncidences du francais
 * - l'indice de coïncidences aléatoire
 */

#include <iostream>
#include <stdlib.h>
#include "utils.h"
#include "freqs.h"

using namespace std;

int main(int argc, char** argv) {
	cout << "Analyse des fréquences d'un chiffré: " << endl;
	string texteCrypte = readInput( cin );
	int r = atoi(argv[1]);
	int k = atoi(argv[2]);
	string sousChaine = subtext( texteCrypte, r, k );
	vector <float> freq = frequencies(sousChaine);
	for ( int i = 0; i < 26; i++ ) {
		cout << " " << (char)('A'+i) << " = " << freq[i] << "\t" ;
	}
	cout << endl ;
	float indiceCoinc = coincidence(freq);
	cout << "Ic: " << indiceCoinc << "\t";
	float indiceFR = coincidenceFrancais();
	cout << "Ifrench: " << indiceFR << "\t";

	/*
	 * Afficher Indice de coincidence du texte entré
	 * dont les lettres sont tirées uniformément au hasard
	 */


	float indiceRandom = coincidenceRandom();
	cout << "Irand: " << indiceRandom << endl;

}
