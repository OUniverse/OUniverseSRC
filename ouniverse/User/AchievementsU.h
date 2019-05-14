//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "User/UserFileU.h"
#include "Interface/Gemini.h"

class AchievementsU : public UserFileU
{

public:

	AchievementsU() {};
	AchievementsU(StringC RootPath);
	
	GeminiC<int> Achievements;
};