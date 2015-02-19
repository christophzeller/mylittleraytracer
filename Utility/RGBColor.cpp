#include "RGBColor.h"
#include "math.h"

RGBColor::RGBColor(double r, double g, double b) : r(r), g(g), b(b)
{
}

RGBColor::RGBColor(void) : r(0.0), g(0.0), b(0.0)
{
}

RGBColor RGBColor::operator+(const RGBColor& other)
{
  return RGBColor(this->r + other.r, this->g + other.g, this->b + other.b);
}

RGBColor RGBColor::operator*(const float other)
{
  return RGBColor(this->r * other, this->g * other, this->b * other);
}

RGBColor RGBColor::operator*(const RGBColor& other)
{
  return RGBColor(this->r * other.r, this->g * other.g, this->b * other.b);
}

RGBColor RGBColor::operator/(const float other)
{
  return RGBColor(this->r / other, this->g / other, this->b / other);
}

RGBColor RGBColor::powc(float p) const {
	return (RGBColor(pow(r, p), pow(g, p), pow(b, p)));
}


RGBColor& RGBColor::operator=(const RGBColor& other)
{
  r = other.r;
  g = other.g;
  b = other.b;
  return *this;
}

RGBColor::~RGBColor(void)
{
}

std::ostream& operator<<(std::ostream& os, const RGBColor& c)
{
  //os << "(" << c.r << ";" << c.g << ";" << c.b << ")";
	os << (int)(c.r * 255) << " " << (int)(c.g * 255) << " " << (int)(c.b * 255) << " ";
  return os;
}
