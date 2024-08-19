#pragma once //Init
#include<string>
#include<glad/glad.h>

namespace Renderer { //Create namespace and class
class ShaderProgram {
    public:
    ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
     ~ShaderProgram();
      bool isCompiled() const { return m_isCompiled; }
      bool use() const;

     private:
     
     bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);
     bool m_isCompiled = false;
     GLuint m_ID;
};
}
