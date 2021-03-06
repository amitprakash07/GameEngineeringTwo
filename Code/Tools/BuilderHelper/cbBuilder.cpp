// Header Files
//=============

#include "cbBuilder.h"
#include "../../Externals/LuaHelper/LuaHelper.h"

// Interface
//==========

// Build
//------

bool Tools::AssetBuilder::cbBuilder::ParseCommandArgumentsAndBuild( char** i_arguments, const unsigned int i_argumentCount )
{
	const unsigned int commandCount = 1;
	const unsigned int actualArgumentCount = i_argumentCount - commandCount;
	std::stringstream message;
	//message << "\nTotal ArgumentCount "<<actualArgumentCount;
	//LuaHelper::OutputErrorMessage(message.str().c_str());
	const unsigned int requiredArgumentCount = 2;
	if ( actualArgumentCount >= requiredArgumentCount )
	{
		m_path_source = i_arguments[commandCount + 0];
		m_path_target = i_arguments[commandCount + 1];

		std::vector<std::string> optionalArguments;
		for ( unsigned int i = ( commandCount + requiredArgumentCount ); i < i_argumentCount; ++i )
		{
			/*message << "Optional Argument = " << i_arguments[i];
			LuaHelper::OutputErrorMessage(message.str().c_str());*/
			optionalArguments.push_back( i_arguments[i] );

		}
		return Build( optionalArguments );
	}
	else
	{
		std::stringstream errorMessage;
		errorMessage << "An asset builder must be called with at least " << requiredArgumentCount << " command line arguments "
			"(the source path and the target path), but ";
		if ( actualArgumentCount == 0 )
		{
			errorMessage << "none were provided\n";
		}
		else if ( actualArgumentCount == 1 )
		{
			errorMessage << "only 1 was provided\n";
		}
		else
		{
			errorMessage << "only " << actualArgumentCount << " were provided\n";
		}
		LuaHelper::OutputErrorMessage(errorMessage.str().c_str());
		return false;
	}
}

// Initialization / Shut Down
//---------------------------

Tools::AssetBuilder::cbBuilder::cbBuilder():
	m_path_source( nullptr ), 
	m_path_target( nullptr )
{

}

Tools::AssetBuilder::cbBuilder::~cbBuilder()
{
	//Do nothing ??
}

