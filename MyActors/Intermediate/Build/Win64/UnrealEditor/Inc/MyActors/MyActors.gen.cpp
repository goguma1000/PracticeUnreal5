// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/MyActors.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyActors() {}
// Cross Module References
	MYACTORS_API UEnum* Z_Construct_UEnum_MyActors_ECharacterState();
	UPackage* Z_Construct_UPackage__Script_MyActors();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECharacterState;
	static UEnum* ECharacterState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECharacterState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECharacterState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MyActors_ECharacterState, Z_Construct_UPackage__Script_MyActors(), TEXT("ECharacterState"));
		}
		return Z_Registration_Info_UEnum_ECharacterState.OuterSingleton;
	}
	template<> MYACTORS_API UEnum* StaticEnum<ECharacterState>()
	{
		return ECharacterState_StaticEnum();
	}
	struct Z_Construct_UEnum_MyActors_ECharacterState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_MyActors_ECharacterState_Statics::Enumerators[] = {
		{ "ECharacterState::PREINIT", (int64)ECharacterState::PREINIT },
		{ "ECharacterState::LOADING", (int64)ECharacterState::LOADING },
		{ "ECharacterState::READY", (int64)ECharacterState::READY },
		{ "ECharacterState::DEAD", (int64)ECharacterState::DEAD },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_MyActors_ECharacterState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DEAD.Name", "ECharacterState::DEAD" },
		{ "LOADING.Name", "ECharacterState::LOADING" },
		{ "ModuleRelativePath", "Public/MyActors.h" },
		{ "PREINIT.Name", "ECharacterState::PREINIT" },
		{ "READY.Name", "ECharacterState::READY" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MyActors_ECharacterState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_MyActors,
		nullptr,
		"ECharacterState",
		"ECharacterState",
		Z_Construct_UEnum_MyActors_ECharacterState_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_MyActors_ECharacterState_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_MyActors_ECharacterState_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_MyActors_ECharacterState_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_MyActors_ECharacterState()
	{
		if (!Z_Registration_Info_UEnum_ECharacterState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECharacterState.InnerSingleton, Z_Construct_UEnum_MyActors_ECharacterState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECharacterState.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActors_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActors_h_Statics::EnumInfo[] = {
		{ ECharacterState_StaticEnum, TEXT("ECharacterState"), &Z_Registration_Info_UEnum_ECharacterState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 904429924U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActors_h_3982018262(TEXT("/Script/MyActors"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActors_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActors_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
