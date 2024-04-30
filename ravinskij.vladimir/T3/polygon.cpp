#include "polygon.hpp"
#include <iterator>
#include <algorithm>
#include <limits>

std::istream& ravinskij::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  using del = ravinskij::CharDelimeter;
  Point temp{ 0, 0 };
  in >> del{ '(' } >> temp.x >> del{ ';' } >> temp.y >> del{ ')' };
  if (in)
  {
    point = temp;
  }
  else
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

std::ostream& ravinskij::operator<<(std::ostream& out, const Point& point)
{
  std::ostream::sentry guard(out);
  if (!guard)
  {
    return out;
  }
  out << '(' << point.x << ';' << point.y << ')';
  return out;
}

bool ravinskij::Point::operator==(const Point& rhs) const
{
  return (x == rhs.x) && (y == rhs.y);
}

std::istream& ravinskij::operator>>(std::istream& in, Polygon& polygon)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  std::size_t vertexCount = 0;
  in >> vertexCount;
  if (vertexCount < 3)
  {
   in.setstate(std::ios::failbit);
   return in;
  }
  std::vector< ravinskij::Point > temp;
  using input_it_t = std::istream_iterator< ravinskij::Point >;
  std::copy_n(input_it_t{ in }, vertexCount, std::back_inserter(temp));
  if(in && temp.size() == vertexCount)
  {
    polygon.points = temp;
  }
  else
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

std::ostream& ravinskij::operator<<(std::ostream& out, const Polygon& polygon)
{
  std::ostream::sentry guard(out);
  if (!guard)
  {
    return out;
  }
  using output_it_t = std::ostream_iterator< ravinskij::Point >;
  const auto& points = polygon.points;
  std::copy(points.cbegin(), points.cend(), output_it_t{ out, " "});
  return out;
}
