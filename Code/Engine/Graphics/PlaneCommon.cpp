#include "Plane.h"
#include "../Core/EngineCore/EngineCore.h"
#include "Material.h"
#include "../Windows/WindowsFunctions.h"
#include "../../Engine/Core/Utilities/IObjectController.h"


Engine::SharedPointer<Engine::Graphics::Plane> 
	Engine::Graphics::Plane::CreatePlane(std::string iMaterialName)
{
	 if(!iMaterialName.empty())
	 {
		 iMaterialName = Engine::EngineCore::getMaterialFolderPath() + iMaterialName;
		 if(WindowsUtil::Assert(Material::addMaterialToList(iMaterialName.c_str())
			 ,"Unable to add Material in PlaneCommon.cpp"))
		 {
			 SharedPointer<Plane> tempPlane =
				 SharedPointer<Plane>(new Plane(iMaterialName), "Engine::Graphics::Plane");
			 if (WindowsUtil::Assert(tempPlane->createBuffer(), "Unable to create Buffer"))
				 return tempPlane;
		 }
	 }
	 return Engine::SharedPointer<Plane>();
}


void Engine::Graphics::Plane::setTransform(
	Engine::Math::Vector3 i_positionOffset, Engine::Math::Quaternion i_orientation)
{
	mTransform.setOrientation(i_orientation);
	mTransform.setPosition(i_positionOffset);
}


bool Engine::Graphics::Plane::isDebugObject() const
{
	return debugObject;
}

bool Engine::Graphics::Plane::isRenderable() const
{
	return true;
}

void Engine::Graphics::Plane::updateObject()
{
	typedefs::ActionWithKeyBound action;
	action.action = typedefs::Default;
	action.keyVal = 0x00;
	if (mObjectController)
		mObjectController->updateObject(*this, action);
}


void Engine::Graphics::Plane::HandleMessage(Engine::utils::StringHash& i_message,
	RTTI* i_MessageSender, void* i_pMessageData)
{
	if (i_MessageSender != nullptr)
	{
		if (i_MessageSender != nullptr && Engine::utils::StringHash("UpdateObject") == i_message && mObjectController)
			mObjectController->updateObject(*this, *reinterpret_cast<Engine::typedefs::ActionWithKeyBound*>(i_pMessageData));
	}
}

Engine::Math::Transform Engine::Graphics::Plane::getTransform()
{
	return mTransform;
}


void Engine::Graphics::Plane::setObjectController(IObjectController* i_objectController)
{
	if (i_objectController)
		mObjectController = i_objectController;
}


void Engine::Graphics::Plane::setScale(float x, float y, float z)
{
	scaleFactor.x = x;
	scaleFactor.y = y;
	scaleFactor.z = z;
}

Engine::Graphics::VertexTextureNormal* 
	Engine::Graphics::Plane::getVertexAttributeData()
{
	if (!vertexattribute)
		vertexattribute = new VertexTextureNormal[4];

	vertexattribute[0].position = Math::Vector3(-0.5, 0,  0.5);
	vertexattribute[1].position = Math::Vector3( 0.5, 0,  0.5);
	vertexattribute[2].position = Math::Vector3( 0.5, 0, -0.5);
	vertexattribute[3].position = Math::Vector3(-0.5, 0, -0.5);

	vertexattribute[0].normal = Math::Vector3(0, 1, 0);
	vertexattribute[1].normal = Math::Vector3(0, 1, 0);
	vertexattribute[2].normal = Math::Vector3(0, 1, 0);
	vertexattribute[3].normal = Math::Vector3(0, 1, 0);

	vertexattribute[0].texture = Math::Vector2(0, 1);
	vertexattribute[1].texture = Math::Vector2(1, 1);
	vertexattribute[2].texture = Math::Vector2(1, 0);
	vertexattribute[3].texture = Math::Vector2(0, 0);

	return vertexattribute;
}


Engine::Math::Vector3 Engine::Graphics::Plane::getNormal()
{
	Engine::Math::Matrix4x4 inverseMatrix = Engine::Math::Matrix4x4(
		mTransform.getOrientation(), mTransform.getPosition()).getInverse();
	Math::Vector3 changedNormal = inverseMatrix.mul(Math::Vector3(0, 1, 0), true);
	return changedNormal;
}







