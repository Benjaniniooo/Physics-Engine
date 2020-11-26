#include "CFramework.hpp"

CFramework* Framework = CFramework::getInstance();
CAbstractObject* AbstractObject = CAbstractObject::getInstance();

int main()
{
  CObject object;
  //object.setVertices(sf::Vertex(sf::Vector2f(100.f, 20.f), sf::Color::Red), sf::Vertex(sf::Vector2f(20.f, 20.f), sf::Color::Red), sf::Vertex(sf::Vector2f(20.f, 10.f), sf::Color::Red), sf::Vertex(sf::Vector2f(10.f, 10.f)));
  //AbstractObject->getCircle(&object, sf::Vector2f(100.f, 100.f), 50, 0.25, sf::Color::Red);
  AbstractObject->getPolygon(&object, sf::Vector2f(100.f, 100.f), 100, 5, sf::Color::Red);

  object.m_origin = sf::Vector2f(100.f, 100.f);
  object.m_mass = 10.d;

  Framework->init(600, 800, "Physics Simulation");
  while(Framework->windowIsAlive == true){
    sf::Event::EventType eventType = Framework->getEvent();
    Framework->handleWindowEvent(eventType);

    Framework->reset();
    Framework->renderVertex(object);
    Framework->display();

    for(int i = 0; i<10000000; i++);
    object.rotate(0);
    //object.setPosition(10, 10);
    object.move(0, 2);
    object.setColor(sf::Color::Green);
    object.setIndividualColor(sf::Color::Cyan, 11);
    object.setIndividualColor(sf::Color::Blue, 33);
  }
  return 0;
}
