
// Shape.h

#include <iostream>
#include "Shape.h"

namespace sdds
{
  std::ostream &operator<<(std::ostream &ostr, const Shape &src)
  {
    src.draw(ostr);
    return ostr;
  }
  std::istream &operator>>(std::istream &istr, Shape &src)
  {
    src.getSpecs(istr);
    return istr;
  }
}
