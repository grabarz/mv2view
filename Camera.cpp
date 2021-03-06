//----------------------------------------------------------------------------------------------------

#include "Camera.hpp"

#include <cmath>

#include "Quaternion.hpp"
//----------------------------------------------------------------------------------------------------

namespace MD2View
{
//----------------------------------------------------------------------------------------------------

Camera::Camera(const Vector3<float>& pos, const Vector3<float>& dir, const Vector3<float>& u)
	: position {pos}
	, direction {dir}
	, up {u}
	, matrix {1.0}
	, orientation {1.0}
	, translation {1.0}
{
	
}
//----------------------------------------------------------------------------------------------------

void Camera::forward()
{
	acceleration.inc(direction);
}
//----------------------------------------------------------------------------------------------------

void Camera::backward()
{
	acceleration.dec(direction);
}
//----------------------------------------------------------------------------------------------------

void Camera::rotateLeft()
{
	Quaternion<float> quat {up, -M_PI / 100.0};

	direction = quat.mul(direction);
}
//----------------------------------------------------------------------------------------------------

void Camera::rotateRight()
{
	Quaternion<float> quat {up, M_PI / 100.0};

	direction = quat.mul(direction);
}
//----------------------------------------------------------------------------------------------------

void Camera::strafeLeft()
{
	Vector3<float> strafe = Vector3<float>::crossProduct(up, direction);

	strafe.normalize();
	acceleration.inc(strafe);
}
//----------------------------------------------------------------------------------------------------

void Camera::strafeRight()
{
	Vector3<float> strafe = Vector3<float>::crossProduct(direction, up);

	strafe.normalize();
	acceleration.inc(strafe);
}
//----------------------------------------------------------------------------------------------------

void Camera::lookUp()
{
}
//----------------------------------------------------------------------------------------------------

void Camera::lookDown()
{
}
//----------------------------------------------------------------------------------------------------

void Camera::moveUp()
{
	acceleration.inc(up);
}
//----------------------------------------------------------------------------------------------------

void Camera::moveDown()
{
	acceleration.dec(up);
}
//----------------------------------------------------------------------------------------------------

void Camera::update(float dt)
{
	position.inc(velocity, dt);
	velocity.inc(acceleration, dt).mul(std::powf(damping, dt));
	acceleration.mul(0.92);

	updateMatrix();
}
//----------------------------------------------------------------------------------------------------

const Matrix4<float>& Camera::getMatrix() const
{
	return matrix;
}
//----------------------------------------------------------------------------------------------------

void Camera::updateMatrix()
{
	typedef Vector3<float> V3;

	V3 viewDir(direction);
	viewDir.normalize();

	V3 viewSide = V3::crossProduct(viewDir, up);
	viewSide.normalize();

	V3 viewUp = V3::crossProduct(viewDir, viewSide); // or viewDir * viewSide

	translation[At<4>(0, 3)] = -position[0];
	translation[At<4>(1, 3)] = -position[1];
	translation[At<4>(2, 3)] = -position[2];

	orientation[At<4>(0, 0)] = viewSide[0];
	orientation[At<4>(0, 1)] = viewSide[1];
	orientation[At<4>(0, 2)] = viewSide[2];

	orientation[At<4>(1, 0)] = viewUp[0];
	orientation[At<4>(1, 1)] = viewUp[1];
	orientation[At<4>(1, 2)] = viewUp[2];

	orientation[At<4>(2, 0)] = -viewDir[0];
	orientation[At<4>(2, 1)] = -viewDir[1];
	orientation[At<4>(2, 2)] = -viewDir[2];

	matrix = Matrix4<float>::multiply(orientation, translation);
}
//----------------------------------------------------------------------------------------------------

} // namespace MD2View
//----------------------------------------------------------------------------------------------------
