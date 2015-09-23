// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "BouncerBall.h"
#include "BouncerBall.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBouncerBall() {}
	void ABouncerPlayer::StaticRegisterNativesABouncerPlayer()
	{
	}
	IMPLEMENT_CLASS(ABouncerPlayer, 407383471);
	void ABall::StaticRegisterNativesABall()
	{
		FNativeFunctionRegistrar::RegisterFunction(ABall::StaticClass(),"GetTarget",(Native)&ABall::execGetTarget);
		FNativeFunctionRegistrar::RegisterFunction(ABall::StaticClass(),"Move",(Native)&ABall::execMove);
	}
	IMPLEMENT_CLASS(ABall, 3173654963);
	void ABouncerBallGameMode::StaticRegisterNativesABouncerBallGameMode()
	{
	}
	IMPLEMENT_CLASS(ABouncerBallGameMode, 3408394989);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_APawn();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();

	BOUNCERBALL_API class UClass* Z_Construct_UClass_ABouncerPlayer_NoRegister();
	BOUNCERBALL_API class UClass* Z_Construct_UClass_ABouncerPlayer();
	BOUNCERBALL_API class UFunction* Z_Construct_UFunction_ABall_GetTarget();
	BOUNCERBALL_API class UFunction* Z_Construct_UFunction_ABall_Move();
	BOUNCERBALL_API class UClass* Z_Construct_UClass_ABall_NoRegister();
	BOUNCERBALL_API class UClass* Z_Construct_UClass_ABall();
	BOUNCERBALL_API class UClass* Z_Construct_UClass_ABouncerBallGameMode_NoRegister();
	BOUNCERBALL_API class UClass* Z_Construct_UClass_ABouncerBallGameMode();
	BOUNCERBALL_API class UPackage* Z_Construct_UPackage_BouncerBall();
	UClass* Z_Construct_UClass_ABouncerPlayer_NoRegister()
	{
		return ABouncerPlayer::StaticClass();
	}
	UClass* Z_Construct_UClass_ABouncerPlayer()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage_BouncerBall();
			OuterClass = ABouncerPlayer::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BouncerPlayer.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BouncerPlayer.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABouncerPlayer(Z_Construct_UClass_ABouncerPlayer, TEXT("ABouncerPlayer"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABouncerPlayer);
	UFunction* Z_Construct_UFunction_ABall_GetTarget()
	{
		UObject* Outer=Z_Construct_UClass_ABall();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetTarget"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Ball.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Call to have the ball find a new target"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABall_Move()
	{
		UObject* Outer=Z_Construct_UClass_ABall();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Move"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080400, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Ball.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Called per frame in tick to move the Ball, override for your own movement, no need to call this in your implementation"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABall_NoRegister()
	{
		return ABall::StaticClass();
	}
	UClass* Z_Construct_UClass_ABall()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_BouncerBall();
			OuterClass = ABall::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_ABall_GetTarget());
				OuterClass->LinkChild(Z_Construct_UFunction_ABall_Move());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_CurrentTarget = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentTarget"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(CurrentTarget, ABall), 0x0000080000000000, Z_Construct_UClass_ABouncerPlayer_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_ABall_GetTarget()); // 514805319
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_ABall_Move()); // 2209672952
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Ball.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Ball.h"));
				MetaData->SetValue(NewProp_CurrentTarget, TEXT("ModuleRelativePath"), TEXT("Ball.h"));
				MetaData->SetValue(NewProp_CurrentTarget, TEXT("ToolTip"), TEXT("A reference to the current target of the ball"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABall(Z_Construct_UClass_ABall, TEXT("ABall"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABall);
	UClass* Z_Construct_UClass_ABouncerBallGameMode_NoRegister()
	{
		return ABouncerBallGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ABouncerBallGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameMode();
			Z_Construct_UPackage_BouncerBall();
			OuterClass = ABouncerBallGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x2090028C;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BouncerBallGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BouncerBallGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABouncerBallGameMode(Z_Construct_UClass_ABouncerBallGameMode, TEXT("ABouncerBallGameMode"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABouncerBallGameMode);
	UPackage* Z_Construct_UPackage_BouncerBall()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/BouncerBall")), false, false));
			ReturnPackage->PackageFlags |= PKG_CompiledIn | 0x00000000;
			FGuid Guid;
			Guid.A = 0xD1027770;
			Guid.B = 0x8C66BF74;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
