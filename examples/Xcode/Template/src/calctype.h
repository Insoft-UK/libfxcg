// The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <fxcg/display.h>
#include <stdint.h>

// the main font struct
typedef struct __CalcTypeFont {
	unsigned int   height;		    // pixel height of the font line in pixels
	unsigned int   base;		    // y offset of base font line
	unsigned int   space;			// width of the font space in sub-pixels
	const uint8_t *glyphData;		// actual character data
	uint16_t       glyphOffset[224];// offset to each char's data (minus 32), 0xFFFF if not available
} TCalcTypeFont;

// faux char data struct (it's embedded directly in byte data by CalcTyper
typedef struct _CalcTypeGlyphData {
    int8_t   xOffset;		// x offset (in subpixels) of the glyph
    int8_t   yOffset;		// y offset (in real pixels) of the glyph
    uint8_t  xAdvance;		// amount (in subpixels) to advance x value
    uint8_t  width;			// width (in real pixels) of the data, though its subpixel encodd
    uint8_t  height;		// height (in real pixels) of the data
    uint8_t  data[1];		// pointer helper for data
                            // data is encoded in RGB bytes for each pixel 3:4:1 (based on usefulness for intensity)
} TCalcTypeGlyphData;

#ifdef __cplusplus
extern "C" {
#endif

    unsigned int CalcType_Width(const TCalcTypeFont *font, const char *str);
    void CalcType_DrawString(const TCalcTypeFont *font, const char *str, int x, int y, color_t color);

#ifdef __cplusplus
};
#endif
