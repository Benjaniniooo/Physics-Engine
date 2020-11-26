#include "CObject.hpp"

#define PI 3.141592653589793238462643383279

CObject::CObject(void){
  m_verticesCount = 0;
}

void CObject::setVertices(void){}

void CObject::setColor(sf::Color color){
  for(int i = 0; i < m_verticesCount; i++){
    m_vertices[i].color = color;
  }
}

void CObject::setOrigin(sf::Vector2f o){
  m_origin.x = o.x;
  m_origin.y = o.y;
}

void CObject::setPosition(sf::Vector2f position){
  double x = position.x - m_origin.x;
  double y = position.y - m_origin.y;

  for(int i = 0; i < m_vertices.size(); i++) {
    m_vertices[i].position.x += x;
    m_vertices[i].position.y += y;
  }

  m_origin.x = position.x;
  m_origin.y = position.y;
}

void CObject::move(double x, double y){
  for(int i = 0; i < m_vertices.size(); i++){
    m_vertices[i].position.x += x;
    m_vertices[i].position.y += y;
  }

  m_origin.x += x;
  m_origin.y += y;
}

void CObject::rotate(int degree){
  for(int i = 0; i < m_vertices.size(); i++){
    double c = cos((PI / 180) * degree);
    double s = sin((PI / 180) * degree);

    double x = c * (m_vertices[i].position.x - m_origin.x) - s * (m_vertices[i].position.y - m_origin.y) + m_origin.x;
    double y = s * (m_vertices[i].position.x - m_origin.x) + c * (m_vertices[i].position.y - m_origin.y) + m_origin.y;

    m_vertices[i].position.x = x;
    m_vertices[i].position.y = y;
  }
}

void CObject::setIndividualColor(sf::Color color, int number){
  if(m_vertices.size() >= number){
    m_vertices[number-1].color = color;
  }else{
    while(number >= m_vertices.size()){
      number -= m_vertices.size();
    }

    m_vertices[number-1].color = color;
  }
}
