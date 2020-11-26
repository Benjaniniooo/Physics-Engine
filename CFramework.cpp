#include "CFramework.hpp"

CFramework::CFramework(){
  windowIsAlive = false;
}

CFramework* CFramework::Framework = NULL;

CFramework* CFramework::getInstance(){
  if(Framework == NULL){
    Framework = new CFramework;
  }

  return Framework;
}

void CFramework::init(int windowWidth, int windowHeight, std::string name){
  window.create(sf::VideoMode(windowWidth, windowHeight), name);

  windowIsAlive = true;
}

void CFramework::close(){
  window.close();
}

void CFramework::display(){
  window.display();
}

void CFramework::reset(){
  window.clear();
}

void CFramework::handleWindowEvent(sf::Event::EventType windowEvent){
  if(windowEvent == sf::Event::Closed){
    close();
    windowIsAlive = false;
  }
}

sf::Event::EventType CFramework::getEvent(){
  window.pollEvent(event);
  return event.type;
}

void CFramework::renderVertex(CObject object){
  window.draw(&object.m_vertices[0], object.m_verticesCount, sf::TriangleFan);
}
