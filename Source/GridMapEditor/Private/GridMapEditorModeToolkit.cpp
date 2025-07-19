// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GridMapEditorModeToolkit.h"
#include "GridMapEditorMode.h"
#include "GridMapEditorToolkitWidget.h"
#include "GridMapEditCommands.h"
#include "Engine/Selection.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "EditorModeManager.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "LevelEditor.h"

#define LOCTEXT_NAMESPACE "GridMapEditor"

FGridMapEditorModeToolkit::FGridMapEditorModeToolkit()
{
}

void FGridMapEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
        ToolkitWidget = SNew(SGridMapEditorToolkitWidget);
        FModeToolkit::Init(InitToolkitHost);

        if (FModuleManager::Get().IsModuleLoaded("LevelEditor"))
        {
                FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

                ToolBarExtender = MakeShareable(new FExtender);
                ToolBarExtender->AddToolBarExtension("Settings", EExtensionHook::After, GetToolkitCommands(), FToolBarExtensionDelegate::CreateRaw(this, &FGridMapEditorModeToolkit::ExtendLevelEditorToolBar));
                LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolBarExtender);
        }
}

FName FGridMapEditorModeToolkit::GetToolkitFName() const
{
	return FName("GridMapEditorEdMode");
}

FText FGridMapEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("GridMapEditorToolkitName", "Grid Map Editor Toolkit");
}

class FEdMode* FGridMapEditorModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FGridMapEditorMode::EM_GridMapEditorModeId);
}

TSharedPtr<class SWidget> FGridMapEditorModeToolkit::GetInlineContent() const
{
        return ToolkitWidget;
}

TSharedPtr<SWidget> FGridMapEditorModeToolkit::BuildToolBar()
{
        FToolBarBuilder ToolbarBuilder(GetToolkitCommands(), FMultiBoxCustomization::None);
        ExtendLevelEditorToolBar(ToolbarBuilder);
        return ToolbarBuilder.MakeWidget();
}

void FGridMapEditorModeToolkit::ExtendLevelEditorToolBar(FToolBarBuilder& ToolbarBuilder)
{
        ToolbarBuilder.AddToolBarButton(FGridMapEditCommands::Get().SetPaintTiles);
        ToolbarBuilder.AddToolBarButton(FGridMapEditCommands::Get().SetSelectTiles);
        ToolbarBuilder.AddToolBarButton(FGridMapEditCommands::Get().SetTileSettings);
}

#undef LOCTEXT_NAMESPACE
