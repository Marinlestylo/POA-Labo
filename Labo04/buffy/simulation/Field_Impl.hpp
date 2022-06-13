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
