#include "GameplayDebuggerPlus.h"
#include "GameplayDebugger.h"
#include "GameplayDebuggerCategory_Generic.h"

#define LOCTEXT_NAMESPACE "FGameplayDebuggerPlusModule"

void FGameplayDebuggerPlusModule::StartupModule() {
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#if WITH_GAMEPLAY_DEBUGGER
    IGameplayDebugger& GameplayDebuggerModule           = IGameplayDebugger::Get();
    int32 SlotIdx                                       = 9;
    IGameplayDebugger::FOnGetCategory GetCategoryHandle = IGameplayDebugger::FOnGetCategory::CreateStatic(&FGameplayDebuggerCategory_Generic::MakeInstance);
    GameplayDebuggerModule.RegisterCategory(FGameplayDebuggerCategory_Generic::CategoryName, GetCategoryHandle, EGameplayDebuggerCategoryState::EnabledInGameAndSimulate, SlotIdx);
    GameplayDebuggerModule.NotifyCategoriesChanged();
#endif
}

void FGameplayDebuggerPlusModule::ShutdownModule() {
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
#if WITH_GAMEPLAY_DEBUGGER
    if (IGameplayDebugger::IsAvailable()) {
        IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();
        GameplayDebuggerModule.UnregisterCategory(FGameplayDebuggerCategory_Generic::CategoryName);
        GameplayDebuggerModule.NotifyCategoriesChanged();
    }
#endif // WITH_GAMEPLAY_DEBUGGER
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameplayDebuggerPlusModule, GameplayDebuggerPlus)
