//----------------------------------------------------------------------------------------------------

#ifndef _PROGRAM_HPP_1108B19E5032E870B480E495BAA19C77
#define _PROGRAM_HPP_1108B19E5032E870B480E495BAA19C77
//----------------------------------------------------------------------------------------------------

#include "Program_fwd.hpp"

#include <map>
#include <string>

#include <OpenGL/gl3.h>
//----------------------------------------------------------------------------------------------------

namespace MD2View
{
//----------------------------------------------------------------------------------------------------

class Program
{
public:
	Program(const std::string& vStr, const std::string& fStr);

	void compile();

	void load();
	void unload();

	void addUniform(const std::string& uniform);

	template <typename T>
	void setUniform(const std::string& uniform, const T& val);

private:
	std::string vShader;
	std::string fShader;

	GLuint program;

	std::map<std::string, GLuint> uniforms;
};
//----------------------------------------------------------------------------------------------------

} // namespace MD2View
//----------------------------------------------------------------------------------------------------

#endif // _PROGRAM_HPP_1108B19E5032E870B480E495BAA19C77
//----------------------------------------------------------------------------------------------------
