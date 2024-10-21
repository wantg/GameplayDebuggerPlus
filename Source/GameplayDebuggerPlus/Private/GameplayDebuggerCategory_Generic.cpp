#include "GameplayDebuggerCategory_Generic.h"
#include "GameplayDebuggerPlusInterface.h"

#if WITH_GAMEPLAY_DEBUGGER

#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

FGameplayDebuggerCategory_Generic::FGameplayDebuggerCategory_Generic() {
    SetDataPackReplication(&DataPack);
}

void FGameplayDebuggerCategory_Generic::CollectData(APlayerController* OwnerPC, AActor* DebugActor) {
    if (OwnerPC) {
        if (IGameplayDebuggerPlusInterface* GameplayDebuggerPlusInterface = Cast<IGameplayDebuggerPlusInterface>(OwnerPC->GetPawn())) {
            DataPack.ControlledPawnInfoMap = GameplayDebuggerPlusInterface->GetDebugInfoMap();
        }
        if (OwnerPC->GetPawn() == DebugActor) return;
    }
    if (DebugActor) {
        if (IGameplayDebuggerPlusInterface* GameplayDebuggerPlusInterface = Cast<IGameplayDebuggerPlusInterface>(DebugActor)) {
            DataPack.DebugActorInfoMap = GameplayDebuggerPlusInterface->GetDebugInfoMap();
        }
    }
}

void FGameplayDebuggerCategory_Generic::DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) {
    for (TPair<FString, FString> Pair : DataPack.ControlledPawnInfoMap) {
        if (Pair.Key.Len() * Pair.Value.Len() == 0) {
            CanvasContext.Printf(TEXT("{yellow}%s"), *(Pair.Key + Pair.Value));
        } else {
            CanvasContext.Printf(TEXT("{yellow}%s: {white}%s"), *Pair.Key, *Pair.Value);
        }
    }
    CanvasContext.Printf(TEXT(""));
    for (TPair<FString, FString> Pair : DataPack.DebugActorInfoMap) {
        if (Pair.Key.Len() * Pair.Value.Len() == 0) {
            CanvasContext.Printf(TEXT("{yellow}%s"), *(Pair.Key + Pair.Value));
        } else {
            CanvasContext.Printf(TEXT("{yellow}%s: {white}%s"), *Pair.Key, *Pair.Value);
        }
    }
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_Generic::MakeInstance() {
    return MakeShareable(new FGameplayDebuggerCategory_Generic());
}

void FGameplayDebuggerCategory_Generic::FRepData::Serialize(FArchive& Ar) {
    Ar << ControlledPawnInfoMap;
    Ar << DebugActorInfoMap;
}

#endif // WITH_GAMEPLAY_DEBUGGER
