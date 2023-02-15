// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/ABWeapon.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABWeapon() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_AABWeapon_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_AABWeapon();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MyActors();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
// End Cross Module References
	void AABWeapon::StaticRegisterNativesAABWeapon()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABWeapon);
	UClass* Z_Construct_UClass_AABWeapon_NoRegister()
	{
		return AABWeapon::StaticClass();
	}
	struct Z_Construct_UClass_AABWeapon_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Weapon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Weapon;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABWeapon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABWeapon_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ABWeapon.h" },
		{ "ModuleRelativePath", "ABWeapon.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABWeapon_Statics::NewProp_Weapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ABWeapon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABWeapon_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABWeapon, Weapon), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AABWeapon_Statics::NewProp_Weapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABWeapon_Statics::NewProp_Weapon_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABWeapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABWeapon_Statics::NewProp_Weapon,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABWeapon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABWeapon>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABWeapon_Statics::ClassParams = {
		&AABWeapon::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABWeapon_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABWeapon_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AABWeapon_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AABWeapon_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AABWeapon()
	{
		if (!Z_Registration_Info_UClass_AABWeapon.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABWeapon.OuterSingleton, Z_Construct_UClass_AABWeapon_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABWeapon.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<AABWeapon>()
	{
		return AABWeapon::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABWeapon);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABWeapon_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABWeapon_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABWeapon, AABWeapon::StaticClass, TEXT("AABWeapon"), &Z_Registration_Info_UClass_AABWeapon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABWeapon), 483767112U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABWeapon_h_3884024929(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABWeapon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_ABWeapon_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
