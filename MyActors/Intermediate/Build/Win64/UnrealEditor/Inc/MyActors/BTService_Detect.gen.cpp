// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/BTService_Detect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_Detect() {}
// Cross Module References
	MYACTORS_API UClass* Z_Construct_UClass_UBTService_Detect_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_UBTService_Detect();
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	UPackage* Z_Construct_UPackage__Script_MyActors();
// End Cross Module References
	void UBTService_Detect::StaticRegisterNativesUBTService_Detect()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_Detect);
	UClass* Z_Construct_UClass_UBTService_Detect_NoRegister()
	{
		return UBTService_Detect::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_Detect_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_Detect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_Detect_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BTService_Detect.h" },
		{ "ModuleRelativePath", "Public/BTService_Detect.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_Detect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_Detect>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_Detect_Statics::ClassParams = {
		&UBTService_Detect::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UBTService_Detect_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_Detect_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTService_Detect()
	{
		if (!Z_Registration_Info_UClass_UBTService_Detect.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_Detect.OuterSingleton, Z_Construct_UClass_UBTService_Detect_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTService_Detect.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<UBTService_Detect>()
	{
		return UBTService_Detect::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_Detect);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_BTService_Detect_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_BTService_Detect_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_Detect, UBTService_Detect::StaticClass, TEXT("UBTService_Detect"), &Z_Registration_Info_UClass_UBTService_Detect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_Detect), 1923163289U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_BTService_Detect_h_2788584713(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_BTService_Detect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_BTService_Detect_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
