// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
#ifdef MYACTORS_ABCharacter_generated_h
#error "ABCharacter.generated.h already included, missing '#pragma once' in ABCharacter.h"
#endif
#define MYACTORS_ABCharacter_generated_h

#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_SPARSE_DATA
#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnAttackMontageEnded);


#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnAttackMontageEnded);


#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABCharacter(); \
	friend struct Z_Construct_UClass_AABCharacter_Statics; \
public: \
	DECLARE_CLASS(AABCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyActors"), NO_API) \
	DECLARE_SERIALIZER(AABCharacter)


#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAABCharacter(); \
	friend struct Z_Construct_UClass_AABCharacter_Statics; \
public: \
	DECLARE_CLASS(AABCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyActors"), NO_API) \
	DECLARE_SERIALIZER(AABCharacter)


#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AABCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AABCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABCharacter(AABCharacter&&); \
	NO_API AABCharacter(const AABCharacter&); \
public:


#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABCharacter(AABCharacter&&); \
	NO_API AABCharacter(const AABCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABCharacter)


#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_11_PROLOG
#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_SPARSE_DATA \
	FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_RPC_WRAPPERS \
	FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_INCLASS \
	FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_SPARSE_DATA \
	FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_INCLASS_NO_PURE_DECLS \
	FID_MyActors_Source_MyActors_Public_ABCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYACTORS_API UClass* StaticClass<class AABCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyActors_Source_MyActors_Public_ABCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
