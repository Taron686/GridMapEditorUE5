#include "GridMapEditCommands.h"
#include "GridMapEditor.h"
#include "GridMapStyleSet.h"

#define LOCTEXT_NAMESPACE "GridMapEditor"

FGridMapEditCommands::FGridMapEditCommands()
	: TCommands<FGridMapEditCommands>(
		"GridMapEditCommands",	// context name for fast lookup
		NSLOCTEXT("GridMapEditor", "GridMapEditorMode", "Grid Map Edit Mode"), // localized text
		NAME_None,	// parent
               FGridMapStyleSet::Name)
{
}

void FGridMapEditCommands::RegisterCommands()
{
       UI_COMMAND(SetPaintTiles, "Paint", "Paint Tiles", EUserInterfaceActionType::ToggleButton, FInputChord());
       UI_COMMAND(SetSelectTiles, "Select", "Select Tiles", EUserInterfaceActionType::ToggleButton, FInputChord());
       UI_COMMAND(SetTileSettings, "Settings", "Configuration", EUserInterfaceActionType::ToggleButton, FInputChord());
	/*
	UI_COMMAND(SetReapplySettings, "Reapply", "Reapply settings to instances", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(SetSelect, "Select", "Select", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(SetLassoSelect, "Lasso", "Lasso Select", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(SetPaintBucket, "Fill", "Paint Bucket", EUserInterfaceActionType::ToggleButton, FInputChord());
	*/
}

#undef LOCTEXT_NAMESPACE
