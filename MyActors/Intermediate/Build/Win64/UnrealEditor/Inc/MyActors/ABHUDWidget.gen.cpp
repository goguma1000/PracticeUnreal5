// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/ABHUDWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABHUDWidget() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_UABHUDWidget_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_UABHUDWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_MyActors();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
// End Cross Module References
	void UABHUDWidget::StaticRegisterNativesUABHUDWidget()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABHUDWidget);
	UClass* Z_Construct_UClass_UABHUDWidget_NoRegister()
	{
		return UABHUDWidget::StaticClass();
	}
	struct Z_Construct_UClass_UABHUDWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HPBar_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HPBar;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExpBar_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ExpBar;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerLevel_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerLevel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentScore_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentScore;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HighScore_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HighScore;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABHUDWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHUDWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ABHUDWidget.h" },
		{ "ModuleRelativePath", "Public/ABHUDWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HPBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABHUDWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HPBar = { "HPBar", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABHUDWidget, HPBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HPBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HPBar_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHUDWidget_Statics::NewProp_ExpBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABHUDWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABHUDWidget_Statics::NewProp_ExpBar = { "ExpBar", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABHUDWidget, ExpBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_ExpBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_ExpBar_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerName_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABHUDWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerName = { "PlayerName", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABHUDWidget, PlayerName), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerLevel_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABHUDWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerLevel = { "PlayerLevel", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABHUDWidget, PlayerLevel), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerLevel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerLevel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHUDWidget_Statics::NewProp_CurrentScore_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABHUDWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABHUDWidget_Statics::NewProp_CurrentScore = { "CurrentScore", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABHUDWidget, CurrentScore), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_CurrentScore_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_CurrentScore_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HighScore_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABHUDWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HighScore = { "HighScore", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABHUDWidget, HighScore), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HighScore_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HighScore_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABHUDWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HPBar,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABHUDWidget_Statics::NewProp_ExpBar,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABHUDWidget_Statics::NewProp_PlayerLevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABHUDWidget_Statics::NewProp_CurrentScore,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABHUDWidget_Statics::NewProp_HighScore,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABHUDWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABHUDWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABHUDWidget_Statics::ClassParams = {
		&UABHUDWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABHUDWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABHUDWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UABHUDWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UABHUDWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UABHUDWidget()
	{
		if (!Z_Registration_Info_UClass_UABHUDWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABHUDWidget.OuterSingleton, Z_Construct_UClass_UABHUDWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABHUDWidget.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<UABHUDWidget>()
	{
		return UABHUDWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABHUDWidget);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABHUDWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABHUDWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABHUDWidget, UABHUDWidget::StaticClass, TEXT("UABHUDWidget"), &Z_Registration_Info_UClass_UABHUDWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABHUDWidget), 2977422871U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABHUDWidget_h_2895071277(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABHUDWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABHUDWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
