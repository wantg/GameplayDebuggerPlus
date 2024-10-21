# Unreal Engine Gameplay Debugger Plus

# Preivew

<img src="https://github.com/wantg/GameplayDebuggerPlus/raw/main/GameplayDebuggerPlus.png">

## Usage

1. Install

    Copy Plugin Directory into [Propject]/Plugins

2. Add Dependency

    Add GameplayDebuggerPlus module to your ModuleName.Build.cs file under dependencies modules.

    ``` Csharp
    PrivateDependencyModuleNames.AddRange(new string[] { "GameplayDebuggerPlus" });
    ```

3. Implemention Gameplay Debugger Interface in your Player Character

    ``` C++
    #include "GameplayDebuggerPlusInterface.h"

    UCLASS()
    class YOURGAME_API ACharacterPlayer : public IGameplayDebuggerPlusInterface {
        GENERATED_BODY()

       protected:
        virtual TMap<FString, FString> GetDebugInfoMap() override {
            return {
                {"Name", GetActorNameOrLabel()},
            };
        }
    };
    ```

4. Auto active when Gameplay Debugger enabled (Optional)

    Put this config in your DefaultEngine.ini

    ```ini
    [/Script/GameplayDebugger.GameplayDebuggerConfig]
    +Categories=(CategoryName="Generic",ActiveInGame=Enable)
    ```
