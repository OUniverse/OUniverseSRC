//Copyright 2015-2019, All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ouniverseEditorTarget : TargetRules
{
	public ouniverseEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "ouniverse" } );
	}
}
