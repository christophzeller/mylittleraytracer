#include "World.h"

#include <iostream>
#include <fstream>
#include "SingleSphereTracer.h"
#include "MultiObjectsTracer.h"
#include "RayCastingTracer.h"

#include "../Materials/Matte.h"
#include "../Materials/Phong.h"
#include "../Lights/PointLight.h"
#include "../Lights/DirectionalLight.h"

#include "../Geometry/Primitives/Plane.h"

#include "../Cameras/RenderTargets/PPMASCIITarget.h"
#include "../Cameras/PinholeCamera.h"

const double World::kHugeValue = 9999999.9;

void World::build()
{
	vp.setGamma(1.0);
	vp.setPixelSize(1.0);

	vp.setHRes(800);
	vp.setVRes(400);
//	vp.setHRes(800);
//	vp.setVRes(200);
	vp.setSamples(16);

	backgroundColor = RGBColor(0.7, 0.7, 0.8);

	tracer = new RayCastingTracer(this);

	RGBColor yellow(1, 1, 0);
	RGBColor light_purple(0.65, 0.3, 1.0);
	RGBColor lightGrey(0.3, 0.3, 0.3);
	RGBColor darkGrey(0.7, 0.7, 0.7);
	RGBColor turqoise(0.0, 0.4, 0.7);
	RGBColor blue(0.0, 0.0, 1.0);
	RGBColor darkPurple(0.5, 0.3, 0.0);


	Phong* shinyBlue = new Phong();
	shinyBlue->setC_d(blue);
	shinyBlue->setK_a(0.1);
	shinyBlue->setK_d(0.8);

	shinyBlue->setK_s(0.5);
	shinyBlue->setSpecularExponent(8.0);
	shinyBlue->setC_s(RGBColor(1, 1, 1));

	Matte* matteYellow = new Matte();
	matteYellow->setC_d(yellow);
	matteYellow->setK_a(0.1);
	matteYellow->setK_d(0.8);


	Phong* dullYellow = new Phong();
	dullYellow->setC_d(yellow);
	dullYellow->setK_a(0.1);
	dullYellow->setK_d(0.8);

	dullYellow->setK_s(0.1);
	dullYellow->setSpecularExponent(1.0);
	dullYellow->setC_s(RGBColor(1, 1, 1));



	Matte* mattePurple = new Matte();
	mattePurple->setC_d(light_purple);
	mattePurple->setK_a(0.25);
	mattePurple->setK_d(0.60);


	Matte* matteLightGrey = new Matte();
	matteLightGrey->setC_d(lightGrey);
	matteLightGrey->setK_a(0.1);
	matteLightGrey->setK_d(0.85);

	Matte* matteDarkGrey = new Matte();
	matteDarkGrey->setC_d(darkGrey);
	matteDarkGrey->setK_a(0.1);
	matteDarkGrey->setK_d(0.9);

	Matte* matteTurqoise = new Matte();
	matteTurqoise->setC_d(turqoise);
	matteTurqoise->setK_a(0.1);
	matteTurqoise->setK_d(0.7);

	Matte* matteDarkPurple = new Matte();
	matteDarkPurple->setC_d(light_purple);
	matteDarkPurple->setK_a(0.25);
	matteDarkPurple->setK_d(0.60);

	Phong* phongYellow = new Phong();
	phongYellow->setC_d(yellow);
	phongYellow->setK_a(0.10);
	phongYellow->setK_d(0.60);

	phongYellow->setC_s(RGBColor(1, 1, 1));
	phongYellow->setK_s(0.8);
	phongYellow->setSpecularExponent(64.0);



	Sphere*	s1 = new Sphere(Point3D(-15, 15, 80), 10);
	s1->setMaterial(matteYellow);

	Sphere*	s2 = new Sphere(Point3D(10, -10, 60), 10);
	s2->setMaterial(mattePurple);

	Sphere* s3 = new Sphere(Point3D(-5, 5, 40), 10);
	//s3->setMaterial(matteLightGrey);
	s3->setMaterial(phongYellow);

	Sphere* s4 = new Sphere(Point3D(0, 0, 20), 10);
	s4->setMaterial(matteTurqoise);

	Sphere* s5 = new Sphere(Point3D(5, -5, 0), 10);
	//s5->setMaterial(matteDarkGrey);
	s5->setMaterial(dullYellow);

	Sphere* s6 = new Sphere(Point3D(-10, 10, -20), 10);
	s6->setMaterial(matteDarkPurple);

	Sphere* s7 = new Sphere(Point3D(15, -15, -40), 10);
	s7->setMaterial(shinyBlue);

	Plane* p1 = new Plane(Point3D(0, 0, 80), Normal(0, 1, 0));
	p1->setMaterial(shinyBlue);

	Plane* p2 = new Plane(Point3D(0, 0, -80), Normal(0, 0, -1));
	p2->setMaterial(matteLightGrey);

	objects.push_back(s1);
	objects.push_back(s2);
	objects.push_back(s3);
	objects.push_back(s4);
	objects.push_back(s5);
	objects.push_back(s6);
	objects.push_back(s7);

	objects.push_back(p1);
	//objects.push_back(p2);

//	camera = new OrthographicCamera();
//	const char* f = "render.ppm";

	camera = new PinholeCamera(Point3D(0, 0, 150), Point3D(0, 0, 0), Vector3D(0, 1, 0), 50.0);
	camera->setRenderTarget(new PPMASCIITarget(vp, "phongrow.ppm"));

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
		std::cout << "deleted" << std::endl;
    }

    if (camera)
    {
		std::cout << "deleting camera " << std::endl;
		delete camera;
		std::cout << "deleted" << std::endl;
    }

    if (ambientLight)
    {
		std::cout << "deleting ambient light " << std::endl;
		delete ambientLight;
		std::cout << "deleted" << std::endl;
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
    std::cout << "clearing lights array..." << std::endl;
	lights.clear();
	std::cout << "cleared" << std::endl;
}
