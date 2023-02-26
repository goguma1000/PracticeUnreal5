// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaBattleSetting/Public/ABCharacterSetting.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacterSetting() {}
// Cross Module References
	ARENABATTLESETTING_API UClass* Z_Construct_UClass_UABCharacterSetting_NoRegister();
	ARENABATTLESETTING_API UClass* Z_Construct_UClass_UABCharacterSetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_ArenaBattleSetting();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
// End Cross Module References
	void UABCharacterSetting::StaticRegisterNativesUABCharacterSetting()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABCharacterSetting);
	UClass* Z_Construct_UClass_UABCharacterSetting_NoRegister()
	{
		return UABCharacterSetting::StaticClass();
	}
	struct Z_Construct_UClass_UABCharacterSetting_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterAssets_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharacterAssets_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_CharacterAssets;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABCharacterSetting_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattleSetting,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABCharacterSetting_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ABCharacterSetting.h" },
		{ "ModuleRelativePath", "Public/ABCharacterSetting.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABCharacterSetting_Statics::NewProp_CharacterAssets_Inner = { "CharacterAssets", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABCharacterSetting_Statics::NewProp_CharacterAssets_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABCharacterSetting.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABCharacterSetting_Statics::NewProp_CharacterAssets = { "CharacterAssets", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABCharacterSetting, CharacterAssets), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UABCharacterSetting_Statics::NewProp_CharacterAssets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterSetting_Statics::NewProp_CharacterAssets_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABCharacterSetting_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABCharacterSetting_Statics::NewProp_CharacterAssets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABCharacterSetting_Statics::NewProp_CharacterAssets,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABCharacterSetting_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABCharacterSetting>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABCharacterSetting_Statics::ClassParams = {
		&UABCharacterSetting::StaticClass,
		"ArenaBattle",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABCharacterSetting_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterSetting_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UABCharacterSetting_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterSetting_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UABCharacterSetting()
	{
		if (!Z_Registration_Info_UClass_UABCharacterSetting.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABCharacterSetting.OuterSingleton, Z_Construct_UClass_UABCharacterSetting_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABCharacterSetting.OuterSingleton;
	}
	template<> ARENABATTLESETTING_API UClass* StaticClass<UABCharacterSetting>()
	{
		return UABCharacterSetting::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABCharacterSetting);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_ArenaBattleSetting_Public_ABCharacterSetting_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_ArenaBattleSetting_Public_ABCharacterSetting_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABCharacterSetting, UABCharacterSetting::StaticClass, TEXT("UABCharacterSetting"), &Z_Registration_Info_UClass_UABCharacterSetting, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABCharacterSetting), 519871937U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_ArenaBattleSetting_Public_ABCharacterSetting_h_1123283272(TEXT("/Script/ArenaBattleSetting"),
		Z_CompiledInDeferFile_FID_MyActors_Source_ArenaBattleSetting_Public_ABCharacterSetting_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_ArenaBattleSetting_Public_ABCharacterSetting_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
