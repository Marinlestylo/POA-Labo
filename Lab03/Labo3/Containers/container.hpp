#ifndef LABO3_CONTAINER_HPP
#define LABO3_CONTAINER_HPP


#include <string>
#include <algorithm>
#include <list>

class Person;
class Container {
public:
    Container(std::string name, std::list<Person *>& people);

    virtual ~Container() = default;

    virtual std::ostream& toStream(std::ostream& os) const;

    std::string getPeopleNames() const;

    const std::string &getName() const;

    int size() const;

    void emptyContainer();

    /**
     * Ajoute un personnage au container
     * @throw std::runtime_error si le container est plein
     * @param p personnage à ajouter
     */
    void addPerson(Person &p);

    /**
     * Enlève un personne du container
     * @throw std::runtime_error si le container est vide
     * @param p personnage à enlever
     */
    void removePerson(Person &p);

    bool isEmpty() const;

    virtual bool isFull() const;

    bool isMember(const Person &p) const;

    bool isContainerSafe();

    std::list<Person*>::const_iterator begin() const;

    std::list<Person*>::const_iterator end() const;

protected:
    std::list<Person *> *getPeople() const;

private:

    std::string name;
    std::list<Person *> people;
};


#endif //LABO3_CONTAINER_HPP
