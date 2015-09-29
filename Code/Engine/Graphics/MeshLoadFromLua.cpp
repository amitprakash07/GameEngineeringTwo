#include "Mesh.h"
#include "../../Externals/Lua/Includes.h"
#include "../Windows/WindowsFunctions.h"
#include <assert.h>

#define MESHFILE_PATH "data/SquareMesh.lua"


bool LuaLoadVertex(lua_State* i_luaState, Engine::Graphics::Mesh* i_mesh)
{
	int vertexCount = luaL_len(i_luaState, -1);
	Engine::Graphics::vertex *tempVertex = i_mesh->getVertex();
	if (!tempVertex)
		return false;

	for (int i = 1; i <= vertexCount; i++)
	{
		int vertexIndex;
		lua_pushinteger(i_luaState, i);
		lua_gettable(i_luaState, -2);

		//Retrieving the positions of the vertex
		lua_pushstring(i_luaState, "position");
		lua_gettable(i_luaState, -2); //Lua Stack contains position table at -2


		int counts = luaL_len(i_luaState, -1);
		if(counts < 2 )
		{
			std::stringstream errormessage;
			errormessage << "Atleast x and y coordinates are required for a vertex. found " << counts << "\n";
			WindowsUtil::Print(errormessage.str());
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
				tempVertex[i-1].X = static_cast<float>(lua_tonumber(i_luaState, -1));
				break;
			case 1:
				tempVertex[i-1].Y = static_cast<float>(lua_tonumber(i_luaState, -1));
				break;
			/*case 3:
				tempVertex[vertexIndex].Z = static_cast<float>(lua_tonumber(i_luaState, -1));*/
			}
			lua_pop(i_luaState, 1);//Popping out the previous position value
		}

		lua_pop(i_luaState, 1); //Popping out the position table


		//Retrieving the color of the vertex
		lua_pushstring(i_luaState, "color");
		lua_gettable(i_luaState, -2);
		int countColorChannels = luaL_len(i_luaState, -1);
		if(countColorChannels <3)
		{
			std::stringstream errormessage;
			errormessage << "Atleast 3 color channels are required to color the vertex. Found " << countColorChannels << "\n";
			WindowsUtil::Print(errormessage.str());
			return false;
		}

		for (int j = 1; j <= countColorChannels; j++)
		{
			//traversing in the color field array by pushing the index
			lua_pushinteger(i_luaState, j);
			lua_gettable(i_luaState, -2);
			switch (j - 1)
			{
			case 0:
				tempVertex[i-1].R = static_cast<uint8_t>(lua_tonumber(i_luaState, -1) * 255);
				break;
			case 1:
				tempVertex[i-1].G = static_cast<uint8_t>(lua_tonumber(i_luaState, -1) * 255);
				break;
			case 2:
				tempVertex[i-1].B = static_cast<uint8_t>(lua_tonumber(i_luaState, -1) * 255);
				break;
			case 3:
				tempVertex[i-1].A = static_cast<uint8_t>(lua_tonumber(i_luaState, -1) * 255);
				break;
			}
			lua_pop(i_luaState, 1);//Popping out the previous color value
		}

		lua_pop(i_luaState, 1); //Popping out the color table

		lua_pop(i_luaState, 1); //Popping out the pushed vertex data
	}
	return true;
}

bool LuaLoadTriangleIndex(lua_State* i_luaState, Engine::Graphics::Mesh* i_mesh)
{
	int indicesCount;
	Engine::Graphics::triangleIndex* tempIndices = i_mesh->getTriangleIndicesList();
	Engine::Graphics::winding defaultWinding;
	lua_pushstring(i_luaState, "winding");
	lua_gettable(i_luaState, -2);

	std::string windingValue = lua_tostring(i_luaState, -1);
	if (strcmp(windingValue.c_str(), "right") == 0)
		defaultWinding = Engine::Graphics::RIGHT;
	else
		defaultWinding = Engine::Graphics::LEFT;

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
				tempIndices[i - 1].first = static_cast<uint8_t>(lua_tointeger(i_luaState, -1));
				break;
			case 1:
				tempIndices[i - 1].second = static_cast<uint8_t>(lua_tointeger(i_luaState, -1));
				break;
			case 2:
				tempIndices[i - 1].third = static_cast<uint8_t>(lua_tointeger(i_luaState, -1));
				break;
			}
			
			lua_pop(i_luaState, 1); //Popping out the every index order data


		}
#ifdef PLATFORM_D3D
		if (i_mesh->getWinding() == Engine::Graphics::RIGHT)
		{
			int temp = tempIndices[i - 1].second;
			tempIndices[i - 1].second = tempIndices[i - 1].third;
			tempIndices[i - 1].third = temp;
		}
#endif

#ifdef PLATFORM_OPEN_GL
		if (i_mesh->getWinding() == Engine::Graphics::LEFT)
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


/**********************************************Lua Error Check Helper Functions*******************************************/
bool isString(lua_State * luaState)
{
	if (lua_type(luaState, -1) != LUA_TSTRING)
	{
		std::stringstream errorMessage;
		errorMessage << "The value for  must be a string  (instead of a " << luaL_typename(luaState, -1) << ")\n";
		WindowsUtil::Print(errorMessage.str());
		return false;
	}
	return true;
}

bool isTable(lua_State* luaState)
{
	if (!lua_istable(luaState, -1))
	{
		std::stringstream errorMessage;
		errorMessage << "Asset files must return a table (instead of a " << luaL_typename(luaState, -1) << ")\n";
		WindowsUtil::Print(errorMessage.str());
		return false;
	}
	return true;
}

bool isValueNil(lua_State * luaState)
{

	if (lua_isnil(luaState, -1))
	{
		std::stringstream errorMessage;
		errorMessage << "No value for the given key  was found in the asset table \n";
		WindowsUtil::Print(errorMessage.str());
		return true;
	}
	return false;
}

bool isValueNumber(lua_State* luaState)
{
	if (lua_type(luaState, -1) != LUA_TNUMBER)
	{
		std::stringstream errorMessage;
		errorMessage << "The Value for the key is not a double \n";
		WindowsUtil::Print(errorMessage.str());
		return false;
	}
	return true;
}

bool exitAndShutdownLua(lua_State *i_luaState)
{
	if (i_luaState)
	{
		assert(lua_gettop(i_luaState) == 0);
		lua_close((i_luaState));
		i_luaState = nullptr;
		return true;
	}
	std::stringstream errormessage;
	errormessage << "Lua state is already NULL. No need to shutdown again\n";
	WindowsUtil::Print(errormessage.str());
	return true;
}

bool isLuaResultOkay(lua_State *i_luaState, int result)
{
	if (result != LUA_OK)
	{
		std::stringstream errormessage;
		errormessage << "Unable to load the file. \n" << lua_tostring(i_luaState, 1);

		//Popping out the error message
		lua_pop(i_luaState, 1);
		WindowsUtil::Print(errormessage.str());
		exitAndShutdownLua(i_luaState);
		return false;
	}
	return true;
}
/*************************************************************************************************************************************/