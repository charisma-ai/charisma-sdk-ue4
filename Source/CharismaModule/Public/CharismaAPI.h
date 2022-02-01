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

	static FString ToQueryString(const TMap<FString, FString>& QueryParams);

	static void Log(const int32 Key, const FString& Message, const ECharismaLogSeverity Severity, const float Duration = 5.f);

	static void CreatePlaythroughToken(const int32 StoryId, const int32 StoryVersion, const FString& ApiKey,
		const TFunction<void(const FString Token, const FString PlaythroughUuid)>& SuccessCallback,
		const TFunction<void(const FString Error)>& ErrorCallback);

	static void CreateConversation(const FString& PlaythroughToken,
		const TFunction<void(const FString ConversationUuid)>& SuccessCallback,
		const TFunction<void(const FString Error)>& ErrorCallback);

	static void SetMemory(const FString& PlaythroughToken, const FString& RecallValue, const FString& SaveValue,
		const TFunction<void()>& SuccessCallback,
		const TFunction<void(const FString Error)>& ErrorCallback);

	static void RestartFromEventId(const FString& PlaythroughToken, const int64 EventId,
		const TFunction<void()>& SuccessCallback,
		const TFunction<void(const FString Error)>& ErrorCallback);

	static void GetMessageHistory(const FString& PlaythroughToken, const FString& ConversationUuid, const int64 MinEventId,
		const TFunction<void(const FCharismaMessageHistoryResponse MessageHistory)>& SuccessCallback,
		const TFunction<void(const FString Error)>& ErrorCallback);

	static void GetPlaythroughInfo(const FString& PlaythroughToken,
		const TFunction<void(const FCharismaPlaythroughInfoResponse PlaythroughInfo)>& SuccessCallback,
		const TFunction<void(const FString Error)>& ErrorCallback);
};
