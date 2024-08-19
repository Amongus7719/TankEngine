#include "ShaderProgram.h"
#include<iostream>

namespace Renderer{
    ShaderProgram::ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
    {
     {
        GLuint vertexShaderID;
        if(createShader(vertexShader,GL_VERTEX_SHADER, vertexShaderID))
        {
            std::cerr << "VERTEX SHADER compile-time error" << std::endl;
            return;
        }
     }

      {
        GLuint fragmentShaderID;
        if(createShader(fragmentShader,GL_FRAGMENT_SHADER, fragmentShaderID))
        {
            std::cerr << "FRAGMENT SHADER compile-time error" << std::endl;
            glDeleteShader(fragmentShaderID);
            return;
        }
        else {
            m_isCompiled = true;
        }
     }
    
     m_ID = glCreateProgram();
     glAttachShader(m_ID, vertexShaderID);
     glAttachShader(m_ID, fragmentShaderID);
     glLinkProgram(m_ID);
     GLint succses;   
     glGetProgramiv(m_ID, GL_LINK_STATUS, &succses);

        if(!succses)
        {
            GLchar infolog[1024];
                glGetShaderInfoLog(m_ID,1024,nullptr,infolog);
                std::cerr << "ERROR::SHADER: Link time error:\n" << infolog << std::endl;
        }

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
    }
   bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID)
        {
            shaderID = glCreateShader(shaderType);
            const char* code = source.c_str();
            glShaderSource(shaderID, 1, &code, nullptr);
            glCompileShader(shaderID);

            GLint succses;
            glGetShaderiv(shaderID, GL_COMPILE_STATUS, &succses);
            if(!succses)
            {
                GLchar infolog[1024];
                glGetShaderInfoLog(shaderID,1024,nullptr,infolog);
                std::cerr << "ERROR::SHADER: Compile time error:\n" << infolog << std::endl;
                return false;
            }
            return true;
        } 
        ShaderProgram::~ShaderProgram()
        {
            glDeleteShader
        }
}
