/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  5 Mar 2013 2:30:56pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...

#include "../DecibelScaling.h"
#include "../Parameters.h"

//[/Headers]

#include "KlangFalterEditor.h"
#include "IRComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...


template<typename T>
T SnapValue(T val, T snapValue, T sensitivity)
{
  return (::fabs(val - snapValue) < sensitivity) ? snapValue : val;
}


//[/MiscUserDefs]

//==============================================================================
KlangFalterEditor::KlangFalterEditor (PluginAudioProcessor& processor)
    : AudioProcessorEditor(&processor),
      _processor(processor),
      _decibelScaleDry (0),
      _irTabComponent (0),
      _stretchHeaderLabel (0),
      _stretchSlider (0),
      _levelMeterDry (0),
      _dryLevelLabel (0),
      _wetLevelLabel (0),
      _drySlider (0),
      _decibelScaleOut (0),
      _wetSlider (0),
      _browseButton (0),
      _irBrowserComponent (0),
      _settingsButton (0),
      _stretchLabel (0),
      _beginHeaderLabel (0),
      _beginSlider (0),
      _beginLabel (0),
      _wetButton (0),
      _dryButton (0),
      _autogainButton (0),
      _reverseButton (0),
      _predelayHeaderLabel (0),
      _predelaySlider (0),
      _predelayLabel (0),
      _hiFreqLabel (0),
      _hiGainLabel (0),
      _hiGainHeaderLabel (0),
      _hiFreqHeaderLabel (0),
      _hiGainSlider (0),
      _hiFreqSlider (0),
      _loFreqLabel (0),
      _loGainLabel (0),
      _loGainHeaderLabel (0),
      _loFreqHeaderLabel (0),
      _loGainSlider (0),
      _loFreqSlider (0),
      _hiEqButton (0),
      _loEqButton (0),
      _levelMeterOut (0),
      _levelMeterOutLabelButton (0),
      _levelMeterDryLabel (0),
      _widthHeaderLabel (0),
      _widthSlider (0),
      _widthLabel (0)
{
    addAndMakeVisible (_decibelScaleDry = new DecibelScale());

    addAndMakeVisible (_irTabComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    _irTabComponent->setTabBarDepth (30);
    _irTabComponent->addTab (L"Placeholder", Colour (0xffe5e5f0), new IRComponent(), true);
    _irTabComponent->setCurrentTabIndex (0);

    addAndMakeVisible (_stretchHeaderLabel = new Label (String::empty,
                                                        L"Stretch"));
    _stretchHeaderLabel->setFont (Font (15.0000f, Font::plain));
    _stretchHeaderLabel->setJustificationType (Justification::centred);
    _stretchHeaderLabel->setEditable (false, false, false);
    _stretchHeaderLabel->setColour (Label::textColourId, Colour (0xff202020));
    _stretchHeaderLabel->setColour (TextEditor::textColourId, Colour (0xff202020));
    _stretchHeaderLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_stretchSlider = new Slider (String::empty));
    _stretchSlider->setRange (0, 2, 0);
    _stretchSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    _stretchSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _stretchSlider->setColour (Slider::thumbColourId, Colour (0xffafafff));
    _stretchSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffafafff));
    _stretchSlider->addListener (this);

    addAndMakeVisible (_levelMeterDry = new LevelMeter());

    addAndMakeVisible (_dryLevelLabel = new Label (L"DryLevelLabel",
                                                   L"-inf"));
    _dryLevelLabel->setFont (Font (11.0000f, Font::plain));
    _dryLevelLabel->setJustificationType (Justification::centredRight);
    _dryLevelLabel->setEditable (false, false, false);
    _dryLevelLabel->setColour (Label::textColourId, Colour (0xff202020));
    _dryLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    _dryLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_wetLevelLabel = new Label (L"WetLevelLabel",
                                                   L"-inf"));
    _wetLevelLabel->setFont (Font (11.0000f, Font::plain));
    _wetLevelLabel->setJustificationType (Justification::centredRight);
    _wetLevelLabel->setEditable (false, false, false);
    _wetLevelLabel->setColour (Label::textColourId, Colour (0xff202020));
    _wetLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    _wetLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_drySlider = new Slider (String::empty));
    _drySlider->setRange (0, 10, 0);
    _drySlider->setSliderStyle (Slider::LinearVertical);
    _drySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _drySlider->addListener (this);

    addAndMakeVisible (_decibelScaleOut = new DecibelScale());

    addAndMakeVisible (_wetSlider = new Slider (String::empty));
    _wetSlider->setRange (0, 10, 0);
    _wetSlider->setSliderStyle (Slider::LinearVertical);
    _wetSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _wetSlider->addListener (this);

    addAndMakeVisible (_browseButton = new TextButton (String::empty));
    _browseButton->setTooltip (L"Show Browser For Impulse Response Selection");
    _browseButton->setButtonText (L"Show Browser");
    _browseButton->setConnectedEdges (Button::ConnectedOnBottom);
    _browseButton->addListener (this);
    _browseButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_irBrowserComponent = new IRBrowserComponent());

    addAndMakeVisible (_settingsButton = new TextButton (String::empty));
    _settingsButton->setButtonText (L"Settings");
    _settingsButton->setConnectedEdges (Button::ConnectedOnRight | Button::ConnectedOnTop);
    _settingsButton->addListener (this);

    addAndMakeVisible (_stretchLabel = new Label (String::empty,
                                                  L"100%"));
    _stretchLabel->setFont (Font (15.0000f, Font::plain));
    _stretchLabel->setJustificationType (Justification::centred);
    _stretchLabel->setEditable (false, false, false);
    _stretchLabel->setColour (Label::textColourId, Colour (0xff202020));
    _stretchLabel->setColour (TextEditor::textColourId, Colours::black);
    _stretchLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_beginHeaderLabel = new Label (String::empty,
                                                      L"Begin"));
    _beginHeaderLabel->setFont (Font (15.0000f, Font::plain));
    _beginHeaderLabel->setJustificationType (Justification::centred);
    _beginHeaderLabel->setEditable (false, false, false);
    _beginHeaderLabel->setColour (Label::textColourId, Colour (0xff202020));
    _beginHeaderLabel->setColour (TextEditor::textColourId, Colour (0xff202020));
    _beginHeaderLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_beginSlider = new Slider (String::empty));
    _beginSlider->setRange (0, 2, 0);
    _beginSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    _beginSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _beginSlider->setColour (Slider::thumbColourId, Colour (0xffafafff));
    _beginSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffafafff));
    _beginSlider->addListener (this);
    _beginSlider->setSkewFactor (0.5);

    addAndMakeVisible (_beginLabel = new Label (String::empty,
                                                L"0ms"));
    _beginLabel->setFont (Font (15.0000f, Font::plain));
    _beginLabel->setJustificationType (Justification::centred);
    _beginLabel->setEditable (false, false, false);
    _beginLabel->setColour (Label::textColourId, Colours::black);
    _beginLabel->setColour (TextEditor::textColourId, Colours::black);
    _beginLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_wetButton = new TextButton (String::empty));
    _wetButton->setTooltip (L"Wet Signal On/Off");
    _wetButton->setButtonText (L"Wet");
    _wetButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _wetButton->addListener (this);
    _wetButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _wetButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_dryButton = new TextButton (String::empty));
    _dryButton->setTooltip (L"Dry Signal On/Off");
    _dryButton->setButtonText (L"Dry");
    _dryButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _dryButton->addListener (this);
    _dryButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _dryButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_autogainButton = new TextButton (String::empty));
    _autogainButton->setTooltip (L"Autogain On/Off");
    _autogainButton->setButtonText (L"Autogain 0.0dB");
    _autogainButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _autogainButton->addListener (this);
    _autogainButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _autogainButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_reverseButton = new TextButton (String::empty));
    _reverseButton->setTooltip (L"Reverse Impulse Response");
    _reverseButton->setButtonText (L"Reverse");
    _reverseButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _reverseButton->addListener (this);
    _reverseButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _reverseButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_predelayHeaderLabel = new Label (String::empty,
                                                         L"Predelay"));
    _predelayHeaderLabel->setFont (Font (15.0000f, Font::plain));
    _predelayHeaderLabel->setJustificationType (Justification::centred);
    _predelayHeaderLabel->setEditable (false, false, false);
    _predelayHeaderLabel->setColour (Label::textColourId, Colour (0xff202020));
    _predelayHeaderLabel->setColour (TextEditor::textColourId, Colour (0xff202020));
    _predelayHeaderLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_predelaySlider = new Slider (String::empty));
    _predelaySlider->setRange (0, 200, 0);
    _predelaySlider->setSliderStyle (Slider::RotaryVerticalDrag);
    _predelaySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _predelaySlider->setColour (Slider::backgroundColourId, Colour (0x0));
    _predelaySlider->setColour (Slider::thumbColourId, Colour (0xffafafff));
    _predelaySlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffafafff));
    _predelaySlider->addListener (this);

    addAndMakeVisible (_predelayLabel = new Label (String::empty,
                                                   L"0ms"));
    _predelayLabel->setFont (Font (15.0000f, Font::plain));
    _predelayLabel->setJustificationType (Justification::centred);
    _predelayLabel->setEditable (false, false, false);
    _predelayLabel->setColour (Label::textColourId, Colour (0xff202020));
    _predelayLabel->setColour (TextEditor::textColourId, Colours::black);
    _predelayLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_hiFreqLabel = new Label (String::empty,
                                                 L"15.2kHz"));
    _hiFreqLabel->setFont (Font (11.0000f, Font::plain));
    _hiFreqLabel->setJustificationType (Justification::centred);
    _hiFreqLabel->setEditable (false, false, false);
    _hiFreqLabel->setColour (Label::textColourId, Colour (0xff202020));
    _hiFreqLabel->setColour (TextEditor::textColourId, Colours::black);
    _hiFreqLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_hiGainLabel = new Label (String::empty,
                                                 L"0.0dB"));
    _hiGainLabel->setFont (Font (11.0000f, Font::plain));
    _hiGainLabel->setJustificationType (Justification::centred);
    _hiGainLabel->setEditable (false, false, false);
    _hiGainLabel->setColour (Label::textColourId, Colour (0xff202020));
    _hiGainLabel->setColour (TextEditor::textColourId, Colours::black);
    _hiGainLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_hiGainHeaderLabel = new Label (String::empty,
                                                       L"Gain"));
    _hiGainHeaderLabel->setFont (Font (11.0000f, Font::plain));
    _hiGainHeaderLabel->setJustificationType (Justification::centred);
    _hiGainHeaderLabel->setEditable (false, false, false);
    _hiGainHeaderLabel->setColour (Label::textColourId, Colour (0xff202020));
    _hiGainHeaderLabel->setColour (TextEditor::textColourId, Colours::black);
    _hiGainHeaderLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_hiFreqHeaderLabel = new Label (String::empty,
                                                       L"Freq"));
    _hiFreqHeaderLabel->setFont (Font (11.0000f, Font::plain));
    _hiFreqHeaderLabel->setJustificationType (Justification::centred);
    _hiFreqHeaderLabel->setEditable (false, false, false);
    _hiFreqHeaderLabel->setColour (Label::textColourId, Colour (0xff202020));
    _hiFreqHeaderLabel->setColour (TextEditor::textColourId, Colours::black);
    _hiFreqHeaderLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_hiGainSlider = new Slider (String::empty));
    _hiGainSlider->setRange (-30, 30, 0);
    _hiGainSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    _hiGainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _hiGainSlider->setColour (Slider::thumbColourId, Colour (0xffafafff));
    _hiGainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xb1606060));
    _hiGainSlider->addListener (this);

    addAndMakeVisible (_hiFreqSlider = new Slider (String::empty));
    _hiFreqSlider->setRange (2000, 20000, 0);
    _hiFreqSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    _hiFreqSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _hiFreqSlider->setColour (Slider::thumbColourId, Colour (0xffafafff));
    _hiFreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xb1606060));
    _hiFreqSlider->addListener (this);

    addAndMakeVisible (_loFreqLabel = new Label (String::empty,
                                                 L"1234Hz"));
    _loFreqLabel->setFont (Font (11.0000f, Font::plain));
    _loFreqLabel->setJustificationType (Justification::centred);
    _loFreqLabel->setEditable (false, false, false);
    _loFreqLabel->setColour (Label::textColourId, Colour (0xff202020));
    _loFreqLabel->setColour (TextEditor::textColourId, Colours::black);
    _loFreqLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_loGainLabel = new Label (String::empty,
                                                 L"0.0dB"));
    _loGainLabel->setFont (Font (11.0000f, Font::plain));
    _loGainLabel->setJustificationType (Justification::centred);
    _loGainLabel->setEditable (false, false, false);
    _loGainLabel->setColour (Label::textColourId, Colour (0xff202020));
    _loGainLabel->setColour (TextEditor::textColourId, Colours::black);
    _loGainLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_loGainHeaderLabel = new Label (String::empty,
                                                       L"Gain"));
    _loGainHeaderLabel->setFont (Font (11.0000f, Font::plain));
    _loGainHeaderLabel->setJustificationType (Justification::centred);
    _loGainHeaderLabel->setEditable (false, false, false);
    _loGainHeaderLabel->setColour (Label::textColourId, Colour (0xff202020));
    _loGainHeaderLabel->setColour (TextEditor::textColourId, Colours::black);
    _loGainHeaderLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_loFreqHeaderLabel = new Label (String::empty,
                                                       L"Freq"));
    _loFreqHeaderLabel->setFont (Font (11.0000f, Font::plain));
    _loFreqHeaderLabel->setJustificationType (Justification::centred);
    _loFreqHeaderLabel->setEditable (false, false, false);
    _loFreqHeaderLabel->setColour (Label::textColourId, Colour (0xff202020));
    _loFreqHeaderLabel->setColour (TextEditor::textColourId, Colours::black);
    _loFreqHeaderLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_loGainSlider = new Slider (String::empty));
    _loGainSlider->setRange (-30, 30, 0);
    _loGainSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    _loGainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _loGainSlider->setColour (Slider::thumbColourId, Colour (0xffafafff));
    _loGainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xb1606060));
    _loGainSlider->addListener (this);

    addAndMakeVisible (_loFreqSlider = new Slider (String::empty));
    _loFreqSlider->setRange (20, 2000, 0);
    _loFreqSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    _loFreqSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _loFreqSlider->setColour (Slider::thumbColourId, Colour (0xffafafff));
    _loFreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xb1606060));
    _loFreqSlider->addListener (this);

    addAndMakeVisible (_hiEqButton = new TextButton (String::empty));
    _hiEqButton->setTooltip (L"High Shelf EQ On/Off");
    _hiEqButton->setButtonText (L"Hi Shelf");
    _hiEqButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _hiEqButton->addListener (this);
    _hiEqButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _hiEqButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_loEqButton = new TextButton (String::empty));
    _loEqButton->setTooltip (L"Low Shelf EQ On/Off");
    _loEqButton->setButtonText (L"Lo Shelf");
    _loEqButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _loEqButton->addListener (this);
    _loEqButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _loEqButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_levelMeterOut = new LevelMeter());

    addAndMakeVisible (_levelMeterOutLabelButton = new TextButton (String::empty));
    _levelMeterOutLabelButton->setTooltip (L"Switches Between Out/Wet Level Measurement");
    _levelMeterOutLabelButton->setButtonText (L"Out");
    _levelMeterOutLabelButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _levelMeterOutLabelButton->addListener (this);
    _levelMeterOutLabelButton->setColour (TextButton::buttonColourId, Colour (0xbbbbff));
    _levelMeterOutLabelButton->setColour (TextButton::buttonOnColourId, Colour (0xbcbcff));

    addAndMakeVisible (_levelMeterDryLabel = new Label (String::empty,
                                                        L"Dry"));
    _levelMeterDryLabel->setFont (Font (11.0000f, Font::plain));
    _levelMeterDryLabel->setJustificationType (Justification::centred);
    _levelMeterDryLabel->setEditable (false, false, false);
    _levelMeterDryLabel->setColour (Label::textColourId, Colour (0xff202020));
    _levelMeterDryLabel->setColour (TextEditor::textColourId, Colours::black);
    _levelMeterDryLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_widthHeaderLabel = new Label (String::empty,
                                                      L"Width"));
    _widthHeaderLabel->setFont (Font (15.0000f, Font::plain));
    _widthHeaderLabel->setJustificationType (Justification::centred);
    _widthHeaderLabel->setEditable (false, false, false);
    _widthHeaderLabel->setColour (Label::textColourId, Colour (0xff202020));
    _widthHeaderLabel->setColour (TextEditor::textColourId, Colour (0xff202020));
    _widthHeaderLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_widthSlider = new Slider (String::empty));
    _widthSlider->setRange (0, 10, 0);
    _widthSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    _widthSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _widthSlider->setColour (Slider::backgroundColourId, Colour (0x0));
    _widthSlider->setColour (Slider::thumbColourId, Colour (0xffafafff));
    _widthSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffafafff));
    _widthSlider->addListener (this);
    _widthSlider->setSkewFactor (0.30102);

    addAndMakeVisible (_widthLabel = new Label (String::empty,
                                                L"1.0"));
    _widthLabel->setFont (Font (15.0000f, Font::plain));
    _widthLabel->setJustificationType (Justification::centred);
    _widthLabel->setEditable (false, false, false);
    _widthLabel->setColour (Label::textColourId, Colour (0xff202020));
    _widthLabel->setColour (TextEditor::textColourId, Colours::black);
    _widthLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));


    //[UserPreSize]

    setLookAndFeel(&_customLookAndFeel);

    //[/UserPreSize]

    setSize (760, 330);


    //[Constructor] You can add your own custom stuff here..
    _irTabComponent->clearTabs(); // Remove placeholder only used as dummy in the Jucer
    _browseButton->setClickingTogglesState(true);
    _dryButton->setClickingTogglesState(true);
    _wetButton->setClickingTogglesState(true);
    _autogainButton->setClickingTogglesState(true);
    _reverseButton->setClickingTogglesState(true);
    _loEqButton->setClickingTogglesState(true);
    _hiEqButton->setClickingTogglesState(true);
    _levelMeterOutLabelButton->setClickingTogglesState(true);

    _processor.addNotificationListener(this);
    _processor.getSettings().addChangeListener(this);
    _irBrowserComponent->init(&_processor);
    updateUI();
    startTimer(100);
    //[/Constructor]
}

KlangFalterEditor::~KlangFalterEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    _processor.removeNotificationListener(this);
    _processor.getSettings().removeChangeListener(this);
    //[/Destructor_pre]

    deleteAndZero (_decibelScaleDry);
    deleteAndZero (_irTabComponent);
    deleteAndZero (_stretchHeaderLabel);
    deleteAndZero (_stretchSlider);
    deleteAndZero (_levelMeterDry);
    deleteAndZero (_dryLevelLabel);
    deleteAndZero (_wetLevelLabel);
    deleteAndZero (_drySlider);
    deleteAndZero (_decibelScaleOut);
    deleteAndZero (_wetSlider);
    deleteAndZero (_browseButton);
    deleteAndZero (_irBrowserComponent);
    deleteAndZero (_settingsButton);
    deleteAndZero (_stretchLabel);
    deleteAndZero (_beginHeaderLabel);
    deleteAndZero (_beginSlider);
    deleteAndZero (_beginLabel);
    deleteAndZero (_wetButton);
    deleteAndZero (_dryButton);
    deleteAndZero (_autogainButton);
    deleteAndZero (_reverseButton);
    deleteAndZero (_predelayHeaderLabel);
    deleteAndZero (_predelaySlider);
    deleteAndZero (_predelayLabel);
    deleteAndZero (_hiFreqLabel);
    deleteAndZero (_hiGainLabel);
    deleteAndZero (_hiGainHeaderLabel);
    deleteAndZero (_hiFreqHeaderLabel);
    deleteAndZero (_hiGainSlider);
    deleteAndZero (_hiFreqSlider);
    deleteAndZero (_loFreqLabel);
    deleteAndZero (_loGainLabel);
    deleteAndZero (_loGainHeaderLabel);
    deleteAndZero (_loFreqHeaderLabel);
    deleteAndZero (_loGainSlider);
    deleteAndZero (_loFreqSlider);
    deleteAndZero (_hiEqButton);
    deleteAndZero (_loEqButton);
    deleteAndZero (_levelMeterOut);
    deleteAndZero (_levelMeterOutLabelButton);
    deleteAndZero (_levelMeterDryLabel);
    deleteAndZero (_widthHeaderLabel);
    deleteAndZero (_widthSlider);
    deleteAndZero (_widthLabel);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KlangFalterEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffa6a6b1));

    //[UserPaint] Add your own custom painting code here..
    juce::Image backgroundImage(juce::ImageCache::getFromMemory(BinaryData::brushed_aluminium_png,
                                                                BinaryData::brushed_aluminium_pngSize));
    g.setFillType(juce::FillType(backgroundImage, juce::AffineTransform()));
    g.fillAll();
    //[/UserPaint]
}

void KlangFalterEditor::resized()
{
    _decibelScaleDry->setBounds (584, 40, 32, 176);
    _irTabComponent->setBounds (16, 12, 542, 204);
    _stretchHeaderLabel->setBounds (80, 220, 84, 24);
    _stretchSlider->setBounds (80, 244, 84, 40);
    _levelMeterDry->setBounds (632, 40, 12, 176);
    _dryLevelLabel->setBounds (572, 224, 60, 24);
    _wetLevelLabel->setBounds (656, 224, 64, 24);
    _drySlider->setBounds (612, 32, 24, 192);
    _decibelScaleOut->setBounds (672, 40, 32, 176);
    _wetSlider->setBounds (700, 32, 24, 192);
    _browseButton->setBounds (12, 308, 736, 24);
    _irBrowserComponent->setBounds (12, 332, 736, 288);
    _settingsButton->setBounds (708, 0, 52, 16);
    _stretchLabel->setBounds (80, 280, 84, 24);
    _beginHeaderLabel->setBounds (16, 220, 84, 24);
    _beginSlider->setBounds (16, 244, 84, 40);
    _beginLabel->setBounds (16, 280, 84, 24);
    _wetButton->setBounds (672, 248, 44, 24);
    _dryButton->setBounds (584, 248, 44, 24);
    _autogainButton->setBounds (584, 280, 132, 24);
    _reverseButton->setBounds (486, 8, 72, 24);
    _predelayHeaderLabel->setBounds (144, 220, 84, 24);
    _predelaySlider->setBounds (144, 244, 84, 40);
    _predelayLabel->setBounds (144, 280, 84, 24);
    _hiFreqLabel->setBounds (436, 284, 52, 24);
    _hiGainLabel->setBounds (476, 284, 52, 24);
    _hiGainHeaderLabel->setBounds (476, 240, 52, 24);
    _hiFreqHeaderLabel->setBounds (436, 240, 52, 24);
    _hiGainSlider->setBounds (484, 260, 36, 28);
    _hiFreqSlider->setBounds (444, 260, 36, 28);
    _loFreqLabel->setBounds (324, 284, 52, 24);
    _loGainLabel->setBounds (364, 284, 52, 24);
    _loGainHeaderLabel->setBounds (364, 240, 52, 24);
    _loFreqHeaderLabel->setBounds (324, 240, 52, 24);
    _loGainSlider->setBounds (372, 260, 36, 28);
    _loFreqSlider->setBounds (332, 260, 36, 28);
    _hiEqButton->setBounds (452, 220, 56, 24);
    _loEqButton->setBounds (340, 220, 56, 24);
    _levelMeterOut->setBounds (720, 40, 12, 176);
    _levelMeterOutLabelButton->setBounds (712, 20, 28, 18);
    _levelMeterDryLabel->setBounds (620, 16, 36, 24);
    _widthHeaderLabel->setBounds (208, 220, 84, 24);
    _widthSlider->setBounds (208, 244, 84, 40);
    _widthLabel->setBounds (208, 280, 84, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void KlangFalterEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == _stretchSlider)
    {
        //[UserSliderCode__stretchSlider] -- add your slider handling code here..
        double sliderVal = _stretchSlider->getValue();
        if (::fabs(sliderVal-1.0) < 0.025)
        {
          sliderVal = 1.0;
          _stretchSlider->setValue(1.0, juce::dontSendNotification);
        }
        _processor.setStretch(sliderVal);
        //[/UserSliderCode__stretchSlider]
    }
    else if (sliderThatWasMoved == _drySlider)
    {
        //[UserSliderCode__drySlider] -- add your slider handling code here..
        const float scale = static_cast<float>(_drySlider->getValue());
        const float decibels = SnapValue(DecibelScaling::Scale2Db(scale), 0.0f, 0.5f);
        _processor.setParameterNotifyingHost(Parameters::DryDecibels, decibels);
        //[/UserSliderCode__drySlider]
    }
    else if (sliderThatWasMoved == _wetSlider)
    {
        //[UserSliderCode__wetSlider] -- add your slider handling code here..
        const float scale = static_cast<float>(_wetSlider->getValue());
        const float decibels = SnapValue(DecibelScaling::Scale2Db(scale), 0.0f, 0.5f);
        _processor.setParameterNotifyingHost(Parameters::WetDecibels, decibels);
        //[/UserSliderCode__wetSlider]
    }
    else if (sliderThatWasMoved == _beginSlider)
    {
        //[UserSliderCode__beginSlider] -- add your slider handling code here..
        _processor.setFileBeginSeconds(_beginSlider->getValue());
        //[/UserSliderCode__beginSlider]
    }
    else if (sliderThatWasMoved == _predelaySlider)
    {
        //[UserSliderCode__predelaySlider] -- add your slider handling code here..
        _processor.setPredelayMs(_predelaySlider->getValue());
        //[/UserSliderCode__predelaySlider]
    }
    else if (sliderThatWasMoved == _hiGainSlider)
    {
        //[UserSliderCode__hiGainSlider] -- add your slider handling code here..
        _processor.setParameterNotifyingHost(Parameters::EqHighDecibels, static_cast<float>(_hiGainSlider->getValue()));
        //[/UserSliderCode__hiGainSlider]
    }
    else if (sliderThatWasMoved == _hiFreqSlider)
    {
        //[UserSliderCode__hiFreqSlider] -- add your slider handling code here..
        _processor.setParameterNotifyingHost(Parameters::EqHighFreq, static_cast<float>(_hiFreqSlider->getValue()));
        //[/UserSliderCode__hiFreqSlider]
    }
    else if (sliderThatWasMoved == _loGainSlider)
    {
        //[UserSliderCode__loGainSlider] -- add your slider handling code here..
        _processor.setParameterNotifyingHost(Parameters::EqLowDecibels, static_cast<float>(_loGainSlider->getValue()));
        //[/UserSliderCode__loGainSlider]
    }
    else if (sliderThatWasMoved == _loFreqSlider)
    {
        //[UserSliderCode__loFreqSlider] -- add your slider handling code here..
        _processor.setParameterNotifyingHost(Parameters::EqLowFreq, static_cast<float>(_loFreqSlider->getValue()));
        //[/UserSliderCode__loFreqSlider]
    }
    else if (sliderThatWasMoved == _widthSlider)
    {
        //[UserSliderCode__widthSlider] -- add your slider handling code here..
        _processor.setParameterNotifyingHost(Parameters::StereoWidth, SnapValue(static_cast<float>(_widthSlider->getValue()), 1.0f, 0.05f));
        //[/UserSliderCode__widthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void KlangFalterEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

    const File presetDirectory = File::getCurrentWorkingDirectory();

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == _browseButton)
    {
        //[UserButtonCode__browseButton] -- add your button handler code here..
        int browserHeight = 0;
        juce::String browseButtonText;
        if (_browseButton->getToggleState())
        {
          browserHeight = 300;
          browseButtonText = juce::String("Hide Browser");
        }
        else
        {
          browserHeight = 0;
          browseButtonText = juce::String("Show Browser");
        }
        setBounds(getBounds().withHeight(_browseButton->getY() + _browseButton->getHeight() + browserHeight));
        _irBrowserComponent->setBounds(_irBrowserComponent->getBounds().withHeight(browserHeight - 10));
        _browseButton->setButtonText(browseButtonText);
        //[/UserButtonCode__browseButton]
    }
    else if (buttonThatWasClicked == _settingsButton)
    {
        //[UserButtonCode__settingsButton] -- add your button handler code here..
        _settingsDialog = new SettingsDialogComponent(_processor);
        juce::DialogWindow::showDialog("Settings",
                                       _settingsDialog,
                                       this,
                                       juce::Colours::white,
                                       true);
        //[/UserButtonCode__settingsButton]
    }
    else if (buttonThatWasClicked == _wetButton)
    {
        //[UserButtonCode__wetButton] -- add your button handler code here..
        _processor.setParameter(Parameters::WetOn, _wetButton->getToggleState());
        //[/UserButtonCode__wetButton]
    }
    else if (buttonThatWasClicked == _dryButton)
    {
        //[UserButtonCode__dryButton] -- add your button handler code here..
        _processor.setParameter(Parameters::DryOn, _dryButton->getToggleState());
        //[/UserButtonCode__dryButton]
    }
    else if (buttonThatWasClicked == _autogainButton)
    {
        //[UserButtonCode__autogainButton] -- add your button handler code here..
        _processor.setParameter(Parameters::AutoGainOn, _autogainButton->getToggleState());
        //[/UserButtonCode__autogainButton]
    }
    else if (buttonThatWasClicked == _reverseButton)
    {
        //[UserButtonCode__reverseButton] -- add your button handler code here..
        _processor.setReverse(_reverseButton->getToggleState());
        //[/UserButtonCode__reverseButton]
    }
    else if (buttonThatWasClicked == _hiEqButton)
    {
        //[UserButtonCode__hiEqButton] -- add your button handler code here..
        _processor.setParameter(Parameters::EqHighOn, _hiEqButton->getToggleState());
        //[/UserButtonCode__hiEqButton]
    }
    else if (buttonThatWasClicked == _loEqButton)
    {
        //[UserButtonCode__loEqButton] -- add your button handler code here..
        _processor.setParameter(Parameters::EqLowOn, _loEqButton->getToggleState());
        //[/UserButtonCode__loEqButton]
    }
    else if (buttonThatWasClicked == _levelMeterOutLabelButton)
    {
        //[UserButtonCode__levelMeterOutLabelButton] -- add your button handler code here..
        _processor.getSettings().setResultLevelMeterDisplay(_levelMeterOutLabelButton->getToggleState() ? Settings::Out : Settings::Wet);
        //[/UserButtonCode__levelMeterOutLabelButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void KlangFalterEditor::updateUI()
{
  const double maxFileDuration = _processor.getMaxFileDuration();
  const bool irAvailable = (maxFileDuration > 0.0);
  const size_t numInputChannels = static_cast<size_t>(std::min(_processor.getNumInputChannels(), 2));
  const size_t numOutputChannels = static_cast<size_t>(std::min(_processor.getNumOutputChannels(), 2));
  {
    const double stretch = _processor.getStretch();
    _stretchSlider->setEnabled(irAvailable);
    _stretchSlider->setRange(0.5, 1.5);
    _stretchSlider->setValue(stretch, juce::dontSendNotification);
    _stretchLabel->setText(String(static_cast<int>(100.0*stretch)) + String("%"), true);
  }
  {
    const float db = _processor.getParameter(Parameters::DryDecibels);
    const float scale = DecibelScaling::Db2Scale(db);
    _drySlider->setEnabled(true);
    _drySlider->setRange(0.0, 1.0);
    _drySlider->setValue(scale, juce::dontSendNotification);
    _dryLevelLabel->setText(DecibelScaling::DecibelString(db), true);
    _dryButton->setToggleState(_processor.getParameter(Parameters::DryOn), false);
  }
  {
    const float db = _processor.getParameter(Parameters::WetDecibels);
    const float scale = DecibelScaling::Db2Scale(db);
    _wetSlider->setEnabled(true);
    _wetSlider->setRange(0.0, 1.0);
    _wetSlider->setValue(scale, juce::dontSendNotification);
    _wetLevelLabel->setText(DecibelScaling::DecibelString(db), true);
    _wetButton->setToggleState(_processor.getParameter(Parameters::WetOn), false);
  }
  {
    _reverseButton->setEnabled(true);
    _reverseButton->setToggleState(_processor.getReverse(), false);
  }
  {
    const double fileBeginSeconds = std::min(_processor.getFileBeginSeconds(), maxFileDuration);
    _beginSlider->setEnabled(irAvailable);
    if (maxFileDuration > 0.0)
    {
      _beginSlider->setRange(0.0, maxFileDuration);
    }
    _beginSlider->setValue(fileBeginSeconds, juce::dontSendNotification);
    _beginLabel->setText(juce::String(static_cast<int>(fileBeginSeconds*1000.0 + 0.5)) + juce::String("ms"), true);
  }
  {
    const double predelayMs = _processor.getPredelayMs();
    _predelaySlider->setValue(predelayMs);
    _predelaySlider->setEnabled(irAvailable);
    _predelayLabel->setText(juce::String(static_cast<int>(predelayMs+0.5)) + juce::String("ms"), true);
  }
  {
    const float autoGainDecibels = _processor.getParameter(Parameters::AutoGainDecibels);
    const bool autoGainOn = _processor.getParameter(Parameters::AutoGainOn);
    const juce::String autoGainText = DecibelScaling::DecibelString(autoGainDecibels);
    _autogainButton->setButtonText(juce::String("Autogain ") + autoGainText);
    _autogainButton->setToggleState(autoGainOn, false);
  }
  {
    const bool loEqEnabled = irAvailable;
    const bool loEqOn = (_processor.getParameter(Parameters::EqLowOn) && loEqEnabled);
    const float freq = _processor.getParameter(Parameters::EqLowFreq);
    const float gainDb = _processor.getParameter(Parameters::EqLowDecibels);
    _loEqButton->setEnabled(loEqEnabled);
    _loEqButton->setToggleState(loEqOn, false);
    _loFreqSlider->setEnabled(loEqEnabled);
    _loFreqSlider->setValue(freq, juce::dontSendNotification);
    _loFreqLabel->setText(juce::String(static_cast<int>(freq+0.5f)) + juce::String("Hz"), false);
    _loGainSlider->setEnabled(loEqEnabled);
    _loGainSlider->setValue(gainDb, juce::dontSendNotification);
    _loGainLabel->setText(DecibelScaling::DecibelString(gainDb), false);
  }
  {
    const bool hiEqEnabled = irAvailable;
    const bool hiEqOn = (_processor.getParameter(Parameters::EqHighOn) && hiEqEnabled);
    const float freq = _processor.getParameter(Parameters::EqHighFreq);
    const float gainDb = _processor.getParameter(Parameters::EqHighDecibels);
    _hiEqButton->setEnabled(hiEqEnabled);
    _hiEqButton->setToggleState(hiEqOn, false);
    _hiFreqSlider->setEnabled(hiEqEnabled);
    _hiFreqSlider->setValue(freq, juce::dontSendNotification);
    _hiFreqLabel->setText(juce::String(freq/1000.0f, 2) + juce::String("kHz"), false);
    _hiGainSlider->setEnabled(hiEqEnabled);
    _hiGainSlider->setValue(gainDb, juce::dontSendNotification);
    _hiGainLabel->setText(DecibelScaling::DecibelString(gainDb), false);
  }
  {
    _widthHeaderLabel->setVisible(numOutputChannels >= 2);
    _widthSlider->setVisible(numOutputChannels >= 2);
    _widthLabel->setVisible(numOutputChannels >= 2);
    const float stereoWidth = _processor.getParameter(Parameters::StereoWidth);
    _widthSlider->setValue(stereoWidth, juce::dontSendNotification);
    _widthLabel->setText(juce::String(stereoWidth, 2), false);
  }
  {
    _levelMeterDry->setChannelCount(numInputChannels);
    _levelMeterOut->setChannelCount(numOutputChannels);
    Settings::ResultLevelMeterDisplay resultDisplay = _processor.getSettings().getResultLevelMeterDisplay();
    _levelMeterOutLabelButton->setToggleState(resultDisplay == Settings::Out, false);
    _levelMeterOutLabelButton->setButtonText((resultDisplay == Settings::Out) ? juce::String("Out") : juce::String("Wet"));
  }
  {
    const size_t numTabs = static_cast<size_t>(_irTabComponent->getNumTabs());
    if (numTabs > numInputChannels * numOutputChannels || numTabs != _irComponents.size())
    {
      _irTabComponent->clearTabs();
      _irComponents.clear();
    }
    for (size_t input=0; input<numInputChannels; ++input)
    {
      for (size_t output=0; output<numOutputChannels; ++output)
      {
        if (_irComponents.find(std::make_pair(input, output)) == _irComponents.end())
        {
          IRAgent* agent = _processor.getAgent(input, output);
          jassert(agent);
          if (agent)
          {
            IRComponent* irComponent = new IRComponent();
            irComponent->init(_processor.getAgent(input, output));
            _irTabComponent->addTab(juce::String(static_cast<int>(input)) + juce::String("-") + juce::String(static_cast<int>(output)),
                                    juce::Colour(0xffe5e5f0),
                                    irComponent,
                                    true);
            _irComponents.insert(std::make_pair(std::make_pair(input, output), irComponent));
          }
        }
      }
    }
  }
}


void KlangFalterEditor::changeListenerCallback(ChangeBroadcaster* source)
{
  if (source)
  {
    updateUI();
  }
}


void KlangFalterEditor::changeNotification()
{
  updateUI();
}


void KlangFalterEditor::timerCallback()
{
  Settings::ResultLevelMeterDisplay resultDisplay = _processor.getSettings().getResultLevelMeterDisplay();
  _levelMeterDry->setLevel(0, _processor.getLevelDry(0));
  _levelMeterDry->setLevel(1, _processor.getLevelDry(1));
  _levelMeterOut->setLevel(0, (resultDisplay == Settings::Out) ? _processor.getLevelOut(0) : _processor.getLevelWet(0));
  _levelMeterOut->setLevel(1, (resultDisplay == Settings::Out) ? _processor.getLevelOut(1) : _processor.getLevelWet(1));
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KlangFalterEditor" componentName=""
                 parentClasses="public AudioProcessorEditor, public ChangeNotifier::Listener, public ChangeListener, public Timer"
                 constructorParams="PluginAudioProcessor&amp; processor" variableInitialisers="AudioProcessorEditor(&amp;processor),&#10;_processor(processor)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="760" initialHeight="330">
  <BACKGROUND backgroundColour="ffa6a6b1"/>
  <GENERICCOMPONENT name="" id="6dd7ac2ee661b784" memberName="_decibelScaleDry" virtualName=""
                    explicitFocusOrder="0" pos="584 40 32 176" class="DecibelScale"
                    params=""/>
  <TABBEDCOMPONENT name="IRTabComponent" id="697fc3546f1ab7f1" memberName="_irTabComponent"
                   virtualName="" explicitFocusOrder="0" pos="16 12 542 204" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="Placeholder" colour="ffe5e5f0" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="IRComponent.cpp"/>
  </TABBEDCOMPONENT>
  <LABEL name="" id="ff104b46d553eb03" memberName="_stretchHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="80 220 84 24" textCol="ff202020"
         edTextCol="ff202020" edBkgCol="0" labelText="Stretch" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="e6fe992b37e74eba" memberName="_stretchSlider" virtualName=""
          explicitFocusOrder="0" pos="80 244 84 40" thumbcol="ffafafff"
          rotarysliderfill="ffafafff" min="0" max="2" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="" id="93270230a2db62e0" memberName="_levelMeterDry" virtualName=""
                    explicitFocusOrder="0" pos="632 40 12 176" class="LevelMeter"
                    params=""/>
  <LABEL name="DryLevelLabel" id="892bd8ba7f961215" memberName="_dryLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="572 224 60 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="-inf" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="34"/>
  <LABEL name="WetLevelLabel" id="3469fbc38286d2b6" memberName="_wetLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="656 224 64 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="-inf" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="34"/>
  <SLIDER name="" id="3694f3553dea94b" memberName="_drySlider" virtualName=""
          explicitFocusOrder="0" pos="612 32 24 192" min="0" max="10" int="0"
          style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="" id="f3824f7df1d2ea95" memberName="_decibelScaleOut" virtualName=""
                    explicitFocusOrder="0" pos="672 40 32 176" class="DecibelScale"
                    params=""/>
  <SLIDER name="" id="e50054d828347fbd" memberName="_wetSlider" virtualName=""
          explicitFocusOrder="0" pos="700 32 24 192" min="0" max="10" int="0"
          style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="" id="e5cc4d9d88fb6d29" memberName="_browseButton" virtualName=""
              explicitFocusOrder="0" pos="12 308 736 24" tooltip="Show Browser For Impulse Response Selection"
              bgColOn="ffbcbcff" buttonText="Show Browser" connectedEdges="8"
              needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="" id="5388ff2994f22af6" memberName="_irBrowserComponent"
                    virtualName="" explicitFocusOrder="0" pos="12 332 736 288" class="IRBrowserComponent"
                    params=""/>
  <TEXTBUTTON name="" id="53a50811080a676c" memberName="_settingsButton" virtualName=""
              explicitFocusOrder="0" pos="708 0 52 16" buttonText="Settings"
              connectedEdges="6" needsCallback="1" radioGroupId="0"/>
  <LABEL name="" id="51bcb70beb24f3cf" memberName="_stretchLabel" virtualName=""
         explicitFocusOrder="0" pos="80 280 84 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="100%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="59911bc6fa006837" memberName="_beginHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="16 220 84 24" textCol="ff202020"
         edTextCol="ff202020" edBkgCol="0" labelText="Begin" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="5e1bc6ab0a48dea8" memberName="_beginSlider" virtualName=""
          explicitFocusOrder="0" pos="16 244 84 40" thumbcol="ffafafff"
          rotarysliderfill="ffafafff" min="0" max="2" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.5"/>
  <LABEL name="" id="b32110895dcec8f5" memberName="_beginLabel" virtualName=""
         explicitFocusOrder="0" pos="16 280 84 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="0ms" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="" id="c0b279e2bae7030e" memberName="_wetButton" virtualName=""
              explicitFocusOrder="0" pos="672 248 44 24" tooltip="Wet Signal On/Off"
              bgColOff="80bcbcbc" bgColOn="ffbcbcff" buttonText="Wet" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="499237d463b07642" memberName="_dryButton" virtualName=""
              explicitFocusOrder="0" pos="584 248 44 24" tooltip="Dry Signal On/Off"
              bgColOff="80bcbcbc" bgColOn="ffbcbcff" buttonText="Dry" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="f25a3c5b0535fcca" memberName="_autogainButton" virtualName=""
              explicitFocusOrder="0" pos="584 280 132 24" tooltip="Autogain On/Off"
              bgColOff="80bcbcbc" bgColOn="ffbcbcff" buttonText="Autogain 0.0dB"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="fcb6829f0d6fc21f" memberName="_reverseButton" virtualName=""
              explicitFocusOrder="0" pos="486 8 72 24" tooltip="Reverse Impulse Response"
              bgColOff="80bcbcbc" bgColOn="ffbcbcff" buttonText="Reverse" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="" id="33afc8fa0b56ce55" memberName="_predelayHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="144 220 84 24" textCol="ff202020"
         edTextCol="ff202020" edBkgCol="0" labelText="Predelay" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="5263ccd8286f1f44" memberName="_predelaySlider" virtualName=""
          explicitFocusOrder="0" pos="144 244 84 40" bkgcol="0" thumbcol="ffafafff"
          rotarysliderfill="ffafafff" min="0" max="200" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="22992cd4f6d0f5c1" memberName="_predelayLabel" virtualName=""
         explicitFocusOrder="0" pos="144 280 84 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="0ms" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="841738a894cf241a" memberName="_hiFreqLabel" virtualName=""
         explicitFocusOrder="0" pos="436 284 52 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="15.2kHz" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="fc2c2b94ce457ca1" memberName="_hiGainLabel" virtualName=""
         explicitFocusOrder="0" pos="476 284 52 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="0.0dB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="56744cc537b91ad6" memberName="_hiGainHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="476 240 52 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="71caf1a3b5a498dd" memberName="_hiFreqHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="436 240 52 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="Freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="1c3776d0e6cbce1d" memberName="_hiGainSlider" virtualName=""
          explicitFocusOrder="0" pos="484 260 36 28" thumbcol="ffafafff"
          rotarysliderfill="b1606060" min="-30" max="30" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="702db07b37c24f93" memberName="_hiFreqSlider" virtualName=""
          explicitFocusOrder="0" pos="444 260 36 28" thumbcol="ffafafff"
          rotarysliderfill="b1606060" min="2000" max="20000" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="8b28430d938b39ca" memberName="_loFreqLabel" virtualName=""
         explicitFocusOrder="0" pos="324 284 52 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="1234Hz" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="390bab67dc140d90" memberName="_loGainLabel" virtualName=""
         explicitFocusOrder="0" pos="364 284 52 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="0.0dB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="8d9e4adc7538b7dc" memberName="_loGainHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="364 240 52 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="f3b3523aee42340f" memberName="_loFreqHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="324 240 52 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="Freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="a3dc7342caaa661f" memberName="_loGainSlider" virtualName=""
          explicitFocusOrder="0" pos="372 260 36 28" thumbcol="ffafafff"
          rotarysliderfill="b1606060" min="-30" max="30" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="313e885756edaea8" memberName="_loFreqSlider" virtualName=""
          explicitFocusOrder="0" pos="332 260 36 28" thumbcol="ffafafff"
          rotarysliderfill="b1606060" min="20" max="2000" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="" id="6455cd468963d5f2" memberName="_hiEqButton" virtualName=""
              explicitFocusOrder="0" pos="452 220 56 24" tooltip="High Shelf EQ On/Off"
              bgColOff="80bcbcbc" bgColOn="ffbcbcff" buttonText="Hi Shelf"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="a9ee81604acef972" memberName="_loEqButton" virtualName=""
              explicitFocusOrder="0" pos="340 220 56 24" tooltip="Low Shelf EQ On/Off"
              bgColOff="80bcbcbc" bgColOn="ffbcbcff" buttonText="Lo Shelf"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="" id="e4867bf99a47726a" memberName="_levelMeterOut" virtualName=""
                    explicitFocusOrder="0" pos="720 40 12 176" class="LevelMeter"
                    params=""/>
  <TEXTBUTTON name="" id="f5ed3d758ad2c3f4" memberName="_levelMeterOutLabelButton"
              virtualName="" explicitFocusOrder="0" pos="712 20 28 18" tooltip="Switches Between Out/Wet Level Measurement"
              bgColOff="bbbbff" bgColOn="bcbcff" buttonText="Out" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="" id="55e5b719a217b777" memberName="_levelMeterDryLabel"
         virtualName="" explicitFocusOrder="0" pos="620 16 36 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="Dry" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="d56b184ced7d1910" memberName="_widthHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="208 220 84 24" textCol="ff202020"
         edTextCol="ff202020" edBkgCol="0" labelText="Width" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="731dc43e41eff903" memberName="_widthSlider" virtualName=""
          explicitFocusOrder="0" pos="208 244 84 40" bkgcol="0" thumbcol="ffafafff"
          rotarysliderfill="ffafafff" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.30102"/>
  <LABEL name="" id="fff91dc356552479" memberName="_widthLabel" virtualName=""
         explicitFocusOrder="0" pos="208 280 84 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="1.0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
