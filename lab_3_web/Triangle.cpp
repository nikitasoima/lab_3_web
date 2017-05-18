#include "stdafx.h"
#include "Triangle.h"
#include "math.h"

using namespace std;




Triangle::Triangle(double _side_1, double _side_2, double _angle){
	side_1 = _side_1;
	side_2 = _side_2;
	angle = getRadians(_angle);

}

void Triangle::increaseAngle(int number) {
	angle = getRadians(getDegr(angle) * number);
}

void Triangle::decreaseAngle(int number) {
	angle = getRadians(getDegr(angle) / number);
}

double* Triangle::getAngles() {
	double *angles = new double[3];
	double side_3 = calculateThirdSide();

	angles[0] = getDegr(angle);
	angles[1] = getDegr(acos((pow(side_1, 2) + pow(side_3, 2) - pow(side_2, 2)) / (2 * side_1 * side_3)));
	angles[2] = getDegr(acos((pow(side_2, 2) + pow(side_3, 2) - pow(side_1, 2)) / (2 * side_2 * side_3)));

	return angles;
}

double Triangle::calculateThirdSide() {
	return sqrt(pow(side_1, 2) + pow(side_2, 2) - 2 * side_1 * side_2 * cos(angle));
}

double* Triangle::getBisector(){
	double *bisector = new double[3];
	double side_3 = calculateThirdSide();

	bisector[0] = sqrt((side_2 * side_3 * (side_2 + side_3 + side_1) * (side_2 + side_3 - side_1))) / (side_2 + side_3);
	bisector[1] = sqrt((side_1 * side_3 * (side_1 + side_3 + side_2) * (side_1 + side_3 - side_2))) / (side_1 + side_3);
	bisector[2] = sqrt((side_1 * side_2 * (side_1 + side_2 + side_3) * (side_1 + side_2 - side_3))) / (side_1 + side_2);

	return bisector;
}

double** Triangle::getSidesByBisector(){
	double **sides = new double*[3];
	for (int count = 0; count < 3; count++)
		sides[count] = new double[2];

	double side_3 = calculateThirdSide();

	sides[0][0] = (side_1 * side_3) / (side_1 + side_2); //3 сторона
	sides[0][1] = side_3 - sides[0][0];

	sides[1][0] = (side_1 * side_2) / (side_1 + side_3); //2 сторона
	sides[1][1] = side_2 - sides[1][0];

	sides[2][0] = (side_3 * side_1) / (side_1 + side_3); //1 сторона
	sides[2][1] = side_1 - sides[2][0];

	return sides;

}

double Triangle::getRadians(double _angle) {
	return (_angle * pi) / 180;
}

double Triangle::getDegr(double _angle) {
	return (_angle * 180) / pi;
}

