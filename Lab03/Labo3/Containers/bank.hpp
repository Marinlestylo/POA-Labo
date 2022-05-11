#ifndef LABO3_BANK_HPP
#define LABO3_BANK_HPP

#include "container.hpp"

/**
 * Classe représentant une rive de la rivière
 * @author Friedli Jonathan
 * @author Jaquier Alexandre
 */
class Bank : public Container {
public:
    /**
     * Constructeur de la classe Bank
     * @param name nom de la rive
     * @param people personne se trouvant sur la rive
     */
    explicit Bank(const std::string &name);
};


#endif //LABO3_BANK_HPP
