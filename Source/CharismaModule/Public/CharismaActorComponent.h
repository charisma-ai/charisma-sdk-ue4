#pragma once

#include "CharismaGameModeComponent.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Playthrough.h"
#include "RuntimeAudioImporterLibrary.h"
#include "Components/AudioComponent.h"

#include "CharismaActorComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CHARISMAMODULE_API UCharismaActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharismaActorComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bPlayAudio = false;

	UPROPERTY()
	UAudioComponent* CharacterAudioComponent;

	UPROPERTY(BlueprintReadWrite)
	TArray<FCharismaEmotion> CharacterEmotions;

	UPROPERTY()
	UPlaythrough* Playthrough;

	UPROPERTY()
	FTimerHandle Timer;

	UPROPERTY()
	UCharismaGameModeComponent* GameModeComponent;

	UFUNCTION()
	void BindToPlaythrough();

	UFUNCTION()
	void OnMessageReceived(const FCharismaMessageEvent& Message);

	UFUNCTION()
	void OnAudioDecoded(
		URuntimeAudioImporterLibrary* RuntimeAudioImporterLibraryRef, UImportedSoundWave* SoundWaveRef, ETranscodingStatus Status);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	URuntimeAudioImporterLibrary* RuntimeAudioImporterLibrary;
};
