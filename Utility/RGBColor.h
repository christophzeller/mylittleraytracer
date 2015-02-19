#ifndef __RGBCOLOR
#define __RGBCOLOR

#include <iostream>

class RGBColor
{
public:
  RGBColor powc(float p) const;

  RGBColor operator+(const RGBColor& other);
  RGBColor operator*(const float other);
  RGBColor operator*(const RGBColor& other);
  RGBColor operator/(const float other);

  RGBColor& operator=(const RGBColor& other);
  RGBColor& operator+=(const RGBColor& other);

  bool operator==(const RGBColor& other) const;

  RGBColor(double r, double g, double b);
  RGBColor(void);
  ~RGBColor(void);

  //friend RGBColor operator*(const float lhs, const RGBColor& rhs);
  friend std::ostream& operator<<(std::ostream& os, const RGBColor& c);

private:
  double r, g, b;
};

inline bool RGBColor::operator==(const RGBColor& other) const
{
  return ((r == other.r) && (g == other.g) && (b == other.b));
}

#endif
