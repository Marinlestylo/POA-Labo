#ifndef LABO3_BOAT_HPP
#define LABO3_BOAT_HPP

#include "bank.hpp"
#include "container.hpp"

/**
 * Classe représentant un bateau
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Boat : public Container {
public:
    /**
     * Constructeur de la classe Boat
     * @param current rive sur laquelle le bateau se trouve
     */
    explicit Boat(const Bank &current);

    /**
     * Méthode permettant de déplacer le bateau sur une autre rive
     * @param bank La nouvelle rive
     * @return true si le déplacement a réussi, false sinon
     */
    bool moveBoat(Bank &bank);

    /**
     * Méthode permettant de savoir sur quelle rive le bateau se trouve
     * @param bank rive à checker
     * @return true si le bateau se trouve sur la rive, false sinon
     */
    bool isDockedOnthisBank(const Bank &bank) const;

    /**
     * Méthode permettant de récupérer le bateau sous forme affichable
     * @param os opérateur de sortie
     * @return le bateau sous forme affichable
     */
    std::ostream &toStream(std::ostream &os) const override;

    /**
     * Méthode permettant de savoir si une personne est dans le bateau
     * @param person Personne à rechercher
     * @return true si la personne est dans le bateau, false sinon
     */
    bool isOnBank(const Person& person) const;

    /**
     * Méthode permettant de savoir si le bateau est rempli
     * @return true si le bateau est rempli, false sinon
     */
    bool isFull() const override;

private:
    const Bank *currentBank;
    static const std::string RIVER;
    static const int MAX_CAPACITY = 2;
};


#endif //LABO3_BOAT_HPP
