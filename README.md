Cryptographie historique 
========================

Pour compiler chiffre-vigenere, faire:
$make chiffre-vigenere

Puis pour tester:
$ cat ./fichiers/baudelaire-az.txt | ./chiffre-vigenere TOTO


---------

Pour compiler dechiffre-vigenere, faire:
$make dechiffre-vigenere

Puis pour tester:
$ cat ./fichiers/baudelaire-c1.txt | ./chiffre-vigenere YOUPI

---------

Pour compiler check-freqs, faire:
$make check-freqs

Puis pour tester:
$ cat ./fichiers/lafontaine-az.txt | ./chiffre-vigenere AZERTY | ./check-freqs 6 0

