// Copyright Epic Games, Inc. All Rights Reserved.

#include "HDRUtilitiesBPLibrary.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <dxgi1_6.h>
#endif

UHDRUtilitiesBPLibrary::UHDRUtilitiesBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	
}

bool UHDRUtilitiesBPLibrary::GetPrimaryDisplayInformation(FHDRDisplayInformation& DisplayInformation)
{
#if PLATFORM_WINDOWS
	HRESULT hr = S_OK;
	IDXGIFactory6* pFactory = nullptr;

	hr = CreateDXGIFactory1(__uuidof(IDXGIFactory6), (void**)&pFactory);
	if(SUCCEEDED(hr) && pFactory)
	{
		IDXGIAdapter1* pAdapter = nullptr;
		hr = pFactory->EnumAdapters1(0, &pAdapter);
		if (SUCCEEDED(hr) && pAdapter)
		{
			IDXGIOutput* pOutput = nullptr;
			hr = pAdapter->EnumOutputs(0, &pOutput);
			if (SUCCEEDED(hr) && pOutput)
			{
				IDXGIOutput6* pOutput6 = nullptr;
				hr = pOutput->QueryInterface(__uuidof(IDXGIOutput6), (void**)&pOutput6);
				if (SUCCEEDED(hr) && pOutput6)
				{
					FHDRDisplayInformation HDRDIsplayInfo;
					DXGI_OUTPUT_DESC1 desc1;
					hr = pOutput6->GetDesc1(&desc1);
					if (SUCCEEDED(hr))
					{
						HDRDIsplayInfo.DeviceName = desc1.DeviceName;
						HDRDIsplayInfo.MaxLuminance = desc1.MaxLuminance;
						HDRDIsplayInfo.MinLuminance = desc1.MinLuminance;
						HDRDIsplayInfo.MaxFullFrameLuminance = desc1.MaxFullFrameLuminance;
					}
					pOutput6->Release();
					DisplayInformation = HDRDIsplayInfo;
					return true;
				}
			}
		}
	}
	
#endif
	UE_LOG(LogTemp, Log, TEXT("[UHDRUtilitiesBPLibrary::GetPrimaryDisplayInformation] The system does not support IDXGIOutput6"));
	
	return false;
}
