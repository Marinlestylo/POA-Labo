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
    std::cout << std::endl << "--------------------- Tests des Vaisseaux "
                              "---------------------" << std::endl << std::endl;
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
    std::cout << tieHunter.getConsumption(100,100) << std::endl;

    // Les méthodes non constantes ne peuvent pas être appelées sur une instance
    // constantes.
    std::cout << "Tests des ships constants :" << std::endl;
    const Dreadnought constantShip(40);
}

void test(){
    std::cout << std::endl << "--------------------- Tests des Squadrons "
                              "---------------------" << std::endl << std::endl;

    std::cout << "Creation d'un Squadron" << std::endl;
    Squadron squad1("test1");
    std::cout << squad1 << std::endl;

    std::cout << "Creation d'un Squadron constant" << std::endl;

    // Les méthodes non constantes ne peuvent pas être appelées sur une instance
    // constantes.
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

    std::cout << "Test de la suppression des vaisseaux (shuttle est enlevé 2X)" <<
    std::endl;
    squad1.removeShipFromSquadron(shuttle);
    squad1.removeShipFromSquadron(shuttle);
    squad1.removeShipFromSquadron(dreadnought);
    squad1.removeShipFromSquadron(tieInterceptor);
    squad1.removeShipFromSquadron(tieHunter);
    std::cout << squad1 << std::endl;


    std::cout << "Choix du chef du squadron1 -> tieHunter" << std::endl;
    squad1.setLeader(tieHunter);
    std::cout << squad1 << std::endl;


    std::cout << "Test de la formule de consommation (cf. test de la consommation "
                 "du vaisseau tieHunter)" << std::endl;
    std::cout << squad1.getConsommation(100,100) << std::endl;
    //TODO le calcul est arrondi c'est chelou
    std::cout << squad1 << std::endl;

    std::cout << "Affichage du vaisseau 0 via la méthode get" << std::endl;
    std::cout << squad1.getShip(0) << std::endl;

    std::cout << "Affichage d'un vaisseau en dehors des index limites via la "
                 "méthode get" << std::endl;
    try {
        squad1.getShip(5);
    } catch (std::out_of_range &e) {
        std::cout << "Une erreur out_of_range à bien été lancée" << std::endl
        << std::endl;
    }

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

    test();
    return EXIT_SUCCESS;
}


