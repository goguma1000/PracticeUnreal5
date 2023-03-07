// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/ABGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABGameMode() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_AABGameMode_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_AABGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MyActors();
	MYACTORS_API UClass* Z_Construct_UClass_AABGameState_NoRegister();
// End Cross Module References
	void AABGameMode::StaticRegisterNativesAABGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABGameMode);
	UClass* Z_Construct_UClass_AABGameMode_NoRegister()
	{
		return AABGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AABGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ABGameState_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ABGameState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ABGameMode.h" },
		{ "ModuleRelativePath", "Public/ABGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABGameMode_Statics::NewProp_ABGameState_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABGameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABGameMode_Statics::NewProp_ABGameState = { "ABGameState", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABGameMode, ABGameState), Z_Construct_UClass_AABGameState_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AABGameMode_Statics::NewProp_ABGameState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABGameMode_Statics::NewProp_ABGameState_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABGameMode_Statics::NewProp_ABGameState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABGameMode_Statics::ClassParams = {
		&AABGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AABGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AABGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AABGameMode()
	{
		if (!Z_Registration_Info_UClass_AABGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABGameMode.OuterSingleton, Z_Construct_UClass_AABGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABGameMode.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<AABGameMode>()
	{
		return AABGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABGameMode);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABGameMode, AABGameMode::StaticClass, TEXT("AABGameMode"), &Z_Registration_Info_UClass_AABGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABGameMode), 4146072903U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameMode_h_4080299229(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
