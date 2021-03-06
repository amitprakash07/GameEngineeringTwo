return
{

-- ===============================MeshBuilder=========================
	{
		BuildTool = "MeshBuilder.exe",
		{
			src = "ComputerGraphics/Cube.lua",
			target = "ComputerGraphics/Cube.mesh",
		},					
		{
			src = "ComputerGraphics/reflectiveSphere.lua",
			target = "ComputerGraphics/reflectiveSphere.mesh",
		},
		{
			src = "ComputerGraphics/Torus.lua",
			target = "ComputerGraphics/Torus.mesh",
		},	
		{
			src = "ComputerGraphics/environmentMappingSphere.lua",
			target = "ComputerGraphics/environmentMappingSphere.mesh",
		},			
		{
			src = "ComputerGraphics/TestSphere.lua",
			target = "ComputerGraphics/TestSphere.mesh",
		},	
		{
			src = "ComputerGraphics/backWall.lua",
			target = "ComputerGraphics/backWall.mesh",
		},
		{
			src = "ComputerGraphics/ceiling.lua",
			target = "ComputerGraphics/ceiling.mesh",
		},
		{
			src = "ComputerGraphics/floor.lua",
			target = "ComputerGraphics/floor.mesh",
		},
		{
			src = "ComputerGraphics/frontWall.lua",
			target = "ComputerGraphics/frontWall.mesh",
		},
		{
			src = "ComputerGraphics/leftWall.lua",
			target = "ComputerGraphics/leftWall.mesh",
		},
		{
			src = "ComputerGraphics/rightWall.lua",
			target = "ComputerGraphics/rightWall.mesh",
		},
	-- Teapot one
		{
			src = "ComputerGraphics/teapot1_lid.lua",
			target = "ComputerGraphics/teapot1_lid.mesh",
		},
		{
			src = "ComputerGraphics/teapot1_handle.lua",
			target = "ComputerGraphics/teapot1_handle.mesh",
		},
		{
			src = "ComputerGraphics/teapot1_circum.lua",
			target = "ComputerGraphics/teapot1_circum.mesh",
		},
	-- Teapot two
		{
			src = "ComputerGraphics/teapot2_circum.lua",
			target = "ComputerGraphics/teapot2_circum.mesh",
		},
		{
			src = "ComputerGraphics/teapot2_lid.lua",
			target = "ComputerGraphics/teapot2_lid.mesh",
		},
		{
			src = "ComputerGraphics/teapot2_handle01.lua",
			target = "ComputerGraphics/teapot2_handle01.mesh",
		},
		{
			src = "ComputerGraphics/teapot2_handle02.lua",
			target = "ComputerGraphics/teapot2_handle02.mesh",
		},
	-- tray
		{
			src = "ComputerGraphics/tray.lua",
			target = "ComputerGraphics/tray.mesh",
		},
	-- konvinceTeapot
		{
			src = "ComputerGraphics/konvinceTeapot.lua",
			target = "ComputerGraphics/konvinceTeapot.mesh",
		},
	-- utahTeapot
		{
			src = "ComputerGraphics/utahTeapot.lua",
			target = "ComputerGraphics/utahTeapot.mesh",
		},
	-- proxyLightSphere
		{
			src = "ComputerGraphics/proxyLightSphere.lua",
			target = "ComputerGraphics/proxyLightSphere.mesh",
		},
	-- Sphere
		{
			src = "ComputerGraphics/sphere.lua",
			target = "ComputerGraphics/sphere.mesh",
		},
	-- Plane
		{
			src = "ComputerGraphics/Plane.lua",
			target = "ComputerGraphics/Plane.mesh",
		},
	},
-- =====================================================================

-- ===============================EffectBuilder=========================
	{
		BuildTool = "EffectBuilder.exe",
		{
			src = "ComputerGraphics/cubeEffect.lua",
			target = "ComputerGraphics/cubeEffect.effect"
		},	
		{
			src = "ComputerGraphics/planeEffect.lua",
			target = "ComputerGraphics/planeEffect.effect"
		},	
		{
			src = "ComputerGraphics/floorEffect.lua",
			target = "ComputerGraphics/floorEffect.effect"
		},	
		{
			src = "ComputerGraphics/reflectiveSphereEffect.lua",
			target = "ComputerGraphics/reflectiveSphereEffect.effect"
		},	
		{
			src = "ComputerGraphics/skyBoxEffect.lua",
			target = "ComputerGraphics/skyBoxEffect.effect"
		},
		{
			src = "ComputerGraphics/environmentMappingSphereEffect.lua",
			target = "ComputerGraphics/environmentMappingSphereEffect.effect"
		},
		{
			src = "ComputerGraphics/blueEffect.lua",
			target = "ComputerGraphics/blueEffect.effect"
		},
		{
			src = "ComputerGraphics/utahTeapotEffect.lua",
			target = "ComputerGraphics/utahTeapotEffect.effect"
		},
		{
			src = "ComputerGraphics/proxyLightEffect.lua",
			target = "ComputerGraphics/proxyLightEffect.effect"
		},
		{
			src = "ComputerGraphics/sphereEffect.lua",
			target = "ComputerGraphics/sphereEffect.effect"
		},
		{
			src = "ComputerGraphics/planeMeshEffect.lua",
			target = "ComputerGraphics/planeMeshEffect.effect"
		},
		{
			src = "ComputerGraphics/sphereToonEffect.lua",
			target = "ComputerGraphics/sphereToonEffect.effect"
		},
	},

-- =======================================================================


-- ===============================MaterialBuilder=========================
	{
		BuildTool = "MaterialBuilder.exe",
		{
			src = "ComputerGraphics/cubeMaterial.lua",
			target = "ComputerGraphics/cubeMaterial.mat",
		},				
		{
			src = "ComputerGraphics/floorMaterial.lua",
			target = "ComputerGraphics/floorMaterial.mat",
		},
		{
			src = "ComputerGraphics/reflectiveSphereMaterial.lua",
			target = "ComputerGraphics/reflectiveSphereMaterial.mat",
		},
		-- sky box Materials
		{
			src = "ComputerGraphics/skyBoxMaterialTwo.lua",
			target = "ComputerGraphics/skyBoxMaterialTwo.mat",
		},
		{
			src = "ComputerGraphics/skyBoxMaterialThree.lua",
			target = "ComputerGraphics/skyBoxMaterialThree.mat",
		},
		{
			src = "ComputerGraphics/skyBoxMaterial.lua",
			target = "ComputerGraphics/skyBoxMaterial.mat",
		},		
		{
			src = "ComputerGraphics/environmentMappingSphereMaterial.lua",
			target = "ComputerGraphics/environmentMappingSphereMaterial.mat",
		},
		{
			src = "ComputerGraphics/ceilingMaterial.lua",
			target = "ComputerGraphics/ceilingMaterial.mat",
		},
		{
			src = "ComputerGraphics/rightWallMaterial.lua",
			target = "ComputerGraphics/rightWallMaterial.mat",
		},
		{
			src = "ComputerGraphics/leftWallMaterial.lua",
			target = "ComputerGraphics/leftWallMaterial.mat",
		},
		{
			src = "ComputerGraphics/frontWallMaterial.lua",
			target = "ComputerGraphics/frontWallMaterial.mat",
		},
		{
			src = "ComputerGraphics/backWallMaterial.lua",
			target = "ComputerGraphics/backWallMaterial.mat",
		},
	-- konvinceTeapot
		{
			src = "ComputerGraphics/konvinceTeapotMaterial.lua",
			target = "ComputerGraphics/konvinceTeapotMaterial.mat",
		},
	-- utahTeapot
		{
			src = "ComputerGraphics/utahTeapotMaterial.lua",
			target = "ComputerGraphics/utahTeapotMaterial.mat",
		},
	-- proxyLightSphere
		{
			src = "ComputerGraphics/proxyLightSphereMaterial.lua",
			target = "ComputerGraphics/proxyLightSphereMaterial.mat",
		},	
	-- sphereMaterial
		{
			src = "ComputerGraphics/sphereMaterial.lua",
			target = "ComputerGraphics/sphereMaterial.mat",
		},
		-- planeMeshMaterial
		{
			src = "ComputerGraphics/planeMeshMaterial.lua",
			target = "ComputerGraphics/planeMeshMaterial.mat",
		},
		{
			src = "ComputerGraphics/sphereToonMaterial.lua",
			target = "ComputerGraphics/sphereToonMaterial.mat",
		},
	},

-- ======================================================================


-- ===============================ShaderBuilder=========================
	{
		BuildTool = "ShaderBuilder.exe",
		
		{
			src = "ComputerGraphics/cubeVertex.glsl",
			target = "ComputerGraphics/cubeVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/cubeFragment.glsl",
			target = "ComputerGraphics/cubeFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
		-- *******************************************************************
		{
			src = "ComputerGraphics/planeVertex.glsl",
			target = "ComputerGraphics/planeVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/planeFragment.glsl",
			target = "ComputerGraphics/planeFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************
		{
			src = "ComputerGraphics/reflectiveSphereVertex.glsl",
			target = "ComputerGraphics/reflectiveSphereVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/reflectiveSphereFragment.glsl",
			target = "ComputerGraphics/reflectiveSphereFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************
		{
			src = "ComputerGraphics/skyBoxVertex.glsl",
			target = "ComputerGraphics/skyBoxVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/skyBoxFragment.glsl",
			target = "ComputerGraphics/skyBoxFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************		
		{
			src = "ComputerGraphics/environmentMappingSphereVertex.glsl",
			target = "ComputerGraphics/environmentMappingSphereVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/environmentMappingSphereFragment.glsl",
			target = "ComputerGraphics/environmentMappingSphereFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************	
	{
			src = "ComputerGraphics/teapotVertex.glsl",
			target = "ComputerGraphics/teapotVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/teapotFragment.glsl",
			target = "ComputerGraphics/teapotFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************	
	{
			src = "ComputerGraphics/proxyLightVertex.glsl",
			target = "ComputerGraphics/proxyLightVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/proxyLightFragment.glsl",
			target = "ComputerGraphics/proxyLightFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************	
	{
			src = "ComputerGraphics/floorVertex.glsl",
			target = "ComputerGraphics/floorVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/floorFragment.glsl",
			target = "ComputerGraphics/floorFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************
	{
			src = "ComputerGraphics/sphereVertex.glsl",
			target = "ComputerGraphics/sphereVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/sphereFragment.glsl",
			target = "ComputerGraphics/sphereFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************
	{
			src = "ComputerGraphics/planeMeshVertex.glsl",
			target = "ComputerGraphics/planeMeshVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/planeMeshFragment.glsl",
			target = "ComputerGraphics/planeMeshFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************
	{
			src = "ComputerGraphics/sphereToonVertex.glsl",
			target = "ComputerGraphics/sphereToonVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/sphereToonFragment.glsl",
			target = "ComputerGraphics/sphereToonFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************
	{
			src = "ComputerGraphics/SSAOPassVertex.glsl",
			target = "ComputerGraphics/SSAOPassVertex.glsl",
			optionaltype = "vertex",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}
		},

		{
			src = "ComputerGraphics/SSAOPassFragment.glsl",
			target = "ComputerGraphics/SSAOPassFragment.glsl",
			optionaltype = "fragment",
			dependencies =
			{
				"ComputerGraphics/shader_common.inc"
			}

		},
	-- *******************************************************************
	
	},

-- ====================================================================


-- ===============================TextureBuilder=========================
	
	{
		BuildTool = "TextureBuilder.exe",
		{
			src = "ComputerGraphics/borgTexture.jpg",
			target = "ComputerGraphics/borgTexture.jpg",
		},	
		{
			src = "ComputerGraphics/borgTexture_Bump.jpg",
			target = "ComputerGraphics/borgTexture_Bump.jpg",
		},
		{
			src = "ComputerGraphics/borgTexture_normal.jpg",
			target = "ComputerGraphics/borgTexture_normal.jpg",
		},	
		{
			src = "ComputerGraphics/myFace.dds",
			target = "ComputerGraphics/myFace.dds",
		},		
		{
			src = "ComputerGraphics/marbleTexture.jpg",
			target = "ComputerGraphics/marbleTexture.jpg",
		},
		{
			src = "ComputerGraphics/checkerBoard.jpg",
			target = "ComputerGraphics/checkerBoard.jpg",
		},
		{
			src = "ComputerGraphics/defaultTexture.png",
			target = "ComputerGraphics/defaultTexture.png",
		},
		{
			src = "ComputerGraphics/Yokohama3.dds",
			target = "ComputerGraphics/Yokohama3.dds",
		},
		{
			src = "ComputerGraphics/LancellottiChapel.dds",
			target = "ComputerGraphics/LancellottiChapel.dds",
		},
		{
			src = "ComputerGraphics/Test.dds",
			target = "ComputerGraphics/Test.dds",
		},
		{
			src = "ComputerGraphics/plank.png",
			target = "ComputerGraphics/plank.png",
		},
		{
			src = "ComputerGraphics/Yokohama3_Inverted.dds",
			target = "ComputerGraphics/Yokohama3_Inverted.dds",
		},
        {
			src = "ComputerGraphics/Yokohama2.dds",
			target = "ComputerGraphics/Yokohama2.dds",
		},
        {
			src = "ComputerGraphics/LancellottiChapel.dds",
			target = "ComputerGraphics/LancellottiChapel.dds",
		},
	--Basket Texture For Sphere
		{
			src = "ComputerGraphics/basketDiffuse.dds",
			target = "ComputerGraphics/basketDiffuse.dds",
		},
		{
			src = "ComputerGraphics/basketNormal.dds",
			target = "ComputerGraphics/basketNormal.dds",
		},
		{
			src = "ComputerGraphics/basketBump.dds",
			target = "ComputerGraphics/basketBump.dds",
		},		
	--Wall Textures
		{
			src = "ComputerGraphics/brickWall_1.dds",
			target = "ComputerGraphics/brickWall_1.dds",
		},
		{
			src = "ComputerGraphics/brickWall_1_bump.dds",
			target = "ComputerGraphics/brickWall_1_bump.dds",
		},
		{
			src = "ComputerGraphics/brickWall_1_normal.dds",
			target = "ComputerGraphics/brickWall_1_normal.dds",
		},

		{
			src = "ComputerGraphics/brickWall_2.dds",
			target = "ComputerGraphics/brickWall_2.dds",
		},
		{
			src = "ComputerGraphics/brickWall_2_bump_map.dds",
			target = "ComputerGraphics/brickWall_2_bump_map.dds",
		},
		{
			src = "ComputerGraphics/brickWall_2_normal.dds",
			target = "ComputerGraphics/brickWall_2_normal.dds",
		},

		{
			src = "ComputerGraphics/brickWall_3.dds",
			target = "ComputerGraphics/brickWall_3.dds",
		},
		{
			src = "ComputerGraphics/brickWall_3_bump.dds",
			target = "ComputerGraphics/brickWall_3_bump.dds",
		},
		{
			src = "ComputerGraphics/brickWall_3_normal.dds",
			target = "ComputerGraphics/brickWall_3_normal.dds",
		},
	--ceiling Texture
		{
			src = "ComputerGraphics/ceiling.dds",
			target = "ComputerGraphics/ceiling.dds",
		},
		{
			src = "ComputerGraphics/ceiling_normal.dds",
			target = "ComputerGraphics/ceiling_normal.dds",
		},
	--Sand drune Texture
		{
			src = "ComputerGraphics/sandDrune.dds",
			target = "ComputerGraphics/sandDrune.dds",
		},
		{
			src = "ComputerGraphics/sandDrune_bump.dds",
			target = "ComputerGraphics/sandDrune_bump.dds",
		},
		{
			src = "ComputerGraphics/sandDruneNormalMap.dds",
			target = "ComputerGraphics/sandDruneNormalMap.dds",
		},
	--Sphere Texture
		{
			src = "ComputerGraphics/nightSkySpherical.dds",
			target = "ComputerGraphics/nightSkySpherical.dds",
		},
		{
			src = "ComputerGraphics/nightSkySpherical_normal.dds",
			target = "ComputerGraphics/nightSkySpherical_normal.dds",
		},
	}
-- ====================================================================

}
