#ifndef LABO3_BANK_HPP
#define LABO3_BANK_HPP

#include "container.hpp"

/**
 * Classe représentant une rive de la rivière
 */
class Bank : public Container {
public:
    /**
     * Constructeur de la classe Bank
     * @param name nom de la rive
     * @param people personne se trouvant sur la rive
     */
    Bank(const std::string &name, std::list<Person *> people);
};


#endif //LABO3_BANK_HPP
