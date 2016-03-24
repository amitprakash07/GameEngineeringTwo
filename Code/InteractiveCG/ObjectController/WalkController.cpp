#include "WalkController.h"
#include "../../Engine/Core/EngineCore/Objects/Object.h"
#include "../../Engine/Core/Maths/Vector3.h"
#include "../../Engine/Core/Maths/Functions.h"
#include "../../Engine/Core/EngineCore/Objects/Scene.h"
#include "../../Engine/Graphics/SkyBox.h"

using namespace Engine::Math;
void Application::WalkController::updateObject(Engine::Object& iObject, Engine::typedefs::ActionWithKeyBound iAction)
{
	Engine::Math::Transform transform = iObject.getTransform();
	Quaternion leftRotor = Quaternion(ConvertDegreesToRadians(-3), Vector3(0, 1, 0));
	Quaternion rightRotor = Quaternion(ConvertDegreesToRadians(3), Vector3(0, 1, 0));
	Quaternion upRotor = Quaternion(ConvertDegreesToRadians(-3), Vector3(1, 0, 0));
	Quaternion downRotor = Quaternion(ConvertDegreesToRadians(3), Vector3(1, 0, 0));
	switch (iAction.keyVal)
	{
	case VK_UP:
		transform.setPosition(transform.getPosition() + Vector3(0, 0.5, 0));
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case VK_DOWN:
		transform.setPosition(transform.getPosition() + Vector3(0, -0.5, 0));
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case VK_LEFT:
		transform.setPosition(transform.getPosition() + Vector3(-0.5, 0, 0));
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case VK_RIGHT:
		transform.setPosition(transform.getPosition() + Vector3(0.5, 0, 0));
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case 0x57:
		//w key
		transform.setPosition(transform.getPosition() + Vector3(0, 0, -0.5));
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case 0x53:
		//S key
		transform.setPosition(transform.getPosition() + Vector3(0, 0, 0.5));
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case 0x41:	
		//A key
		leftRotor = leftRotor * transform.getOrientation();
		transform.setOrientation(leftRotor);
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case 0x44:	
		//D Key
		rightRotor = rightRotor * transform.getOrientation();
		transform.setOrientation(rightRotor);
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;	
	case 0x51:
		//Q Key
		upRotor = upRotor * transform.getOrientation();
		transform.setOrientation(upRotor);
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case 0x45:
		//E Key
		downRotor = downRotor * transform.getOrientation();
		transform.setOrientation(downRotor);
		iObject.setTransform(transform.getPosition(), transform.getOrientation());
		break;
	case 0x52:
		//R Key
		iObject.resetTransform();
	case VK_NEXT:
		Engine::Graphics::SkyBox::nextSkyBox();
		break;
	case VK_PRIOR:
		break;

	}


	
}



