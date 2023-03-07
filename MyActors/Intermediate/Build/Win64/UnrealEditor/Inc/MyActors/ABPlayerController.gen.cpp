// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/ABPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABPlayerController() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_AABPlayerController_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_AABPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_MyActors();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	MYACTORS_API UClass* Z_Construct_UClass_UABHUDWidget_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_AABPlayerState_NoRegister();
// End Cross Module References
	void AABPlayerController::StaticRegisterNativesAABPlayerController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABPlayerController);
	UClass* Z_Construct_UClass_AABPlayerController_NoRegister()
	{
		return AABPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AABPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_HUDWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HUDWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ABPlayerState_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ABPlayerState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "ABPlayerController.h" },
		{ "ModuleRelativePath", "Public/ABPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/ABPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidgetClass = { "HUDWidgetClass", nullptr, (EPropertyFlags)0x0024080000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABPlayerController, HUDWidgetClass), Z_Construct_UClass_UABHUDWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidgetClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidget = { "HUDWidget", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABPlayerController, HUDWidget), Z_Construct_UClass_UABHUDWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABPlayerController_Statics::NewProp_ABPlayerState_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABPlayerController_Statics::NewProp_ABPlayerState = { "ABPlayerState", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABPlayerController, ABPlayerState), Z_Construct_UClass_AABPlayerState_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AABPlayerController_Statics::NewProp_ABPlayerState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABPlayerController_Statics::NewProp_ABPlayerState_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABPlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABPlayerController_Statics::NewProp_HUDWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABPlayerController_Statics::NewProp_ABPlayerState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABPlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABPlayerController_Statics::ClassParams = {
		&AABPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABPlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABPlayerController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AABPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AABPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AABPlayerController()
	{
		if (!Z_Registration_Info_UClass_AABPlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABPlayerController.OuterSingleton, Z_Construct_UClass_AABPlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABPlayerController.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<AABPlayerController>()
	{
		return AABPlayerController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABPlayerController);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABPlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABPlayerController, AABPlayerController::StaticClass, TEXT("AABPlayerController"), &Z_Registration_Info_UClass_AABPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABPlayerController), 4269923238U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABPlayerController_h_174015255(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABPlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
