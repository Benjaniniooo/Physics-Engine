template <typename T, typename... Ts>
void CObject::setVertices(T vertex, Ts... vertex1){
  m_vertices.push_back((sf::Vertex) vertex);
  m_verticesCount += 1;

  setVertices(vertex1...);
}
