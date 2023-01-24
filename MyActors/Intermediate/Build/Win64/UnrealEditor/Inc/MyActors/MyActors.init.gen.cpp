// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyActors_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MyActors;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MyActors()
	{
		if (!Z_Registration_Info_UPackage__Script_MyActors.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MyActors",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xDF333990,
				0x1B53E820,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MyActors.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MyActors.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MyActors(Z_Construct_UPackage__Script_MyActors, TEXT("/Script/MyActors"), Z_Registration_Info_UPackage__Script_MyActors, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xDF333990, 0x1B53E820));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
