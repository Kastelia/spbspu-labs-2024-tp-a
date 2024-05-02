#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "polygon.hpp"
#include "commandImpl.hpp"

namespace zakozhurnikova
{
  void area(const std::vector< Polygon >& polygons, std::istream& in, std::ostream& out);
  void max(const std::vector< Polygon >& polygons, std::istream& in, std::ostream& out);
  void min(const std::vector< Polygon >& polygons, std::istream& in, std::ostream& out);
  void count(const std::vector< Polygon >& polygons, std::istream& in, std::ostream& out);
  void intersections(const std::vector< Polygon >& polygons, std::istream& in, std::ostream& out);
  void rmecho(std::vector< Polygon >& polygons, std::istream& in, std::ostream& out);
}
#endif