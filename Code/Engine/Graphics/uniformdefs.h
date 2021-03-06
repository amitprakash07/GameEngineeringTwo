#ifndef __UNIFORM_DEFS_H
#define __UNIFORM_DEFS_H

#include "typedefs.h"
#include "../Core/Maths/Matrix4x4.h"
#include <stdint.h>
#include <string>
#include "../../Externals/OpenGLExtensions/OpenGlExtensions.h"


namespace Engine
{
	namespace Graphics
	{
		struct VectorStruct
		{
			float x;
			float y;
			float z;
			float w;
			VectorStruct();
			VectorStruct(VectorStruct & iVectorStruct);
		};

		enum UniformDataType :uint8_t
		{
			Bool = 0,
			BoolArray = 1,
			Int = 2,
			IntArray = 3,
			Float = 4,
			FloatArray = 5,
			Matrix = 6,
			MatrixArray = 7,
			Vector = 8,
			VectorArray = 9,
			Block = 10,
			NotKnown = 11
		};


		enum class DataTypes
		{
			glUnknown = -1,
#ifdef  PLATFORM_OPEN_GL
			glfloat = GL_FLOAT,
			vec2 = GL_FLOAT_VEC2,
			vec3 = GL_FLOAT_VEC3,
			vec4 = GL_FLOAT_VEC4,

			glDouble = GL_DOUBLE,
			dvec2 = GL_DOUBLE_VEC2,
			dvec3 = GL_DOUBLE_VEC3,
			dvec4 = GL_DOUBLE_VEC4,

			glInt = GL_INT,
			ivec2 = GL_INT_VEC2,
			ivec3 = GL_INT_VEC3,
			ivec4 = GL_INT_VEC4,

			unsignedint = GL_UNSIGNED_INT,
			uvec2 = GL_UNSIGNED_INT_VEC2,
			uvec3 = GL_UNSIGNED_INT_VEC3,
			uvec4 = GL_UNSIGNED_INT_VEC4,

			glBool = GL_BOOL,
			bvec2 = GL_BOOL_VEC2,
			bvec3 = GL_BOOL_VEC3,
			bvec4 = GL_BOOL_VEC4,

			mat2 = GL_FLOAT_MAT2,
			mat3 = GL_FLOAT_MAT3,
			mat4 = GL_FLOAT_MAT4,

			mat2x3 = GL_FLOAT_MAT2x3,
			mat2x4 = GL_FLOAT_MAT2x4,
			mat3x2 = GL_FLOAT_MAT3x2,
			mat3x4 = GL_FLOAT_MAT3x4,
			mat4x2 = GL_FLOAT_MAT4x2,
			mat4x3 = GL_FLOAT_MAT4x3,

			dmat2 = GL_DOUBLE_MAT2,
			dmat3 = GL_DOUBLE_MAT3,
			dmat4 = GL_DOUBLE_MAT4,

			dmat2x3 = GL_DOUBLE_MAT2x3,
			dmat2x4 = GL_DOUBLE_MAT2x4,
			dmat3x2 = GL_DOUBLE_MAT3x2,
			dmat3x4 = GL_DOUBLE_MAT3x4,
			dmat4x2 = GL_DOUBLE_MAT4x2,
			dmat4x3 = GL_DOUBLE_MAT4x3,

			sampler1D = GL_SAMPLER_1D,
			sampler2D = GL_SAMPLER_2D,
			sampler3D = GL_SAMPLER_3D,
			samplerCube = GL_SAMPLER_CUBE,
			sampler1DShadow = GL_SAMPLER_1D_SHADOW,
			sampler2DShadow = GL_SAMPLER_2D_SHADOW,
			sampler1DArray = GL_SAMPLER_1D_ARRAY,
			sampler2DArray = GL_SAMPLER_2D_ARRAY,
			sampler1DArrayShadow = GL_SAMPLER_1D_ARRAY_SHADOW,
			sampler2DArrayShadow = GL_SAMPLER_2D_ARRAY_SHADOW,
			sampler2DMS = GL_SAMPLER_2D_MULTISAMPLE,
			sampler2DMSArray = GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
			samplerCubeShadow = GL_SAMPLER_CUBE_SHADOW,
			samplerBuffer = GL_SAMPLER_BUFFER,
			sampler2DRect = GL_SAMPLER_2D_RECT,
			sampler2DRectShadow = GL_SAMPLER_2D_RECT_SHADOW,
			isampler1D = GL_INT_SAMPLER_1D,
			isampler2D = GL_INT_SAMPLER_2D,
			isampler3D = GL_INT_SAMPLER_3D,
			isamplerCube = GL_INT_SAMPLER_CUBE,
			isampler1DArray = GL_INT_SAMPLER_1D_ARRAY,
			isampler2DArray = GL_INT_SAMPLER_2D_ARRAY,
			isampler2DMS = GL_INT_SAMPLER_2D_MULTISAMPLE,
			isampler2DMSArray = GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
			isamplerBuffer = GL_INT_SAMPLER_BUFFER,
			isampler2DRect = GL_INT_SAMPLER_2D_RECT,
			usampler1D = GL_UNSIGNED_INT_SAMPLER_1D,
			usampler2D = GL_UNSIGNED_INT_SAMPLER_2D,
			usampler3D = GL_UNSIGNED_INT_SAMPLER_3D,
			usamplerCube = GL_UNSIGNED_INT_SAMPLER_CUBE,
			usampler1DArray = GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
			usampler2DArray = GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
			usampler2DMS = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
			usampler2DMSArray = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
			usamplerBuffer = GL_UNSIGNED_INT_SAMPLER_BUFFER,
			usampler2DRect = GL_UNSIGNED_INT_SAMPLER_2D_RECT,			
			CHAR = 36310,
			STRING = 36311,
#endif			
		};

		size_t getDataTypeSize(DataTypes iType);

		DataTypes getDataType(int iType);

		union Data
		{
			float floatVal;
			float vec2[2] ;
			float vec3[3];
			float vec4[4];
			
			int iVal;
			int iVec2[2];
			int iVec3[3];
			int iVec4[4];

			double dVal;
			double dVal2[2];
			double dVal3[3];
			double dVal4[4];

			unsigned int uiVal;
			unsigned int uiVal2[2];
			unsigned int uiVal3[3];
			unsigned int uiVal4[4];

			bool boolVal;
			bool boolVal2[2];
			bool boolVal3[3];
			bool boolVal4[4];

			float mat2[4];
			float mat3[9];
			float mat4[16];

			float mat2x3[6];
			float mat2x4[8];
			float mat3x2[6];
			float mat3x4[12];
			float mat4x2[8];
			float mat4x3[12];

			double dmat2[4];
			double dmat3[9];
			double dmat4[16];

			double dmat2x3[6];
			double dmat2x4[8];
			double dmat3x2[6];
			double dmat3x4[12];
			double dmat4x2[8];
			double dmat4x3[12];

			Data();	
			~Data(){}
			//Data(const Data & iData);
			//Data& operator=(Data iData);
			void assignData(DataTypes iDataType, Data iData);
		};

		enum ShaderType :uint8_t
		{
			Unknown = 0,
			Vertex = 1,
			Fragment = 2,
			Tessalation = 3,
			Geometry = 4,
			Compute = 5
		};

		enum Transform_Matrix_Type :uint8_t
		{
			Unspecified = 0,
			LocalToWorld = 1,
			WorldToView = 2,
			ViewToScreen = 3,
			ScaleMatrix = 4,
			NormalMatrix = 5,
			shadowProjectionMatrix = 6
		};

		struct MatrixStruct
		{
			Math::Matrix4x4 matrix;
			Transform_Matrix_Type Type;
		};

		union UniformValues
		{
			bool boolValue;
			bool * boolArray;
			int intValue;
			int * intArray;
			float floatValue;
			float* floatArray;
			MatrixStruct matrixValue;
			MatrixStruct *matrixArray;
			VectorStruct vectorValue;
			VectorStruct * vectorArray;			
			UniformValues();		
		};

		struct Parameter
		{
			std::string mParameterName;
			DataTypes mDataType;
			Data mParameterData;
		};

		struct UniformData
		{
			char * uniformName;
			UniformHandle handle;
			UniformDataType valType;
			uint8_t valCount;
			ShaderType shaderType;
			UniformValues value;
			UniformData();					
		};


		struct UniformBlockStruct
		{
			std::string uniformName;
			GLuint index;
			GLint size;
			GLint offset;
			DataTypes type;
			Data data;
			
			UniformBlockStruct()
			{
				index = 0;
				size = -1;
				offset = -1;
				type = DataTypes::glUnknown;
				data = Data();
			}			
		};

		

		struct MaterialUniform
		{
			UniformHandle Handle; //8 or 4
			ShaderType type; //1
			UniformDataType valType; //1
			uint8_t valCount; //1
			float values[4]; //16

			MaterialUniform();			
			~MaterialUniform();			
		};


		enum __renderState
		{
			ALPHA_BLENDING = 1 << 0,
			DEPTH_TESTING = 1 << 1,
			DEPTH_WRITING = 1 << 2,
			FACE_CULLING = 1 << 3
		};

		enum MapType :uint8_t
		{
			ALBEDO = 0,
			NORMAL = 1,
			SPECULAR = 2,
			BUMP = 3,
			SHADOW = 4
		};

		struct Map
		{
			char *file; //Texture File Name
			char *uniform; //Uniform Name			
			ShaderType shaderType;
			MapType mapType;
		};

		struct EffectStruct
		{
			std::string effectName;
			ShaderType shaderType;
			bool uniformBlockSet;
		};
	}
}

#endif
