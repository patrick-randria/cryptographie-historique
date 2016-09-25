#include <string>
#include <iostream>
#include <sstream>
#include "utils.h"
#include "freqs.h"

using namespace std;

string readInput( istream & in )
{
	ostringstream s( ostringstream::out );
	char c;
	in >> c;
	while ( in.good() )
	{
		s << c;
		in >> c;
	}
	return s.str();
}

string filter_az( const std::string & s )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = 0; i < s.size(); ++i )
    {
      char c = s[ i ];
      if ( ( c >= 'a' ) && ( c <= 'z' ) )
	s2 << c;
      else if ( ( c >= 'A' ) && ( c <= 'Z' ) )
	s2 << (char) ( c-'A'+'a' );
    }
  return s2.str();
}

string filter_AZ( const std::string & s )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = 0; i < s.size(); ++i )
    {
      char c = s[ i ];
      if ( ( c >= 'a' ) && ( c <= 'z' ) )
	s2 << (char) ( c-'a'+'A' );
      else if ( ( c >= 'A' ) && ( c <= 'Z' ) )
	s2 << c;
    }
  return s2.str();
}

string subtext( const string & s, int every, int shift )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = shift; i < s.size(); i += every )
    s2 << s[ i ];
   return s2.str(); 
}

string chiffreVigenere( const string & clair, const string & cle ){

	// Enlever toute les ponctuations dans le texte s'il y en a
	string texteClair = filter_AZ(clair);
	string cleMajuscule = cle;

	// La variable j représente la position de la lettre à utiliser dans la clé
	int j = 0;
	for (int i = 0; i < texteClair.length(); i++)
	{
		texteClair[i] += cleMajuscule[j] - 'A';
		if (texteClair[i] > 'Z') { texteClair[i] += -'Z' + 'A' - 1; }
		j = (j + 1 == cleMajuscule.length()) ? 0 : j + 1;
	}

	return texteClair;

}

string dechiffreVigenere( const string & chiffre, const string & cle ) {
	string texteChiffre = chiffre;
	string cleTmp = cle;

	transform(texteChiffre.begin(), texteChiffre.end(), texteChiffre.begin(), ::toupper);
	std::transform(cleTmp.begin(), cleTmp.end(), cleTmp.begin(), ::toupper);
	int j = 0;
	for (int i = 0; i < texteChiffre.length(); i++)
	{
		if (isalpha(texteChiffre[i]))
		{
			texteChiffre[i] = texteChiffre[i] >= cleTmp[j] ?
					texteChiffre[i] - cleTmp[j] + 'A' :
				'A' + ('Z' - cleTmp[j] + texteChiffre[i] - 'A') + 1;
		}
		j = j + 1 == cleTmp.length() ? 0 : j + 1;
	}

	return texteChiffre;
}

vector<float> frequencies( const string & s ){

	int stringLength = s.length();
	vector<float> freq (26, 0.0f);

	for ( int i = 0; i < stringLength; i++ ) {
		freq[s[i] - 'A']++ ;
	}

	for ( int i = 0; i < 26; i++ ) {
		 freq[i] = freq[i] / stringLength ;
	}

	return freq;

}

float coincidence( const vector<float> & freq ) {

	float indice = 0.0 ;
	for (int i=0; i<26; ++i) {
		indice += freq[i] * freq[i];
	}
	return indice  ;
}
float coincidenceFrancais(){
	vector<float> tabFreqLettresFr = frequenciesFrench();
	float indice = 0.0 ;
	for (int i=0; i<26; ++i) {
		indice += tabFreqLettresFr[i] * tabFreqLettresFr[i];
	}
	return indice  ;
}

float coincidenceRandom(){
	vector<float> tabFreqLettres = frequenciesRandom();
	float indice = 0.0 ;
	for (int i=0; i<26; ++i) {
		indice += tabFreqLettres[i] * tabFreqLettres[i];
	}
	return indice  ;
}

bool verifierSiProcheCoincidenceFR(const string & texte, int i, int j ){
		vector <float> freqTexte = frequencies(subtext( texte, i, j ));
		float Ic = coincidence(freqTexte);
		float Ifrench = coincidenceFrancais();
		float Irand = coincidenceRandom();
		if (Ic > ((Ifrench-Irand)/2)) { return true; }
		else { return false; }
}


