// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "Playthrough.h"
#include "CharismaAPI.h"

#include "PlaythroughCreateCharismaConversation.generated.h"

UCLASS()
class CHARISMAMODULE_API UPlaythroughCreateCharismaConversation : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "")
	static UPlaythroughCreateCharismaConversation* CreateCharismaConversation(UObject* WorldContextObject, UPlaythrough* Playthrough, const FString Token, const int32 PlaythroughId);

	virtual void Activate() override;

	UPROPERTY()
	UPlaythrough* CurPlaythrough;
	UPROPERTY()
	FString CurToken;
	UPROPERTY()
	int32 CurPlaythroughId;
	int32 CurConversationId;

private:

	UObject* WorldContextObject;
};