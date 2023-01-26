// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Fountain.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFountain() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_AFountain_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_AFountain();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MyActors();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_URotatingMovementComponent_NoRegister();
// End Cross Module References
	void AFountain::StaticRegisterNativesAFountain()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFountain);
	UClass* Z_Construct_UClass_AFountain_NoRegister()
	{
		return AFountain::StaticClass();
	}
	struct Z_Construct_UClass_AFountain_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Water_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Water;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Body;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Light_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Light;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Splash_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Splash;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Movement_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Movement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotateSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotateSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFountain_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Fountain.h" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Water_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Water = { "Water", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Water), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Water_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Water_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Body_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Body), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Body_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Body_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Light_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Light = { "Light", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Light), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Light_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Light_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Splash_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Splash = { "Splash", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Splash), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Splash_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Splash_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_Movement_MetaData[] = {
		{ "Category", "Fountain" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_Movement = { "Movement", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, Movement), Z_Construct_UClass_URotatingMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_Movement_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_Movement_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_ID_MetaData[] = {
		{ "Category", "ID" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, ID), METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_ID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_ID_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "Fountain.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed = { "RotateSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFountain, RotateSpeed), METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFountain_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Water,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Body,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Light,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Splash,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_Movement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_ID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFountain_Statics::NewProp_RotateSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFountain_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFountain>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFountain_Statics::ClassParams = {
		&AFountain::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFountain_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFountain_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFountain_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFountain()
	{
		if (!Z_Registration_Info_UClass_AFountain.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFountain.OuterSingleton, Z_Construct_UClass_AFountain_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFountain.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<AFountain>()
	{
		return AFountain::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFountain);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Fountain_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Fountain_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFountain, AFountain::StaticClass, TEXT("AFountain"), &Z_Registration_Info_UClass_AFountain, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFountain), 958197580U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Fountain_h_2024376649(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Fountain_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Fountain_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
