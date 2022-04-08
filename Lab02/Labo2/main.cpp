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

void testShips(){
    std::cout << "Creation et affichage de vaisseaux" << std::endl;
    Shuttle shuttle(20);
    Dreadnought dreadnought(40);
    TieInterceptor tieInterceptor;
    TieHunter tieHunter;
    std::cout << shuttle << std::endl <<
              dreadnought << std::endl <<
              tieInterceptor<< std::endl<<
              tieHunter << std::endl;
    std::cout << "Changement de nom pour Dreadnought :" << std::endl;
    dreadnought.setNickname("Dreadnought");
    std::cout << dreadnought << std::endl;
    std::cout << "Formule de consommation pour tieHunter :" << std::endl;
    std::cout << tieHunter.getConsumption(100,100);
}

void test(){
    std::cout << "Creation d'un Squadron" << std::endl;
    Squadron squad1("test1");
    std::cout << squad1 << std::endl;

    std::cout << "Creation d'un Squadron constant" << std::endl;
    const Squadron squadStat("teststatique");
    std::cout << squadStat << std::endl;

    std::cout << "Creation de vaisseaux" << std::endl;
    Shuttle shuttle(20);
    Dreadnought dreadnought(40);
    TieInterceptor tieInterceptor;
    TieHunter tieHunter;
    std::cout << shuttle << std::endl <<
              dreadnought << std::endl <<
              tieInterceptor<< std::endl<<
              tieHunter << std::endl;

    std::cout << "Ajout des vaisseaux dans le squadron1" << std::endl;
    squad1.addShipFromSquadron(shuttle);
    squad1.addShipFromSquadron(dreadnought);
    squad1.addShipFromSquadron(tieInterceptor);
    squad1.addShipFromSquadron(tieHunter);
    std::cout << squad1 << std::endl;

    std::cout << "Test du constructeur de copie (squad2)" << std::endl;
    Squadron squad2(squad1);
    std::cout << squad2 << std::endl;
    std::cout << "Test de la suppression des vaisseaux" << std::endl;


    std::cout << "Choix du chef du squadron1 -> tieHunter" << std::endl;
    squad1.setLeader(tieHunter);
    std::cout << squad1 << std::endl;

    std::cout << "Test de la formule de consommation " << std::endl;
    squad1.getConsommation(9,0);
    std::cout << squad1 << std::endl;


    testShips();
}

int main() {
    TieHunter blackLeader;
	blackLeader.setNickname("Black leader");
	TieHunter blackTwo;
	Shuttle shuttle(23.4); // 23.4 tonnes de marchandises
	Squadron squad("Black Squadron");

    squad += blackLeader;
	squad += blackTwo;
	squad += shuttle;
    squad.setLeader(blackLeader);
	std::cout << squad << std::endl << std::endl;

    //test();
    return EXIT_SUCCESS;
}


