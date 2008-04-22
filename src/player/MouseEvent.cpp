//
//  libavg - Media Playback Engine. 
//  Copyright (C) 2003-2006 Ulrich von Zadow
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  Current versions can be found at www.libavg.de
//

#include "MouseEvent.h"
#include "Node.h"

#include "../base/Logger.h"

#include <iostream>
#include <sstream>

using namespace std;

namespace avg {

MouseEvent::MouseEvent(Event::Type eventType,
        bool leftButtonState, bool middleButtonState, bool rightButtonState,
        const IntPoint& Position, int button)
    : CursorEvent(MOUSECURSORID, eventType, Position, MOUSE)
{
    m_LeftButtonState = leftButtonState;
    m_MiddleButtonState = middleButtonState;
    m_RightButtonState = rightButtonState;
    if (eventType == CURSORMOTION) {
        m_Button = 0;
    } else {
        m_Button = button;
    }
}

MouseEvent::~MouseEvent()
{
}

int MouseEvent::getButton() const
{
    return m_Button;
}

bool MouseEvent::getLeftButtonState() const
{
    return m_LeftButtonState;
}

bool MouseEvent::getMiddleButtonState() const
{
    return m_MiddleButtonState;
}

bool MouseEvent::getRightButtonState() const
{
    return m_RightButtonState;
}

void MouseEvent::trace()
{
    Event::trace();
    AVG_TRACE(Logger::EVENTS2, "pos: " << m_Position 
            << ", button: " << m_Button);
}

CursorEvent* MouseEvent::cloneAs(Type EventType) const
{
    MouseEvent *res = new MouseEvent(*this);
    res->m_Type = EventType;
    return res;
}

}
