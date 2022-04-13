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
#include "squadron.hpp"

void testShips() {
    std::cout << std::endl << "--------------------- Tests des Vaisseaux "
                              "---------------------" << std::endl << std::endl;
    std::cout << "Creation et affichage de vaisseaux" << std::endl;
    Shuttle shuttle(20);
    Dreadnought dreadnought(40);
    TieInterceptor tieInterceptor;
    TieHunter tieHunter;
    std::cout << shuttle << std::endl << std::endl <<
              dreadnought << std::endl << std::endl <<
              tieInterceptor << std::endl << std::endl <<
              tieHunter << std::endl << std::endl;
    std::cout << "Changement de nom pour Dreadnought :" << std::endl;
    dreadnought.setNickname("Dreadnought");
    std::cout << dreadnought << std::endl;

    std::cout << "Formule de consommation pour DreadNought avec une cargaison de "
                 "taille 40, la distance et la vitesse sont de 20 :" << std::endl;
    std::cout << dreadnought.getConsumption(20, 20) << std::endl;

    // Les méthodes non constantes ne peuvent pas être appelées sur une instance
    // constantes.
    std::cout << "Tests des ships constants :" << std::endl;
    const Dreadnought constantShip(40);
    std::cout << constantShip << std::endl;

}

void test() {
    testShips();

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
    std::cout << shuttle << std::endl << std::endl <<
              dreadnought << std::endl << std::endl <<
              tieInterceptor << std::endl << std::endl <<
              tieHunter << std::endl << std::endl;

    std::cout << "Ajout des vaisseaux dans le squadron1" << std::endl;
    squad1.addShipToSquadron(shuttle);
    squad1.addShipToSquadron(dreadnought);

    std::cout << squad1 << std::endl;

    std::cout << "Test du constructeur de copie (squad2)" << std::endl;
    Squadron squad2(squad1);
    std::cout << squad2 << std::endl;

    squad1.addShipToSquadron(tieInterceptor);
    squad1.addShipToSquadron(tieHunter);

    std::cout << "Test de l'opérateur d'affectation" << std::endl;
    squad2 = squad1;
    std::cout << "Squad 1" << std::endl << squad1 << std::endl;
    std::cout << "Squad 2" << std::endl << squad2 << std::endl;

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


    std::cout << "Test de la formule de consommation (avec une distance et une "
                 "vitesse de 100)" << std::endl;
    std::cout << "Consommation de l'éscadrille ne contenant qu'un TieHunter : "
              << squad1.getConsumption(100, 100) << std::endl;
    std::cout << "Consommation d'un TieHunter : " << tieHunter.getConsumption(100,
                                                                              100)
              << std::endl;
    std::cout << squad1 << std::endl << std::endl;

    std::cout << "Affichage du vaisseau 0 via la méthode get" << std::endl;
    std::cout << squad1.getShip(0) << std::endl << std::endl;

    std::cout << "Affichage d'un vaisseau en dehors des index limites via la "
                 "méthode get" << std::endl << std::endl;
    try {
        squad1.getShip(5);
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Consommation d'un squadron avec une distance ou une vitesse "
                 "invalide" << std::endl;
    try {
        squad1.getConsumption(-1, 10);
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        squad1.getConsumption(1, 1000000);
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
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