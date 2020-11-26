#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "CAbstractObject.hpp"

#ifndef CFRAMEWORK_HPP
#define CFRAMEWORK_HPP

class CFramework{
public:
  CFramework();
  void init(int windowWidth, int windowHeight, std::string name);
  void reset();
  void renderVertex(CObject object);
  void display();
  void close();

  sf::Event::EventType getEvent();
  sf::Event getKeyPressed();
  void handleWindowEvent(sf::Event::EventType windowEvent);

  static CFramework* getInstance();

  bool windowIsAlive;

protected:
  sf::RenderWindow window;
  sf::Event event;

private:
  static CFramework* Framework;
};

#endif
