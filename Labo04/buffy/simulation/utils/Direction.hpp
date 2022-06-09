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
