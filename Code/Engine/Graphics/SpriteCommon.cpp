#include "Sprite.h"
#include "../Windows/WindowsFunctions.h"
#include "../Core/EngineCore/EngineCore.h"
#include "Material.h"
#include "Effect.h"
#include "../Core/Maths/Functions.h"
#include "Uniform.h"
#include <limits.h>

Engine::SharedPointer<Engine::Graphics::Sprite>
Engine::Graphics::Sprite::CreateSprite(std::string iSpriteName,
	std::string iMaterialName,
	/*
	Sprite Quad coordinate will be
	
	*/
	float left,
	float right,
	float top,
	float bottom,
	Coordinate i_coordinate)
{
	int windowWidth = EngineCore::getWindowingSystem()->getWindowWidth() ;
	int windowHeight = EngineCore::getWindowingSystem()->getWindowHeight();

	switch (i_coordinate)
	{
	case VIEWPORT_COORDINATE:
		WindowsUtil::Assert(Math::InRange(left, 0, windowWidth)
			&& Math::InRange(right, 0, windowWidth)
			&& Math::InRange(top, 0, windowHeight)
			&& Math::InRange(bottom, 0, windowHeight),
			"Sprite position should be in within viewport window");
		break;
	case SCREEN_COORDINATE:
		WindowsUtil::Assert(Math::InRange(left, -1, 1)
			&& Math::InRange(right, -1, 1)
			&& Math::InRange(top, -1, 1)
			&& Math::InRange(bottom, -1, 1),
			"Sprite position should be in screen coordinate");
		break;
	case TEXTURE_COORDINATE:
		WindowsUtil::Assert(Math::InRange(left, 0, 1)
			&& Math::InRange(right, 0, 1)
			&& Math::InRange(top, 0, 1)
			&& Math::InRange(bottom, 0, 1),
			"Sprite position should be in texture coordinate");
		break;
	}


	std::stringstream errormessage;

	if (!iSpriteName.empty() && !iMaterialName.empty())
	{
		iMaterialName = EngineCore::getMaterialFolderPath() + iMaterialName;
		if (Engine::Graphics::Material::addMaterialToList(iMaterialName.c_str()))
		{			
			SharedPointer<Sprite> sprite = SharedPointer<Sprite>(new Sprite(iSpriteName, iMaterialName,
				left, right, top, bottom, i_coordinate),
				"Engine::Graphics::Sprite");
			if (!sprite->createBuffers())
			{
				errormessage << "Unable to Create buffer for the sprite";
				WindowsUtil::Print(errormessage.str(), __FILE__);
				sprite.deleteObject();
				return SharedPointer<Sprite>();
			}
			return sprite;
		}
		else
		{
			errormessage << "Something went wrong while loading sprite material";
			WindowsUtil::Print(errormessage.str(), __FILE__);
		}
	}
	else
	{
		errormessage << "Sprite Name or Material Name is empty";
		WindowsUtil::Print(errormessage.str(), __FILE__);
	}

	return SharedPointer<Engine::Graphics::Sprite>();
}

void Engine::Graphics::Sprite::changeSpriteMaterial(std::string iMaterial)
{
	if (!Engine::Graphics::Material::isMaterialExist(iMaterial.c_str()))
		Engine::Graphics::Material::addMaterialToList(iMaterial.c_str());
	mMaterial = iMaterial;
}


void Engine::Graphics::Sprite::draw(bool drawDebugObject)
{
	if (drawDebugObject && isDebug || !isDebug)
	{
		SharedPointer<Material> spriteMaterial =
			Engine::Graphics::Material::getMaterial(mMaterial.c_str());
		SharedPointer<Effect> spriteEffect =
			Engine::Graphics::Effect::getEffect(spriteMaterial->getEffectName());

		spriteEffect->setShaders();
		Engine::Graphics::Uniform::setAllUniformToShaderObjects(spriteMaterial->getEffectName());
		UniformBlock::setAllUniformBlockForTheEffectInShader(spriteMaterial->getEffectName());
		spriteMaterial->setMaterialUniformParameters();
		spriteMaterial->setTextureUniform();
		drawSprite();
	}
}

bool Engine::Graphics::Sprite::isMultiple() const
{
	return multiple;
}


uint8_t Engine::Graphics::Sprite::sliceSprite(uint8_t i_rows, uint8_t i_columns)
{
	multiple = true;
	rows = i_rows;
	columns = i_columns;
	totalCells = i_rows * i_columns;
	URange = 1.0f / columns;
	VRange = 1.0f / rows;
	return totalCells;
}

void Engine::Graphics::Sprite::setCellToRender(uint8_t i_cellToRender)
{
	if (multiple)
	{
		if (WindowsUtil::Assert((cellToRender <= totalCells) && multiple,
			"cell To render should be less than the split"))
			return;
		cellToRender = i_cellToRender;
	}
}


void Engine::Graphics::Sprite::nextCell()
{
	if (multiple)
	{
		cellToRender++;
		if (cellToRender >= totalCells)
			cellToRender = 0;
	}
}


Engine::Graphics::vertexTexture* Engine::Graphics::Sprite::getTextureAndVerticesData() const
{
	//leftBottom
	vertexAttribute[0].position.x = rectLeft;
	vertexAttribute[0].position.y = rectBottom;
	vertexAttribute[0].position.z = 1.0f;


	//right Bottom
	vertexAttribute[1].position.x = rectRight;
	vertexAttribute[1].position.y = rectBottom;
	vertexAttribute[1].position.z = 1.0f;


	//right Top
	vertexAttribute[2].position.x = rectRight;
	vertexAttribute[2].position.y = rectTop;
	vertexAttribute[2].position.z = 1.0f;

	//Left Top
	vertexAttribute[3].position.x = rectLeft;
	vertexAttribute[3].position.y = rectTop;
	vertexAttribute[3].position.z = 1.0f;

	if (!multiple)
	{
		//leftBottom
		vertexAttribute[0].texture.x = 0.0f;
		vertexAttribute[0].texture.y = 0.0f;

		//right Bottom
		vertexAttribute[1].texture.x = 1.0f;
		vertexAttribute[1].texture.y = 0.0f;

		//right Top
		vertexAttribute[2].texture.x = 1.0f;
		vertexAttribute[2].texture.y = 1.0f;

		//Left Top
		vertexAttribute[3].texture.x = 0.0f;
		vertexAttribute[3].texture.y = 1.0f;
	}
	else
	{
		uint8_t renderingRow = cellToRender / rows;
		uint8_t renderingColumn = cellToRender % columns;

		//leftBottom
		vertexAttribute[0].texture.x = URange * renderingColumn;
		vertexAttribute[0].texture.y = VRange * renderingRow;

		//right Bottom
		vertexAttribute[1].texture.x = URange * (1 + renderingColumn);
		vertexAttribute[1].texture.y = VRange * renderingRow;

		//right Top
		vertexAttribute[2].texture.x = URange * (1 + renderingColumn);
		vertexAttribute[2].texture.y = VRange * (1 + renderingRow);

		//Left Top
		vertexAttribute[3].texture.x = URange * renderingColumn;
		vertexAttribute[3].texture.y = VRange * (1 + renderingRow);
	}

	return vertexAttribute;
}

//Stub - May be need to fix but later
void Engine::Graphics::Sprite::setTransform(Engine::Math::Vector3, Engine::Math::Quaternion)
{

}


bool Engine::Graphics::Sprite::isDebugObject() const
{
	return isDebug;
}

void Engine::Graphics::Sprite::debugObject(bool Debug)
{
	isDebug = Debug;
}

bool Engine::Graphics::Sprite::isRenderable() const
{
	return true;
}


void Engine::Graphics::Sprite::setObjectController(SharedPointer<IObjectController>i_ObjectController)
{
	if (!mObjectController.isNull())
		mObjectController = i_ObjectController;
}


void Engine::Graphics::Sprite::updateObject()
{
	if (multiple)
	{
		if ((currentTick % spriteDelay) == 0)
			nextCell();
		currentTick++;
		if (currentTick == UINT32_MAX)
			currentTick = 0;
	}
}

void Engine::Graphics::Sprite::castShadow(bool, Graphics::ShadowMethod)
{
	
}


bool Engine::Graphics::Sprite::castingShadowEnabled()
{
	return false;
}


void Engine::Graphics::Sprite::enableCollision(bool)
{
	//Nothing to do
}

void Engine::Graphics::Sprite::enablePhysics(bool)
{
	//NMothing to do right now
}


bool Engine::Graphics::Sprite::isCollidable()
{
	return false;
}


bool Engine::Graphics::Sprite::isPhysicsEnabled()
{
	return false;
}


void Engine::Graphics::Sprite::receiveShadow(bool)
{
	//Nothinf to do right now
}


bool Engine::Graphics::Sprite::receivingShadowEnabled()
{
	return false;
}


bool Engine::Graphics::Sprite::IsPlayer()
{
	return isPlayer;
}


void Engine::Graphics::Sprite::setPlayer(bool i_isPlayer)
{
	isPlayer = i_isPlayer;
}


void Engine::Graphics::Sprite::setObjectType(ObjectType iObjectType)
{
	mObjectType = iObjectType;
}


Engine::ObjectType Engine::Graphics::Sprite::getObjectType()
{
	return mObjectType;
}

void Engine::Graphics::Sprite::SetMaterial(std::string iMaterialName)
{
	mMaterial = iMaterialName;
}













