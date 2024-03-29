﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Scene/MetaActorEntity.h"
#include "MetaSkillActor.generated.h"

class AMetaMmoGameMode;
class UParticleSystemComponent;
class UParticleSystem;
class UAudioComponent;


/**
 * 
 */
UCLASS()
class METAMMO_API AMetaSkillActor : public AMetaActorEntity
{
	GENERATED_BODY()
	

public:

	AMetaSkillActor();

	virtual void Destroyed() override;

	// 服务器端销毁技能, 播放爆炸特效
	void PlayExplode();


public:

	uint8 SkillId;

	// 特效组件
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* SkillParticleComponent;

	UPROPERTY(EditAnywhere)
		UAudioComponent* ShootAudio;

	UPROPERTY(EditAnywhere)
		UAudioComponent* ExplodeAudio;

	UPROPERTY(EditAnywhere)
		UParticleSystem* SkillParticle;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ExplodeParticle;

protected:

	virtual void BeginPlay() override;

	void DestroySkill();


protected:
	
	// 爆炸特效定时器
	FTimerHandle DestroyHandle;
};
