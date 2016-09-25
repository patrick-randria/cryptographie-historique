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

	int cleMaxLength = texteCrypte.length() / 10 ;
	float indiceFR = coincidenceFrancais();
	float indiceRandom = coincidenceRandom();

	for(int n=0 ; n <= cleMaxLength ; n++) {
		int nbFR = 0;
		for(int shift=0; shift<n ; shift++) {
			if (verifierSiProcheCoincidenceFR(texteCrypte, n, shift)) { nbFR++; }
		}
		if (nbFR == n) { // c'est probalement la bonne taille
			vector<char> cle(n);
			for(int i=0 ; i<n ; i++) {
				for(char l = 'A' ; l <= 'Z' ; l++) {

				}
			}
		}



	}

}
