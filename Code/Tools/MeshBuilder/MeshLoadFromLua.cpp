#include "Mesh.h"
#include "../../Externals/LuaHelper/LuaHelper.h"
#include <iostream>
#include <windows.h>


bool LuaLoadVertex(lua_State* i_luaState, Tools::AssetBuilder::Mesh* i_mesh)
{
	int vertexCount = luaL_len(i_luaState, -1);
	Tools::AssetBuilder::vertex *tempVertex = i_mesh->getVertex();
	if (!tempVertex)
		return false;

	for (int i = 1; i <= vertexCount; i++)
	{
//		int vertexIndex;
		lua_pushinteger(i_luaState, i);
		lua_gettable(i_luaState, -2);

		//Position
		{
			//Retrieving the positions of the vertex
			lua_pushstring(i_luaState, "position");
			lua_gettable(i_luaState, -2); //Lua Stack contains position table at -2


			int counts = luaL_len(i_luaState, -1);
			if (counts < 3)
			{
				std::stringstream errormessage;
				errormessage << "Atleast x and y coordinates are required for a vertex. found " << counts << "\n";
				LuaHelper::OutputErrorMessage(errormessage.str().c_str(), __FILE__);
				return false;
			}

			for (int j = 1; j <= counts; j++)
			{
				//traversing in the position array by pushing index
				lua_pushinteger(i_luaState, j);
				lua_gettable(i_luaState, -2);
				switch (j - 1)
				{
				case 0:
					tempVertex[i - 1].X = static_cast<float>(lua_tonumber(i_luaState, -1));
					break;
				case 1:
					tempVertex[i - 1].Y = static_cast<float>(lua_tonumber(i_luaState, -1));
					break;
				case 2:
#ifdef PLATFORM_OPEN_GL
					tempVertex[i - 1].Z = static_cast<float>(lua_tonumber(i_luaState, -1));
#elif PLATFORM_D3D
					tempVertex[i - 1].Z = 1.0f * (static_cast<float>(lua_tonumber(i_luaState, -1)));
#endif
					break;
				}
				lua_pop(i_luaState, 1);//Popping out the previous position value
			}

			lua_pop(i_luaState, 1); //Popping out the position table
		}//Position
		
		 //Normals
		{			
			lua_pushstring(i_luaState, "normal");
			lua_gettable(i_luaState, -2);
			int normalCount = luaL_len(i_luaState, -1);
			if(normalCount < 3)
			{
				std::stringstream errormessage;
				errormessage << "Insufficient data for the normals. Need three; Found " << normalCount << "\n";
				LuaHelper::OutputErrorMessage(errormessage.str().c_str(), __FILE__);
				return false;
			}

			for (int j = 1; j <= normalCount; j++)
			{
				//traversing in the normals array by pushing index
				lua_pushinteger(i_luaState, j);
				lua_gettable(i_luaState, -2);
				switch (j - 1)
				{
				case 0:
					tempVertex[i - 1].nx = static_cast<float>(lua_tonumber(i_luaState, -1));
					break;
				case 1:
					tempVertex[i - 1].ny = static_cast<float>(lua_tonumber(i_luaState, -1));
					break;
				case 2:
#ifdef PLATFORM_OPEN_GL
					tempVertex[i - 1].nz = static_cast<float>(lua_tonumber(i_luaState, -1));
#elif PLATFORM_D3D
					tempVertex[i - 1].nz = 1.0f * (static_cast<float>(lua_tonumber(i_luaState, -1)));
#endif
					break;
				}
				lua_pop(i_luaState, 1);//Popping out the previous normal value
			}

			lua_pop(i_luaState, 1); //Popping out the normal table			
		}//Normal
		
		//Tagents
		{
			lua_pushstring(i_luaState, "tangent");
			lua_gettable(i_luaState, -2);
			int tangentCount = luaL_len(i_luaState, -1);
			if (tangentCount < 3)
			{
				std::stringstream errormessage;
				errormessage << "Insufficient data for the tangent. Need three; Found " << tangentCount << "\n";
				LuaHelper::OutputErrorMessage(errormessage.str().c_str(), __FILE__);
				return false;
			}

			for (int j = 1; j <= tangentCount; j++)
			{
				//traversing in the normals array by pushing index
				lua_pushinteger(i_luaState, j);
				lua_gettable(i_luaState, -2);
				switch (j - 1)
				{
				case 0:
					tempVertex[i - 1].tx = static_cast<float>(lua_tonumber(i_luaState, -1));
					break;
				case 1:
					tempVertex[i - 1].ty = static_cast<float>(lua_tonumber(i_luaState, -1));
					break;
				case 2:
#ifdef PLATFORM_OPEN_GL
					tempVertex[i - 1].tz = static_cast<float>(lua_tonumber(i_luaState, -1));
#elif PLATFORM_D3D
					tempVertex[i - 1].tz = 1.0f * (static_cast<float>(lua_tonumber(i_luaState, -1)));
#endif
					break;
				}
				lua_pop(i_luaState, 1);//Popping out the previous tangent value
			}

			lua_pop(i_luaState, 1); //Popping out the tangent table
		}//Tangent
		
		 //BiTangent
		{
			lua_pushstring(i_luaState, "bitangent");
			lua_gettable(i_luaState, -2);
			int biTangentCount = luaL_len(i_luaState, -1);
			if (biTangentCount < 3)
			{
				std::stringstream errormessage;
				errormessage << "Insufficient data for the normals. Need three; Found " << biTangentCount << "\n";
				LuaHelper::OutputErrorMessage(errormessage.str().c_str(), __FILE__);
				return false;
			}

			for (int j = 1; j <= biTangentCount; j++)
			{
				//traversing in the normals array by pushing index
				lua_pushinteger(i_luaState, j);
				lua_gettable(i_luaState, -2);
				switch (j - 1)
				{
				case 0:
#ifdef PLATFORM_OPEN_GL
					tempVertex[i - 1].btx = static_cast<float>(lua_tonumber(i_luaState, -1));
#elif PLATFORM_D3D
					tempVertex[i - 1].btx = 1.0f * (static_cast<float>(lua_tonumber(i_luaState, -1)));
#endif
					break;
				case 1:
#ifdef PLATFORM_OPEN_GL
					tempVertex[i - 1].bty = static_cast<float>(lua_tonumber(i_luaState, -1));
#elif PLATFORM_D3D
					tempVertex[i - 1].bty = 1.0f * (static_cast<float>(lua_tonumber(i_luaState, -1)));
#endif
					break;
				case 2:
					tempVertex[i - 1].btz = static_cast<float>(lua_tonumber(i_luaState, -1));
					break;
				}
				lua_pop(i_luaState, 1);//Popping out the previous bitangent value
			}

			lua_pop(i_luaState, 1); //Popping out the bitangent table			
		}//BiTangent
		
		//Texture
		{
			lua_pushstring(i_luaState, "texture");
			lua_gettable(i_luaState, -2);
			int textureCount = luaL_len(i_luaState, -1);
			if (textureCount < 2)
			{
				std::stringstream errormessage;
				errormessage << "Insufficient data for the texture. Need three; Found " << textureCount << "\n";
				LuaHelper::OutputErrorMessage(errormessage.str().c_str(), __FILE__);
				return false;
			}

			for (int j = 1; j <= textureCount; j++)
			{
				//traversing in the normals array by pushing index
				lua_pushinteger(i_luaState, j);
				lua_gettable(i_luaState, -2);
				switch (j - 1)
				{
				case 0:
					tempVertex[i - 1].u = static_cast<float>(lua_tonumber(i_luaState, -1));					
					break;
				case 1:
#ifdef PLATFORM_OPEN_GL
					tempVertex[i - 1].v = 1 - static_cast<float>(lua_tonumber(i_luaState, -1));
#elif PLATFORM_D3D
					tempVertex[i - 1].v = 1 - (static_cast<float>(lua_tonumber(i_luaState, -1)));
#endif
					break;				
				}
				lua_pop(i_luaState, 1);//Popping out the previous texture value
			}

			lua_pop(i_luaState, 1); //Popping out the texture table	
		}//Texture

		
		//Retrieving the color of the vertex
		lua_pushstring(i_luaState, "color");
		lua_gettable(i_luaState, -2);
		int countColorChannels = luaL_len(i_luaState, -1);

#ifdef BUILD_DEBUG
		std::cout << "Printing Color Channels" << countColorChannels << std::endl;
#endif

		if(countColorChannels <3)
		{
			std::stringstream errormessage;
			errormessage << "Atleast 3 color channels are required to color the vertex. Found " << countColorChannels << "\n";
			LuaHelper::OutputErrorMessage(errormessage.str().c_str(),__FILE__);
			return false;
		}

		for (int j = 1; j <= countColorChannels; j++)
		{
			//traversing in the color field array by pushing the index
			lua_pushinteger(i_luaState, j);
			lua_gettable(i_luaState, -2);
			float tempVal=0.0f;
			tempVal = static_cast<float>(lua_tonumber(i_luaState, -1));
			switch (j - 1)
			{
			case 0:
				tempVertex[i - 1].R = static_cast<uint8_t> (tempVal * 255);
#ifdef BUILD_DEBUG
				std::cout << "Let's print loading colors\n";
				std::cout << tempVertex[i - 1].R << std::endl;
#endif
				break;
			case 1:
#ifdef BUILD_DEBUG
				std::cout<<"Printing directly from lua"<< lua_tonumber(i_luaState, -1) * 255;
#endif
				tempVertex[i - 1].G = static_cast<uint8_t> (tempVal * 255);
#ifdef BUILD_DEBUG
				std::cout << tempVertex[i - 1].R << std::endl;
#endif				
				break;
			case 2:
				tempVertex[i - 1].B = static_cast<uint8_t> (tempVal * 255);
#ifdef BUILD_DEBUG
				std::cout << tempVertex[i - 1].R << std::endl;
#endif			break;
			case 3:
				tempVertex[i - 1].A = static_cast<uint8_t> (tempVal * 255);
#ifdef BUILD_DEBUG
				std::cout << tempVertex[i - 1].R << std::endl;
#endif				
				break;
			}
			lua_pop(i_luaState, 1);//Popping out the previous color value
		}

		lua_pop(i_luaState, 1); //Popping out the color table

		lua_pop(i_luaState, 1); //Popping out the pushed vertex data
	}
	return true;
}

bool LuaLoadTriangleIndex(lua_State* i_luaState, Tools::AssetBuilder::Mesh* i_mesh)
{
	int indicesCount;
	Tools::AssetBuilder::triangleIndex* tempIndices = i_mesh->getTriangleIndicesList();
	Tools::AssetBuilder::winding defaultWinding;
	lua_pushstring(i_luaState, "winding");
	lua_gettable(i_luaState, -2);

	std::string windingValue = lua_tostring(i_luaState, -1);
	if (strcmp(windingValue.c_str(), "right") == 0)
		defaultWinding = Tools::AssetBuilder::RIGHT;
	else
		defaultWinding = Tools::AssetBuilder::LEFT;

	i_mesh->setWinding(defaultWinding);

	lua_pop(i_luaState, 1); //Popping out the winding table

	indicesCount = luaL_len(i_luaState, -1);
	for (int i = 1; i <= indicesCount; i++)
	{
		lua_pushinteger(i_luaState, i);
		lua_gettable(i_luaState, -2);

		if (!tempIndices)
			return false;

		int indices = luaL_len(i_luaState, -1);
		for (int j = 1; j <= indices; j++)
		{
			lua_pushinteger(i_luaState, j);
			lua_gettable(i_luaState, -2);
			switch (j - 1)
			{
			case 0:
				tempIndices[i - 1].first = static_cast<uint32_t>(lua_tointeger(i_luaState, -1));
				break;
			case 1:
				tempIndices[i - 1].second = static_cast<uint32_t>(lua_tointeger(i_luaState, -1));
				break;
			case 2:
				tempIndices[i - 1].third = static_cast<uint32_t>(lua_tointeger(i_luaState, -1));
				break;
			}
			
			lua_pop(i_luaState, 1); //Popping out the every index order data
		}

#ifdef PLATFORM_D3D
		if (i_mesh->getWinding() == Tools::AssetBuilder::RIGHT)
		{
			int temp = tempIndices[i - 1].second;
			tempIndices[i - 1].second = tempIndices[i - 1].third;
			tempIndices[i - 1].third = temp;
		}
#elif PLATFORM_OPEN_GL
		if (i_mesh->getWinding() == Tools::AssetBuilder::LEFT)
		{
			int temp = tempIndices[i - 1].second;
			tempIndices[i - 1].second = tempIndices[i - 1].third;
			tempIndices[i - 1].third = temp;
		}
#endif
		lua_pop(i_luaState, 1); //Popping out the indices array
	}

	return true;
}

