// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYACTORS_ABGameInstance_generated_h
#error "ABGameInstance.generated.h already included, missing '#pragma once' in ABGameInstance.h"
#endif
#define MYACTORS_ABGameInstance_generated_h

#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_18_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FABCharacterData_Statics; \
	MYACTORS_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> MYACTORS_API UScriptStruct* StaticStruct<struct FABCharacterData>();

#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_SPARSE_DATA
#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_RPC_WRAPPERS
#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABGameInstance(); \
	friend struct Z_Construct_UClass_UABGameInstance_Statics; \
public: \
	DECLARE_CLASS(UABGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/MyActors"), NO_API) \
	DECLARE_SERIALIZER(UABGameInstance)


#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_INCLASS \
private: \
	static void StaticRegisterNativesUABGameInstance(); \
	friend struct Z_Construct_UClass_UABGameInstance_Statics; \
public: \
	DECLARE_CLASS(UABGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/MyActors"), NO_API) \
	DECLARE_SERIALIZER(UABGameInstance)


#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABGameInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABGameInstance(UABGameInstance&&); \
	NO_API UABGameInstance(const UABGameInstance&); \
public:


#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABGameInstance(UABGameInstance&&); \
	NO_API UABGameInstance(const UABGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UABGameInstance)


#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_40_PROLOG
#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_SPARSE_DATA \
	FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_RPC_WRAPPERS \
	FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_INCLASS \
	FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_SPARSE_DATA \
	FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_INCLASS_NO_PURE_DECLS \
	FID_MyActors_Source_MyActors_Public_ABGameInstance_h_43_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYACTORS_API UClass* StaticClass<class UABGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyActors_Source_MyActors_Public_ABGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
