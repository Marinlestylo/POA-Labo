#include <iostream>
#include "season.hpp"

using namespace std;

int main() {
    const Season& season = Season::Spring;
    for (int i = 0; i < Season::size(); i++)
        cout << Season::get(i).name() << endl;
    for (const Season* s = *Season::values();
         s <= Season::values()[Season::size() - 1]; s++)
        cout << s->name() << " " << s->index() << " "
             << s->next().name() << endl;
}
