#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayDebuggerPlusInterface.generated.h"

UINTERFACE(MinimalAPI, NotBlueprintable)
class UGameplayDebuggerPlusInterface : public UInterface {
    GENERATED_BODY()
};

class IGameplayDebuggerPlusInterface {
    GENERATED_BODY()

   public:
    virtual TMap<FString, FString> GetDebugInfoMap() { return {}; }
};
