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
/// @file    GUICursorDialog.cpp
/// @author  Pablo Alvarez Lopez
/// @date    Sep 2022
///
// Dialog for edit element under cursor
/****************************************************************************/
#include <config.h>

#include <utils/foxtools/MFXMenuHeader.h>
#include <utils/gui/div/GUIDesigns.h>
#include <utils/gui/windows/GUIAppEnum.h>
#include <utils/gui/windows/GUIMainWindow.h>
#include <utils/gui/windows/GUISUMOAbstractView.h>

#include <netedit/GNEUndoList.h>

#include "GUICursorDialog.h"


// ===========================================================================
// FOX callback mapping
// ===========================================================================

FXDEFMAP(GUICursorDialog) GUICursorDialogMap[] = {
    FXMAPFUNC(SEL_COMMAND,  MID_GNE_SETFRONTELEMENT,    GUICursorDialog::onCmdSetFrontElement)
};

// Object implementation
FXIMPLEMENT(GUICursorDialog, GUIGLObjectPopupMenu, GUICursorDialogMap, ARRAYNUMBER(GUICursorDialogMap))

// ===========================================================================
// member method definitions
// ===========================================================================

GUICursorDialog::GUICursorDialog(CursorDialogType cursorDialogType, GUISUMOAbstractView* view, const std::vector<GUIGlObject*> &objects) :
    GUIGLObjectPopupMenu(view->getMainWindow(), view),
    myView(view) {
    if (cursorDialogType == CursorDialogType::FRONT_ELEMENT) {
        // create header
        new MFXMenuHeader(this, view->getMainWindow()->getBoldFont(), "Mark front element", GUIIconSubSys::getIcon(GUIIcon::FRONTELEMENT), nullptr, 0);
        new FXMenuSeparator(this);
        // create a menu command for every AC
        for (const auto &GLObject : objects) {
            myGLObjects[GUIDesigns::buildFXMenuCommand(this, GLObject->getMicrosimID(), /*AC->getIcon()*/ nullptr, this, MID_GNE_SETFRONTELEMENT)] = GLObject;
        }
    }
}


GUICursorDialog::~GUICursorDialog() {}


long
GUICursorDialog::onCmdSetFrontElement(FXObject* obj, FXSelector, void*) {
    // search element in myGLObjects
    for (const auto &GLObject : myGLObjects) {
        if (GLObject.first == obj) {
            GLObject.second->markAsFrontElement();
        }
    }
    // destroy popup
    myView->destroyPopup();
    return 1;
}

/****************************************************************************/