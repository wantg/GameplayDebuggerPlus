#pragma once

#if WITH_GAMEPLAY_DEBUGGER

#include "CoreMinimal.h"
#include "GameplayDebuggerCategory.h"

class APlayerController;
class AActor;

class FGameplayDebuggerCategory_Generic : public FGameplayDebuggerCategory {
   public:
    FGameplayDebuggerCategory_Generic();
    void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
    void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;

    static TSharedRef<FGameplayDebuggerCategory> MakeInstance();
    inline static FName CategoryName = "Generic";

   protected:
    struct FRepData {
        // Put all data you want to display here
        TMap<FString, FString> ControlledPawnInfoMap;
        TMap<FString, FString> DebugActorInfoMap;

        void Serialize(FArchive& Ar);
    };

    FRepData DataPack;
};

#endif // WITH_GAMEPLAY_DEBUGGER
