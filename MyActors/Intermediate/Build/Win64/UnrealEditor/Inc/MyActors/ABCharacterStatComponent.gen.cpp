// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/ABCharacterStatComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacterStatComponent() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_UABCharacterStatComponent_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_UABCharacterStatComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_MyActors();
// End Cross Module References
	void UABCharacterStatComponent::StaticRegisterNativesUABCharacterStatComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABCharacterStatComponent);
	UClass* Z_Construct_UClass_UABCharacterStatComponent_NoRegister()
	{
		return UABCharacterStatComponent::StaticClass();
	}
	struct Z_Construct_UClass_UABCharacterStatComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHP_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHP;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABCharacterStatComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABCharacterStatComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ABCharacterStatComponent.h" },
		{ "ModuleRelativePath", "Public/ABCharacterStatComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_Level_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "Public/ABCharacterStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0040000000000801, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABCharacterStatComponent, Level), METADATA_PARAMS(Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_Level_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_Level_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_CurrentHP_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "Public/ABCharacterStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_CurrentHP = { "CurrentHP", nullptr, (EPropertyFlags)0x0040000000022801, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABCharacterStatComponent, CurrentHP), METADATA_PARAMS(Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_CurrentHP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_CurrentHP_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABCharacterStatComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABCharacterStatComponent_Statics::NewProp_CurrentHP,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABCharacterStatComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABCharacterStatComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABCharacterStatComponent_Statics::ClassParams = {
		&UABCharacterStatComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABCharacterStatComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterStatComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UABCharacterStatComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterStatComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UABCharacterStatComponent()
	{
		if (!Z_Registration_Info_UClass_UABCharacterStatComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABCharacterStatComponent.OuterSingleton, Z_Construct_UClass_UABCharacterStatComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABCharacterStatComponent.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<UABCharacterStatComponent>()
	{
		return UABCharacterStatComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABCharacterStatComponent);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABCharacterStatComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABCharacterStatComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABCharacterStatComponent, UABCharacterStatComponent::StaticClass, TEXT("UABCharacterStatComponent"), &Z_Registration_Info_UClass_UABCharacterStatComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABCharacterStatComponent), 948459605U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABCharacterStatComponent_h_4060235974(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABCharacterStatComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABCharacterStatComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
