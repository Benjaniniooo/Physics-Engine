#ifndef CDYNAMICS_HPP
#define CDYNAMICS_HPP

#include<SFML/Window.hpp>

class CDynamics{
public:
  CDynamics();

  double m_mass;
  sf::Vector2f m_velocity;
  sf::Vector2f m_acceleration;
  sf::Vector2f m_centerOfMass;
  sf::Vector2f m_force;
};

#endif
