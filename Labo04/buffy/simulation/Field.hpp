#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <list>
#include <limits>
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
    * Désactive le constructeur de copie
    * @param other field à copier
    */
   Field(const Field& other) = delete;

   /**
    * Désactive l'opérateur d'affectation
    * @param other field à affecter
    */
   Field &operator=(const Field& other) = delete;

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
    * @return un itérateur sur le premier humanoïde de la liste
    */
   std::list<Humanoid*>::const_iterator begin() const;

   /**
    * @return un itérateur sur le dernier humanoïde de la liste
    */
   std::list<Humanoid*>::const_iterator end() const;

   /**
    * Retourne l'humanoïde avec l'identifiant voulu le plus proche de la position donnée
    * @tparam T   Type de l'humanoïde recherché
    * @param from Position de départ
    * @return l'humanoïde le plus proche de la position donnée
    */
   template<typename T>
   T* getNearestHumanoid(Position& from) const;

   /**
    * Réduit le nombre des humanoïdes spécifiés
    * @param target l'humanoïde dont il faut diminuer la population
    */
   void decreasePopulation(Humanoid* target);

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

#include "Field_Impl.hpp"

#endif //BUFFY_FIELD_HPP
