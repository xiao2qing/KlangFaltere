// ==================================================================================
// Copyright (c) 2012 HiFi-LoFi
//
// This is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ==================================================================================

#ifndef _CUSTOMLOOKANDFEEL_H
#define _CUSTOMLOOKANDFEEL_H

#include "../JuceLibraryCode/JuceHeader.h"

class CustomLookAndFeel : public juce::LookAndFeel
{
public:
  CustomLookAndFeel();
  virtual ~CustomLookAndFeel();

  static const CustomLookAndFeel& GetCustomLookAndFeel(juce::Component* component);

  // Waveform
  juce::Colour getWaveformColour() const;

  // Scales
  juce::Font getScaleFont() const;
  juce::Colour getScaleColour() const;
  juce::Colour getLevelColourMinusInfDb() const;
  juce::Colour getLevelColourMinus40Db() const;
  juce::Colour getLevelColourZeroDb() const;
  juce::Colour getLevelColourClipping() const;

  // Waveform
  juce::Colour getWaveformBackgroundColour() const;
  
private:
  CustomLookAndFeel(const CustomLookAndFeel&);
  CustomLookAndFeel& operator=(const CustomLookAndFeel&);
};


#endif // Header guard
