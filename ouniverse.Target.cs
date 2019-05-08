//Copyright 2015-2019, All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ouniverseTarget : TargetRules
{
	public ouniverseTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "ouniverse" } );
	}
}
