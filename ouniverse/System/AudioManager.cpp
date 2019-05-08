//Copyright 2015-2019, All Rights Reserved.

#include "System/AudioManager.h"
#include "System/AudioGroup.h"

#include "Kismet/GameplayStatics.h"
#include "VorbisAudioInfo.h"
#include "Components/AudioComponent.h"
#include "AudioDecompress.h"
#include "AudioDevice.h"
#include "ActiveSound.h"
#include "Audio.h"
#include "Developer/TargetPlatform/Public/Interfaces/IAudioFormat.h"

#include "System/UiManager.h"
#include "Engine/World.h"
#include "Misc/FileHelper.h"
#include "CohtmlHUD.h"
#include "cohtml/Binding/EventHandler.h"
#include "cohtml/Binding/Binding.h"
#include "CohtmlFStringBinder.h"


AudioManager* AudioManager::Create(UWorld* Scope)
{
	return new AudioManager(Scope);
}

AudioManager::AudioManager(UWorld* Scope)
{
	AudioGroup* Internal = RegisterAudioGroup("internal", AudioGroups::Internal, nullptr);
	AudioGroup* Master = RegisterAudioGroup("master", AudioGroups::Master, Internal);
	AudioGroup* UI = RegisterAudioGroup("ui", AudioGroups::UI, Master);
	RegisterAudioGroup("fanfare", AudioGroups::Fanfare, UI);
	RegisterAudioGroup("tones", AudioGroups::Tones, UI);
	AudioGroup* World = RegisterAudioGroup("world", AudioGroups::World, Master);
	AudioGroup* Voice = RegisterAudioGroup("voice", AudioGroups::Voice, World);
	RegisterAudioGroup("banter", AudioGroups::Banter, Voice);
	RegisterAudioGroup("dialogue", AudioGroups::Dialogue, Voice);
	RegisterAudioGroup("impacts", AudioGroups::Impacts, World);
}


AudioGroup* AudioManager::RegisterAudioGroup(FString ID, AudioGroups Group, AudioGroup* Parent)
{

	AudioGroup* NewGroup = new AudioGroup();
	NewGroup->ID = ID;

	if (Parent!=NULL)
	{
		NewGroup->SetParent(Parent);
	}

	AudioGroupsVector[Group] = NewGroup;

	return NewGroup;
}


void AudioManager::BindUI()
{
	//Ui->BindCall("audioMNG.playSoundUI", cohtml::MakeHandler(this, &UAudioManager::PlaySoundUI));
	//Ui->BindCall("audioMNG.playSoundUIFullPath", cohtml::MakeHandler(this, &UAudioManager::PlaySoundUIFullPath));
}

void AudioManager::PlaySoundUI(FString FilePath, int Group, float VolumeMultiplier, float PitchMultiplier)
{
	PlaySoundUIFullPath(FilePath, Group, VolumeMultiplier, PitchMultiplier);
}

void AudioManager::PlaySoundUIFullPath(FString FilePath, int Group, float VolumeMultiplier, float PitchMultiplier)
{
	USoundWave* SoundWave = GetSoundWaveFromFile(*FilePath);
	USoundConcurrency* Concurrency = NewObject<USoundConcurrency>();

	if (SoundWave)
	{
		if (FAudioDevice* AudioDevice = Scope->GetAudioDevice())
		{
			FActiveSound NewActiveSound;
			NewActiveSound.SetSound(SoundWave);
			NewActiveSound.SetWorld(Scope);

			NewActiveSound.VolumeMultiplier = 1.0f;
			NewActiveSound.PitchMultiplier = 1.0f;

			NewActiveSound.RequestedStartTime = FMath::Max(0.f, 0.0f);

			NewActiveSound.bIsUISound = true;
			NewActiveSound.bAllowSpatialization = false;
			//NewActiveSound.ConcurrencySettings = (USoundConcurrency*)nullptr;
			NewActiveSound.Priority = SoundWave->Priority;
			NewActiveSound.SubtitlePriority = SoundWave->GetSubtitlePriority();

			NewActiveSound.SetOwner((AActor*)nullptr);

			AudioDevice->AddNewActiveSound(NewActiveSound);
		}
	}
}

bool AudioManager::PlaySound2DFromFile(const FString& FilePath, float VolumeMultiplier, float PitchMultiplier, float StartTime)
{
	USoundWave* SoundWave = GetSoundWaveFromFile(FilePath);
	USoundConcurrency* Concurrency = NewObject<USoundConcurrency>();

	if (!SoundWave)
		return false;

	UGameplayStatics::PlaySound2D(Scope, SoundWave, VolumeMultiplier, PitchMultiplier, StartTime, Concurrency);
	return true;
}

class UAudioComponent* AudioManager::PlaySoundAttachedFromFile(const FString& FilePath, class USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, EAttachLocation::Type LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundAttenuation* AttenuationSettings)
{
	USoundWave* SoundWave = GetSoundWaveFromFile(FilePath);

	if (!SoundWave)
		return NULL;

	return UGameplayStatics::SpawnSoundAttached(SoundWave, AttachToComponent, AttachPointName, Location, LocationType, bStopWhenAttachedToDestroyed, VolumeMultiplier, PitchMultiplier, StartTime, AttenuationSettings);
}

void AudioManager::PlaySoundAtLocationFromFile(UObject* WorldContextObject, const FString& FilePath, FVector Location, float VolumeMultiplier, float PitchMultiplier, float StartTime, class USoundAttenuation* AttenuationSettings)
{
	USoundWave* SoundWave = GetSoundWaveFromFile(FilePath);

	if (!SoundWave)
		return;

	UGameplayStatics::PlaySoundAtLocation(WorldContextObject, SoundWave, Location, VolumeMultiplier, PitchMultiplier, StartTime, AttenuationSettings);
}

class USoundWave* AudioManager::GetSoundWaveFromFile(const FString& FilePath)
{
#if PLATFORM_PS4
	UE_LOG(LogTemp, Error, TEXT("UVictoryBPFunctionLibrary::GetSoundWaveFromFile ~ vorbis-method not supported on PS4. See UVictoryBPFunctionLibrary::fillSoundWaveInfo"));
	return nullptr;
#else
	USoundWave* SoundWave = NewObject<USoundWave>(USoundWave::StaticClass());

	if (!SoundWave)
		return NULL;

	//* If true the song was successfully loaded
	bool loaded = false;

	//* loaded song file (binary, encoded)
	TArray < uint8 > rawFile;

	loaded = FFileHelper::LoadFileToArray(rawFile, FilePath.GetCharArray().GetData());
	if (loaded)
	{
		FByteBulkData* bulkData = &SoundWave->CompressedFormatData.GetFormat(TEXT("OGG"));

		bulkData->Lock(LOCK_READ_WRITE);
		FMemory::Memcpy(bulkData->Realloc(rawFile.Num()), rawFile.GetData(), rawFile.Num());
		bulkData->Unlock();

		loaded = FillSoundWaveInfo(SoundWave, &rawFile) == 0 ? true : false;
	}

	if (!loaded)
		return NULL;

	return SoundWave;
#endif 
}

#if !PLATFORM_PS4
int32 AudioManager::FillSoundWaveInfo(USoundWave* SoundWave, TArray<uint8>* rawFile)
{
	FSoundQualityInfo info;
	FVorbisAudioInfo vorbis_obj;
	if (!vorbis_obj.ReadCompressedInfo(rawFile->GetData(), rawFile->Num(), &info))
	{
		//Debug("Can't load header");
		return 1;
	}

	if (!SoundWave) return 1;
	SoundWave->SoundGroup = ESoundGroup::SOUNDGROUP_Default;
	SoundWave->NumChannels = info.NumChannels;
	SoundWave->Duration = info.Duration;
	SoundWave->RawPCMDataSize = info.SampleDataSize;
	SoundWave->SetSampleRate(info.SampleRate);
	return 0;
}


int32 AudioManager::FindSource(class USoundWave* SoundWave, class FSoundSource* out_audioSource)
{
	FAudioDevice* device = GEngine ? GEngine->GetMainAudioDevice() : NULL; //gently ask for the audio device

	FActiveSound* activeSound;
	FSoundSource* audioSource;
	FWaveInstance* sw_instance;
	if (!device)
	{
		activeSound = NULL;
		audioSource = NULL;
		out_audioSource = audioSource;
		return -1;
	}

	TArray<FActiveSound*> tmpActualSounds = device->GetActiveSounds();
	if (tmpActualSounds.Num())
	{
		for (auto activeSoundIt(tmpActualSounds.CreateIterator()); activeSoundIt; ++activeSoundIt)
		{
			activeSound = *activeSoundIt;
			for (auto WaveInstanceIt(activeSound->WaveInstances.CreateIterator()); WaveInstanceIt; ++WaveInstanceIt)
			{
				sw_instance = WaveInstanceIt.Value();
				if (sw_instance->WaveData->CompressedDataGuid == SoundWave->CompressedDataGuid)
				{
					audioSource = device->GetSoundSource(sw_instance); //4.13 onwards, <3 Rama
					out_audioSource = audioSource;
					return 0;
				}
			}
		}
	}

	audioSource = NULL;
	activeSound = NULL;
	out_audioSource = audioSource;
	return -2;
}
#endif //PLATFORM_PS4
