// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AuraFireBolt.h"
#include "Actor/AuraProjectile.h"


void UAuraFireBolt::SpawnProjectiles(const FVector& ProjectileTargetLocation)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if (!bIsServer) return;

	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo());

	FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
	
    FTransform SpawnTransform;
    SpawnTransform.SetLocation(SocketLocation);
    SpawnTransform.SetRotation(Rotation.Quaternion());

    AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
    ProjectileClass,
    SpawnTransform,
    GetOwningActorFromActorInfo(),
    Cast<APawn>(GetOwningActorFromActorInfo()),
    ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

    Projectile->FinishSpawning(SpawnTransform);
}