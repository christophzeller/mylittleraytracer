#include "World.h"

#include <iostream>
#include <fstream>
#include "SingleSphereTracer.h"
#include "MultiObjectsTracer.h"
#include "RayCastingTracer.h"

#include "../Materials/Matte.h"
#include "../Lights/PointLight.h"
#include "../Lights/DirectionalLight.h"

#include "../Cameras/RenderTargets/PPMASCIITarget.h"

//void World::build()
//{
//	vp.setGamma(1.0);
//	vp.setPixelSize(1.0);
//	vp.setHRes(200);
//	vp.setVRes(200);
//
//	backgroundColor = RGBColor(0.0, 0.0, 0.0);
//
//	sphere.setRadius(85.0);
//	sphere.setCenter(Point3D(0.0, 0.0, 0.0));
//
//	tracer = new SingleSphereTracer(this);
//}

const double World::kHugeValue = 9999999.9;

void World::build()
{
	vp.setGamma(1.0);
	vp.setPixelSize(0.5);
	vp.setHRes(400);
	vp.setVRes(400);

	backgroundColor = RGBColor(0.0, 0.0, 0.0);

	tracer = new RayCastingTracer(this);

	RGBColor yellow(1, 1, 0);										// yellow
	RGBColor light_purple(0.65, 0.3, 1.0);							// light purple
	RGBColor lightGrey(0.3, 0.3, 0.3);
	RGBColor darkGrey(0.7, 0.7, 0.7);
	RGBColor turqoise(0.0, 0.4, 0.7);
	RGBColor blue(0.0, 1.0, 0.0);
	RGBColor darkPurple(0.5, 0.3, 0.0);

	Sphere*	sphere_ptr1 = new Sphere(Point3D(5, 3, 0), 30);
	sphere_ptr1->setColor(yellow);

	Matte* matteYellow = new Matte();
	matteYellow->setC_d(yellow);
	matteYellow->setK_a(0.25);
	matteYellow->setK_d(0.60);
	sphere_ptr1->setMaterial(matteYellow);

	Sphere*	sphere_ptr2 = new Sphere(Point3D(45, -7, -60), 20);
	sphere_ptr2->setColor(light_purple);

	Matte* mattePurple = new Matte();
	mattePurple->setC_d(light_purple);
	mattePurple->setK_a(0.25);
	mattePurple->setK_d(0.60);
	sphere_ptr2->setMaterial(mattePurple);

	Matte* matteLightGrey = new Matte();
	matteLightGrey->setC_d(lightGrey);
	matteLightGrey->setK_a(0.1);
	matteLightGrey->setK_d(0.7);

	Matte* matteDarkGrey = new Matte();
	matteDarkGrey->setC_d(darkGrey);
	matteDarkGrey->setK_a(0.1);
	matteDarkGrey->setK_d(0.7);

	Matte* matteTurqoise = new Matte();
	matteTurqoise->setC_d(turqoise);
	matteTurqoise->setK_a(0.1);
	matteTurqoise->setK_d(0.7);

	Matte* matteDarkPurple = new Matte();
	matteDarkPurple->setC_d(light_purple);
	matteDarkPurple->setK_a(0.25);
	matteDarkPurple->setK_d(0.60);

	Sphere* s3 = new Sphere(Point3D(-45, 0, -40), 30);
	s3->setMaterial(matteLightGrey);

	Sphere* s4 = new Sphere(Point3D(-15, 45, -75), 20);
	s4->setMaterial(matteTurqoise);

	Sphere* s5 = new Sphere(Point3D(-15, -35, 0), 25);
	s5->setMaterial(matteDarkGrey);

	Sphere* s6 = new Sphere(Point3D(35, 25, 15), 10);
	s6->setMaterial(matteDarkPurple);

	objects.push_back(sphere_ptr1);
	objects.push_back(sphere_ptr2);
	objects.push_back(s3);
	objects.push_back(s4);
	objects.push_back(s5);
	objects.push_back(s6);

	camera = new OrthographicCamera();
//	const char* f = "render.ppm";
	camera->setRenderTarget(new PPMASCIITarget(vp, "test.ppm"));

	ambientLight = new AmbientLight();

	PointLight* pointLight = new PointLight(Point3D(0, 0, 0), RGBColor(0.0, 0.1, 0.5));
	lights.push_back(pointLight);

	Vector3D lightDir = Vector3D(10, 75, 30);
	lightDir.normalize();
	DirectionalLight* dirLight = new DirectionalLight(lightDir);
	lights.push_back(dirLight);

}

void World::render() //const
{
  camera->renderScene(*this);
}

ShadeRec World::hitObjects(const Ray& ray) //const
{
  ShadeRec sr = ShadeRec(*this);

  double t;
  double tMin = kHugeValue;
  Normal normal;

  Point3D localHitPoint;

  int objectCount = objects.size();

  for (int i = 0; i < objectCount; i++)
  {
	// object is hit and nearer than the currently held nearest object
	if (objects[i]->hit(ray, t, sr) && (t < tMin))
	{
		sr.isObjectHit = true;
		tMin = t;
		sr.color = objects[i]->getColor();
		sr.material = objects[i]->getMaterial();
		sr.hitPoint = ray.origin + t * ray.direction;
		normal = sr.normal;
		localHitPoint = sr.localHitPoint;
		//std::cout << "hit " << sr.color << std::endl;
	}

	if (sr.isObjectHit)
	{
	  sr.t = tMin;
	  sr.normal = normal;
	  sr.localHitPoint = localHitPoint;
	}
  }

  return sr;
}

void World::paintPixel(const int row, const int column, const RGBColor& color) const
{

}

World::World(void)
{
}


World::~World(void)
{
    if (tracer)
    {
	std::cout << "deleting tracer " << std::endl;
	delete tracer;
    }

    if (camera)
    {
	std::cout << "deleting camera " << std::endl;
	delete camera;
    }

    if (ambientLight)
    {
	std::cout << "deleting ambient light " << std::endl;
	delete ambientLight;
    }

    for (unsigned int i = 0; i < objects.size(); i++)
    {
      std::cout << "deleting object " << i << "..." << std::endl;
      delete objects[i];
    }
    objects.clear();

    for (unsigned int i = 0; i < lights.size(); i++)
	{
	  std::cout << "deleting light " << i << "..." << std::endl;
	  delete lights[i];
	}
	lights.clear();
}
