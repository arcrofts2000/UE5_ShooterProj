// Copyright - Adam Crofts

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5_ShooterProjEditorTarget : TargetRules
{
	public UE5_ShooterProjEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V6;

		ExtraModuleNames.AddRange( new string[] { "UE5_ShooterProj" } );
	}
}
