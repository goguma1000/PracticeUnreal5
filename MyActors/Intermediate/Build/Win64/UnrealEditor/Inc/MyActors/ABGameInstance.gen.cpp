// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyActors/Public/ABGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABGameInstance() {}
// Cross Module References
	MYACTORS_API UScriptStruct* Z_Construct_UScriptStruct_FABCharacterData();
	UPackage* Z_Construct_UPackage__Script_MyActors();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	MYACTORS_API UClass* Z_Construct_UClass_UABGameInstance_NoRegister();
	MYACTORS_API UClass* Z_Construct_UClass_UABGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
// End Cross Module References

static_assert(std::is_polymorphic<FABCharacterData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FABCharacterData cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ABCharacterData;
class UScriptStruct* FABCharacterData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ABCharacterData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ABCharacterData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FABCharacterData, Z_Construct_UPackage__Script_MyActors(), TEXT("ABCharacterData"));
	}
	return Z_Registration_Info_UScriptStruct_ABCharacterData.OuterSingleton;
}
template<> MYACTORS_API UScriptStruct* StaticStruct<FABCharacterData>()
{
	return FABCharacterData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FABCharacterData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHP_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Attack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DropExp_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_DropExp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NextExp_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NextExp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FABCharacterData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "ModuleRelativePath", "Public/ABGameInstance.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FABCharacterData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FABCharacterData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Level_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/ABGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FABCharacterData, Level), METADATA_PARAMS(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Level_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Level_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_MaxHP_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/ABGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_MaxHP = { "MaxHP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FABCharacterData, MaxHP), METADATA_PARAMS(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_MaxHP_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_MaxHP_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Attack_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/ABGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FABCharacterData, Attack), METADATA_PARAMS(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Attack_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Attack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_DropExp_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/ABGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_DropExp = { "DropExp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FABCharacterData, DropExp), METADATA_PARAMS(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_DropExp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_DropExp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_NextExp_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/ABGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_NextExp = { "NextExp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FABCharacterData, NextExp), METADATA_PARAMS(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_NextExp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_NextExp_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FABCharacterData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_MaxHP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_Attack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_DropExp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FABCharacterData_Statics::NewProp_NextExp,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FABCharacterData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"ABCharacterData",
		sizeof(FABCharacterData),
		alignof(FABCharacterData),
		Z_Construct_UScriptStruct_FABCharacterData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FABCharacterData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FABCharacterData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FABCharacterData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FABCharacterData()
	{
		if (!Z_Registration_Info_UScriptStruct_ABCharacterData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ABCharacterData.InnerSingleton, Z_Construct_UScriptStruct_FABCharacterData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ABCharacterData.InnerSingleton;
	}
	void UABGameInstance::StaticRegisterNativesUABGameInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABGameInstance);
	UClass* Z_Construct_UClass_UABGameInstance_NoRegister()
	{
		return UABGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UABGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ABCharacterTable_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ABCharacterTable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_MyActors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABGameInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ABGameInstance.h" },
		{ "ModuleRelativePath", "Public/ABGameInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABGameInstance_Statics::NewProp_ABCharacterTable_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABGameInstance_Statics::NewProp_ABCharacterTable = { "ABCharacterTable", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABGameInstance, ABCharacterTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UABGameInstance_Statics::NewProp_ABCharacterTable_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABGameInstance_Statics::NewProp_ABCharacterTable_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABGameInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABGameInstance_Statics::NewProp_ABCharacterTable,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABGameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABGameInstance_Statics::ClassParams = {
		&UABGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABGameInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABGameInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UABGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UABGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UABGameInstance()
	{
		if (!Z_Registration_Info_UClass_UABGameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABGameInstance.OuterSingleton, Z_Construct_UClass_UABGameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABGameInstance.OuterSingleton;
	}
	template<> MYACTORS_API UClass* StaticClass<UABGameInstance>()
	{
		return UABGameInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABGameInstance);
	struct Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameInstance_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameInstance_h_Statics::ScriptStructInfo[] = {
		{ FABCharacterData::StaticStruct, Z_Construct_UScriptStruct_FABCharacterData_Statics::NewStructOps, TEXT("ABCharacterData"), &Z_Registration_Info_UScriptStruct_ABCharacterData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FABCharacterData), 1380293921U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABGameInstance, UABGameInstance::StaticClass, TEXT("UABGameInstance"), &Z_Registration_Info_UClass_UABGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABGameInstance), 3880641137U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameInstance_h_1956407588(TEXT("/Script/MyActors"),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameInstance_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameInstance_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyActors_Source_MyActors_Public_ABGameInstance_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
