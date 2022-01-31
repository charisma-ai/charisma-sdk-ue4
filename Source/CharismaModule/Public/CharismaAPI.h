#pragma once

#include "CharismaEvents.h"
#include "Client.h"
#include "CoreMinimal.h"
#include "Interfaces/IHttpResponse.h"
#include "Room.h"

#include "CharismaAPI.generated.h"

enum ECharismaLogSeverity
{
	Info,
	Warning,
	Error
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHARISMAMODULE_API UCharismaAPI : public UObject
{
	GENERATED_BODY()

public:

	static const FString BaseURL;
	static const FString SocketURL;

	UFUNCTION(BlueprintCallable, Category = CharismaAPI)
	static void InitPlaythoughObject(const int32 StoryId, const int32 StoryVersion, const FString& ApiKey, UPlaythrough*& Playthrough);

	static void Log(const int32 Key, const FString& Message, const ECharismaLogSeverity Severity, const float Duration = 5.f);

	UFUNCTION()
	static FString ToQueryString(const TMap<FString, FString>& QueryParams);

	UFUNCTION()
	static void CreateConversationAPI(UPlaythrough* Playthrough, const FString& PlaythroughToken);

	UFUNCTION()
	static void SetMemoryAPI(UPlaythrough* Playthrough, const FString& Token, const FString& RecallValue, const FString& SaveValue);

	UFUNCTION()
	static void RestartFromEventIdAPI(UPlaythrough* Playthrough, const FString& TokenForRestart, const int64 EventId);

	UFUNCTION()
	static void GetMessageHistoryAPI(UPlaythrough* Playthrough, const FString& Token, const int32 ConversationId, const int64 MinEventId);

	UFUNCTION()
	static void GetPlaythroughInfoAPI(UPlaythrough* Playthrough, const FString& Token);

};
