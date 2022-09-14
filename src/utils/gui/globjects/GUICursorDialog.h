/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2022 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    GUICursorDialog.h
/// @author  Pablo Alvarez Lopez
/// @date    Sep 2022
///
// Dialog for edit element under cursor
/****************************************************************************/
#pragma once
#include <config.h>

#include "GUIGLObjectPopupMenu.h"


// ===========================================================================
// class definitions
// ===========================================================================

/**
 * @class GUICursorDialog
 * @brief Dialog for edit rerouter intervals
 */

class GUICursorDialog : public GUIGLObjectPopupMenu {
    /// @brief FOX-declaration
    FXDECLARE(GUICursorDialog)

public:
    /// @name cursor dialog type
    enum class CursorDialogType {
        PROPERTIES,
        FRONT_ELEMENT
    };

    /// @brief constructor used for Pop-up dialogs
    GUICursorDialog(CursorDialogType cursorDialogType, GUISUMOAbstractView* view, const std::vector<GUIGlObject*> &objects);

    /// @brief destructor
    ~GUICursorDialog();

    /// @name FOX-callbacks
    /// @{

    /// @brief set front element
    long onCmdSetFrontElement(FXObject*, FXSelector, void*);

    /// @}

protected:
    /// @brief FOX need this
    FOX_CONSTRUCTOR(GUICursorDialog)

    /// @brief pointer to view
    GUISUMOAbstractView* myView;

    /// @brief container for GLObjects
    std::map<FXObject*, GUIGlObject*> myGLObjects;

private:
    /// @brief Invalidated copy constructor.
    GUICursorDialog(const GUICursorDialog&) = delete;

    /// @brief Invalidated assignment operator.
    GUICursorDialog& operator=(const GUICursorDialog&) = delete;
};
