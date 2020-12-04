/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  25 Nov 2012 3:27:01pm

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

//[/Headers]

#include "KlangFalterEditor.h"
#include "IRComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...


template<typename T>
T SnapValue(const T& val, const T& snapValue, const T& sensitivity)
{
  return (::fabs(val - snapValue) < sensitivity) ? snapValue : val;
}


//[/MiscUserDefs]

//==============================================================================
KlangFalterEditor::KlangFalterEditor (PluginAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter),
      _decibelScale (0),
      _irTabComponent (0),
      _stretchHeaderLabel (0),
      _stretchSlider (0),
      _levelMeterDry (0),
      _levelMeterWet (0),
      _dryLevelLabel (0),
      _wetLevelLabel (0),
      _drySlider (0),
      _decibelScale2 (0),
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
      _predelayLabel (0)
{
    addAndMakeVisible (_decibelScale = new DecibelScale());
    _decibelScale->setName (L"DecibelScale");

    addAndMakeVisible (_irTabComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    _irTabComponent->setTabBarDepth (30);
    _irTabComponent->addTab (L"1-1", Colour (0xffe5e5f0), new IRComponent(), true);
    _irTabComponent->addTab (L"1-2", Colour (0xffe5e5f0), new IRComponent(), true);
    _irTabComponent->addTab (L"2-1", Colour (0xffe5e5f0), new IRComponent(), true);
    _irTabComponent->addTab (L"2-2", Colour (0xffe5e5f0), new IRComponent(), true);
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
    _levelMeterDry->setName (L"LevelMeterDry");

    addAndMakeVisible (_levelMeterWet = new LevelMeter());
    _levelMeterWet->setName (L"LevelMeterWet");

    addAndMakeVisible (_dryLevelLabel = new Label (L"DryLevelLabel",
                                                   L"-inf"));
    _dryLevelLabel->setFont (Font (15.0000f, Font::plain));
    _dryLevelLabel->setJustificationType (Justification::centredRight);
    _dryLevelLabel->setEditable (false, false, false);
    _dryLevelLabel->setColour (Label::textColourId, Colour (0xff202020));
    _dryLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    _dryLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_wetLevelLabel = new Label (L"WetLevelLabel",
                                                   L"-inf"));
    _wetLevelLabel->setFont (Font (15.0000f, Font::plain));
    _wetLevelLabel->setJustificationType (Justification::centredRight);
    _wetLevelLabel->setEditable (false, false, false);
    _wetLevelLabel->setColour (Label::textColourId, Colour (0xff202020));
    _wetLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    _wetLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (_drySlider = new Slider (L"DrySlider"));
    _drySlider->setRange (0, 10, 0);
    _drySlider->setSliderStyle (Slider::LinearVertical);
    _drySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _drySlider->addListener (this);

    addAndMakeVisible (_decibelScale2 = new DecibelScale());
    _decibelScale2->setName (L"DecibelScale");

    addAndMakeVisible (_wetSlider = new Slider (L"WetSlider"));
    _wetSlider->setRange (0, 10, 0);
    _wetSlider->setSliderStyle (Slider::LinearVertical);
    _wetSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    _wetSlider->addListener (this);

    addAndMakeVisible (_browseButton = new TextButton (String::empty));
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
    _wetButton->setButtonText (L"Wet");
    _wetButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _wetButton->addListener (this);
    _wetButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _wetButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_dryButton = new TextButton (String::empty));
    _dryButton->setButtonText (L"Dry");
    _dryButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _dryButton->addListener (this);
    _dryButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _dryButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_autogainButton = new TextButton (String::empty));
    _autogainButton->setButtonText (L"Autogain 0.0dB");
    _autogainButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    _autogainButton->addListener (this);
    _autogainButton->setColour (TextButton::buttonColourId, Colour (0x80bcbcbc));
    _autogainButton->setColour (TextButton::buttonOnColourId, Colour (0xffbcbcff));

    addAndMakeVisible (_reverseButton = new TextButton (String::empty));
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


    //[UserPreSize]

    setLookAndFeel(&_customLookAndFeel);

    //[/UserPreSize]

    setSize (760, 330);


    //[Constructor] You can add your own custom stuff here..

    _processor = ownerFilter;
    if (_processor)
    {
      IRManager& irManager = _processor->getIRManager();
      _processor->addChangeListener(this);
      irManager.addChangeListener(this);
      IRComponent* irComponent00 = dynamic_cast<IRComponent*>(_irTabComponent->getTabContentComponent(0));
      IRComponent* irComponent01 = dynamic_cast<IRComponent*>(_irTabComponent->getTabContentComponent(1));
      IRComponent* irComponent10 = dynamic_cast<IRComponent*>(_irTabComponent->getTabContentComponent(2));
      IRComponent* irComponent11 = dynamic_cast<IRComponent*>(_irTabComponent->getTabContentComponent(3));
      irComponent00->init(&irManager, 0, 0);
      irComponent01->init(&irManager, 0, 1);
      irComponent10->init(&irManager, 1, 0);
      irComponent11->init(&irManager, 1, 1);
      _levelMeterDry->setChannelCount(2);
      _levelMeterWet->setChannelCount(4);
      _irBrowserComponent->init(_processor);
      startTimer(100);
    }
    processorChanged();

    _browseButton->setClickingTogglesState(true);
    _dryButton->setClickingTogglesState(true);
    _wetButton->setClickingTogglesState(true);
    _autogainButton->setClickingTogglesState(true);
    _reverseButton->setClickingTogglesState(true);

    //[/Constructor]
}

KlangFalterEditor::~KlangFalterEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

    if (_processor)
    {
      _processor->removeChangeListener(this);
      _processor->getIRManager().removeChangeListener(this);
    }

    //[/Destructor_pre]

    deleteAndZero (_decibelScale);
    deleteAndZero (_irTabComponent);
    deleteAndZero (_stretchHeaderLabel);
    deleteAndZero (_stretchSlider);
    deleteAndZero (_levelMeterDry);
    deleteAndZero (_levelMeterWet);
    deleteAndZero (_dryLevelLabel);
    deleteAndZero (_wetLevelLabel);
    deleteAndZero (_drySlider);
    deleteAndZero (_decibelScale2);
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
  BinaryData::ImageProvider imageProvider;
  g.setFillType(juce::FillType(imageProvider.getImageForIdentifier("brushed_aluminium_png"), juce::AffineTransform()));
    g.fillAll();
    //[/UserPaint]
}

void KlangFalterEditor::resized()
{
    _decibelScale->setBounds (580, 40, 32, 176);
    _irTabComponent->setBounds (12, 12, 542, 204);
    _stretchHeaderLabel->setBounds (104, 220, 84, 24);
    _stretchSlider->setBounds (104, 244, 84, 40);
    _levelMeterDry->setBounds (616, 40, 12, 176);
    _levelMeterWet->setBounds (704, 40, 24, 176);
    _dryLevelLabel->setBounds (584, 220, 60, 24);
    _wetLevelLabel->setBounds (680, 220, 64, 24);
    _drySlider->setBounds (624, 32, 24, 192);
    _decibelScale2->setBounds (668, 40, 32, 176);
    _wetSlider->setBounds (724, 32, 24, 192);
    _browseButton->setBounds (12, 308, 736, 24);
    _irBrowserComponent->setBounds (12, 332, 736, 288);
    _settingsButton->setBounds (708, 0, 52, 16);
    _stretchLabel->setBounds (104, 280, 84, 24);
    _beginHeaderLabel->setBounds (16, 220, 84, 24);
    _beginSlider->setBounds (16, 244, 84, 40);
    _beginLabel->setBounds (16, 280, 84, 24);
    _wetButton->setBounds (696, 240, 44, 24);
    _dryButton->setBounds (596, 240, 44, 24);
    _autogainButton->setBounds (410, 240, 144, 24);
    _reverseButton->setBounds (482, 8, 72, 24);
    _predelayHeaderLabel->setBounds (196, 220, 84, 24);
    _predelaySlider->setBounds (196, 244, 84, 40);
    _predelayLabel->setBounds (196, 280, 84, 24);
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
        if (_processor)
        {
          double sliderVal = _stretchSlider->getValue();
          if (::fabs(sliderVal-1.0) < 0.025)
          {
            sliderVal = 1.0;
            _stretchSlider->setValue(1.0, false);
          }
          _processor->getIRManager().setStretch(sliderVal);
        }
        //[/UserSliderCode__stretchSlider]
    }
    else if (sliderThatWasMoved == _drySlider)
    {
        //[UserSliderCode__drySlider] -- add your slider handling code here..
        const float scale = static_cast<float>(_drySlider->getValue());
        const float gain = SnapValue(DecibelScaling::Scale2Gain(scale), 1.0f, 0.075f);
        if (_processor)
        {
          _processor->setParameterNotifyingHost(PluginAudioProcessor::Dry, gain);
        }
        //[/UserSliderCode__drySlider]
    }
    else if (sliderThatWasMoved == _wetSlider)
    {
        //[UserSliderCode__wetSlider] -- add your slider handling code here..
        const float scale = static_cast<float>(_wetSlider->getValue());
        const float gain = SnapValue(DecibelScaling::Scale2Gain(scale), 1.0f, 0.075f);
        if (_processor)
        {
          _processor->setParameterNotifyingHost(PluginAudioProcessor::Wet, gain);
        }
        //[/UserSliderCode__wetSlider]
    }
    else if (sliderThatWasMoved == _beginSlider)
    {
        //[UserSliderCode__beginSlider] -- add your slider handling code here..
        _processor->getIRManager().setFileBeginSeconds(_beginSlider->getValue());
        //[/UserSliderCode__beginSlider]
    }
    else if (sliderThatWasMoved == _predelaySlider)
    {
        //[UserSliderCode__predelaySlider] -- add your slider handling code here..
        _processor->getIRManager().setPredelayMs(_predelaySlider->getValue());
        //[/UserSliderCode__predelaySlider]
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
        _settingsDialog = nullptr;
        _settingsDialog = new SettingsDialogComponent(*_processor);
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
        _processor->setParameter(PluginAudioProcessor::WetOn, _wetButton->getToggleState() ? 1.0f : 0.0f);
        //[/UserButtonCode__wetButton]
    }
    else if (buttonThatWasClicked == _dryButton)
    {
        //[UserButtonCode__dryButton] -- add your button handler code here..
        _processor->setParameter(PluginAudioProcessor::DryOn, _dryButton->getToggleState() ? 1.0f : 0.0f);
        //[/UserButtonCode__dryButton]
    }
    else if (buttonThatWasClicked == _autogainButton)
    {
        //[UserButtonCode__autogainButton] -- add your button handler code here..
        _processor->setParameter(PluginAudioProcessor::AutoGainOn, _autogainButton->getToggleState() ? 1.0f : 0.0f);
        //[/UserButtonCode__autogainButton]
    }
    else if (buttonThatWasClicked == _reverseButton)
    {
        //[UserButtonCode__reverseButton] -- add your button handler code here..
        if (_processor)
        {
          _processor->getIRManager().setReverse(_reverseButton->getToggleState());
        }
        //[/UserButtonCode__reverseButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void KlangFalterEditor::processorChanged()
{
  const IRManager* irManager = _processor ? &_processor->getIRManager() : nullptr;
  const double maxFileDuration = irManager ? irManager->getMaxFileDuration() : 0.0;
  const bool irAvailable = (maxFileDuration > 0.0);

  if (_stretchSlider)
  {
    const double stretch = irManager ? irManager->getStretch() : 1.0;
    _stretchSlider->setEnabled(irAvailable);
    _stretchSlider->setRange(0.5, 1.5);
    _stretchSlider->setValue(stretch, false, false);
    _stretchLabel->setText(String(static_cast<int>(100.0*stretch)) + String("%"), true);
  }

  if (_drySlider)
  {
    if (_processor)
    {
      const float gain = _processor->getParameter(PluginAudioProcessor::Dry);
      const float db = DecibelScaling::Gain2Db(gain);
      const float scale = DecibelScaling::Db2Scale(db);
      _drySlider->setEnabled(true);
      _drySlider->setRange(0.0, 1.0);
      _drySlider->setValue(scale, false, false);
      _dryLevelLabel->setText(DecibelScaling::DecibelString(db), true);
    }
    else
    {
      _drySlider->setEnabled(false);
    }
  }

  if (_wetSlider)
  {
    if (_processor)
    {
      const float gain = _processor->getParameter(PluginAudioProcessor::Wet);
      const float db = DecibelScaling::Gain2Db(gain);
      const float scale = DecibelScaling::Db2Scale(db);
      _wetSlider->setEnabled(true);
      _wetSlider->setRange(0.0, 1.0);
      _wetSlider->setValue(scale, false, false);
      _wetLevelLabel->setText(DecibelScaling::DecibelString(db), true);
    }
    else
    {
      _wetSlider->setEnabled(false);
    }
  }

  if (_reverseButton)
  {
    if (irManager)
    {
      _reverseButton->setEnabled(true);
      _reverseButton->setToggleState(irManager->getReverse(), false);
    }
    else
    {
      _reverseButton->setEnabled(false);
      _reverseButton->setToggleState(false, false);
    }
  }

  if (_beginSlider)
  {
    const double fileBeginSeconds = std::min(irManager->getFileBeginSeconds(), maxFileDuration);
    _beginSlider->setEnabled(irAvailable);
    if (maxFileDuration > 0.0)
    {
      _beginSlider->setRange(0.0, maxFileDuration);
    }
    _beginSlider->setValue(fileBeginSeconds, false, false);

    if (_beginLabel)
    {
      _beginLabel->setText(juce::String(static_cast<int>(fileBeginSeconds*1000.0 + 0.5)) + juce::String("ms"), true);
    }
  }

  if (_predelaySlider)
  {
    const double predelayMs = irManager->getPredelayMs();
    _predelaySlider->setValue(predelayMs);
    _predelaySlider->setEnabled(irAvailable);
    if (_predelayLabel)
    {
      _predelayLabel->setText(juce::String(static_cast<int>(predelayMs+0.5)) + juce::String("ms"), true);
    }
  }

  if (_autogainButton)
  {
    const float autoGain = _processor->getParameter(PluginAudioProcessor::AutoGain);
    const float autoGainOn = _processor->getParameter(PluginAudioProcessor::AutoGainOn);
    const juce::String autoGainText = DecibelScaling::DecibelString(DecibelScaling::Gain2Db(autoGain));
    _autogainButton->setButtonText(juce::String("Autogain ") + autoGainText);
    _autogainButton->setToggleState(autoGainOn > 0.5, false);
  }

  if (_dryButton)
  {
    _dryButton->setToggleState(_processor->getParameter(PluginAudioProcessor::DryOn) > 0.5, false);
  }

  if (_wetButton)
  {
    _wetButton->setToggleState(_processor->getParameter(PluginAudioProcessor::WetOn) > 0.5, false);
  }
}


void KlangFalterEditor::changeListenerCallback(ChangeBroadcaster* /*source*/)
{
  processorChanged();
}


void KlangFalterEditor::timerCallback()
{
  float levelDry1 = 0.0f;
  float levelDry2 = 0.0f;
  float levelWet00 = 0.0f;
  float levelWet01 = 0.0f;
  float levelWet10 = 0.0f;
  float levelWet11 = 0.0f;
  if (_processor)
  {
    IRManager& irManager = _processor->getIRManager();
    levelDry1 = _processor->getLevelDry(0);
    levelDry2 = _processor->getLevelDry(1);
    levelWet00 = irManager.getAgent(0, 0)->getLevel();
    levelWet01 = irManager.getAgent(0, 1)->getLevel();
    levelWet10 = irManager.getAgent(1, 0)->getLevel();
    levelWet11 = irManager.getAgent(1, 1)->getLevel();
  }
  _levelMeterDry->setLevel(0, levelDry1);
  _levelMeterDry->setLevel(1, levelDry2);
  _levelMeterWet->setLevel(0, levelWet00);
  _levelMeterWet->setLevel(1, levelWet01);
  _levelMeterWet->setLevel(2, levelWet10);
  _levelMeterWet->setLevel(3, levelWet11);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KlangFalterEditor" componentName=""
                 parentClasses="public AudioProcessorEditor, public ChangeListener, public Timer"
                 constructorParams="PluginAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="760" initialHeight="330">
  <BACKGROUND backgroundColour="ffa6a6b1"/>
  <GENERICCOMPONENT name="DecibelScale" id="6dd7ac2ee661b784" memberName="_decibelScale"
                    virtualName="" explicitFocusOrder="0" pos="580 40 32 176" class="DecibelScale"
                    params=""/>
  <TABBEDCOMPONENT name="IRTabComponent" id="697fc3546f1ab7f1" memberName="_irTabComponent"
                   virtualName="" explicitFocusOrder="0" pos="12 12 542 204" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="1-1" colour="ffe5e5f0" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="IRComponent.cpp"/>
    <TAB name="1-2" colour="ffe5e5f0" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="IRComponent.cpp"/>
    <TAB name="2-1" colour="ffe5e5f0" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="IRComponent.cpp"/>
    <TAB name="2-2" colour="ffe5e5f0" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="IRComponent.cpp"/>
  </TABBEDCOMPONENT>
  <LABEL name="" id="ff104b46d553eb03" memberName="_stretchHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="104 220 84 24" textCol="ff202020"
         edTextCol="ff202020" edBkgCol="0" labelText="Stretch" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="e6fe992b37e74eba" memberName="_stretchSlider" virtualName=""
          explicitFocusOrder="0" pos="104 244 84 40" thumbcol="ffafafff"
          rotarysliderfill="ffafafff" min="0" max="2" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="LevelMeterDry" id="93270230a2db62e0" memberName="_levelMeterDry"
                    virtualName="" explicitFocusOrder="0" pos="616 40 12 176" class="LevelMeter"
                    params=""/>
  <GENERICCOMPONENT name="LevelMeterWet" id="e4867bf99a47726a" memberName="_levelMeterWet"
                    virtualName="" explicitFocusOrder="0" pos="704 40 24 176" class="LevelMeter"
                    params=""/>
  <LABEL name="DryLevelLabel" id="892bd8ba7f961215" memberName="_dryLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="584 220 60 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="-inf" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <LABEL name="WetLevelLabel" id="3469fbc38286d2b6" memberName="_wetLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="680 220 64 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="-inf" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="DrySlider" id="3694f3553dea94b" memberName="_drySlider"
          virtualName="" explicitFocusOrder="0" pos="624 32 24 192" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="DecibelScale" id="f3824f7df1d2ea95" memberName="_decibelScale2"
                    virtualName="" explicitFocusOrder="0" pos="668 40 32 176" class="DecibelScale"
                    params=""/>
  <SLIDER name="WetSlider" id="e50054d828347fbd" memberName="_wetSlider"
          virtualName="" explicitFocusOrder="0" pos="724 32 24 192" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="" id="e5cc4d9d88fb6d29" memberName="_browseButton" virtualName=""
              explicitFocusOrder="0" pos="12 308 736 24" bgColOn="ffbcbcff"
              buttonText="Show Browser" connectedEdges="8" needsCallback="1"
              radioGroupId="0"/>
  <GENERICCOMPONENT name="" id="5388ff2994f22af6" memberName="_irBrowserComponent"
                    virtualName="" explicitFocusOrder="0" pos="12 332 736 288" class="IRBrowserComponent"
                    params=""/>
  <TEXTBUTTON name="" id="53a50811080a676c" memberName="_settingsButton" virtualName=""
              explicitFocusOrder="0" pos="708 0 52 16" buttonText="Settings"
              connectedEdges="6" needsCallback="1" radioGroupId="0"/>
  <LABEL name="" id="51bcb70beb24f3cf" memberName="_stretchLabel" virtualName=""
         explicitFocusOrder="0" pos="104 280 84 24" textCol="ff202020"
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
              explicitFocusOrder="0" pos="696 240 44 24" bgColOff="80bcbcbc"
              bgColOn="ffbcbcff" buttonText="Wet" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="" id="499237d463b07642" memberName="_dryButton" virtualName=""
              explicitFocusOrder="0" pos="596 240 44 24" bgColOff="80bcbcbc"
              bgColOn="ffbcbcff" buttonText="Dry" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="" id="f25a3c5b0535fcca" memberName="_autogainButton" virtualName=""
              explicitFocusOrder="0" pos="410 240 144 24" bgColOff="80bcbcbc"
              bgColOn="ffbcbcff" buttonText="Autogain 0.0dB" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="fcb6829f0d6fc21f" memberName="_reverseButton" virtualName=""
              explicitFocusOrder="0" pos="482 8 72 24" bgColOff="80bcbcbc"
              bgColOn="ffbcbcff" buttonText="Reverse" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="" id="33afc8fa0b56ce55" memberName="_predelayHeaderLabel"
         virtualName="" explicitFocusOrder="0" pos="196 220 84 24" textCol="ff202020"
         edTextCol="ff202020" edBkgCol="0" labelText="Predelay" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="5263ccd8286f1f44" memberName="_predelaySlider" virtualName=""
          explicitFocusOrder="0" pos="196 244 84 40" thumbcol="ffafafff"
          rotarysliderfill="ffafafff" min="0" max="200" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="22992cd4f6d0f5c1" memberName="_predelayLabel" virtualName=""
         explicitFocusOrder="0" pos="196 280 84 24" textCol="ff202020"
         edTextCol="ff000000" edBkgCol="0" labelText="0ms" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: brushed_aluminium_png, 14724, "../Resources/brushed_aluminium.png"
static const unsigned char resource_KlangFalterEditor_brushed_aluminium_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,84,0,0,0,110,8,2,0,0,0,247,102,124,157,0,0,0,9,112,72,89,115,0,0,11,
19,0,0,11,19,1,0,154,156,24,0,0,0,4,103,65,77,65,0,0,177,142,124,251,81,147,0,0,0,32,99,72,82,77,0,0,122,37,0,0,128,131,0,0,249,255,0,0,128,233,0,0,117,48,0,0,234,96,0,0,58,152,0,0,23,111,146,95,197,70,
0,0,56,250,73,68,65,84,120,218,172,83,71,14,192,32,12,75,248,255,153,231,66,17,81,45,203,97,244,80,31,16,114,246,242,90,171,153,185,187,189,224,127,239,221,8,33,10,178,79,240,135,245,197,48,152,48,247,
137,80,64,44,72,51,66,196,230,87,125,206,22,177,6,74,41,98,216,90,147,4,144,24,107,242,7,10,97,203,140,148,47,53,230,90,196,231,1,185,88,97,174,221,56,48,255,226,139,127,214,217,181,98,12,75,218,190,172,
37,147,60,71,225,151,185,241,94,241,155,163,200,43,171,40,219,178,187,41,56,228,162,120,115,176,87,187,161,35,226,104,209,161,153,249,30,229,0,31,1,40,43,163,21,10,97,24,134,34,235,255,255,241,192,65,
184,33,36,93,229,250,48,100,98,77,179,211,88,40,196,25,32,154,159,208,152,239,84,147,162,117,194,237,93,75,147,214,68,125,202,21,109,91,136,168,30,29,81,238,239,189,159,223,133,157,181,214,0,40,15,169,
253,68,234,52,70,51,167,110,108,41,232,230,51,142,38,19,118,200,217,33,38,90,1,115,136,252,21,22,45,241,106,56,201,51,198,120,127,250,165,141,184,142,57,48,129,217,141,77,98,48,136,73,104,147,73,16,114,
107,51,19,156,83,199,190,80,129,125,105,241,193,61,29,114,162,114,42,87,213,77,6,86,244,174,98,108,10,244,7,147,248,145,234,87,0,82,171,32,5,96,24,132,93,246,255,23,123,88,65,8,33,137,210,177,157,134,
108,218,168,73,250,0,198,52,197,200,201,200,129,14,162,149,62,90,145,31,145,27,62,150,228,140,165,89,35,165,22,114,98,105,152,69,71,2,226,130,162,150,60,139,77,49,52,238,36,239,183,59,155,160,115,86,243,
11,246,251,198,88,150,235,192,66,248,63,30,254,53,27,166,230,60,92,228,169,251,6,142,157,72,85,77,192,157,9,209,171,248,95,22,145,104,185,88,33,40,145,104,119,148,137,41,30,205,117,25,16,23,93,134,226,
151,86,96,17,80,253,205,43,0,229,229,146,2,48,16,194,208,77,239,127,230,22,132,16,242,17,187,233,206,14,227,196,151,248,240,77,28,201,226,183,34,119,97,185,68,128,38,35,167,201,18,90,64,86,96,37,122,187,
63,63,119,28,133,12,23,184,135,135,183,56,156,203,118,227,128,88,72,220,198,85,36,120,148,197,125,86,99,118,189,212,54,232,252,165,137,148,199,128,19,13,147,91,55,73,109,63,218,213,184,232,112,206,146,
228,219,178,219,247,157,240,200,229,120,53,14,38,252,55,70,64,204,249,173,219,144,34,219,85,220,184,121,143,104,196,119,168,189,2,112,98,6,41,0,131,64,12,188,244,255,111,110,65,8,33,19,89,235,205,130,
61,168,201,238,108,30,54,150,145,124,104,179,133,106,241,150,231,180,25,23,225,236,192,250,29,35,70,212,108,186,49,112,189,170,220,123,81,92,116,213,86,181,238,46,110,32,11,184,248,92,118,127,123,233,
197,47,20,214,97,166,112,97,239,17,70,116,246,111,161,249,171,214,83,166,60,220,48,122,158,78,150,121,68,206,174,186,218,204,98,161,207,5,5,81,197,42,228,239,14,85,27,198,24,102,213,100,202,39,101,141,
81,20,192,43,0,41,102,140,3,80,8,131,208,229,223,255,204,14,38,228,5,104,29,190,155,139,162,210,10,124,53,223,154,242,146,60,146,222,76,2,187,30,190,254,54,234,17,134,94,107,178,176,77,43,18,182,185,12,
74,29,222,2,25,95,45,92,149,79,79,251,87,163,71,50,38,85,162,77,173,81,154,60,177,191,174,182,158,159,189,96,2,182,100,13,211,131,46,225,83,106,201,197,200,212,245,41,253,50,253,205,236,182,150,98,245,
158,194,147,46,152,137,3,139,252,142,235,62,140,162,36,94,149,162,207,206,40,36,53,144,182,45,56,77,34,25,157,152,83,28,1,24,51,183,21,128,65,24,134,194,88,255,255,151,133,9,18,146,211,186,61,236,221,
154,91,227,171,40,63,84,220,39,212,109,22,179,144,13,215,76,44,101,41,185,87,85,184,219,236,255,96,194,72,6,92,150,48,86,153,72,161,216,39,178,51,215,253,116,182,206,160,146,3,93,223,134,86,48,219,245,
48,153,249,129,38,137,215,61,124,92,59,133,46,228,91,183,151,238,100,33,46,25,107,112,239,186,113,220,164,208,228,52,154,161,192,29,52,158,107,125,190,239,170,170,218,20,160,59,162,217,32,248,181,22,181,
3,90,173,166,5,86,55,255,37,0,103,86,142,3,48,8,195,150,254,255,205,84,66,178,44,219,49,136,141,41,37,52,135,143,15,2,184,52,195,254,54,40,135,151,184,60,58,118,84,223,123,146,201,31,249,184,43,58,115,
139,188,145,7,191,215,159,88,0,69,149,229,28,5,195,247,191,206,241,89,113,40,67,74,110,27,221,208,7,27,47,42,234,15,146,158,48,47,199,65,83,168,50,20,216,227,40,72,120,26,58,147,17,27,21,62,62,139,206,
117,3,117,221,202,241,254,228,94,144,188,0,16,64,105,227,157,39,174,225,77,228,243,75,10,210,169,13,35,133,125,94,2,176,106,229,56,0,64,64,80,225,255,111,86,72,54,50,151,141,80,40,20,18,199,216,57,76,
201,60,185,92,103,155,231,196,249,126,219,170,135,5,184,68,167,175,111,185,114,194,120,112,40,114,250,34,139,176,244,59,203,121,206,175,155,219,195,135,0,252,139,224,103,191,182,57,201,53,184,126,86,28,
192,96,1,183,210,196,146,192,118,126,179,227,41,174,50,73,165,233,238,152,139,105,152,127,5,193,40,213,74,62,5,96,43,67,253,49,9,136,168,182,4,32,213,76,110,0,136,65,24,248,73,255,53,239,35,146,101,249,
64,172,210,0,31,48,135,135,35,62,68,100,233,113,57,228,88,220,2,175,42,160,255,200,8,238,228,228,95,133,185,152,34,204,111,56,176,181,164,25,183,182,107,51,38,155,197,224,142,99,204,68,236,176,27,155,
109,222,198,255,58,130,143,126,193,230,142,104,215,132,36,75,102,151,39,136,209,119,20,0,34,184,146,103,33,9,238,133,8,157,5,250,206,140,90,245,238,227,156,40,206,42,169,16,176,0,249,192,105,27,193,230,
47,46,130,42,175,156,79,0,74,205,37,5,64,24,6,162,93,148,220,255,200,22,4,25,230,147,212,238,92,40,130,105,157,207,219,85,101,79,86,202,12,212,125,81,52,98,133,138,58,28,123,26,89,140,135,156,136,254,
132,241,101,40,249,211,123,111,166,57,245,118,182,8,164,143,157,246,103,226,43,172,247,182,28,219,47,32,103,212,56,99,7,214,75,188,123,155,144,212,62,69,188,180,163,108,174,190,28,75,242,77,215,187,86,
198,239,212,158,160,46,32,90,174,137,39,241,81,77,170,141,3,73,44,80,170,238,241,210,182,140,9,212,107,192,164,177,125,63,235,17,128,85,51,88,1,32,4,129,232,101,253,255,95,222,5,65,100,158,169,196,118,
234,148,20,141,217,115,158,147,35,85,122,152,35,47,241,201,247,183,137,195,98,114,237,237,95,140,101,102,25,174,230,2,73,218,248,146,80,243,107,79,248,241,215,32,181,22,51,70,153,89,130,167,46,5,60,218,
37,175,245,217,203,245,194,92,208,112,147,82,231,25,157,208,130,229,19,118,115,54,54,4,97,82,229,59,204,234,111,172,192,79,77,53,17,24,111,59,85,22,187,107,62,176,188,87,75,147,69,185,84,102,254,30,241,
21,128,117,51,70,2,32,4,97,160,133,255,127,179,29,195,100,67,134,194,254,26,207,136,36,139,87,18,203,188,126,86,20,42,198,146,207,12,63,44,209,173,250,218,239,115,130,13,123,60,10,79,136,115,33,35,9,26,
226,131,130,156,6,157,249,165,0,127,93,73,60,79,215,108,16,236,151,42,182,135,8,108,109,166,145,138,80,44,234,75,222,16,83,189,182,164,237,184,233,32,134,246,214,45,115,187,133,106,137,114,104,236,73,
245,2,223,233,62,66,34,250,48,167,40,173,129,149,174,245,164,210,59,216,60,235,9,64,186,25,228,0,16,130,48,240,255,191,86,47,164,105,97,52,187,30,185,169,8,56,148,147,249,77,41,249,66,140,236,197,106,
88,106,219,72,208,49,98,226,149,207,207,74,196,137,217,192,15,144,5,146,173,60,19,70,74,210,201,38,224,215,150,57,249,123,178,192,49,201,4,128,102,127,6,132,215,219,249,169,11,210,228,195,184,52,237,229,
250,169,206,86,39,209,97,13,147,196,194,96,79,94,10,163,162,170,20,174,45,173,116,81,179,240,81,107,42,221,91,179,64,51,209,208,202,232,160,37,223,107,9,192,184,185,227,0,8,195,48,52,3,247,63,51,67,37,
43,248,87,214,10,81,32,164,81,158,157,135,202,11,40,125,79,39,250,10,231,177,52,237,129,184,202,27,150,192,32,216,240,26,168,133,67,27,173,206,87,230,107,13,42,26,59,9,150,246,63,160,62,141,22,11,128,
133,122,186,201,104,97,69,215,66,253,147,228,37,111,226,220,166,208,18,195,179,18,90,186,94,15,74,29,94,72,6,85,59,169,162,91,20,111,72,33,100,212,125,32,130,41,171,201,222,87,54,178,135,136,213,240,108,
172,183,226,62,226,130,75,55,41,69,104,175,188,2,112,110,46,41,0,131,64,12,189,255,173,93,8,67,200,207,193,101,161,116,90,21,235,36,47,220,243,223,98,84,114,46,237,251,21,172,189,56,159,58,121,41,54,103,
131,119,56,154,118,195,66,116,148,202,37,162,86,49,9,148,232,103,85,41,254,133,152,227,64,199,164,66,161,65,152,112,29,117,4,21,82,218,252,36,247,146,225,190,141,255,176,9,210,209,192,166,48,38,218,168,
178,110,233,29,74,163,177,73,166,150,49,236,159,214,61,66,186,147,214,234,243,128,80,30,110,181,9,34,127,172,221,104,39,244,8,192,202,25,163,0,20,194,48,212,193,251,159,249,15,130,148,164,47,118,248,155,
8,46,90,107,77,158,238,26,223,217,114,119,155,138,176,231,138,52,73,220,231,0,13,2,166,160,29,34,248,181,135,176,232,255,121,215,13,221,108,41,112,46,137,40,134,45,217,4,153,138,19,46,232,140,37,72,241,
95,4,128,102,99,146,32,178,55,57,79,46,55,20,91,175,116,241,131,159,118,153,158,137,96,40,91,58,237,191,248,31,129,22,217,172,197,8,21,38,212,47,175,93,92,194,240,75,177,235,47,212,254,4,96,229,204,109,
0,0,97,24,72,193,254,51,211,161,200,57,27,36,88,128,42,128,206,79,166,227,85,103,155,227,69,237,48,38,96,150,9,95,196,188,225,3,228,24,224,31,177,178,46,249,197,250,244,98,147,207,217,60,216,145,16,17,
177,11,31,57,225,131,115,38,14,48,146,197,71,16,112,254,60,150,41,94,228,198,99,124,248,102,37,6,170,72,149,46,243,135,143,190,55,146,8,46,155,185,169,66,58,88,192,212,189,219,239,16,64,12,115,80,125,
206,131,43,183,79,88,2,80,114,6,57,0,132,32,12,228,176,255,127,179,7,147,13,161,157,170,31,240,100,64,166,131,95,95,137,183,8,241,191,250,59,198,11,236,231,158,0,133,21,17,125,246,147,247,210,235,133,
202,88,161,171,19,243,63,54,88,26,168,70,214,56,24,181,229,11,227,40,130,35,199,249,159,136,38,125,231,80,236,207,214,197,98,239,83,11,181,39,116,41,221,250,148,150,162,87,147,88,109,170,111,185,128,46,
110,135,97,216,26,92,74,91,109,112,48,110,151,122,59,26,212,147,246,23,106,247,232,40,52,54,82,149,212,215,202,18,128,145,51,90,1,40,6,65,104,255,255,213,99,12,134,152,90,239,187,131,46,17,75,79,93,182,
63,204,171,160,85,30,118,90,245,236,119,229,220,69,184,220,78,35,137,192,48,147,35,19,189,71,74,80,67,119,134,229,34,131,165,76,229,140,177,50,152,170,219,86,54,58,252,185,181,174,70,88,109,52,188,17,
55,216,148,123,188,144,20,28,154,165,15,116,22,161,92,125,112,179,60,255,47,235,184,212,134,199,160,228,91,3,107,214,75,78,74,60,210,116,157,125,142,93,207,251,36,191,73,115,219,130,63,10,105,250,127,
242,8,64,201,21,27,1,16,131,32,139,175,220,127,224,116,158,7,136,254,0,41,82,72,8,32,95,102,26,49,67,34,43,27,230,38,243,108,12,48,32,198,236,76,134,202,129,198,176,251,89,103,187,29,42,19,151,114,116,
251,243,43,51,136,221,47,157,80,192,35,250,4,79,204,72,127,9,126,171,28,117,212,113,204,216,92,184,244,229,43,33,113,25,204,206,142,14,53,72,177,213,254,221,35,79,204,206,226,208,91,201,40,195,95,110,
25,61,174,11,246,69,117,163,209,66,74,109,109,61,3,242,8,13,119,94,198,122,2,144,114,198,56,0,131,48,12,204,208,255,127,56,75,135,72,85,107,39,23,164,238,8,146,1,176,141,241,149,153,128,52,228,74,108,
245,3,23,105,214,200,154,85,249,172,102,128,59,57,72,123,10,16,99,95,116,201,74,188,103,252,163,136,156,125,30,4,58,85,8,121,103,85,179,191,101,252,212,234,121,115,50,135,63,87,22,14,13,112,43,52,227,
150,167,220,183,248,198,230,181,51,180,254,25,120,126,2,174,17,230,237,241,64,158,137,108,58,150,121,187,96,101,93,97,139,240,61,220,109,203,98,111,101,180,88,131,111,1,24,57,119,28,128,97,16,134,50,244,
254,103,238,208,165,194,126,54,91,198,72,145,9,248,195,163,11,70,168,71,10,15,67,142,241,129,189,69,150,60,203,130,179,77,59,208,120,182,238,179,200,210,105,254,77,205,237,106,81,95,196,33,157,115,219,
127,244,204,100,164,93,84,253,90,23,200,127,57,231,40,81,229,128,194,56,106,233,104,21,116,106,228,196,226,156,36,24,11,245,186,105,111,17,162,182,232,107,235,26,34,58,244,177,43,139,164,136,251,55,134,
22,231,52,218,124,122,220,43,0,37,103,140,3,80,8,194,80,135,127,255,51,59,144,252,52,45,45,184,186,25,136,32,165,239,43,84,104,64,139,5,122,169,75,80,116,245,58,62,12,225,205,40,24,154,40,191,132,78,125,
105,235,3,81,69,116,249,149,117,119,39,79,30,165,157,194,78,48,222,181,1,53,14,120,158,250,234,179,91,164,223,207,228,130,64,48,90,199,54,3,240,19,141,110,10,98,117,232,27,213,143,148,173,48,58,35,91,
104,45,86,93,167,171,183,10,156,27,84,171,30,228,164,159,208,113,104,233,85,55,109,176,0,33,77,27,223,139,58,185,2,144,114,46,39,0,128,48,12,245,224,254,27,11,130,135,34,205,179,31,116,2,21,76,107,210,
100,58,186,69,171,22,122,24,131,94,206,220,145,24,212,129,25,3,24,57,128,164,128,98,152,205,38,99,38,111,247,199,59,178,97,68,204,32,112,137,224,106,136,198,32,96,20,186,82,17,187,91,228,211,222,164,171,
123,87,110,175,133,65,120,252,64,111,86,195,232,139,147,194,135,157,110,105,157,21,128,215,77,227,33,220,127,78,88,12,50,14,6,249,101,117,212,115,34,215,22,128,180,51,216,1,0,130,97,168,131,255,255,102,
78,34,107,95,51,113,23,7,134,173,237,106,218,61,32,230,64,213,87,148,246,119,130,160,191,82,229,27,131,27,34,86,30,43,195,63,100,43,22,218,209,169,160,160,190,189,193,214,17,148,155,5,80,253,73,148,214,
12,178,207,97,153,243,127,194,255,236,45,22,80,198,115,44,247,165,79,109,102,229,181,176,218,51,5,89,85,105,94,38,87,228,203,250,97,43,199,20,196,32,182,56,191,227,220,98,147,217,251,144,236,103,134,216,
67,46,1,56,59,119,28,128,65,24,134,50,244,254,103,166,82,36,84,197,246,163,192,212,137,14,81,139,63,137,121,146,213,100,11,243,21,8,234,184,75,30,97,10,75,183,56,167,185,56,128,30,91,20,225,79,235,11,
250,91,86,247,37,128,192,210,228,154,26,191,98,14,237,189,43,169,198,16,25,192,76,228,238,75,6,116,118,250,59,96,14,114,116,47,200,216,5,22,89,208,187,29,51,213,38,49,221,77,19,34,152,245,0,30,73,4,217,
190,194,210,123,237,204,213,103,149,6,117,12,207,90,215,173,220,42,25,188,107,10,192,217,149,220,0,0,130,48,30,238,63,179,63,66,122,0,97,3,67,136,213,30,240,114,61,136,243,93,201,60,240,114,111,132,196,
49,39,192,114,14,73,10,1,16,165,114,56,35,159,73,142,230,141,221,104,218,17,199,26,145,12,10,91,97,164,193,171,165,104,119,54,222,141,51,212,206,108,95,243,89,224,216,226,120,140,209,28,205,140,15,7,213,
101,192,46,148,37,54,89,122,25,175,132,14,132,214,170,80,209,160,142,171,115,149,229,151,23,40,32,188,155,100,205,10,194,23,128,178,51,70,2,24,6,97,88,135,254,255,205,205,212,1,203,42,205,156,37,151,59,
8,70,49,247,184,149,44,138,80,172,254,180,163,22,152,161,205,8,194,126,204,213,33,95,225,67,93,204,207,0,52,192,169,54,94,2,13,82,61,55,122,132,194,82,194,53,127,233,204,239,67,64,51,162,89,18,172,127,
51,121,30,103,67,188,164,132,158,47,219,102,121,240,106,64,141,91,245,63,240,200,2,12,77,161,61,147,81,156,115,74,10,173,80,219,128,44,220,143,117,129,247,188,207,122,4,224,236,76,110,0,0,129,16,232,195,
254,107,246,207,0,174,118,96,140,123,6,135,205,172,156,72,82,246,247,107,50,201,120,45,77,140,183,226,100,66,146,71,121,184,148,36,149,232,74,74,88,194,130,236,114,36,17,74,228,181,177,43,147,108,221,
179,76,239,252,139,66,222,74,167,230,229,229,67,140,48,1,141,137,96,100,221,184,236,82,150,89,153,196,129,131,7,182,80,192,117,179,15,160,170,77,182,232,147,139,234,67,83,242,197,179,52,205,52,198,38,
86,2,187,167,35,0,99,103,140,3,80,8,131,208,197,251,159,249,155,252,133,148,7,118,55,213,193,88,40,149,30,220,62,137,213,155,222,239,148,142,156,234,140,200,101,18,171,198,71,125,117,95,46,118,212,87,
172,181,125,14,95,98,13,207,79,41,40,219,36,202,170,57,173,219,197,237,9,191,119,82,63,131,236,31,157,100,211,82,70,229,118,98,239,206,182,168,102,247,30,251,31,132,59,42,28,21,31,236,47,208,3,171,156,
174,151,86,137,0,78,136,65,238,137,255,240,134,96,153,196,69,196,26,106,147,235,217,62,153,190,220,53,159,0,164,157,193,13,192,48,8,3,121,116,255,153,251,139,42,99,46,70,29,33,40,17,196,192,249,57,68,
241,107,198,182,71,173,1,204,80,1,96,112,170,169,120,197,37,212,156,167,87,39,84,163,156,57,149,168,175,224,175,212,161,14,50,83,252,181,157,237,105,106,69,203,79,34,243,211,29,108,43,233,115,195,223,
234,85,192,125,146,239,167,173,225,97,80,133,59,208,82,54,91,169,92,174,4,120,61,87,219,225,179,63,2,176,156,180,134,145,60,243,91,205,204,203,70,245,21,128,180,243,184,1,0,132,97,32,15,246,159,153,31,
66,57,219,68,192,6,160,160,52,151,201,54,94,122,0,12,131,190,14,194,224,78,199,206,145,121,164,199,86,150,43,227,204,204,233,22,49,214,79,128,68,25,67,4,60,6,19,29,117,123,202,82,192,117,134,37,212,36,
141,236,250,15,223,22,203,77,175,132,159,243,80,136,5,38,162,11,0,105,9,63,20,104,133,42,242,121,154,40,159,203,241,220,155,166,102,78,249,142,233,100,223,43,136,5,177,2,146,16,216,0,91,94,2,112,118,198,
54,0,132,48,12,164,248,253,103,166,67,145,125,182,30,58,26,132,80,8,16,18,206,159,128,193,196,72,253,51,185,11,149,162,45,125,167,23,221,82,12,140,11,38,244,124,120,74,89,67,9,255,48,183,159,106,75,146,
110,148,91,23,113,93,8,102,199,20,116,186,193,58,40,250,214,81,31,82,128,43,19,105,223,6,253,223,183,203,111,160,228,113,242,76,172,61,89,198,246,75,103,195,124,71,232,124,36,89,156,232,165,24,228,166,
35,90,38,85,74,247,18,81,110,94,88,74,129,252,108,111,1,56,59,151,20,0,64,16,136,182,232,254,103,46,8,66,230,99,67,23,104,97,152,163,166,111,74,121,89,157,167,225,141,176,198,112,229,247,38,2,187,66,235,
48,139,116,207,57,251,46,147,249,57,57,128,0,249,146,83,43,205,231,133,106,110,48,168,155,48,185,121,35,0,17,193,92,144,188,185,222,245,200,118,233,36,30,235,232,110,33,144,59,100,117,72,151,8,57,229,
61,172,82,186,214,19,232,34,155,142,46,228,124,3,78,56,212,73,77,193,176,60,249,237,5,176,212,176,167,0,32,156,44,7,248,61,93,2,144,118,70,41,0,128,48,8,221,253,79,221,79,68,204,167,13,186,64,16,140,205,
116,230,118,245,41,50,15,75,151,154,105,27,46,230,232,244,155,71,81,109,15,5,133,50,38,144,172,136,84,76,50,13,201,16,1,236,160,255,79,203,26,11,8,21,93,85,191,158,142,244,225,3,251,103,122,231,7,194,
240,87,79,28,80,195,246,228,182,194,144,36,66,98,12,181,27,68,194,237,168,195,5,186,20,13,244,104,42,1,233,28,162,40,203,57,4,218,194,118,85,20,211,46,134,43,176,173,155,44,1,24,187,147,28,0,66,16,136,
162,44,250,254,103,118,71,58,177,120,232,5,52,193,32,50,212,255,34,115,234,241,218,173,143,15,202,164,208,222,143,189,177,107,230,9,165,84,104,173,78,147,27,197,65,32,32,55,98,204,137,242,76,247,132,68,
125,161,53,49,137,168,103,237,182,90,99,90,200,28,121,193,100,96,40,182,69,238,77,239,194,94,205,152,109,28,6,109,38,19,113,44,186,9,128,0,226,184,39,126,19,149,112,154,214,164,249,131,128,38,58,72,123,
46,80,79,143,0,156,157,49,14,128,48,12,3,59,240,255,55,119,64,138,34,159,99,181,101,5,49,64,68,168,115,181,63,89,190,214,125,101,232,106,91,25,235,53,88,163,216,198,43,201,28,22,84,228,147,234,252,19,
35,138,153,175,244,111,49,154,200,121,162,212,50,173,153,204,222,150,203,114,188,101,141,15,163,80,223,14,171,167,4,219,149,160,107,134,17,102,230,115,237,219,225,90,201,10,215,25,124,182,27,79,248,21,
174,121,86,175,183,28,4,28,200,25,57,37,191,244,93,86,100,29,178,11,46,151,50,214,77,129,168,85,81,234,154,28,116,38,218,173,174,220,2,80,118,46,57,0,132,48,8,221,204,253,207,236,206,152,194,131,206,21,
154,168,148,159,159,21,72,130,203,117,67,20,107,18,222,174,115,170,91,4,104,116,199,122,223,106,106,28,36,64,168,226,71,46,47,165,177,210,150,174,253,13,35,170,76,190,0,173,54,222,56,64,54,234,108,208,
252,44,226,219,95,37,127,233,198,241,197,163,10,96,54,49,73,103,134,44,76,22,183,210,134,88,9,249,234,230,24,58,194,203,4,231,194,232,138,172,169,132,175,202,174,53,154,253,78,239,8,192,217,181,227,0,
20,130,176,55,200,253,175,236,102,76,127,54,111,115,53,33,64,105,41,107,102,36,166,133,84,212,159,64,253,204,158,86,198,219,16,16,238,66,51,128,159,128,36,217,179,197,173,109,241,184,56,252,130,25,123,
103,97,230,202,224,221,179,241,14,182,203,235,191,121,123,103,246,216,188,27,178,173,148,0,114,239,253,4,119,0,205,26,245,49,92,115,105,180,33,129,255,115,35,73,8,185,195,35,112,150,151,70,250,165,2,66,
22,206,76,60,203,240,14,124,214,22,128,180,51,198,1,0,4,97,224,226,255,223,236,198,192,245,208,232,7,76,76,16,44,180,101,113,37,8,139,170,45,9,172,57,31,187,29,69,126,56,222,156,50,225,214,3,143,228,31,
246,255,110,252,143,163,125,154,13,78,153,233,184,68,36,102,162,99,241,180,223,83,68,248,159,40,96,142,105,155,134,60,216,123,93,34,2,179,232,164,222,214,128,113,140,132,214,20,48,214,77,180,138,103,81,
109,0,59,178,146,6,121,130,129,187,57,177,114,163,12,1,166,61,126,211,237,199,121,124,29,178,5,96,237,140,113,0,10,65,24,218,193,251,159,249,15,46,10,125,85,147,191,25,39,7,18,176,192,235,40,185,52,115,
181,8,203,219,115,181,22,0,14,253,91,180,155,97,245,197,172,163,98,89,238,201,236,37,12,47,11,88,168,217,10,70,128,94,203,124,56,170,204,9,252,162,157,3,253,203,104,141,125,246,189,170,119,175,104,60,
217,117,190,90,21,91,173,215,118,118,169,60,36,139,36,219,250,177,34,162,29,185,11,49,22,168,205,61,252,10,80,59,56,53,103,161,141,80,148,243,240,9,192,217,25,221,0,16,194,32,244,246,159,218,191,139,82,
120,181,46,160,137,169,198,2,133,99,164,87,94,95,33,180,210,84,47,11,251,172,160,69,182,216,211,90,65,36,127,35,126,6,138,139,15,162,5,222,108,82,184,180,42,22,131,145,154,171,89,206,22,146,96,168,230,
1,129,31,181,238,163,149,71,98,190,100,40,80,61,176,147,230,66,210,214,192,169,181,226,181,109,54,244,215,169,158,146,173,59,119,46,150,168,230,47,97,181,147,1,72,216,94,195,63,177,51,17,159,75,0,214,
206,24,7,0,16,132,129,14,254,255,205,58,18,218,94,212,184,58,25,13,104,75,161,211,118,80,212,225,115,80,126,215,83,104,172,161,109,42,76,242,97,72,132,135,168,53,213,72,85,62,100,101,100,22,56,212,60,
101,233,40,29,177,168,198,187,154,41,216,79,242,48,144,222,30,94,192,20,64,20,125,172,65,36,174,164,129,100,125,117,108,148,130,90,14,254,179,246,222,111,45,18,212,156,43,237,167,233,8,45,111,98,71,235,
3,235,52,194,76,212,170,163,1,35,163,189,178,4,160,236,220,109,0,8,97,24,74,113,251,207,124,29,178,98,63,3,11,32,10,148,16,255,242,69,61,89,212,57,105,179,29,187,7,163,197,170,227,168,132,171,21,31,152,
227,130,101,134,36,182,63,90,250,199,138,241,72,218,123,213,215,154,234,236,244,112,1,147,90,153,184,128,163,188,151,32,168,215,146,113,31,194,217,163,217,215,123,172,96,79,212,163,185,172,164,39,81,186,
28,193,207,59,151,149,28,71,254,60,226,31,109,213,245,80,5,147,210,206,161,106,218,155,58,190,47,175,33,119,46,211,28,34,93,61,237,23,128,179,107,89,1,0,4,97,30,250,255,111,238,16,136,184,71,214,57,8,
10,89,83,215,92,181,11,122,13,14,122,209,39,238,113,134,137,119,212,136,23,59,93,213,149,85,229,86,63,231,131,138,46,232,112,72,42,221,53,193,151,112,48,28,200,217,96,34,6,30,234,134,189,127,91,247,206,
187,54,158,124,78,178,146,212,104,52,128,83,172,205,168,98,140,18,132,38,161,84,253,138,109,66,4,26,243,192,134,254,255,95,79,138,24,129,213,251,36,234,170,180,20,66,242,72,141,3,115,169,37,212,117,195,
45,0,103,103,112,3,0,8,194,64,30,236,63,179,223,6,174,64,220,64,141,26,168,181,151,152,160,128,174,134,46,107,15,214,78,71,203,193,174,44,40,229,226,168,72,99,248,215,28,233,131,123,20,185,148,97,8,80,
238,115,69,121,58,41,151,2,18,84,21,204,180,86,61,31,89,253,107,97,245,173,228,173,133,0,14,56,51,7,180,105,49,125,205,194,94,220,40,105,250,195,18,17,192,248,32,162,34,57,250,118,81,23,212,41,168,119,
51,154,49,60,26,219,15,59,23,183,170,14,100,128,61,166,59,8,79,0,206,206,29,7,96,24,132,161,30,42,238,127,228,14,149,170,10,127,160,89,51,101,128,16,131,252,184,170,202,109,152,253,70,100,19,36,210,136,
198,87,124,51,179,57,141,92,151,69,170,253,108,180,10,127,99,54,123,141,184,33,169,45,67,14,56,174,185,44,8,146,2,44,75,19,38,200,52,214,52,238,131,166,224,1,162,115,243,42,57,203,38,252,90,199,192,137,
10,152,166,176,69,135,133,173,52,158,178,49,46,108,115,230,96,110,19,238,13,213,251,239,128,9,19,15,30,209,8,243,28,222,2,112,118,37,55,0,128,48,168,15,247,159,217,175,41,103,156,161,138,10,2,135,222,
61,134,185,113,80,45,140,21,93,102,23,189,176,164,168,142,197,247,162,226,138,46,104,69,16,170,22,221,169,77,129,102,108,20,113,71,87,187,99,209,138,89,94,125,195,207,199,185,29,95,152,198,80,216,87,137,
120,174,167,177,238,199,24,98,53,211,8,166,49,6,150,254,221,86,248,210,164,36,161,82,182,152,57,170,106,33,205,73,51,66,40,177,173,160,249,10,64,218,153,28,1,12,2,49,204,143,244,95,115,126,25,102,45,27,
146,180,192,189,96,164,107,168,53,68,25,38,108,56,196,123,165,20,93,95,14,214,82,25,75,104,247,165,171,254,20,70,36,38,154,146,135,138,7,147,54,221,165,83,80,42,10,66,37,237,208,113,165,210,254,121,213,
255,193,249,171,151,64,113,29,208,105,203,131,203,216,229,124,108,164,139,39,239,196,33,183,41,129,194,115,141,82,122,90,243,57,178,18,126,157,197,140,199,192,39,186,142,12,200,237,33,87,249,131,131,200,
104,114,11,192,217,25,172,0,0,130,48,180,67,255,255,205,157,18,217,214,76,239,18,68,32,230,244,109,103,48,6,156,14,38,74,30,95,151,135,183,101,86,102,215,65,185,71,32,245,51,214,54,60,186,223,128,77,249,
133,128,235,236,105,159,229,70,10,220,49,204,124,124,161,43,29,172,90,40,212,129,64,104,2,186,218,234,64,155,252,41,131,95,188,115,217,24,146,4,39,248,138,71,76,228,2,182,244,144,190,111,101,166,131,137,
248,117,215,201,192,228,194,20,143,178,153,93,14,35,173,111,196,43,79,220,28,1,24,59,131,27,128,97,24,4,250,145,253,103,206,207,138,194,129,189,64,251,105,104,132,241,113,116,224,236,96,128,33,111,244,
189,64,139,165,81,38,177,193,70,37,60,176,220,156,241,230,12,200,220,0,243,253,118,240,66,136,117,8,8,75,121,161,35,203,79,95,213,182,214,36,159,49,162,27,50,39,1,224,177,233,50,28,125,7,231,219,149,20,
87,188,3,212,140,111,198,13,104,244,167,81,211,251,33,189,132,211,180,111,23,193,112,243,32,189,102,35,3,218,169,121,153,37,23,60,71,106,207,111,50,29,14,150,117,5,96,236,140,113,0,128,65,16,232,255,95,
221,177,6,15,194,222,85,115,21,148,239,240,115,140,23,110,137,237,110,23,0,120,40,72,219,221,51,44,181,223,64,107,65,221,117,250,133,19,29,69,16,158,98,175,94,156,130,205,4,17,13,88,219,64,218,35,64,179,
93,59,209,13,217,123,209,67,247,201,76,33,122,24,34,36,118,124,151,195,209,128,198,53,104,98,141,185,219,237,161,19,185,207,20,190,185,161,26,142,101,176,200,69,23,192,24,18,140,123,193,49,199,19,128,
179,107,217,1,0,130,97,14,254,255,155,221,154,165,15,27,119,49,33,161,155,118,221,169,145,8,129,97,109,162,76,224,100,168,243,107,141,104,172,128,225,201,116,209,234,67,170,203,10,6,220,185,89,132,101,
170,86,132,140,131,236,74,90,153,218,10,214,78,218,163,242,163,176,55,135,244,79,183,70,91,2,24,126,4,172,192,25,211,20,172,174,68,223,100,64,235,86,199,129,112,214,108,7,167,76,250,92,157,141,50,83,170,
49,107,189,204,146,202,18,14,181,20,221,203,6,234,131,4,218,78,178,48,172,177,142,0,164,93,203,10,0,32,8,243,208,255,127,115,135,64,98,115,83,176,99,116,19,67,230,30,39,179,110,125,196,165,41,48,91,151,
168,84,31,198,111,21,241,176,4,135,224,163,1,8,71,149,36,239,243,125,185,50,28,66,250,204,69,85,144,108,58,136,112,47,25,21,61,16,46,247,221,110,124,208,77,136,93,88,245,81,43,173,85,78,16,49,51,23,219,
196,221,182,48,42,179,218,126,32,64,9,198,91,143,208,146,44,168,140,201,97,20,5,121,248,112,217,236,39,50,191,221,120,231,10,64,217,21,35,1,0,130,160,255,255,186,193,41,64,192,198,70,243,204,0,233,27,
233,5,230,176,84,152,65,52,183,169,3,89,2,61,242,44,77,203,165,127,94,147,13,160,180,105,16,111,104,195,128,146,137,169,12,71,43,91,18,216,228,90,30,39,231,99,45,240,250,194,18,171,55,68,90,52,144,40,
145,26,15,173,249,129,223,43,235,193,168,138,252,150,79,130,35,236,230,54,107,172,49,224,89,33,175,195,237,67,122,25,73,3,52,156,122,52,22,29,63,1,56,59,119,28,0,66,16,136,82,120,255,51,111,103,144,153,
7,186,165,149,49,209,128,243,99,217,178,54,166,56,111,183,80,64,84,176,182,247,58,80,61,43,147,45,5,93,72,254,172,150,143,83,171,111,255,216,86,188,64,182,156,177,184,5,251,201,40,174,167,52,171,249,32,
205,43,29,137,198,167,123,223,207,65,26,151,151,9,34,63,82,250,85,72,102,65,1,219,184,82,28,251,77,85,108,36,170,10,244,20,166,57,64,51,155,49,227,112,137,131,4,27,55,189,146,250,68,201,42,66,36,63,129,
41,123,139,79,0,230,206,29,5,0,16,134,161,29,188,255,153,29,10,82,242,169,117,211,201,77,65,68,147,198,231,106,200,121,206,14,96,83,138,55,85,149,103,57,215,84,22,210,132,31,102,200,171,234,6,187,225,
137,42,39,35,140,87,166,56,56,183,147,19,47,76,206,79,102,48,195,160,65,160,190,53,25,244,171,38,151,102,66,76,149,160,238,48,113,61,169,162,83,232,193,23,15,236,58,51,66,6,100,151,252,103,69,190,245,
0,123,184,183,229,161,248,237,64,230,205,229,223,21,80,122,21,121,58,91,0,222,206,24,11,0,16,4,161,222,255,212,13,53,248,80,126,185,180,181,57,85,10,2,7,237,175,79,75,110,179,221,94,29,111,131,49,199,
14,195,109,107,197,9,208,113,171,129,23,25,179,52,11,251,0,41,75,188,161,20,19,35,10,199,6,183,174,117,181,180,240,127,215,9,235,243,101,158,54,222,47,206,156,140,56,140,74,131,51,165,67,4,3,69,159,249,
174,10,177,45,233,61,206,21,54,186,68,236,170,112,145,15,134,211,174,156,25,185,128,232,50,221,47,1,40,59,131,27,128,65,24,6,230,209,253,103,230,129,84,161,248,108,194,2,32,74,11,53,38,231,79,177,65,120,
158,95,134,91,62,84,191,142,139,140,33,109,117,187,68,93,99,148,245,127,126,219,58,197,251,85,78,38,101,211,91,137,128,37,89,29,90,182,164,76,37,116,170,157,138,115,33,75,57,131,248,181,200,215,85,55,
230,31,180,57,11,96,207,206,233,191,168,90,196,52,14,28,166,139,111,70,163,123,242,118,225,39,125,213,74,205,23,119,143,5,87,183,70,112,58,55,54,180,21,50,159,51,56,223,187,229,37,0,101,103,112,3,0,8,
194,64,30,238,63,179,190,140,161,244,64,55,208,104,98,161,92,151,234,88,184,151,154,87,235,236,253,48,75,228,8,63,101,109,60,177,144,157,161,40,49,97,239,59,124,75,238,144,112,48,148,57,110,188,84,155,
148,74,161,113,62,8,48,53,65,43,4,212,108,59,141,255,133,247,13,15,62,154,240,66,24,43,170,121,155,12,116,230,18,131,107,209,195,183,130,183,207,233,137,109,8,237,60,162,210,237,180,100,225,68,53,179,
168,186,59,169,75,61,147,179,182,0,164,157,49,14,192,32,12,3,25,248,255,135,179,116,168,20,149,96,31,65,221,216,145,136,147,152,243,76,11,218,49,141,107,24,115,149,123,201,128,192,207,142,40,25,198,176,
95,216,123,136,8,87,7,118,62,20,131,6,74,98,119,115,216,206,48,214,35,191,201,25,108,82,243,59,108,235,31,249,221,153,231,245,199,10,87,130,2,204,231,37,33,71,238,89,29,27,71,246,104,223,212,29,206,222,
234,211,181,185,66,20,16,158,219,155,20,226,19,164,12,141,213,240,47,139,144,20,104,208,210,230,39,229,71,0,206,206,29,7,0,16,132,161,12,222,255,204,14,38,134,216,87,32,174,78,26,81,62,45,101,185,242,
18,142,70,127,220,148,34,34,46,113,117,241,115,78,209,29,217,75,69,90,115,95,253,57,228,220,254,16,101,9,146,232,112,188,221,32,206,22,134,18,245,151,81,128,157,58,219,123,14,233,181,117,199,161,35,109,
227,225,191,175,71,133,15,241,41,58,52,17,231,91,61,131,91,208,157,230,107,69,26,8,26,9,110,236,18,129,21,76,113,90,201,154,141,22,148,121,108,27,83,157,184,32,78,17,38,164,110,101,11,192,217,181,172,
0,0,194,160,29,250,255,111,46,8,34,230,35,233,210,125,193,134,76,167,163,152,66,72,17,69,20,39,63,227,220,104,217,173,224,253,155,244,234,22,1,243,77,251,37,89,168,222,46,146,90,238,249,147,44,69,65,171,
236,244,86,194,45,221,45,48,50,65,198,43,108,182,164,51,191,25,196,68,151,17,130,136,243,237,138,237,71,74,31,199,7,6,99,208,189,111,131,238,72,197,209,37,57,221,173,80,237,153,241,65,86,46,227,165,19,
56,188,19,1,78,34,3,1,158,43,152,245,78,1,56,59,99,36,0,66,16,6,82,220,255,31,76,117,173,195,146,76,180,183,194,81,32,36,228,235,238,80,82,58,8,97,12,253,186,204,140,235,199,149,244,122,60,152,193,229,
228,228,92,165,89,214,201,148,226,16,104,29,36,130,83,233,236,147,182,170,104,214,117,230,5,111,111,31,246,178,142,61,21,155,231,94,65,241,207,228,25,213,93,231,116,148,100,162,65,83,109,26,189,172,14,
8,202,162,39,100,212,169,27,103,177,237,17,25,3,194,25,196,206,48,11,125,111,53,126,186,243,252,47,0,101,103,140,3,0,8,131,64,7,255,255,102,55,67,4,78,93,29,220,170,64,75,153,110,108,142,169,21,87,96,
163,132,205,227,16,116,20,183,249,19,119,89,70,6,24,55,142,12,89,170,5,119,250,152,64,147,208,14,3,79,76,80,131,122,115,95,103,139,27,209,201,40,168,25,8,219,251,173,216,23,2,15,39,176,103,254,171,47,
232,125,242,246,180,113,152,154,210,215,134,155,98,159,143,199,150,35,141,133,204,133,38,163,70,80,195,65,93,215,63,56,10,19,176,203,56,42,202,10,22,150,0,164,156,49,14,0,32,8,3,25,252,255,155,29,76,12,
41,109,193,56,59,26,42,212,114,203,7,221,232,136,174,28,20,83,24,199,86,52,177,153,43,222,170,147,1,85,130,109,71,72,215,83,45,207,64,69,163,160,10,103,76,121,196,144,232,174,23,6,12,95,152,228,115,204,
193,44,50,135,166,42,180,200,211,182,230,255,87,128,158,100,136,114,19,38,115,4,77,173,133,198,61,154,15,157,218,177,43,39,120,18,60,87,172,46,149,52,5,52,30,28,13,125,19,15,237,54,18,147,223,212,45,0,
103,87,146,3,0,4,196,252,255,213,14,68,154,233,50,120,129,68,194,148,110,187,171,47,119,122,5,245,75,17,240,186,66,53,188,35,207,121,96,208,129,250,121,71,218,183,124,149,171,97,231,105,227,154,88,217,
179,132,174,175,0,32,131,119,69,202,34,248,181,223,114,111,89,55,154,227,34,254,4,60,79,134,191,113,157,228,149,43,183,157,0,22,81,131,203,92,185,71,37,37,118,157,187,234,228,38,200,103,32,127,9,201,176,
150,16,209,19,40,243,66,142,226,100,146,152,183,173,18,89,107,77,1,40,187,98,36,0,64,16,196,208,255,63,236,210,234,41,34,254,160,178,227,48,3,94,68,192,75,104,45,102,160,215,219,83,150,78,211,178,181,
35,0,117,242,155,112,58,15,144,215,209,139,96,86,104,121,236,147,242,183,119,89,148,121,102,95,42,125,224,215,254,115,5,5,71,67,10,25,211,230,192,193,105,95,221,42,18,118,22,40,165,132,244,169,216,212,
23,78,77,138,0,148,92,235,46,244,40,21,199,229,171,21,54,43,135,124,98,61,41,152,114,141,194,182,190,0,156,157,193,13,0,32,8,3,121,184,255,204,126,129,150,195,232,2,26,131,6,11,246,142,13,104,174,156,
67,226,1,180,176,168,189,244,90,195,0,251,237,188,146,166,246,217,51,60,41,249,54,83,178,60,89,0,138,194,21,208,196,133,233,35,99,158,2,250,160,20,7,252,81,201,143,205,111,147,129,188,204,144,249,24,150,
131,98,105,232,49,51,237,172,227,187,170,235,47,24,136,149,147,19,21,172,220,210,251,108,212,219,126,181,216,231,55,123,7,170,30,164,151,242,68,49,179,123,203,241,115,5,224,236,92,110,0,0,65,24,202,193,
253,103,246,74,232,107,53,184,130,49,197,210,207,113,66,148,1,209,14,153,245,206,156,57,185,76,100,74,191,179,49,116,97,243,175,3,37,151,253,28,12,127,89,12,231,138,12,48,239,240,103,203,152,137,198,50,
209,17,59,98,239,249,242,17,78,115,196,232,238,104,119,107,145,228,30,243,51,112,209,141,101,126,106,215,233,67,34,186,241,243,207,92,163,239,209,171,211,25,71,204,167,127,150,106,235,194,162,196,26,164,
163,74,87,10,252,240,59,200,223,95,1,72,59,99,28,0,64,16,6,254,255,215,198,197,16,184,22,130,155,171,209,80,40,165,220,193,158,185,86,116,232,123,223,26,140,25,194,15,191,102,140,68,200,20,120,199,107,
188,145,106,156,98,174,56,28,227,81,207,108,150,171,155,233,233,157,55,246,90,11,176,48,252,252,225,17,234,58,51,92,155,157,220,123,159,154,219,23,152,190,61,134,41,61,146,133,21,81,90,247,247,132,106,
74,107,84,17,49,133,42,108,78,69,176,81,218,92,95,3,198,243,17,128,180,115,185,1,0,132,65,232,197,253,103,246,214,152,242,192,223,0,30,140,105,85,40,48,50,76,133,58,231,86,180,213,243,182,100,91,214,135,
96,30,131,243,54,196,203,19,45,113,179,153,113,152,139,8,12,159,123,68,184,114,109,51,11,25,101,112,217,207,255,100,222,131,200,231,4,48,187,234,80,14,126,215,80,35,205,62,70,160,20,19,172,234,153,173,
71,140,243,105,250,155,83,139,209,64,205,174,178,185,182,35,164,210,176,197,92,153,53,170,177,141,139,21,211,158,85,171,166,0,172,157,81,10,192,32,12,67,253,216,253,207,236,199,96,132,188,180,42,243,0,
115,104,33,52,181,125,62,113,108,168,199,152,235,225,190,59,100,141,180,162,47,196,86,135,202,242,69,61,230,220,117,37,192,180,115,140,162,218,111,91,45,230,135,167,247,219,61,129,111,9,50,57,74,185,119,
72,100,127,140,250,149,175,180,53,219,56,133,177,4,160,121,19,183,96,247,172,28,57,167,238,47,121,65,84,183,216,74,28,227,56,132,239,248,245,158,239,252,203,224,133,166,41,12,37,193,190,177,150,105,143,
217,154,149,152,2,176,118,5,57,0,128,32,168,67,255,127,115,183,102,32,168,91,63,112,171,97,161,192,46,173,251,58,10,45,238,99,37,203,10,184,168,40,198,245,230,147,43,145,143,41,9,154,131,81,113,131,35,
34,59,61,168,13,136,148,131,137,240,7,166,212,233,255,37,194,238,29,198,194,241,79,103,108,62,78,247,75,230,79,147,172,238,107,99,96,81,127,228,86,162,34,100,56,226,42,62,13,22,101,85,152,84,101,53,155,
224,26,212,173,78,153,127,229,70,169,160,13,238,158,241,234,50,6,249,71,0,206,206,32,7,96,16,4,130,61,248,255,55,247,64,66,8,204,46,182,87,15,198,104,16,36,235,206,193,34,103,54,93,48,222,176,17,82,175,
37,243,223,160,249,153,77,157,70,6,140,106,185,225,217,32,206,189,133,186,201,72,129,145,188,81,155,248,29,127,8,221,149,228,134,88,94,186,39,162,177,132,135,11,255,75,188,74,37,233,111,144,79,245,194,
58,167,255,22,173,60,29,240,225,141,209,98,0,74,138,249,59,151,93,95,31,168,58,51,62,238,19,194,181,158,5,154,56,215,2,118,69,134,41,90,145,210,20,199,248,43,0,103,103,148,3,0,8,130,208,238,127,234,126,
155,242,16,59,64,91,31,97,162,12,68,92,215,88,182,189,163,192,219,194,201,229,217,152,85,46,41,147,161,6,249,116,157,68,10,178,184,22,118,227,49,230,73,19,61,83,35,118,216,186,238,229,176,255,195,240,
214,8,36,231,14,221,18,183,52,122,62,135,211,124,143,225,37,41,171,231,128,218,93,142,223,40,148,137,186,155,176,249,162,21,120,225,74,116,246,213,155,119,192,94,1,72,59,131,27,0,64,24,4,126,220,127,102,
227,207,32,135,65,119,168,166,4,202,13,1,9,219,222,168,28,167,123,155,140,80,242,27,200,228,54,198,32,140,176,92,108,118,197,111,10,95,101,73,163,141,107,66,184,24,242,8,172,145,30,32,147,150,44,210,26,
248,85,4,171,149,235,159,159,11,181,197,237,154,72,90,107,78,18,28,209,31,229,208,51,24,43,217,144,162,105,145,123,48,155,254,182,239,86,252,66,90,64,168,141,167,21,92,180,79,201,63,59,5,96,237,140,113,
0,0,65,24,232,224,255,223,236,102,8,244,176,33,206,234,160,49,161,148,82,118,45,44,63,229,147,102,26,38,197,179,18,26,52,85,125,114,47,163,224,185,192,125,152,106,185,178,21,223,180,172,37,249,132,20,
2,209,29,35,41,208,243,225,206,131,15,150,190,108,243,83,131,8,191,229,248,70,98,142,73,198,39,63,134,12,206,18,154,197,6,13,95,231,154,128,67,181,232,72,228,197,108,32,85,21,231,53,246,173,126,31,231,
61,117,4,224,236,220,82,0,6,129,24,184,31,189,255,153,91,40,20,73,38,177,237,5,68,97,209,125,36,227,33,252,105,239,108,111,21,96,197,17,189,205,183,95,54,111,18,129,3,127,242,195,33,48,58,49,82,180,57,
28,66,130,105,229,195,248,219,238,162,78,236,105,173,139,223,66,49,132,127,245,219,173,92,202,197,172,145,106,168,242,67,233,84,112,240,215,233,224,117,94,4,84,118,217,207,100,148,101,17,207,99,172,74,
6,46,115,101,228,68,76,118,221,186,185,240,119,149,228,58,92,87,181,99,227,166,100,58,207,246,228,20,167,0,148,157,49,14,192,32,12,3,25,250,255,55,119,96,65,57,251,74,119,36,36,20,25,97,39,199,67,198,
120,60,62,7,18,137,103,35,160,18,146,219,168,217,220,69,16,197,171,227,86,89,55,159,100,117,178,125,22,104,16,228,165,141,2,138,6,36,81,168,103,241,53,245,241,110,191,230,117,93,62,1,252,106,250,43,220,
247,113,163,143,114,70,225,16,18,81,3,221,55,127,206,253,48,255,93,254,204,41,219,120,242,104,48,141,210,28,123,195,153,2,250,17,141,17,131,145,164,210,215,219,139,95,1,56,59,115,28,0,66,24,6,54,252,255,
205,116,209,10,143,71,209,82,209,208,68,57,145,237,156,37,73,35,69,130,145,138,148,127,129,40,185,57,86,19,45,180,204,17,168,35,44,69,30,237,229,219,212,30,153,52,196,153,201,206,227,231,180,89,183,197,
21,54,168,13,197,185,108,242,151,28,59,47,230,255,198,1,231,237,101,134,21,80,83,162,89,113,110,207,120,155,70,3,221,64,248,236,56,62,52,241,226,246,176,45,231,20,224,108,227,143,44,125,233,219,91,53,
22,192,220,175,0,164,157,89,14,0,33,8,67,189,255,169,157,196,68,77,151,231,199,156,192,13,17,105,41,71,183,31,20,59,156,44,237,127,215,120,222,64,161,139,89,141,216,44,193,241,112,87,98,147,73,50,85,65,
246,194,153,54,177,70,170,169,41,200,18,62,47,219,2,126,78,161,11,168,121,51,70,184,204,131,177,0,14,1,158,183,250,15,214,232,54,215,148,72,182,171,221,74,56,98,45,11,37,133,254,46,242,14,143,212,18,58,
150,21,136,109,136,196,253,120,105,213,193,62,251,187,210,88,176,16,201,187,233,70,191,211,132,94,60,151,124,143,62,5,224,236,12,82,0,8,97,24,232,97,255,255,225,94,188,45,165,201,68,244,3,130,162,213,
134,56,249,70,210,94,248,113,73,72,15,27,56,115,148,175,40,15,171,15,162,22,23,171,246,235,234,216,202,29,180,147,208,235,134,45,107,85,101,10,141,182,175,199,62,223,170,26,4,145,117,226,26,95,29,75,34,
112,231,2,65,226,249,91,231,79,92,230,223,166,62,74,33,245,32,193,243,23,48,237,26,167,49,20,34,130,205,118,90,20,97,179,116,155,81,34,131,125,150,142,198,132,174,76,245,227,244,133,202,30,243,37,84,159,
45,0,101,87,114,3,0,8,131,124,184,255,204,254,26,194,149,58,3,90,161,66,123,75,4,34,13,30,63,97,172,202,128,161,123,50,10,113,234,175,116,218,139,216,91,122,221,179,104,215,155,105,67,69,1,176,90,253,
200,20,122,18,177,27,95,48,230,35,232,254,47,169,184,149,181,93,240,171,157,38,153,255,55,109,160,95,18,177,47,22,74,191,113,42,28,125,9,17,115,214,144,207,28,15,69,220,218,132,58,109,76,65,210,82,70,
83,59,51,233,47,155,239,78,128,90,20,144,138,226,209,122,2,112,118,238,88,0,130,64,12,220,194,251,159,217,206,135,201,36,40,61,221,2,251,9,67,174,181,76,197,93,142,19,245,179,10,16,137,8,23,246,139,75,
169,235,249,120,89,164,17,142,156,144,21,168,74,233,186,48,97,243,182,0,74,190,90,242,64,29,125,227,18,248,245,189,86,199,22,169,144,60,219,179,90,126,64,57,214,249,38,80,88,147,25,109,9,40,102,123,228,
243,189,171,23,94,160,111,96,188,119,126,169,84,197,88,105,235,155,44,58,52,142,186,61,226,110,132,139,78,144,207,202,91,0,210,206,32,5,96,16,136,129,30,250,255,55,247,38,75,102,76,133,158,61,40,8,186,
102,99,230,9,7,203,92,214,246,255,132,103,104,213,80,68,189,55,84,77,81,100,0,219,164,197,96,199,161,104,152,199,241,223,73,6,138,205,163,16,165,74,33,37,37,126,97,208,134,223,222,140,153,17,86,220,144,
189,246,46,48,207,75,2,218,201,199,253,51,48,75,75,229,130,223,101,215,141,161,76,219,50,48,141,210,203,190,81,51,111,231,164,119,126,90,182,227,65,90,34,122,184,212,123,228,113,212,146,250,118,8,6,169,
22,17,228,11,207,25,95,1,56,59,99,20,0,64,24,6,58,248,255,55,59,8,34,77,114,69,71,69,112,211,54,189,166,179,5,200,84,51,176,154,68,194,129,216,141,52,21,180,19,92,172,70,128,128,58,91,19,53,128,34,213,
219,211,210,132,133,201,177,253,142,108,234,88,38,85,105,18,248,205,210,181,221,217,140,6,164,192,199,114,175,31,225,0,48,99,96,77,81,244,188,164,68,190,222,216,190,83,112,236,24,248,232,127,107,135,103,
142,48,69,7,66,128,84,22,189,151,39,213,183,109,181,144,122,239,205,37,0,105,215,150,3,0,8,130,186,255,169,251,233,131,201,67,182,46,208,86,203,18,17,124,6,158,92,75,116,77,14,43,127,208,168,71,100,167,
80,121,40,35,138,240,54,52,45,22,188,17,7,104,157,98,31,65,163,100,161,131,113,210,58,166,66,2,206,254,199,40,243,237,188,126,182,30,253,49,2,200,51,17,3,208,96,17,36,150,87,93,162,206,156,255,1,205,24,
151,3,74,243,172,241,253,72,98,75,190,71,60,23,115,136,118,28,80,231,144,14,128,2,221,62,78,148,135,95,1,72,59,99,28,0,64,24,4,58,248,255,55,187,25,34,61,218,68,103,55,77,165,20,97,223,136,30,218,49,116,
107,105,205,106,189,40,184,154,173,196,186,196,126,5,52,171,210,128,86,198,83,150,109,250,179,113,15,38,91,134,145,51,34,221,111,53,126,35,37,194,255,154,123,120,124,230,112,231,199,223,3,246,8,238,181,
156,171,186,164,148,67,245,5,209,119,33,16,85,249,136,71,169,21,218,177,57,56,114,157,178,135,214,249,176,67,73,165,48,74,40,121,119,138,6,61,2,144,118,230,54,0,128,48,12,108,216,127,102,90,43,23,142,
111,1,138,8,144,227,196,246,200,198,94,228,241,146,178,232,179,74,105,245,87,198,195,62,77,117,135,243,212,249,20,25,70,27,31,148,192,91,228,12,133,65,40,23,119,171,87,59,223,168,105,125,236,158,159,223,
97,123,41,32,252,231,167,240,105,142,236,213,48,212,124,229,164,192,10,95,209,120,100,184,72,39,37,184,96,178,59,187,87,191,57,180,226,166,229,70,218,129,56,30,108,205,17,189,116,121,200,20,128,180,115,
185,1,0,4,97,232,197,253,103,246,102,8,165,175,81,71,48,65,160,159,148,21,119,57,54,36,69,194,185,246,69,77,41,25,21,245,113,234,42,154,85,245,130,175,6,84,23,109,205,204,112,214,11,64,92,99,152,167,107,
231,87,203,84,188,181,248,51,141,129,11,128,73,18,191,113,212,107,157,48,193,89,76,14,3,115,186,25,240,20,250,186,227,123,29,125,83,111,10,37,88,131,129,140,208,67,117,45,250,205,213,164,238,191,16,24,
217,160,238,22,128,178,51,198,2,24,132,65,168,67,239,127,230,14,46,45,31,48,238,125,190,186,68,18,8,60,195,23,204,202,78,56,23,216,98,44,158,86,204,15,68,221,157,40,55,182,232,197,77,56,13,111,45,206,
76,11,63,114,107,161,133,9,233,201,30,89,193,188,112,81,157,224,61,210,126,107,150,129,81,166,101,183,137,61,243,143,237,15,51,209,116,136,29,146,165,186,237,240,215,223,226,61,1,7,49,89,103,189,96,104,
53,105,38,219,99,30,139,200,213,122,95,103,100,41,111,41,101,241,187,66,242,10,32,80,159,31,255,37,161,68,110,171,134,247,105,49,143,100,96,192,118,77,45,154,155,224,171,140,145,15,66,199,149,56,112,117,
212,209,166,33,177,22,231,184,234,34,60,231,130,34,79,53,227,186,68,24,243,170,66,82,231,189,201,206,129,4,7,71,9,86,212,84,201,255,196,155,143,54,99,130,117,92,26,255,89,175,196,143,119,226,25,247,193,
51,32,7,87,137,57,166,128,220,106,192,90,195,227,185,96,18,215,164,0,158,165,171,184,246,17,18,172,164,49,189,143,124,162,20,68,4,32,0,107,231,130,2,48,8,195,80,239,127,106,25,130,148,228,165,43,108,30,
192,15,22,162,77,218,60,217,126,84,68,8,177,95,151,20,118,209,233,0,55,234,88,102,155,151,118,44,171,92,67,238,149,11,63,17,28,208,53,216,245,136,19,66,14,101,11,24,91,146,237,123,149,232,160,24,9,219,
215,124,236,183,55,39,180,154,138,201,191,6,182,75,117,84,72,168,43,243,8,240,34,31,158,146,136,120,227,85,201,91,63,17,201,42,174,105,190,46,17,91,195,216,93,228,92,164,136,17,43,80,212,84,34,53,207,
195,115,156,45,0,103,87,142,3,0,8,194,24,252,255,123,25,29,76,12,161,71,208,23,104,140,220,45,93,153,25,22,37,98,8,21,241,37,204,70,37,40,135,195,185,214,48,175,110,72,209,132,148,247,85,129,26,247,70,
224,85,41,126,25,159,254,66,214,141,192,187,201,20,104,5,20,47,64,90,53,16,153,216,179,1,135,124,164,9,106,71,11,109,242,55,9,170,102,219,84,175,141,50,53,144,205,129,99,35,12,218,119,33,117,21,23,192,
223,251,196,174,167,248,69,90,135,211,69,131,38,230,157,166,96,77,198,253,83,215,19,183,0,156,157,193,13,0,32,8,3,221,127,106,63,106,8,28,5,156,193,32,210,150,243,116,126,108,68,217,103,146,214,41,45,
213,169,120,30,157,127,160,49,63,15,4,194,59,44,44,66,23,148,80,151,76,119,212,114,128,110,161,46,106,170,5,42,43,61,198,241,68,131,159,75,97,79,15,138,83,163,110,132,9,250,75,4,227,10,26,222,227,207,
246,119,96,133,104,178,218,2,112,47,214,69,123,232,89,160,187,179,160,129,149,223,39,47,11,148,142,88,94,138,76,110,36,118,97,82,96,11,192,218,25,227,0,0,130,48,144,193,255,191,89,39,99,202,81,49,113,
115,38,49,34,189,210,129,75,227,240,54,250,133,231,215,233,171,168,50,21,182,97,70,68,89,215,193,23,120,127,105,124,2,111,118,122,127,233,102,43,15,105,36,184,80,42,32,180,82,60,198,117,245,239,219,117,
207,135,137,102,238,12,23,154,133,234,236,53,88,7,9,146,21,218,218,155,100,81,184,69,97,168,194,219,42,147,155,17,252,209,71,140,45,3,166,18,27,146,61,18,98,20,22,81,67,30,247,108,39,167,0,164,157,219,
13,192,32,12,3,217,127,106,62,90,85,81,238,140,130,186,0,72,188,98,3,182,95,97,143,158,190,169,38,107,208,53,127,77,53,40,69,180,243,93,153,232,253,167,102,30,183,193,165,227,141,90,9,215,13,198,55,91,
166,178,41,234,57,219,173,43,39,76,37,72,107,81,85,170,253,167,247,19,45,224,36,201,119,190,177,111,143,0,245,41,32,161,229,12,46,75,58,63,184,238,240,243,79,146,96,213,30,19,134,111,16,189,41,8,18,87,
74,26,237,133,252,79,46,131,164,110,38,124,83,50,171,19,250,180,182,5,160,236,92,142,0,8,65,24,106,255,85,239,141,201,202,75,132,6,56,200,32,34,249,252,136,61,61,37,186,151,114,188,218,213,64,136,28,126,
69,191,5,107,205,64,192,68,171,198,58,71,45,176,227,1,188,154,131,76,31,174,55,39,42,37,101,189,48,212,243,90,193,120,243,122,121,85,168,79,175,36,55,247,185,221,213,80,107,160,223,248,151,143,3,118,154,
185,36,14,14,219,65,117,170,55,0,135,224,196,224,218,150,149,157,229,60,252,66,87,119,200,113,252,20,239,194,89,19,21,182,138,246,9,64,218,185,220,0,16,2,33,244,98,255,53,123,243,0,15,38,106,3,38,198,
117,130,44,159,117,110,72,18,207,97,59,154,71,229,185,68,39,245,162,141,160,177,235,76,176,74,197,77,96,40,13,26,35,73,113,203,24,180,32,223,122,170,9,73,213,189,197,62,132,60,211,15,217,118,53,154,11,
53,133,216,242,25,35,140,77,155,72,125,251,196,151,67,233,139,23,213,182,184,173,202,179,60,57,220,113,94,72,89,240,248,239,169,67,185,148,136,209,153,227,68,198,109,1,72,59,151,20,0,129,24,134,102,33,
189,255,145,93,8,162,54,47,29,245,2,179,41,12,77,154,207,86,85,97,157,200,228,4,249,177,198,112,88,98,200,44,232,160,113,134,90,1,219,20,36,8,246,29,143,142,15,100,222,139,217,236,87,101,197,136,225,42,
161,166,5,58,30,255,185,141,139,3,158,63,104,7,95,153,249,236,119,223,165,245,132,55,9,147,143,183,216,92,200,187,146,165,213,215,82,221,125,178,99,144,241,117,118,129,21,210,66,229,20,49,104,98,67,65,
118,145,159,83,216,5,160,236,220,113,0,0,65,24,234,224,253,207,236,102,8,175,173,184,58,26,33,72,127,251,78,194,76,38,186,76,99,154,73,146,220,94,255,177,196,63,92,22,50,7,36,178,208,184,9,11,47,178,162,
107,129,245,49,33,138,78,162,157,194,148,36,105,8,193,162,135,157,52,8,123,190,32,192,103,55,207,152,255,112,101,205,203,148,45,56,167,107,183,98,115,46,58,65,55,233,128,3,30,82,6,35,55,86,13,78,150,234,
189,42,48,119,147,69,48,173,92,158,217,201,246,209,56,50,46,192,174,149,143,180,0,62,2,112,118,230,72,0,195,32,12,164,240,255,31,76,149,148,12,104,101,146,214,37,54,195,161,195,39,51,131,109,176,43,224,
185,223,24,183,112,19,119,32,148,192,118,214,207,230,207,65,224,156,236,42,137,146,236,105,8,1,78,59,134,152,32,217,190,114,26,164,30,123,6,205,164,220,114,243,255,163,206,203,156,249,244,1,22,9,93,67,
89,107,215,73,71,214,140,90,87,166,16,96,41,202,184,178,21,38,136,208,110,170,249,115,19,178,232,223,57,57,133,80,203,41,55,154,178,159,34,69,163,161,18,189,231,143,0,148,157,49,14,64,33,12,66,59,120,
255,51,187,153,230,1,85,151,31,183,159,24,212,134,2,93,131,175,203,178,89,201,90,80,34,230,135,33,57,41,106,236,169,131,219,79,185,144,190,72,122,126,219,204,239,47,76,255,218,127,105,196,152,13,255,172,
48,49,62,181,33,108,49,127,60,152,131,184,224,125,86,210,75,27,255,151,29,156,21,248,195,24,5,244,95,20,175,54,200,4,200,70,177,109,213,168,233,17,2,137,107,157,249,184,217,19,0,146,170,7,76,185,98,242,
154,182,172,192,67,161,157,74,155,186,69,167,156,29,198,30,110,1,88,59,99,28,0,64,16,6,50,248,255,55,59,152,16,66,143,234,224,23,52,72,161,181,93,230,179,100,181,61,55,88,122,122,141,244,188,144,171,15,
242,54,172,195,200,20,248,217,152,194,172,243,44,102,21,117,52,10,240,252,35,72,190,163,13,105,122,1,147,132,27,99,197,174,112,52,230,84,159,23,116,237,235,243,75,198,198,47,237,131,65,37,42,245,197,190,
167,253,89,75,203,187,229,250,165,9,98,117,92,45,155,252,136,198,88,225,123,129,166,169,73,49,86,136,161,10,55,116,233,70,55,90,101,157,80,25,185,5,224,236,92,110,0,6,97,24,234,3,251,207,220,27,162,241,
139,73,187,1,32,36,240,47,94,25,73,226,103,76,212,103,20,20,157,31,254,80,244,207,163,225,207,143,120,215,21,148,14,82,189,199,120,118,72,12,131,9,162,46,48,71,92,120,213,16,37,106,80,91,188,183,51,33,
111,59,173,126,98,197,249,228,231,159,203,16,87,108,18,52,215,174,72,42,68,30,2,183,26,84,58,252,195,59,15,127,174,167,16,94,158,88,195,10,6,221,38,101,157,211,1,59,77,212,31,167,16,147,41,92,155,187,
114,31,1,40,59,131,28,0,66,16,6,122,240,255,111,214,35,113,218,130,55,143,27,179,145,6,58,116,75,246,78,42,243,42,197,135,9,4,180,28,229,82,32,7,146,57,140,197,77,113,156,178,10,112,30,93,37,220,6,237,
126,226,122,117,178,69,188,96,189,172,101,95,194,84,15,173,57,108,58,206,91,122,147,153,252,111,92,111,251,85,50,214,133,47,84,139,253,56,117,221,206,92,36,202,33,215,227,200,90,26,148,2,31,41,238,240,
160,185,131,29,80,162,116,15,78,82,205,252,203,195,41,57,120,254,30,142,0,164,157,49,14,0,32,8,3,25,248,255,155,93,28,72,75,1,229,1,78,38,166,180,229,244,194,10,6,96,56,215,102,97,132,80,16,53,149,115,
212,27,136,45,159,19,86,175,148,83,0,189,43,118,149,141,190,199,171,97,62,166,23,248,111,124,234,174,238,32,157,252,149,92,143,51,234,107,135,255,59,246,223,100,138,195,240,44,34,122,185,163,210,70,12,
224,140,20,173,144,73,241,73,189,209,41,147,122,136,87,216,240,63,82,57,6,45,6,70,69,243,169,84,34,129,92,58,2,112,118,198,72,0,128,32,12,115,240,255,111,214,209,163,105,69,103,103,42,71,67,153,195,164,
244,151,16,101,60,44,141,20,180,27,72,224,103,149,105,220,112,255,4,89,131,64,4,23,42,115,215,231,245,156,43,234,151,42,11,138,116,121,82,135,79,3,255,178,101,152,75,177,57,53,232,244,11,46,246,251,67,
98,174,121,193,110,222,30,8,28,132,216,112,88,219,73,10,62,169,115,60,233,137,16,177,58,98,69,178,95,87,93,157,5,174,93,143,182,244,186,210,167,70,131,11,5,88,2,12,0,52,103,80,26,178,200,170,15,0,0,0,
0,73,69,78,68,174,66,96,130,0,0};

const char* KlangFalterEditor::brushed_aluminium_png = (const char*) resource_KlangFalterEditor_brushed_aluminium_png;
const int KlangFalterEditor::brushed_aluminium_pngSize = 14724;
