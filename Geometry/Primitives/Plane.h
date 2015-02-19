#ifndef __PLANE
#define __PLANE

#include "../GeometricObject.h"
#include "../../Utility/Point3D.h"
#include "../../Utility/Normal.h"


//class Ray;
//class ShadeRec;

class Plane :
  public GeometricObject
{
public:
  virtual bool hit(const Ray& ray, double& tMin, ShadeRec& sr) const;

  Plane(void);
  Plane(const Point3D& point, const Normal& normal);
  virtual ~Plane(void);

private:
  Point3D point;
  Normal normal;
  static const double kEpsilon;
};

#endif
