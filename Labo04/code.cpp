/**
 * Classe représentant le point d'entrée du programme
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <iostream>
#include "simulation/Simulator.hpp"
#include "displayers/ConsoleDisplayer.hpp"

#define NB_ARGS 4
#define NB_SIMULATION 10000

int main(int argc, char* argv[]) {
   unsigned values[NB_ARGS];

   if (argc != NB_ARGS + 1) {
      throw std::invalid_argument("Usage : buffy <largeur grille> <hauteur grille> <nb vampires>"
                                  " <nb humains>");
   }
   try{
       for (unsigned i = 1; i < NB_ARGS + 1; ++i) {
           if (std::stoi(argv[i]) <= 0) {
               throw std::exception();
           }
           values[i - 1] = (unsigned)std::stoi(argv[i]);
       }
   }catch (const std::exception&){ // Permet de catch les exceptions de std::stoi
		// et si la valeur est < 1
       throw std::invalid_argument("Les arguments doivent etre des nombres entiers positifs !");
   }


   unsigned width = values[0], height = values[1], nbVampires = values[2], nbHumans = values[3];
   ConsoleDisplayer displayer(width, height);

   Simulator simulator(NB_SIMULATION, width, height, nbVampires, nbHumans, displayer);
   simulator.run();

   return EXIT_SUCCESS;
}

/* ----------------------------------------------------------------------------------------------*/


#ifndef BUFFY_SIMULATOR_HPP
#define BUFFY_SIMULATOR_HPP

#include <string>
#include "../displayers/Displayer.hpp"
#include "Field.hpp"
#include "utils/Random.hpp"

/**
 * Classe contrôlant la simulation du jeu
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Simulator {
public:









   /**
    * Constructeur de base
    * @param nbSimulation nombre de simulations à effectuer
    * @param width        largeur de la grille à afficher
    * @param height       hauteur de la grille à afficher
    * @param nbVampires   nombe de vampires
    * @param nbHumans     nombe de humains
    * @param displayer    affichage de la simulation
    */
   Simulator(unsigned nbSimulation, unsigned width, unsigned height, unsigned nbVampires,
             unsigned nbHumans, Displayer& displayer);

   /**
    * Destructeur par défaut
    */
   ~Simulator() = default;

   /**
    * @return le nombre de simulations à effectuer
    */
   unsigned getNbSimulation() const;

   /**
    * Lance une session graphique de simulation avec le displayer passé dans le constructeur
    */
   void run();

   /**
    * Simule des parties sur le nombre de simulations choisies et retourne le nombre de sauvetages
    * sur le nombre de simulations effectuées
    * @return le nombre de sauvetages sur le nombre de simulations effectuées
    */
   double simulate() const;

private:
   unsigned nbSimulation, width, height, nbVampires, nbHumans;
   Field field;
   Displayer& displayer;
   bool ended;
};

#endif //BUFFY_SIMULATOR_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe contrôlant la simulation du jeu
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Simulator.hpp"

using namespace std;

Simulator::Simulator(unsigned nbSimulation, unsigned width, unsigned height, unsigned
nbVampires, unsigned nbHumans, Displayer& displayer) : nbSimulation(nbSimulation),
                                                       width(width), height(height),
                                                       nbVampires(nbVampires),
                                                       nbHumans(nbHumans),
                                                       field(width, height, nbVampires, nbHumans),
                                                       displayer(displayer), ended(false) {
}






void Simulator::run() {
   while (!ended) {
      displayer.displayGrid(field.begin(), field.end());
      displayer.displayPrompt(field.getTurn());
      ended = displayer.getInput(field, *this);
   }
}

double Simulator::simulate() const {
   int nbSaves = 0;
   for (unsigned i = 0; i < nbSimulation; ++i) {
      Field simulationField(width, height, nbVampires, nbHumans);
      while (simulationField.hasVampires()) {
         simulationField.nextTurn();
      }
      if (simulationField.hasHumans()) {
         ++nbSaves;
      }
   }
   return nbSaves / (double)nbSimulation;
}

unsigned Simulator::getNbSimulation() const {
   return nbSimulation;
}

/* ----------------------------------------------------------------------------------------------*/

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

/* ----------------------------------------------------------------------------------------------*/

/**
 * Fichier contenant les implémentations génériques de la méthode de Field.
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
template<typename T>
T* Field::getNearestHumanoid(Position& from) const {
   double shortestEuclideanDistance = std::numeric_limits<double>::max();
   T* nearestHumanoid = nullptr;
   T* temp;
   for (auto humanoid: humanoids) {
      if ((temp = dynamic_cast<T*>(humanoid)) != nullptr) {
         double euclideanDistance = Position::getEuclideanDistance(from,
                                                                   humanoid->getPosition());
         if (euclideanDistance < shortestEuclideanDistance) {
            shortestEuclideanDistance = euclideanDistance;
            nearestHumanoid = temp;
         }
      }
   }
   return nearestHumanoid;
}

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant le terrain de jeu contenant une liste d'humanoïdes.
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <stdexcept>

#include "Field.hpp"
#include "../humanoids/Human.hpp"
#include "../humanoids/Buffy.hpp"
#include "utils/Random.hpp"

using namespace std;

Field::Field(unsigned width, unsigned height, unsigned nbVampires, unsigned nbHumans)
   : width(width), height(height), nbVampires(nbVampires), nbHumans(nbHumans), turn(0) {
   if (width == 0 || height == 0 || nbHumans == 0 || nbVampires == 0) {
      throw runtime_error("Erreur: Les valeurs inserees ne peuvent pas etre nulles");
   }

   for (unsigned i = 0; i < nbHumans; i++) {
      humanoids.emplace_back(new Human((int)Random::random(width), (int)Random::random(height)));
   }

   for (unsigned i = 0; i < nbVampires; i++) {
      humanoids.emplace_back(new Vampire((int)Random::random(width), (int)Random::random(height)));
   }

   humanoids.emplace_back(new Buffy((int)Random::random(width), (int)Random::random(height)));
}






Field::~Field() {
   for (auto& humanoid: humanoids) {
      delete humanoid;
   }
}

int Field::nextTurn() {
   // Déterminer les prochaines actions
   for (auto& humanoid: humanoids)
      humanoid->setAction(*this);
   // Executer les actions
   for (auto& humanoid: humanoids)
      humanoid->executeAction(*this);
   // Enlever les humanoides tués
   for (auto it = humanoids.begin(); it != humanoids.end();)
      if (!(*it)->isAlive()) {
         delete *it; // destruction de l’humanoide référencé
         it = humanoids.erase(it); // suppression de l’élément dans la liste
      } else
         ++it;
   return turn++;
}

unsigned Field::getWidth() const {
   return width;
}

unsigned Field::getHeight() const {
   return height;
}

int Field::getTurn() const {
   return turn;
}

bool Field::hasHumans() const {
   return nbHumans > 0;
}

bool Field::hasVampires() const {
   return nbVampires > 0;
}

std::list<Humanoid*>::const_iterator Field::begin() const {
   return humanoids.begin();
}

std::list<Humanoid*>::const_iterator Field::end() const {
   return humanoids.end();
}

void Field::decreasePopulation(Humanoid* target) {
   if (dynamic_cast<Human*>(target) != nullptr) {
      nbHumans--;
   } else if (dynamic_cast<Vampire*>(target) != nullptr) {
      nbVampires--;
   }
}

void Field::addVampire(Vampire* vampire) {
   humanoids.emplace_back(vampire);
   nbVampires++;
}

/* ----------------------------------------------------------------------------------------------*/




#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <list>
#include "../humanoids/Humanoid.hpp"

class Simulator;

/**
 * Classe abstraite gérant l'affichage d'une simulation
 *
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Displayer {
public:
   /**
    * Constructeur de base
    * @param width  largeur de la grille
    * @param height hauteur de la grille
    */
   Displayer(unsigned width, unsigned height);

   /**
    * Destructeur virtuel par défaut
    */
   virtual ~Displayer() = default;

   /**
    * Affiche la grille de la simulation
    * @param begin Itérateur sur le premier élément de la liste des humanoïdes
    * @param end   Itérateur sur le dernier élément de la liste des humanoïdes
    */
   virtual void displayGrid(std::list<Humanoid*>::const_iterator begin,
                            std::list<Humanoid*>::const_iterator end) = 0;

   /**
    * Affiche le prompt
    * @param turn Nombre de tours effectués
    */
   virtual void displayPrompt(int turn) = 0;

   /**
    * Récupère de l'input de l'utilisateur
    * @param field     Field contenant les humanoïdes
    * @param simulator Simulateur actuel
    * @return true si l'utilisateur souhaite quitter la simulation
    */
   virtual bool getInput(Field& field, Simulator& simulator) = 0;

protected:
   /**
    * @return la largeur de la grille
    */
   unsigned getWidth() const;

   /**
    * @return la hauteur de la grille
    */
   unsigned getHeight() const;

private:
   const unsigned width, height;
};

#endif //BUFFY_DISPLAYER_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe abstraite gérant l'affichage d'une simulation
 *
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Displayer.hpp"

using namespace std;

Displayer::Displayer(unsigned width, unsigned height) : width(width), height(height) {
}

unsigned Displayer::getWidth() const {
   return width;
}

unsigned Displayer::getHeight() const {
   return height;
}

/* ----------------------------------------------------------------------------------------------*/

#ifndef BUFFY_CONSOLEDISPLAYER_HPP
#define BUFFY_CONSOLEDISPLAYER_HPP

#include <vector>
#include "Displayer.hpp"

/**
 * Classe gérant l'affichage d'une simulation dans une console
 *
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class ConsoleDisplayer : public Displayer {
public:
   /**
    * Constructeur de base
    * @param width  largeur de la grille
    * @param height hauteur de la grille
    */
   ConsoleDisplayer(unsigned width, unsigned height);

   void displayGrid(std::list<Humanoid*>::const_iterator begin,
                    std::list<Humanoid*>::const_iterator end) override;

   void displayPrompt(int turn) override;

   bool getInput(Field& f, Simulator& s) override;

private:
   /**
    * Met à jour la grille en itérant sur la liste des humanoïdes
    * @param begin Itérateur sur le premier élément de la liste des humanoïdes
    * @param end   Itérateur sur le dernier élément de la liste des humanoïdes
    */
   void updateGrid(std::list<Humanoid*>::const_iterator begin,
                   std::list<Humanoid*>::const_iterator end);

   std::vector<std::vector<char>> grid;
};

#endif //BUFFY_CONSOLEDISPLAYER_HPP




/**
 * Classe gérant l'affichage d'une simulation dans une console
 *
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <iostream>
#include "../simulation/Field.hpp"
#include "../simulation/Simulator.hpp"
#include "ConsoleDisplayer.hpp"

using namespace std;

ConsoleDisplayer::ConsoleDisplayer(unsigned width, unsigned height)
   : Displayer(width, height), grid(height, vector<char>(width, ' ')) {
}

void ConsoleDisplayer::displayGrid(list<Humanoid*>::const_iterator begin,
                                   list<Humanoid*>::const_iterator end) {
   updateGrid(begin, end);
   cout << "+" << string(getWidth(), '-') << "+" << endl;
   for (auto& row: grid) {
      cout << "|";
      for (auto& humanoid: row) {
         cout << humanoid;
      }
      cout << "|" << endl;
   }
   cout << "+" << string(getWidth(), '-') << "+" << endl;
}

void ConsoleDisplayer::displayPrompt(int turn) {
   cout << "[" << turn << "] q)uit s)tatistics n)ext:";
}

bool ConsoleDisplayer::getInput(Field& f, Simulator& s) {
   string input;
   getline(cin, input);
   if (input == "q") {
      return true;
   } else if (input == "s") {
      cout << "Simulating..." << endl;
      double saves = s.simulate();
      cout << "For " << s.getNbSimulation() << " simulations : succes rate of " << saves * 100
           << "%" << endl;
   } else if (input == "n" || input.empty()) {
      f.nextTurn();
   } else {
      cout << "Invalid input" << endl;
   }
   return false;
}

void ConsoleDisplayer::updateGrid(list<Humanoid*>::const_iterator begin,
                                  list<Humanoid*>::const_iterator end) {
   grid.assign(getHeight(), vector<char>(getWidth(), ' '));
   for (auto iter = begin; iter != end; ++iter) {
      grid.at((size_t)(*iter)->getPosition().getY())
         .at((size_t)(*iter)->getPosition().getX()) = (*iter)->getSymbol();
   }
}

/* ----------------------------------------------------------------------------------------------*/





#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../actions/Action.hpp"
#include "../simulation/utils/Position.hpp"

/**
 * Classe abstraite représentant un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Humanoid {
public:

   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Humanoid(int x, int y);

   /**
    * Destructeur virtual s'assurant de supprimer l'action
    */
   virtual ~Humanoid();

   /**
    * Désactive le constructeur de copie
    * @param other humanoïde à copier
    */
   Humanoid(const Humanoid& other) = delete;

   /**
    * Désactive l'opérateur d'affectation
    * @param other humanoïde à affecter
    */
   Humanoid& operator=(const Humanoid& other) = delete;

   /**
    * Retourne la position de l'humanoïde
    * @return une référence sur la position
    */
   Position& getPosition();

   /**
    * @return true si l'humanoïde est vivant
    */
   bool isAlive() const;

   /**
    * Définit l'état de l'huanoïde
    * @param isAlive nouvel état de l'humanoïde
    */
   void setAlive(bool isAlive);

   /**
    * Exécute l'action de l'humanoïde
    * @param field Field sur lequel l'action est effectuée
    */
   void executeAction(Field& field);

   /**
    * Définit l'action de l'humanoïde en fonction du contenu du field
    * @param field Field sur lequel l'action est définie
    */
   virtual void setAction(const Field& field);



   /**
    * @return un symbole représentant l'humanoïde
    */
   virtual char getSymbol() const = 0;

protected:
   static const int RANGE = 1;

   /**
    * Setter protected pour définir l'attribut newAction
    * @param newAction nouvelle newAction
    */
   void setAction(Action* newAction);

private:
   Action* action;
   bool alive;
   Position position;
};

#endif //BUFFY_HUMANOID_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe abstraite représentant un humanoïde.
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Humanoid.hpp"

Humanoid::Humanoid(int x, int y) : action(nullptr), alive(true), position(x, y) {
}

Humanoid::~Humanoid() {
   delete action;
}

Position& Humanoid::getPosition() {
   return position;
}

bool Humanoid::isAlive() const {
   return alive;
}

void Humanoid::setAlive(bool isAlive) {
   this->alive = isAlive;
}

void Humanoid::executeAction(Field& field) {
   if (action != nullptr) {
      action->execute(field);
   }
}

void Humanoid::setAction(const Field& field) {
   if (action != nullptr) {
      delete action;
      action = nullptr;
   }
}

void Humanoid::setAction(Action* newAction) {
   this->action = newAction;
}

/* ----------------------------------------------------------------------------------------------*/
#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

/**
 * Classe représentant Buffy, la chasseuse de vampire !
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Buffy : public Humanoid {
public:
   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Buffy(int x, int y);

   void setAction(const Field& field) override;

   char getSymbol() const override;
};

#endif //BUFFY_BUFFY_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant Buffy, la chasseuse de vampire !
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Buffy.hpp"
#include "../simulation/Field.hpp"
#include "../actions/MoveAction.hpp"
#include "../actions/KillAction.hpp"

Buffy::Buffy(int x, int y) : Humanoid(x, y) {
}

void Buffy::setAction(const Field& field) {
   Humanoid::setAction(field);
   if (field.hasVampires()) {
      auto target = field.getNearestHumanoid<Vampire>(getPosition());
      double distance = Position::getEuclideanDistance(getPosition(), target->getPosition());
      if (distance > RANGE) {
         Humanoid::setAction(new MoveAction(*this, target, 2));
      } else {
         Humanoid::setAction(new KillAction(target));
      }
   } else {
      Humanoid::setAction(new MoveAction(*this, nullptr, RANGE));
   }
}

char Buffy::getSymbol() const {
   return 'B';
}

/* ----------------------------------------------------------------------------------------------*/







#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

/**
 * Classe représentant un humain
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Human : public Humanoid {
public:
   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Human(int x, int y);

   void setAction(const Field& field) override;

   char getSymbol() const override;
};

#endif //BUFFY_HUMAN_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant un humain
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Human.hpp"
#include "../actions/MoveAction.hpp"

Human::Human(int x, int y) : Humanoid(x, y) {
}

void Human::setAction(const Field& field) {
   Humanoid::setAction(field);
   Humanoid::setAction(new MoveAction(*this, nullptr, RANGE));
}

char Human::getSymbol() const {
   return 'h';
}

/* ----------------------------------------------------------------------------------------------*/

#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

/**
 * Classe représentant un vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Vampire : public Humanoid {
public:
   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Vampire(int x, int y);

   void setAction(const Field& field) override;

   char getSymbol() const override;
};

#endif //BUFFY_VAMPIRE_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant un vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Vampire.hpp"
#include "../simulation/Field.hpp"
#include "../actions/MoveAction.hpp"
#include "../actions/KillAction.hpp"
#include "../actions/TransformAction.hpp"
#include "../simulation/utils/Random.hpp"
#include "Human.hpp"

Vampire::Vampire(int x, int y) : Humanoid(x, y) {
}

void Vampire::setAction(const Field& field) {
   Humanoid::setAction(field);
   if (field.hasHumans()) {
      auto target = field.getNearestHumanoid<Human>(getPosition());
      double distance = Position::getEuclideanDistance(getPosition(), target->getPosition());
      if (distance > RANGE) {
         Humanoid::setAction(new MoveAction(*this, target, RANGE));
      } else {
         if (Random::random(2)) {
            Humanoid::setAction(new KillAction(target));
         } else {
            Humanoid::setAction(new TransformAction(target));
         }
      }
   }
}

char Vampire::getSymbol() const {
   return 'V';
}

/* ----------------------------------------------------------------------------------------------*/

#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

class Field;

class Humanoid;

/**
 * Classe représentant une action effectuée par un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Action {
public:
   /**
    * Constructeur de base
    * @param target      la cible de l'action
    */
   explicit Action(Humanoid* target);

   /**
    * Destructeur virtuel par défaut
    */
   virtual ~Action() = default;

   /**
    * Exécute l'action sur le field correspondant
    * @param field Field actuel de la simulation
    */
   virtual void execute(Field& field) = 0;

protected:
   /**
    * @return un pointeur sur la cible de l'action
    */
   Humanoid* getTarget() const;

private:
   Humanoid* target;
};

#endif //BUFFY_ACTION_HPP
/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant une action effectuée par un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Action.hpp"

Action::Action(Humanoid* target) : target(target) {
}

Humanoid* Action::getTarget() const {
   return target;
}
/* ----------------------------------------------------------------------------------------------*/
#ifndef BUFFY_MOVEACTION_HPP
#define BUFFY_MOVEACTION_HPP

#include "Action.hpp"

/**
 * Classe représentant une action déplaçant un humanoïde aléatoirement ou vers une cible
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class MoveAction : public Action {
public:
   /**
    * Constructeur de base
    * @param actionMaker l'humanoïde qui effectue l'action
    * @param target      la cible de l'action
    * @param step        le nombre de pas possibles
    */
   MoveAction(Humanoid& actionMaker, Humanoid* target, unsigned step);

   void execute(Field& f) override;

private:
   Humanoid& actionMaker;
   unsigned step;
   int currentX, currentY;
};

#endif //BUFFY_MOVEACTION_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant une action déplaçant un humanoïde aléatoirement ou vers une cible
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "MoveAction.hpp"
#include "../simulation/Field.hpp"

MoveAction::MoveAction(Humanoid& actionMaker, Humanoid* target, unsigned step)
   : Action(target), actionMaker(actionMaker), step(step), currentX(0), currentY(0) {
   if (target != nullptr) {
      currentX = target->getPosition().getX();
      currentY = target->getPosition().getY();
   }
}

void MoveAction::execute(Field& f) {
   if (step != 0) {
      if (getTarget() != nullptr) {
         Position targetPosition(currentX, currentY);
         actionMaker.getPosition().setDirectedPosition(targetPosition, (int)step);
      } else {
         actionMaker.getPosition().setRandomPosition((int)f.getWidth(), (int)f.getHeight());
      }
   }
}

/* ----------------------------------------------------------------------------------------------*/


#ifndef BUFFY_KILLACTION_HPP
#define BUFFY_KILLACTION_HPP

#include "Action.hpp"

/**
 * Classe représentant une action qui tue un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class KillAction : public Action {
public:
   /**
    * Constructeur de base
    * @param target      la cible de l'action
    */
   explicit KillAction(Humanoid* target);

   void execute(Field& f) override;
};

#endif //BUFFY_KILLACTION_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant une action qui tue un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "KillAction.hpp"
#include "../simulation/Field.hpp"


KillAction::KillAction(Humanoid* target) : Action(target) {
}

void KillAction::execute(Field& f) {
   if (getTarget()->isAlive()) {
      getTarget()->setAlive(false);
      f.decreasePopulation(getTarget());
   }
}

/* ----------------------------------------------------------------------------------------------*/

#ifndef BUFFY_TRANSFORMACTION_HPP
#define BUFFY_TRANSFORMACTION_HPP

#include "Action.hpp"

/**
 * Classe représentant une action qui transforme un humanoïde en vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class TransformAction : public Action {
public:
   /**
    * Constructeur de base
    * @param target      la cible de l'action
    */
   explicit TransformAction(Humanoid* target);

   void execute(Field& f) override;
};

#endif //BUFFY_TRANSFORMACTION_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant une action qui transforme un humanoïde en vampire
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "TransformAction.hpp"
#include "../simulation/Field.hpp"

TransformAction::TransformAction(Humanoid* target) : Action(target) {
}

void TransformAction::execute(Field& f) {
   if (getTarget()->isAlive()) {
      getTarget()->setAlive(false);
      f.decreasePopulation(getTarget());
      f.addVampire(new Vampire(getTarget()->getPosition().getX(), 
							   getTarget()->getPosition().getY()));
   }
}
/* ----------------------------------------------------------------------------------------------*/

#ifndef BUFFY_POSITION_HPP
#define BUFFY_POSITION_HPP

/**
 * Classe représentant une position dans le field
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Position {
public:
   /**
    * Retourne la distance euclidienne entre deux positions
    * @param from Position de départ
    * @param to   Position de la destination
    * @return un double représentant la distance euclidienne entre deux positions
    */
   static double getEuclideanDistance(Position& from, Position& to);

   /**
    * Constructeur de base
    * @param x Position sur l'axe des x
    * @param y Position sur l'axe des y
    */
   Position(int x, int y);

   /**
    * @return la position sur l'axe des x
    */
   int getX() const;

   /**
    * @return la position sur l'axe des y
    */
   int getY() const;

   /**
    * Définit une nouvelle position aléatoire
    * @param maxX Valeur maximale sur l'axe des x
    * @param maxY Valeur maximale sur l'axe des y
    */
   void setRandomPosition(int maxX, int maxY);

   /**
    * Définit une nouvelle position se rapprochant de la position donnée
    * @param target Position cible
    * @param step   Nombre de pas possibles
    */
   void setDirectedPosition(Position& target, int step);

private :
   int x, y;
};

#endif //BUFFY_POSITION_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Classe représentant une position dans le field
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <cmath>
#include "Direction.hpp"
#include "Random.hpp"

double Position::getEuclideanDistance(Position& from, Position& to) {
   double first = abs((from.getX() - to.getX()));
   double second = abs((from.getY() - to.getY()));
   return round(hypot(first, second));
}

Position::Position(int x, int y) : x(x), y(y) {
}

int Position::getX() const {
   return x;
}

int Position::getY() const {
   return y;
}

void Position::setRandomPosition(int maxX, int maxY) {
   std::vector<const Direction*> possibleDirections;
   bool isRestricted = false;

   if (x == 0 || y == 0 || x == maxX - 1 || y == maxY - 1) {
      isRestricted = true;
      for (const Direction* s = *Direction::values();
           s <= Direction::values()[Direction::size() - 1]; s++) {
         if (x + s->getX() >= 0 && y + s->getY() >= 0 && x + s->getX() < maxX &&
             y + s->getY() < maxY) {
            possibleDirections.emplace_back(s);
         }
      }
   }

   auto& direction = isRestricted
                     ? *possibleDirections[Random::random((unsigned)possibleDirections.size())]
                     : Direction::get(Random::random(Direction::size()));
   x += direction.getX();
   y += direction.getY();
}

void Position::setDirectedPosition(Position& target, int step) {
   int newX = x, newY = y;

   for (int i = 0; i < step; i++) {
      int dirX = target.getX() - newX;
      int dirY = target.getY() - newY;

      dirX = dirX == 0 ? 0 : dirX / (abs(dirX));
      dirY = dirY == 0 ? 0 : dirY / (abs(dirY));

      newX += dirX;
      newY += dirY;
   }
   x = newX;
   y = newY;
}

/* ----------------------------------------------------------------------------------------------*/

#ifndef BUFFY_DIRECTION_HPP
#define BUFFY_DIRECTION_HPP

/**
 * Enum représentant les directions possibles d'un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Direction {
public:

   /**
    * Retourne la direction correspondant à l'index donné
    * @param index index de la direction
    * @throws std::out_of_range si l'index est trop grand
    * @return la direction correspondant à l'index donné
    */
   static const Direction& get(unsigned index);

   /**
    * @return le nombre de directions possibles
    */
   static unsigned size();

   /**
    * @return un tableau de pointeurs sur les directions possibles
    */
   static const Direction** values();

   /**
    * @return la direction sur l'axe des x
    */
   int getX() const;

   /**
    * @return la direction sur l'axe des y
    */
   int getY() const;

   /**
    * Constructeur de copie inaccessible
    */
   Direction(const Direction& other) = delete;

   /**
    * Opérateur d'affectation inaccessible
    */
   Direction& operator=(const Direction& other) = delete;

   static const Direction LEFT_UP, UP, RIGHT_UP, LEFT, RIGHT, LEFT_DOWN, DOWN, RIGHT_DOWN;

private:
   /**
    * Constructeur de base privé
    * @param x Direction sur l'axe des x
    * @param y Direction sur l'axe des y
    */
   Direction(int x, int y);

   static unsigned COUNT;
   static const Direction* DIRECTIONS[];
   int x, y;
};

#endif //BUFFY_DIRECTION_HPP

/* ----------------------------------------------------------------------------------------------*/

/**
 * Enum représentant les directions possibles d'un humanoïde
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include <stdexcept>
#include "Direction.hpp"

const Direction Direction::LEFT_UP(-1, -1);
const Direction Direction::UP(0, -1);
const Direction Direction::RIGHT_UP(1, -1);
const Direction Direction::LEFT(-1, 0);
const Direction Direction::RIGHT(1, 0);
const Direction Direction::LEFT_DOWN(-1, 1);
const Direction Direction::DOWN(0, 1);
const Direction Direction::RIGHT_DOWN(1, 1);

unsigned Direction::COUNT = 0;

const Direction* Direction::DIRECTIONS[]{
   &LEFT_UP, &UP, &RIGHT_UP, &LEFT, &RIGHT, &LEFT_DOWN, &DOWN, &RIGHT_DOWN
};

const Direction& Direction::get(unsigned index) {
   if (index >= COUNT) {
      throw std::out_of_range("Erreur: L'index est trop grand");
   }
   return *DIRECTIONS[index];
}

unsigned Direction::size() {
   return COUNT;
}

const Direction** Direction::values() {
   return DIRECTIONS;
}

int Direction::getX() const {
   return x;
}

int Direction::getY() const {
   return y;
}

Direction::Direction(int x, int y) {
   this->x = x;
   this->y = y;
   COUNT++;
}
/* ----------------------------------------------------------------------------------------------*/

#ifndef BUFFY_RANDOM_HPP
#define BUFFY_RANDOM_HPP

#include <string>
#include <random>
#include "../../humanoids/Humanoid.hpp"

/**
 * Classe helper générant des nombres aléatoires
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */
class Random {
public:
   /**
    * Retourne un entier aléatoire entre 0 et la valeur maximale non-comprise
    * @param max Valeur maximale
    * @return un entier aléatoire entre 0 et la valeur maximale non-comprise
    */
   static unsigned random(unsigned max);

   /**
    * Constructeur de copie inaccessible
    */
   Random(Random& other) = delete;

   /**
    * Opérateur d'affectation inaccessible
    */
   void operator=(Random& other) = delete;

private:
   /**
    * Constructeur de base privé
    */
   Random() = default;

   static std::mt19937 engine;
};

#endif //BUFFY_RANDOM_HPP

/* ----------------------------------------------------------------------------------------------*/


/**
 * Classe helper générant des nombres aléatoires
 * @author Jonathan Friedli
 * @author Lazar Pavicevic
 */

#include "Random.hpp"
#include <chrono>

using namespace std;

mt19937 Random::engine((unsigned)chrono::system_clock::now().time_since_epoch().count());

unsigned Random::random(unsigned max) {
   uniform_int_distribution<unsigned> distribution(0, max - 1);
   return distribution(engine);
}