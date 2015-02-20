#ifndef __GEOMETRICOBJECT
#define __GEOMETRICOBJECT

#include "../Utility/RGBColor.h"
#include "../Tracing/Ray.h"
#include "../Tracing/ShadeRec.h"
#include "../Materials/Material.h"

//class Ray;
//class ShadeRec;

class GeometricObject
{
public:
  virtual bool hit(const Ray& ray, double& tMin, ShadeRec& sr) const = 0;

  GeometricObject(void);
  virtual ~GeometricObject(void);

  inline const RGBColor& getColor() { return color; };
  inline void setColor(const RGBColor& newColor) { color = newColor; }

  inline void setMaterial(Material* newMaterial) { material = newMaterial; }
  inline Material* getMaterial() { return material; }

protected:
  RGBColor color;
  Material* material;
};

#endif
