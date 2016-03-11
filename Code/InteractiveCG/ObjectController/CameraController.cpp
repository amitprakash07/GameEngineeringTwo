#include "CameraController.h"
#include "../../Engine/Core/EngineCore/Objects/Object.h"
#include "../../Engine/Core/Maths/Vector3.h"

void Application::CameraController::updateObject(Engine::Object& iObject, Engine::typedefs::Action iAction)
{
	Engine::Math::Transform transform= iObject.getTransform();
	switch (iAction)
	{
	case Engine::typedefs::MoveForward:
		transform.translate(Engine::Math::Vector3(0.0f, 0.0f, -1.0f));
	break;
	case Engine::typedefs::MoveBackWard:
		transform.translate(Engine::Math::Vector3(0.0f, 0.0f, 1.0f));
	break;
	case Engine::typedefs::MoveLeft:
		transform.translate(Engine::Math::Vector3(-1.0f, 0.0f, 0.0f));
	break;
	case Engine::typedefs::MoveRight:
		transform.translate(Engine::Math::Vector3(1.0f, 0.0f, 0.0f));
	break;
	default:
	break;
	}
	iObject.setTransform(transform.getPosition(), transform.getOrientation());
}


