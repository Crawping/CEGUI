/*************************************************************************
    Crazy Eddie's GUI System (http://crayzedsgui.sourceforge.net)
    Copyright (C)2004 Paul D Turner (crayzed@users.sourceforge.net)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#include "CEGUIImage.h"
#include "CEGUIImageset.h"
#include "CEGUIImagesetManager.h"

#include "CEGUIExceptions.h"

#include "TLButton.h"
#include "TLButtonProperties.h"
#include "CEGUIPropertyHelper.h"

// Start of CEGUI namespace section
namespace CEGUI
{

// Start of TLButtonProperties namespace section
namespace TLButtonProperties
{

String NormalImage::get(const void *receiver) const
{
   //TLButton currently has no getter for this...
   return "";//PropertyHelper::imageToString(static_cast<const TLButton*>(receiver)->getNormal());
}

void NormalImage::set(void *receiver, const String &value)
{
   RenderableImage * image = new RenderableImage();
   image->setImage(PropertyHelper::stringToImage(value));
   image->setHorzFormatting(RenderableImage::HorzStretched);
   image->setVertFormatting(RenderableImage::VertStretched);
   static_cast<TLButton*>(receiver)->setNormalImage(image);
}

String PushedImage::get(const void *receiver) const
{
   //TLButton currently has no getter for this...
   return "";//PropertyHelper::imageToString(static_cast<const TLButton*>(receiver)->getNormal());
}

void PushedImage::set(void *receiver, const String &value)
{
   RenderableImage * image = new RenderableImage();
   image->setImage(PropertyHelper::stringToImage(value));
   image->setHorzFormatting(RenderableImage::HorzStretched);
   image->setVertFormatting(RenderableImage::VertStretched);
   static_cast<TLButton*>(receiver)->setPushedImage(image);
}

String HoverImage::get(const void *receiver) const
{
   //TLButton currently has no getter for this...
   return "";//PropertyHelper::imageToString(static_cast<const TLButton*>(receiver)->getNormal());
}

void HoverImage::set(void *receiver, const String &value)
{
   RenderableImage * image = new RenderableImage();
   image->setImage(PropertyHelper::stringToImage(value));
   image->setHorzFormatting(RenderableImage::HorzStretched);
   image->setVertFormatting(RenderableImage::VertStretched);
   static_cast<TLButton*>(receiver)->setHoverImage(image);
}

String UseStandardImagery::get(const void *receiver) const
{
	return PropertyHelper::boolToString(static_cast<const TLButton*>(receiver)->isStandardImageryEnabled());
}

void UseStandardImagery::set(void *receiver, const String &value)
{
   static_cast<TLButton*>(receiver)->setStandardImageryEnabled(PropertyHelper::stringToBool(value));
}

String TextXOffset::get(const void *receiver) const
{
   return PropertyHelper::floatToString(static_cast<const TLButton*>(receiver)->getTextXOffset());
}

void TextXOffset::set(void *receiver, const String &value)
{
   static_cast<TLButton*>(receiver)->setTextXOffset(PropertyHelper::stringToFloat(value));
}

}

};

