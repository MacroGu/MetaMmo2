﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MetaLoginWidget.generated.h"


class UEditableTextBox;
class UTextBlock;
class AMetaLoginGameMode;

/**
 * 
 */
UCLASS()
class METAMMO_API UMetaLoginWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void InitWidget();

	UFUNCTION(BlueprintCallable)
	void LoginButtonEvent();

	UFUNCTION(BlueprintCallable)
	void RegisterButtonEvent();

public:

	AMetaLoginGameMode* LoginGameMode;

	UPROPERTY(Meta = (BindWidget))
	UEditableTextBox* UserNameBox;

	UPROPERTY(Meta = (BindWidget))
	UEditableTextBox* PasswardBox;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* clientVersionLabel;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* clientScriptVersionLabel;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* serverVersionLabel;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* serverScriptVersionLabel;

};
