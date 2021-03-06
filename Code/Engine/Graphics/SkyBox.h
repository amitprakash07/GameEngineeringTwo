#ifndef __SKY_BOX_H
#define __SKY_BOX_H

#include "../Core/EngineCore/Objects/Object.h"
#include "../Core/Utilities/SharedPointer.h"
#include "../../Engine/Core/Utilities/IMessageHandler.h"
#include <map>

namespace Engine
{
	namespace Graphics
	{
		class SkyBox:public IMessageHandler ,Engine::Object
		{
		public:
			static SharedPointer<SkyBox> CreateSkyBox(std::string i_MaterialName);
			static SharedPointer<SkyBox> getCurrentSkyBox();
			static SharedPointer<SkyBox> getSkyBox(std::string);
			static SharedPointer<SkyBox> getSkyBox(int index);
			static void nextSkyBox();
			Math::Transform getTransform() override;
			void setTransform(Math::Vector3,
				Math::Quaternion = Math::Quaternion()) override;
			bool isDebugObject() const override;
			bool isRenderable() const override;
			void draw(bool drawDebugObject) override;
			void setRenderable(bool iRenderable) override { /*to-do*/ }
			void resetTransform() override;
			void setMaterial(std::string newMaterialName);
			bool isSkyBoxAvailableIntialized()const;
			void updateObject() override;
			void setObjectController(SharedPointer<IObjectController> )override;
			void setScale(float x = 1.0f, float y = 1.0f, float z = 1.0f) override{}
			Math::Vector3 getScale() const override { return Math::Vector3(0.0f);/*Stub*/ }
			Graphics::RGBAColor GetVertexColor() const override { return Graphics::RGBAColor(0.0f); }
			void SetVertexColor(float iR, float iG, float iB, float iA) override{}
			std::string getMaterialName() override { return mMaterialName; }
			bool isCollidable() override;
			bool isPhysicsEnabled() override;
			void enableCollision(bool) override;
			void enablePhysics(bool) override;
			void castShadow(bool, Graphics::ShadowMethod) override;
			bool castingShadowEnabled() override;
			void receiveShadow(bool) override;
			bool receivingShadowEnabled() override;
			bool IsPlayer() override { return false; };
			void setPlayer(bool) override{}
			void setObjectType(ObjectType iObjectType) override;
			ObjectType getObjectType() override;
			void SetMaterial(std::string iMaterialName) override;
			void setCurrentSkyBox();
			static bool isSkyBoxExist(std::string materialName);
			void HandleMessage(
				Engine::utils::StringHash &,
				SharedPointer<RTTI> i_MessageSender, void* i_pMessageData) override;
			std::string getTypeInfo() const override { return ""; }
			bool isBothSameType(SharedPointer<RTTI>, std::string) const override { return true; }
			bool isSSAOEnabled() override { return false; }
			void EnableSSAO(bool iRequest) override {}
		private:
			static std::map<std::string, SharedPointer<SkyBox>> mSkyBoxList;
			static bool isSkyBoxAvailable;			
			SkyBox(std::string material_Name);
			Math::Transform stubTransform;
			std::string mMaterialName;
			bool createBuffer();				
			SharedPointer<IObjectController> mObjectController;
			ObjectType mObjectType;
			bool isCurrent;
			static void deactivateAll();
#ifdef PLATFORM_OPEN_GL
			GLuint s_vertexArrayID;
			GLuint vertexBufferId;
			GLuint indexBufferId;
			bool createVertexArray();
#elif PLATFORM_D3D
			IDirect3DVertexBuffer9* s_vertexBuffer;
			IDirect3DIndexBuffer9* s_indexBuffer;
			IDirect3DVertexDeclaration9* s_vertexDeclaration;
			bool createVertexBuffer();
			bool createIndexBuffer();
#endif
		};
	}
}
#endif
