
class CfgPatches
{
	class MagObfuscation_Scripts
	{
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Scripts"};
	};
};

class CfgMods 
{
	class DZ_MagObfuscation
	{
		name = "Mag Obfuscation";
		dir = "MagObfuscation";
		credits = "";
		author = "";
		creditsJson = "MagObfuscation/Scripts/Data/Credits.json";
		versionPath = "MagObfuscation/scripts/Data/Version.hpp";
		inputs = "MagObfuscation/Scripts/Data/Inputs.xml";
		type = "mod";
		dependencies[] =
		{
			"Game", "World", "Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"MagObfuscation/gui/imagesets/dayz_editor_gui.imageset"
				};
			};
			class engineScriptModule
			{
				value = "";
				files[] =
				{
					"MagObfuscation/scripts/common",
					"MagObfuscation/scripts/1_core"
				};
			};

			class gameScriptModule
			{
				value="";
				files[] = 
				{
					"MagObfuscation/scripts/common",
					"MagObfuscation/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[] = 
				{
					"MagObfuscation/scripts/common",
					"MagObfuscation/scripts/4_World"
				};
			};

			class missionScriptModule 
			{
				value="";
				files[] = 
				{
					"MagObfuscation/scripts/common",
					"MagObfuscation/scripts/5_Mission"
				};
			};
		};
	};
};
