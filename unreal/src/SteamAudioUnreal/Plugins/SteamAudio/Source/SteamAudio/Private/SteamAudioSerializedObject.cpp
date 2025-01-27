//
// Copyright (C) Valve Corporation. All rights reserved.
//

#include "SteamAudioSerializedObject.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/UObjectGlobals.h"

// ---------------------------------------------------------------------------------------------------------------------
// USteamAudioSerializedObject
// ---------------------------------------------------------------------------------------------------------------------

USteamAudioSerializedObject* USteamAudioSerializedObject::SerializeObjectToPackage(IPLSerializedObject SerializedObject, const FString& AssetName)
{
    int DataSize = iplSerializedObjectGetSize(SerializedObject);
    uint8* DataBuffer = iplSerializedObjectGetData(SerializedObject);

    FString PackageName;
    FString ObjectName;
    if (!AssetName.Split(".", &PackageName, &ObjectName))
        return nullptr;

    // Create an empty package.
    UPackage* Package = CreatePackage(*PackageName);
    if (!Package)
        return nullptr;

    Package->FullyLoad();

    // Create a new UObject in the package that will hold the data from the IPLSerializedObject.
    USteamAudioSerializedObject* Object = NewObject<USteamAudioSerializedObject>(Package, *ObjectName, RF_Public | RF_Standalone | RF_MarkAsRootSet);
    if (!Object)
        return nullptr;

    // Copy the data into the UObject.
    Object->Data.SetNum(DataSize);
    FMemory::Memcpy(Object->Data.GetData(), DataBuffer, DataSize);

    // Save the package.
    Package->MarkPackageDirty();
    FAssetRegistryModule::AssetCreated(Object);
    FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
    if (!UPackage::SavePackage(Package, Object, RF_Public | RF_Standalone, *PackageFileName))
        return nullptr;

    return Object;
}
