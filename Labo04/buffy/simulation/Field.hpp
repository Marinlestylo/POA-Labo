#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <list>
#include "../humanoids/Humanoid.hpp"
#include "../humanoids/Vampire.hpp"

/**
 * Classe représentant le terrain de jeu contenant une liste d'humanoïdes.
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Field {
public:
   /**
    * Constructeur de base
    * @param width       valeur maximale pour la position x des humanoïdes
    * @param height      valeur maximale pour la position y des humanoïdes
    * @param nbVampires  nombre de vampires
    * @param nbHumans    nombe de humains
    * @throws runtime_error si les valeurs inserees sont nulles
    */
   Field(unsigned width, unsigned height, unsigned nbVampires, unsigned nbHumans);

   /**
    * Destructeur s'assurant de supprimer les humanoïdes de la liste
    */
   ~Field();

   /**
    * Joue un tour et effectue l'affectation des actions, leurs exécutions
    * et la suppression des humanoïdes
    * @return le nombre de tours effectués
    */
   int nextTurn();

   /**
    * @return la valeur maximale pour la position x des humanoïdes
    */
   unsigned getWidth() const;

   /**
    * @return la valeur maximale pour la position y des humanoïdes
    */
   unsigned getHeight() const;

   /**
    * @return le nombre de tours effectués
    */
   int getTurn() const;

   /**
    * @return true s'il y a encore des humains sur le terrain
    */
   bool hasHumans() const;

   /**
    * @return true s'il y a encore des vampires sur le terrain
    */
   bool hasVampires() const;

   /**
    * Retourne l'humanoïde avec l'identifiant voulu le plus proche de la position donnée
    * @param from       Position de départ
    * @param identifier Identifiant de l'humanoïde recherché
    * @return l'humanoïde le plus proche de la position donnée
    */
   Humanoid* getNearestHumanoid(Position& from, Humanoid::Identifier identifier) const;

   /**
    * @return un itérateur sur le premier humanoïde de la liste
    */
   std::list<Humanoid*>::const_iterator begin() const;

   /**
    * @return un itérateur sur le dernier humanoïde de la liste
    */
   std::list<Humanoid*>::const_iterator end() const;

   /**
    * Réduit le nombre des humanoïdes spécifiés par l'identifiant
    * @param targetIdentifier Identifiant de la population à réduire
    */
   void decreasePopulation(Humanoid::Identifier targetIdentifier);

   /**
    * Ajoute un vampire à la liste
    * @param vampire le vampire à ajouter
    */
   void addVampire(Vampire* vampire);

private:
   unsigned width, height, nbVampires, nbHumans;
   int turn;
   std::list<Humanoid*> humanoids;
};

#endif //BUFFY_FIELD_HPP
