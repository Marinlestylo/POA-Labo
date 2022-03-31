/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 17.03.2022
Description     : Fichier principal du programme permettant de tester le bon
                  fonctionnement de la classe Squadron.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include "tieHunter.hpp"
#include "tieInterceptor.hpp"
#include "dreadnought.hpp"
#include "shuttle.hpp"
#include "transporter.hpp"
#include "squadron.hpp"

int main() {
	TieHunter a;
	TieHunter b;
	TieInterceptor c;
	TieInterceptor d;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;


	Shuttle black(9);
	Shuttle black2(23.4);
	std::cout << black << std::endl;
	std::cout << black2 << std::endl;

	Dreadnought black3(144448);
	Dreadnought black4(23.4);
	std::cout << black3 << std::endl;
	std::cout << black4 << std::endl;
	/*TieHunter blackLeader;
	blackLeader.setNickname("Black leader");
	TieHunter blackTwo;
	Shuttle shuttle(23.4); // 23.4 tonnes de marchandises
	Squadron squad("Black Squadron");
	squad += blackLeader;
	squad += blackTwo;
	squad += shuttle;
	squad.setLeader(blackLeader);
	std::cout << squad << std::endl;*/
}