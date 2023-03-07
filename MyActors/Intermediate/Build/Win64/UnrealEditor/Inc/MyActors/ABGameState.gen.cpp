// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/ABGameState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABGameState() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_AABGameState_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_AABGameState();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_MyActors();
// End Cross Module References
	void AABGameState::StaticRegisterNativesAABGameState()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABGameState);
	UClass* Z_Construct_UClass_AABGameState_NoRegister()
	{
		return AABGameState::StaticClass();
	}
	struct Z_Construct_UClass_AABGameState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TotalGameScore_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TotalGameScore;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABGameState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameStateBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABGameState_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ABGameState.h" },
		{ "ModuleRelativePath", "Public/ABGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABGameState_Statics::NewProp_TotalGameScore_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABGameState.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AABGameState_Statics::NewProp_TotalGameScore = { "TotalGameScore", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABGameState, TotalGameScore), METADATA_PARAMS(Z_Construct_UClass_AABGameState_Statics::NewProp_TotalGameScore_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABGameState_Statics::NewProp_TotalGameScore_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABGameState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABGameState_Statics::NewProp_TotalGameScore,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABGameState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABGameState>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABGameState_Statics::ClassParams = {
		&AABGameState::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABGameState_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABGameState_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AABGameState_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AABGameState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AABGameState()
	{
		if (!Z_Registration_Info_UClass_AABGameState.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABGameState.OuterSingleton, Z_Construct_UClass_AABGameState_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABGameState.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<AABGameState>()
	{
		return AABGameState::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABGameState);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameState_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameState_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABGameState, AABGameState::StaticClass, TEXT("AABGameState"), &Z_Registration_Info_UClass_AABGameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABGameState), 4027378503U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameState_h_2908067485(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameState_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
