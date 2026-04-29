// Copyright Aesir


#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);

	const FAuraGameplayTags& GameplayTags = FAuraGameplayTags::Get();
	FGameplayTag Tag = TAG_Attributes_Secondary_Armor;
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Orange,
		FString::Printf(TEXT("Tag: %s"), *Tag.ToString()));
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);


	EffectAssetTags.Broadcast(TagContainer); 
	//any class who binds to the effectassettags delegate will receive a tag container with the asset tags


}
