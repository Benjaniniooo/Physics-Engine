#include <SFML/Graphics.hpp>
#include <cmath>
#include "CDynamics.hpp"

#ifndef COBJECT_HPP
#define COBJECT_HPP

class CObject : public CDynamics{
public:
  CObject();

  void setVertices(void);

  template <typename T, typename... Ts>
  void setVertices(T vertex, Ts... vertex1);
  void setColor(sf::Color color);
  void setIndividualColor(sf::Color color, int number);
  void setPosition(sf::Vector2f position);
  void setOrigin(sf::Vector2f origin);
  void rotate(int degree);
  void move(double x, double y);

  int m_verticesCount;
  std::vector<sf::Vertex> m_vertices;

  int m_rotation;
  sf::Vector2f m_origin;
};

#endif

#include "CObject.tpp"
