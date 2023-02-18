// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/ABCharacterWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacterWidget() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_UABCharacterWidget_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_UABCharacterWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_MyActors();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
// End Cross Module References
	void UABCharacterWidget::StaticRegisterNativesUABCharacterWidget()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABCharacterWidget);
	UClass* Z_Construct_UClass_UABCharacterWidget_NoRegister()
	{
		return UABCharacterWidget::StaticClass();
	}
	struct Z_Construct_UClass_UABCharacterWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HPProgressBar_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HPProgressBar;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABCharacterWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABCharacterWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ABCharacterWidget.h" },
		{ "ModuleRelativePath", "ABCharacterWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABCharacterWidget_Statics::NewProp_HPProgressBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ABCharacterWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABCharacterWidget_Statics::NewProp_HPProgressBar = { "HPProgressBar", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABCharacterWidget, HPProgressBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UABCharacterWidget_Statics::NewProp_HPProgressBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterWidget_Statics::NewProp_HPProgressBar_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABCharacterWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABCharacterWidget_Statics::NewProp_HPProgressBar,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABCharacterWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABCharacterWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABCharacterWidget_Statics::ClassParams = {
		&UABCharacterWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABCharacterWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UABCharacterWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UABCharacterWidget()
	{
		if (!Z_Registration_Info_UClass_UABCharacterWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABCharacterWidget.OuterSingleton, Z_Construct_UClass_UABCharacterWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABCharacterWidget.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<UABCharacterWidget>()
	{
		return UABCharacterWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABCharacterWidget);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABCharacterWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABCharacterWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABCharacterWidget, UABCharacterWidget::StaticClass, TEXT("UABCharacterWidget"), &Z_Registration_Info_UClass_UABCharacterWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABCharacterWidget), 3577474379U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABCharacterWidget_h_343202291(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABCharacterWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABCharacterWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
