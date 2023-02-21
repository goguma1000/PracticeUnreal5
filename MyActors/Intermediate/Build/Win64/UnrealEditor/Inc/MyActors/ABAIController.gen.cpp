// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/ABAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABAIController() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_AABAIController_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_AABAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_MyActors();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
// End Cross Module References
	void AABAIController::StaticRegisterNativesAABAIController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABAIController);
	UClass* Z_Construct_UClass_AABAIController_NoRegister()
	{
		return AABAIController::StaticClass();
	}
	struct Z_Construct_UClass_AABAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BTAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BTAsset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BBAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BBAsset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABAIController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "ABAIController.h" },
		{ "ModuleRelativePath", "ABAIController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABAIController_Statics::NewProp_BTAsset_MetaData[] = {
		{ "ModuleRelativePath", "ABAIController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABAIController_Statics::NewProp_BTAsset = { "BTAsset", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABAIController, BTAsset), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AABAIController_Statics::NewProp_BTAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABAIController_Statics::NewProp_BTAsset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABAIController_Statics::NewProp_BBAsset_MetaData[] = {
		{ "ModuleRelativePath", "ABAIController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABAIController_Statics::NewProp_BBAsset = { "BBAsset", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABAIController, BBAsset), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AABAIController_Statics::NewProp_BBAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABAIController_Statics::NewProp_BBAsset_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABAIController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABAIController_Statics::NewProp_BTAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABAIController_Statics::NewProp_BBAsset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABAIController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABAIController_Statics::ClassParams = {
		&AABAIController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABAIController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABAIController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AABAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AABAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AABAIController()
	{
		if (!Z_Registration_Info_UClass_AABAIController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABAIController.OuterSingleton, Z_Construct_UClass_AABAIController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABAIController.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<AABAIController>()
	{
		return AABAIController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABAIController);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABAIController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABAIController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABAIController, AABAIController::StaticClass, TEXT("AABAIController"), &Z_Registration_Info_UClass_AABAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABAIController), 2865047742U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABAIController_h_4151614533(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABAIController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
