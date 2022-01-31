// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaythroughEventsManager.h"

UPlaythroughEventsManager::UPlaythroughEventsManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), WorldContextObject(nullptr)
{
}

UPlaythroughEventsManager* UPlaythroughEventsManager::AttachPlaythroughHandlers(UObject* WorldContextObject, UPlaythrough* Playthrough)
{
	UPlaythroughEventsManager* BlueprintNode = NewObject<UPlaythroughEventsManager>();
	BlueprintNode->CurPlaythrough = Playthrough;
	return BlueprintNode;
}

void UPlaythroughEventsManager::Activate()
{
	CurPlaythrough->OnConversationCreated.AddDynamic(this, &UPlaythroughEventsManager::OnConversationCreatedFUNC);
	CurPlaythrough->OnConnected.AddDynamic(this, &UPlaythroughEventsManager::OnConnectedFUNC);
	CurPlaythrough->OnReady.AddDynamic(this, &UPlaythroughEventsManager::OnReadyFUNC);
	CurPlaythrough->OnTyping.AddDynamic(this, &UPlaythroughEventsManager::OnTypingFUNC);
	CurPlaythrough->OnMessage.AddDynamic(this, &UPlaythroughEventsManager::OnMessageFUNC);
}


void UPlaythroughEventsManager::OnConversationCreatedFUNC(int32 ConversationId)
{
	CurConversationId = ConversationId;
	OnConversationCreated.Broadcast(CurConversationId, CurIsConnected, CurIsTyping, CurMessageEvent);
}

void UPlaythroughEventsManager::OnConnectedFUNC(bool IsConnected)
{
	CurIsConnected = IsConnected;
	OnConnected.Broadcast(CurConversationId, CurIsConnected, CurIsTyping, CurMessageEvent);
}

void UPlaythroughEventsManager::OnReadyFUNC()
{
	OnReady.Broadcast(CurConversationId, CurIsConnected, CurIsTyping, CurMessageEvent);
}

void UPlaythroughEventsManager::OnTypingFUNC(bool IsTyping)
{
	CurIsTyping = IsTyping;
	OnTyping.Broadcast(CurConversationId, CurIsConnected, CurIsTyping, CurMessageEvent);
}

void UPlaythroughEventsManager::OnMessageFUNC(const FCharismaMessageEvent& MessageEvent)
{
	CurMessageEvent = MessageEvent;
	OnMessage.Broadcast(CurConversationId, CurIsConnected, CurIsTyping, CurMessageEvent);
}