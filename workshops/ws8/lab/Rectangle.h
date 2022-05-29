
// Rectangle.h

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds
{
  class Rectangle : public LblShape
  {
    unsigned int m_width  {0};
    unsigned int m_height {0};

  public:
    Rectangle() {}
    Rectangle(const char *_label, int _width, int _height);
    virtual ~Rectangle() {}

    void getSpecs(std::istream &istr);
    void draw(std::ostream &ostr) const;
  };
}
#endif
