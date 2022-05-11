#ifndef LABO3_CONTAINER_HPP
#define LABO3_CONTAINER_HPP

#include <string>
#include <algorithm>
#include <list>

class Person;

/**
 * Classe représentant un conteneur
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Container {
public:
    /**
     * Constructeur de la classe Container
     * @param name Nom du conteneur
     */
    explicit Container(const std::string &name);

    /**
     * Destructeur de la classe Container
     */
    virtual ~Container() = default;

    /**
     * Méthode permettant de récupérer le container sous forme affichable
     * @param os opérateur de flux
     * @return le container sous forme affichable
     */
    virtual std::ostream &toStream(std::ostream &os) const;

    /**
     * Méthode permettant de récupérer le nom des personnes du conteneur
     * @return le nom des personnes du conteneur
     */
    std::string getPeopleNames() const;

    /**
     * Méthode permettant de récupérer le nom du conteneur
     * @return le nom du conteneur
     */
    const std::string &getName() const;

    /**
     * Méthode permettant de récupérer la taille
     * @return la taille
     */
    unsigned size() const;

    /**
     * Méthode permettant de vider le container
     */
    void emptyContainer();

    /**
     * Ajoute un personnage au container
     * @throw std::runtime_error si le container est plein
     * @param p personnage à ajouter
     */
    void addPerson(const Person &p);

    /**
     * Ajoute plusieurs personnages au container
     * @throw std::runtime_error si le container est plein
     * @param people liste de personnages à ajouter
     */
    void addAll(const std::list<const Person *> &people);

    /**
     * Enlève un personne du container
     * @throw std::runtime_error si le container est vide
     * @param p personnage à enlever
     */
    void removePerson(const Person &p);

    /**
     * Méthode permettant de savoir si le container est vide
     * @return true si le container est vide, false sinon
     */
    bool isEmpty() const;

    /**
     * Méthode permettant de savoir si le container est plein
     * @return true si le container est plein, false sinon
     */
    virtual bool isFull() const;

    /**
     * Méthode permettant de savoir si un personnage est dans le container
     * @param p personnage à rechercher
     * @return true si le personnage est dans le container, false sinon
     */
    bool isMember(const Person &p) const;

    /**
     * Méthode permettant de savoir si les personnes dans le container sont toutes
     * en sécurité
     * @return true si les personnes sont en sécurité, false sinon
     */
    bool isContainerSafe() const;

    /**
     * Méthode retournant un itérateur constant sur le premier élément de la liste
     * de personnes se trouvant dans le container
     * @return un itérateur constant sur le premier élément de la liste
     */
    std::list<const Person *>::const_iterator begin() const;

    /**
     * Méthode retournant un itérateur constant sur le dernier élément de la liste
     * de personnes se trouvant dans le container
     * @return un itérateur constant sur le dernier élément de la liste
     */
    std::list<const Person *>::const_iterator end() const;

protected:
    /**
     * Méthode permettant de connaître les personnes se trouvant dans le container
     * @return la liste de personnes se trouvant dans le container
     */
    std::list<const Person *> *getPeople() const;

private:

    const std::string name;
    std::list<const Person *> people;
};


#endif //LABO3_CONTAINER_HPP
