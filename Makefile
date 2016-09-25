# ajoutez vos programmes ci-dessous
PROGS_SRC=chiffre-vigenere.cpp dechiffre-vigenere.cpp check-freqs.cpp

SRC=freqs.cpp utils.cpp
OBJ=${SRC:.cpp=.o}
HEADERS=freqs.h utils.h
PROGS=${PROGS_SRC:.cxx=}
CXXFLAGS=-O3 -g -Wall


chiffre-vigenere: chiffre-vigenere.cpp ${OBJ} ${HEADERS} 
	g++ ${CXXFLAGS} $< ${OBJ} -o $@
	
dechiffre-vigenere: dechiffre-vigenere.cpp ${OBJ} ${HEADERS} 
	g++ ${CXXFLAGS} $< ${OBJ} -o $@
	
check-freqs: check-freqs.cpp ${OBJ} ${HEADERS} 
	g++ ${CXXFLAGS} $< ${OBJ} -o $@	

%.o: %.cpp %.h
	g++ ${CXXFLAGS} -c $<

clean:
	rm -f ${PROGS} ${OBJ}
