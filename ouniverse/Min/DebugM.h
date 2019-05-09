//Copyright 2015-2019, All Rights Reserved.

/**
Shortcuts to onscreen debugging messages.
- Can be easily redefined for Production builds.
 */

#pragma once

#define RGB_STD FColor::Turquoise
#define RGB_ERR FColor::Red

#define DBUG(Text) GEngine->AddOnScreenDebugMessage(-1, 15.0f, RGB_STD, Text);
#define DBUGC(Color,Text) GEngine->AddOnScreenDebugMessage(-1, 15.0f, Color, Text);

#define IFS(InInt) FString::FromInt(InInt)
#define FFS(InFloat) FString::SanitizeFloat(InFloat)
