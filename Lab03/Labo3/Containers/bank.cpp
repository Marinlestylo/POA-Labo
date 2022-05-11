#include "bank.hpp"

Bank::Bank(const std::string &name, std::list<Person *> people) : Container(name,
                                                                            people) {}
