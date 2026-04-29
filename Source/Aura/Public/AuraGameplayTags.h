// Copyright Aesir

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *  AuraGameplayTags
 * 
 * Singleton containing native Gameplay Tags (available in c++ and editor and BP)
 */

struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() { return GameplayTags };
	static void InitializeNativeGameplayTags();

protected:

private:
	static FAuraGameplayTags GameplayTags;
};