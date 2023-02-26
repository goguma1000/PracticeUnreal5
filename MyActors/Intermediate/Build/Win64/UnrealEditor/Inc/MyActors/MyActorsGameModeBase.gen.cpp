// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/MyActorsGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyActorsGameModeBase() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_AMyActorsGameModeBase_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_AMyActorsGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MyActors();
// End Cross Module References
	void AMyActorsGameModeBase::StaticRegisterNativesAMyActorsGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyActorsGameModeBase);
	UClass* Z_Construct_UClass_AMyActorsGameModeBase_NoRegister()
	{
		return AMyActorsGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AMyActorsGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyActorsGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActorsGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MyActorsGameModeBase.h" },
		{ "ModuleRelativePath", "Public/MyActorsGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyActorsGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyActorsGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyActorsGameModeBase_Statics::ClassParams = {
		&AMyActorsGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMyActorsGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActorsGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyActorsGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AMyActorsGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyActorsGameModeBase.OuterSingleton, Z_Construct_UClass_AMyActorsGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyActorsGameModeBase.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<AMyActorsGameModeBase>()
	{
		return AMyActorsGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyActorsGameModeBase);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActorsGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActorsGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyActorsGameModeBase, AMyActorsGameModeBase::StaticClass, TEXT("AMyActorsGameModeBase"), &Z_Registration_Info_UClass_AMyActorsGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyActorsGameModeBase), 39506997U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActorsGameModeBase_h_2898313208(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActorsGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_MyActorsGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
