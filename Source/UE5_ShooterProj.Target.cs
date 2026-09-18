// Copyright - Adam Crofts

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5_ShooterProjTarget : TargetRules
{
	public UE5_ShooterProjTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V6;

		ExtraModuleNames.AddRange( new string[] { "UE5_ShooterProj" } );
	}
}
