#include "CAbstractObject.hpp"

#define PI 3.141592653589793238462643383279

CAbstractObject* CAbstractObject::AbstractObject = NULL;

CAbstractObject* CAbstractObject::getInstance(){
  if(AbstractObject == NULL){
    AbstractObject = new CAbstractObject;
  }

  return AbstractObject;
}

void CAbstractObject::getCircle(CObject* object, sf::Vector2f origin, int radius, float step, sf::Color color){
  for(float i = 0; i <= 360; i+=step){
    float x;
    float y;

    x = origin.x + radius * cos(PI/180*i);
    y = origin.y + radius * sin(PI/180*i);

    object->m_vertices.push_back(sf::Vertex(sf::Vector2f(x, y), color));
    object->m_verticesCount += 1;
  }
}

void CAbstractObject::getPolygon(CObject* object, sf::Vector2f origin, int radius, int sides, sf::Color color){
  for(int i = 0; i < sides; i++){
    double x = radius * cos(2 * PI * i / sides) + origin.x;
    double y = radius * sin(2 * PI * i / sides) + origin.y;

    object->m_vertices.push_back(sf::Vertex(sf::Vector2f(x, y), color));
    object->m_verticesCount += 1;
  }
}
