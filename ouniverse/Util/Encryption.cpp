//Copyright 2015-2019, All Rights Reserved.

#include "Util/Encryption.h"

#include "Secure/EncryptionKey.hs"

#include "Runtime/Core/Public/Misc/AES.h"
#include "Runtime/Core/Public/Misc/SecureHash.h"
#include "Runtime/Core/Public/Misc/Base64.h"

FEncryption::FEncryption()
{
	Result =  "";
}

FEncryption::FEncryption(FString StringData, bool bEncryptNotDecyrpt)
{
	if (bEncryptNotDecyrpt)
	{
		Result = Encrypt(StringData);
	}
	else {
		Result = Decrypt(StringData);
	}
}

FString FEncryption::Encrypt(FString InputString)
{
	// Check inputs

	FString Key = ENCRYPTION_KEY;
	if (InputString.IsEmpty()) return "";  //empty string? do nothing
	if (Key.IsEmpty()) return "";

	// To split correctly final result of decryption from trash symbols
	FString SplitSymbol = "EL@$@!";
	InputString.Append(SplitSymbol);

	// We need at least 32 symbols key
	Key = FMD5::HashAnsiString(*Key);
	TCHAR *KeyTChar = Key.GetCharArray().GetData();
	ANSICHAR *KeyAnsi = (ANSICHAR*)TCHAR_TO_ANSI(KeyTChar);

	// Calculate blob size and create blob
	uint8* Blob;
	uint32 Size;

	Size = InputString.Len();
	Size = Size + (FAES::AESBlockSize - (Size % FAES::AESBlockSize));

	Blob = new uint8[Size];

	// Convert string to bytes and encrypt
	if (StringToBytes(InputString, Blob, Size)) {

		FAES::EncryptData(Blob, Size, KeyAnsi);
		InputString = FString::FromHexBlob(Blob, Size);

		delete Blob;
		return InputString;
	}

	delete Blob;
	return "";
}

FString FEncryption::Decrypt(FString InputString)
{
	// Check inputs
	FString Key = ENCRYPTION_KEY;
	if (InputString.IsEmpty()) return "";
	if (Key.IsEmpty()) return "";

	// To split correctly final result of decryption from trash symbols
	FString SplitSymbol = "EL@$@!";

	// We need at least 32 symbols key
	Key = FMD5::HashAnsiString(*Key);
	TCHAR *KeyTChar = Key.GetCharArray().GetData();
	ANSICHAR *KeyAnsi = (ANSICHAR*)TCHAR_TO_ANSI(KeyTChar);

	// Calculate blob size and create blob
	uint8* Blob;
	uint32 Size;

	Size = InputString.Len();
	Size = Size + (FAES::AESBlockSize - (Size % FAES::AESBlockSize));

	Blob = new uint8[Size];

	// Convert string to bytes and decrypt
	if (FString::ToHexBlob(InputString, Blob, Size)) {

		FAES::DecryptData(Blob, Size, KeyAnsi);
		InputString = BytesToString(Blob, Size);

		// Split required data from trash
		FString LeftData;
		FString RightData;
		InputString.Split(SplitSymbol, &LeftData, &RightData, ESearchCase::CaseSensitive, ESearchDir::FromStart);
		InputString = LeftData;

		delete Blob;
		return InputString;
	}

	delete Blob;
	return "";
}

FString FEncryption::Out()
{
	return Result;
}