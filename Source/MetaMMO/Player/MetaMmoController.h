﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MetaMmoController.generated.h"

/**
 * 
 */
UCLASS()
class METAMMO_API AMetaMmoController : public APlayerController
{
	GENERATED_BODY()
	

public:

	//�л�����ģʽ
	void SwitchInputMode(bool IsShowUI);
};
