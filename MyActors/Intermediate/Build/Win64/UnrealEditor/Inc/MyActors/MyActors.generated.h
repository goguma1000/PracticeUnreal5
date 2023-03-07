// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYACTORS_MyActors_generated_h
#error "MyActors.generated.h already included, missing '#pragma once' in MyActors.h"
#endif
#define MYACTORS_MyActors_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyActors_Source_MyActors_Public_MyActors_h


#define FOREACH_ENUM_ECHARACTERSTATE(op) \
	op(ECharacterState::PREINIT) \
	op(ECharacterState::LOADING) \
	op(ECharacterState::READY) \
	op(ECharacterState::DEAD) 

enum class ECharacterState : uint8;
template<> MYACTORS_API UEnum* StaticEnum<ECharacterState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
