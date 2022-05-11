#include "bank.hpp"

Bank::Bank(std::string name, std::list<Person *> people) : Container(std::move
(name), people) {}
