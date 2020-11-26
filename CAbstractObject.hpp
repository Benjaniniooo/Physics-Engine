#include <cmath>
#include "CObject.hpp"

#ifndef CABSTRACTOBJECT_HPP
#define CABSTRACTOBJECT_HPP

class CAbstractObject{
public:
  static CAbstractObject* getInstance();

  void getCircle(CObject* object, sf::Vector2f origin, int radius, float step, sf::Color color);
  void getPolygon(CObject* object, sf::Vector2f origin, int radius, int sides, sf::Color color);

private:
  static CAbstractObject* AbstractObject;

};

#endif
