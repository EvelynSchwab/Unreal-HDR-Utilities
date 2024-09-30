// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "HDRUtilitiesBPLibrary.generated.h"

USTRUCT(BlueprintType)
struct FHDRDisplayInformation
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly)
	FName DeviceName;

	UPROPERTY(BlueprintReadOnly)
	float MinLuminance;
	
	UPROPERTY(BlueprintReadOnly)
	float MaxLuminance;
	
	UPROPERTY(BlueprintReadOnly)
	float MaxFullFrameLuminance;

	FHDRDisplayInformation()
	{
		DeviceName = "None";
		MinLuminance = 0.0f;
		MaxLuminance = 0.0f;
		MaxFullFrameLuminance = 0.0f;
	}
};

UCLASS()
class UHDRUtilitiesBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintPure, meta = (Keywords = "HDR"), Category = "HDR Utilities")
	static bool GetPrimaryDisplayInformation(FHDRDisplayInformation& DisplayInformation);
	
};
