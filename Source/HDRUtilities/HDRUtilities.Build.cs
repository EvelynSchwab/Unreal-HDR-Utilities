// Some copyright should be here...

using System.IO;
using UnrealBuildTool;

public class HDRUtilities : ModuleRules
{
	public HDRUtilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"RHI",
				"RenderCore"
			});
		
		// Include DirectX Headers
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string WindowsSdkDir = Target.WindowsPlatform.WindowsSdkDir;
			string WindowsSdkVer = Target.WindowsPlatform.WindowsSdkVersion;
			if (WindowsSdkDir != null && WindowsSdkVer != null)
				PublicSystemIncludePaths.AddRange(new string[]
				{
					Path.Combine(WindowsSdkDir, "Include", WindowsSdkVer, "um"),
					Path.Combine(WindowsSdkDir, "Include", WindowsSdkVer, "shared"),
					Path.Combine(WindowsSdkDir, "Include", WindowsSdkVer, "winrt")
			});
			
			PublicAdditionalLibraries.Add("dxgi.lib");
		}
	}
}
