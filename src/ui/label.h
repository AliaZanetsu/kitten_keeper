/*
 *  Copyright (C) 2017 the authors (see AUTHORS)
 *
 *  This file is part o kitten keeper.
 *
 *  lair is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  lair is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with lair.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef LD_40_UI_LABEL_H_
#define LD_40_UI_LABEL_H_

#include <vector>

#include <lair/core/lair.h>
#include <lair/core/shapes.h>

#include <lair/render_gl2/texture.h>

#include <lair/ec/sprite_renderer.h>

#include "text.h"
#include "widget.h"

class Label : public Widget {
public:
	Label(Gui* gui, Widget* parent = nullptr);

	const lair::String& text() const;
	const Text& textInfo() const;

	Text& textInfo();

	void setText(const lair::String& text);
	void setFont(lair::BitmapFontAspectSP font);
	void setFont(lair::AssetSP font);
	void setFont(const lair::Path& logicPath);

	void resizeToText();

	virtual void preRender(lair::SpriteRenderer* renderer);
	virtual float render(lair::RenderPass& renderPass, lair::SpriteRenderer* renderer,
	                   const lair::Matrix4& transform, float depth = 0) override;

protected:
	lair::String _text;
	Text         _textInfo;
};


#endif
