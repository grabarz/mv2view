//----------------------------------------------------------------------------------------------------

#ifndef _FRUSTUM_HPP_9EF95D7F38B75DA5C42325F396416D10
#define _FRUSTUM_HPP_9EF95D7F38B75DA5C42325F396416D10
//----------------------------------------------------------------------------------------------------

#include "Frustum_fwd.hpp"

#include "Matrix4.hpp"
//----------------------------------------------------------------------------------------------------

namespace MD2View
{
//----------------------------------------------------------------------------------------------------

class Frustum
{
public:
	Frustum();

	void update(double dt);
	const Matrix4<float>& getMatrix() const;

private:
	Matrix4<float> matrix;
};
//----------------------------------------------------------------------------------------------------

} // namespace DasModel
//----------------------------------------------------------------------------------------------------

#endif // _FRUSTUM_HPP_9EF95D7F38B75DA5C42325F396416D10
//----------------------------------------------------------------------------------------------------