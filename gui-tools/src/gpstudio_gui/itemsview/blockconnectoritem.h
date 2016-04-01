/****************************************************************************
** Copyright (C) 2016 Dream IP
** 
** This file is part of GPStudio.
**
** GPStudio is a free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef BLOCKCONNECTORITEM_H
#define BLOCKCONNECTORITEM_H

#include "gpstudio_gui_common.h"

#include <QGraphicsItem>

class BlockItem;

class GPSTUDIO_GUI_EXPORT BlockConnectorItem : public QGraphicsItem
{
public:
    BlockConnectorItem(BlockItem *itemOut, BlockItem *itemIn);
    ~BlockConnectorItem();

    enum { Type = UserType + 2 };
    int type() const;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    BlockItem *_itemOut;
    BlockItem *_itemIn;
};

#endif // BLOCKCONNECTORITEM_H