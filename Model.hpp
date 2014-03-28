//----------------------------------------------------------------------------------------------------

#ifndef _MODEL_HPP_B1C1300B15B30290444BBD943D016431
#define _MODEL_HPP_B1C1300B15B30290444BBD943D016431
//----------------------------------------------------------------------------------------------------

#include "Model_fwd.hpp"

#include <string>
#include <vector>

#include <OpenGL/gl3.h>
//----------------------------------------------------------------------------------------------------

namespace MD2View
{
//----------------------------------------------------------------------------------------------------

// Descriptors of loaded objects
//----------------------------------------------------------------------------------------------------

struct Model
{
	std::vector<GLuint> vaos;
	GLsizei indices;
};
//----------------------------------------------------------------------------------------------------

} // namespace MD2View
//----------------------------------------------------------------------------------------------------

#endif // _MODEL_HPP_B1C1300B15B30290444BBD943D016431
//----------------------------------------------------------------------------------------------------
