return 
{
	effect = "ComputerGraphics/reflectiveSphereEffect.effect",
	map =
	{
		{
			path = "ComputerGraphics/Yokohama3.dds",
			uniformName = "g_TextureSampler",
			shader = "Fragment",
			mapType = "albedo",
		}		
	},
	uniforms =
	{
		{
			name = "g_PixelColorModifier",
			shader = "fragment",
			valtype = "Float",
			value = {0.2,0.5,0.7},
		},
		
		{
			name = "g_intensity",
			shader = "fragment",
			valtype = "Float",
			value = {1.0},
		}
	},		
}