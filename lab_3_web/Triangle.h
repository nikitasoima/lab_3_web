#pragma once
class Triangle
{
public:

	double side_1;
	double side_2;
	double angle;

	void increaseAngle(int number);
	void decreaseAngle(int number);
	double* getAngles();

	double* getBisector();
	double* sidesByBisector();
	double** getSidesByBisector();

	Triangle(double _side_1, double _side_2, double _angle_3);

private:
	double pi = 3.14159265358;
	double calculateThirdSide();
	double getRadians(double);
	double getDegr(double);
};