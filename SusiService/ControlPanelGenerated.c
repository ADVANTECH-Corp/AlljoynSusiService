/******************************************************************************
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

/**
 * Per-module definition of the current module for debug logging.  Must be defined
 * prior to first inclusion of aj_debug.h.
 * The corresponding flag dbgAJSVCAPP is defined in the containing sample app.
 */
#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>

#include <alljoyn.h>
#include <alljoyn/controlpanel/Common/ConstraintList.h>
#include <alljoyn/controlpanel/ControlPanelService.h>
#include "ControlPanelProvided.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

const char SUSIAccessControlPanelObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel";
const char enSUSIAccessControlPanelObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en";
const char enSUSIAccessBoardInfoContainerObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/BoardInfoContainer";
const char enSUSIAccessBoardManufacturerStringPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/BoardInfoContainer/BoardManufacturerStringProperty";
const char enSUSIAccessBoardNameStringPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/BoardInfoContainer/BoardNameStringProperty";
const char enSUSIAccessVersionContainerObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/VersionContainer";
const char enSUSIAccessDriverVersionPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/VersionContainer/DriverVersionProperty";
const char enSUSIAccessLibraryVersionPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/VersionContainer/LibraryVersionProperty";
const char enSUSIAccessTemperatureContainerObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/TemperatureContainer";
const char enSUSIAccessTemperaturePropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/TemperatureContainer/TemperatureProperty";
const char enSUSIAccessSubscriptionPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/TemperatureContainer/SubscriptionProperty";
const char enSUSIAccessDisplayContainerObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/DisplayContainer";
const char enSUSIAccessDisplayDevicePropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/DisplayContainer/DisplayDeviceProperty";
const char enSUSIAccessBrightnessPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/DisplayContainer/BrightnessProperty";
const char enSUSIAccessBacklightPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/DisplayContainer/BacklightProperty";
const char enSUSIAccessGPIOContainerObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/GPIOContainer";
const char enSUSIAccessGPIOPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/GPIOContainer/GPIOProperty";
const char enSUSIAccessGPIODirPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/GPIOContainer/GPIODirProperty";
const char enSUSIAccessGPIOLevelPropertyObjectPath[] = "/ControlPanel/SUSIAccess/ControlPanel/en/GPIOContainer/GPIOLevelProperty";

ContainerWidget SUSIAccessControlPanel;
ContainerWidget SUSIAccessBoardInfoContainer;
PropertyWidget SUSIAccessBoardManufacturerStringProperty;
PropertyWidget SUSIAccessBoardNameStringProperty;
ContainerWidget SUSIAccessVersionContainer;
PropertyWidget SUSIAccessDriverVersionProperty;
PropertyWidget SUSIAccessLibraryVersionProperty;
ContainerWidget SUSIAccessTemperatureContainer;
PropertyWidget SUSIAccessTemperatureProperty;
PropertyWidget SUSIAccessSubscriptionProperty;
ContainerWidget SUSIAccessDisplayContainer;
PropertyWidget SUSIAccessDisplayDeviceProperty;
PropertyWidget SUSIAccessBrightnessProperty;
PropertyWidget SUSIAccessBacklightProperty;
ContainerWidget SUSIAccessGPIOContainer;
PropertyWidget SUSIAccessGPIOProperty;
PropertyWidget SUSIAccessGPIODirProperty;
PropertyWidget SUSIAccessGPIOLevelProperty;

/*
 * Static variables used to fill widgets
 */
static const uint16_t SUSIAccessControlPanelHints[] = { LAYOUT_HINT_VERTICAL_LINEAR, LAYOUT_HINT_HORIZONTAL_LINEAR };
static const uint16_t SUSIAccessBoardInfoContainerHints[] = { LAYOUT_HINT_HORIZONTAL_LINEAR };
static const char* const SUSIAccessBoardManufacturerStringPropertySignature = "s";
static const char* const SUSIAccessBoardManufacturerStringPropertyLabel[] = { "Board Manufacturer:" };
static const uint16_t SUSIAccessBoardManufacturerStringPropertyHints[] = { PROPERTY_WIDGET_HINT_TEXTVIEW };
static const char* const SUSIAccessBoardNameStringPropertySignature = "s";
static const char* const SUSIAccessBoardNameStringPropertyLabel[] = { "Board Name:" };
static const uint16_t SUSIAccessBoardNameStringPropertyHints[] = { PROPERTY_WIDGET_HINT_TEXTVIEW };
static const uint16_t SUSIAccessVersionContainerHints[] = { LAYOUT_HINT_HORIZONTAL_LINEAR };
static const char* const SUSIAccessDriverVersionPropertySignature = "s";
static const char* const SUSIAccessDriverVersionPropertyLabel[] = { "Driver Version:" };
static const uint16_t SUSIAccessDriverVersionPropertyHints[] = { PROPERTY_WIDGET_HINT_TEXTVIEW };
static const char* const SUSIAccessLibraryVersionPropertySignature = "s";
static const char* const SUSIAccessLibraryVersionPropertyLabel[] = { "Library Version:" };
static const uint16_t SUSIAccessLibraryVersionPropertyHints[] = { PROPERTY_WIDGET_HINT_TEXTVIEW };
static const uint16_t SUSIAccessTemperatureContainerHints[] = { LAYOUT_HINT_HORIZONTAL_LINEAR };
static const char* const SUSIAccessTemperaturePropertySignature = "s";
static const char* const SUSIAccessTemperaturePropertyLabel[] = { "CPU Temperature:" };
static const uint16_t SUSIAccessTemperaturePropertyHints[] = { PROPERTY_WIDGET_HINT_TEXTVIEW };
static const char* const SUSIAccessSubscriptionPropertySignature = "b";
static const char* const SUSIAccessSubscriptionPropertyLabel[] = { "Subscription" };
static const uint16_t SUSIAccessSubscriptionPropertyHints[] = { PROPERTY_WIDGET_HINT_CHECKBOX };
static const uint16_t SUSIAccessDisplayContainerHints[] = { LAYOUT_HINT_HORIZONTAL_LINEAR };
static const char* const SUSIAccessDisplayDevicePropertySignature = "q";
static const char* const SUSIAccessDisplayDevicePropertyLabel[] = { "Display Devices" };
static const uint16_t SUSIAccessDisplayDevicePropertyHints[] = { PROPERTY_WIDGET_HINT_SPINNER };
static ConstraintList SUSIAccessDisplayDevicePropertyConstraintList[4];
static const uint16_t SUSIAccessDisplayDevicePropertyConstraintValue0 = 0;
static const char* const SUSIAccessDisplayDevicePropertyDisplay0[] = { "FB0" };
static const uint16_t SUSIAccessDisplayDevicePropertyConstraintValue1 = 1;
static const char* const SUSIAccessDisplayDevicePropertyDisplay1[] = { "FB1" };
static const uint16_t SUSIAccessDisplayDevicePropertyConstraintValue2 = 2;
static const char* const SUSIAccessDisplayDevicePropertyDisplay2[] = { "FB2" };
static const uint16_t SUSIAccessDisplayDevicePropertyConstraintValue3 = 3;
static const char* const SUSIAccessDisplayDevicePropertyDisplay3[] = { "FB3" };
static const char* const SUSIAccessBrightnessPropertySignature = "q";
static const char* const SUSIAccessBrightnessPropertyLabel[] = { "Brightness" };
static const uint16_t SUSIAccessBrightnessPropertyHints[] = { PROPERTY_WIDGET_HINT_SLIDER };
static const char* const SUSIAccessBrightnessPropertyUnitMeasure[] = { "Degrees" };
static const uint16_t SUSIAccessBrightnessPropertyConstraintRangeMin = 1;
static const uint16_t SUSIAccessBrightnessPropertyConstraintRangeMax = 7;
static const uint16_t SUSIAccessBrightnessPropertyConstraintRangeInc = 1;
static const char* const SUSIAccessBacklightPropertySignature = "q";
static const char* const SUSIAccessBacklightPropertyLabel[] = { "Backlight" };
static const uint16_t SUSIAccessBacklightPropertyHints[] = { PROPERTY_WIDGET_HINT_RADIOBUTTON };
static ConstraintList SUSIAccessBacklightPropertyConstraintList[2];
static const uint16_t SUSIAccessBacklightPropertyConstraintValue0 = 0;
static const char* const SUSIAccessBacklightPropertyDisplay0[] = { "OFF" };
static const uint16_t SUSIAccessBacklightPropertyConstraintValue1 = 1;
static const char* const SUSIAccessBacklightPropertyDisplay1[] = { "ON" };
static const uint16_t SUSIAccessGPIOContainerHints[] = { LAYOUT_HINT_HORIZONTAL_LINEAR };
static const char* const SUSIAccessGPIOPropertySignature = "q";
static const char* const SUSIAccessGPIOPropertyLabel[] = { "GPIO Pin" };
static const uint16_t SUSIAccessGPIOPropertyHints[] = { PROPERTY_WIDGET_HINT_SPINNER };
static ConstraintList SUSIAccessGPIOPropertyConstraintList[10];
static const uint16_t SUSIAccessGPIOPropertyConstraintValue0 = 0;
static const char* const SUSIAccessGPIOPropertyDisplay0[] = { "GPIO 1" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue1 = 1;
static const char* const SUSIAccessGPIOPropertyDisplay1[] = { "GPIO 2" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue2 = 2;
static const char* const SUSIAccessGPIOPropertyDisplay2[] = { "GPIO 3" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue3 = 3;
static const char* const SUSIAccessGPIOPropertyDisplay3[] = { "GPIO 4" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue4 = 4;
static const char* const SUSIAccessGPIOPropertyDisplay4[] = { "GPIO 5" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue5 = 5;
static const char* const SUSIAccessGPIOPropertyDisplay5[] = { "GPIO 6" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue6 = 6;
static const char* const SUSIAccessGPIOPropertyDisplay6[] = { "GPIO 7" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue7 = 7;
static const char* const SUSIAccessGPIOPropertyDisplay7[] = { "GPIO 8" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue8 = 8;
static const char* const SUSIAccessGPIOPropertyDisplay8[] = { "GPIO 9" };
static const uint16_t SUSIAccessGPIOPropertyConstraintValue9 = 9;
static const char* const SUSIAccessGPIOPropertyDisplay9[] = { "GPIO 10" };
static const char* const SUSIAccessGPIODirPropertySignature = "q";
static const char* const SUSIAccessGPIODirPropertyLabel[] = { "Direction" };
static const uint16_t SUSIAccessGPIODirPropertyHints[] = { PROPERTY_WIDGET_HINT_RADIOBUTTON };
static ConstraintList SUSIAccessGPIODirPropertyConstraintList[2];
static const uint16_t SUSIAccessGPIODirPropertyConstraintValue0 = 0;
static const char* const SUSIAccessGPIODirPropertyDisplay0[] = { "OUT" };
static const uint16_t SUSIAccessGPIODirPropertyConstraintValue1 = 1;
static const char* const SUSIAccessGPIODirPropertyDisplay1[] = { "IN" };
static const char* const SUSIAccessGPIOLevelPropertySignature = "q";
static const char* const SUSIAccessGPIOLevelPropertyLabel[] = { "Level" };
static const uint16_t SUSIAccessGPIOLevelPropertyHints[] = { PROPERTY_WIDGET_HINT_RADIOBUTTON };
static ConstraintList SUSIAccessGPIOLevelPropertyConstraintList[2];
static const uint16_t SUSIAccessGPIOLevelPropertyConstraintValue0 = 0;
static const char* const SUSIAccessGPIOLevelPropertyDisplay0[] = { "LOW" };
static const uint16_t SUSIAccessGPIOLevelPropertyConstraintValue1 = 1;
static const char* const SUSIAccessGPIOLevelPropertyDisplay1[] = { "HIGH" };


void WidgetsInit()
{
    initializeContainerWidget(&SUSIAccessControlPanel);
    SUSIAccessControlPanel.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessControlPanel.base, TRUE);

    SUSIAccessControlPanel.base.optParams.bgColor = 0x1e90ff;
    SUSIAccessControlPanel.base.optParams.hints = SUSIAccessControlPanelHints;
    SUSIAccessControlPanel.base.optParams.numHints = 2;

    initializeContainerWidget(&SUSIAccessBoardInfoContainer);
    SUSIAccessBoardInfoContainer.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessBoardInfoContainer.base, TRUE);

    SUSIAccessBoardInfoContainer.base.optParams.bgColor = 0x200;
    SUSIAccessBoardInfoContainer.base.optParams.hints = SUSIAccessBoardInfoContainerHints;
    SUSIAccessBoardInfoContainer.base.optParams.numHints = 1;

    initializePropertyWidget(&SUSIAccessBoardManufacturerStringProperty);
    SUSIAccessBoardManufacturerStringProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessBoardManufacturerStringProperty.base, TRUE);
    setBaseWritable(&SUSIAccessBoardManufacturerStringProperty.base, FALSE);

    SUSIAccessBoardManufacturerStringProperty.signature = SUSIAccessBoardManufacturerStringPropertySignature;
    SUSIAccessBoardManufacturerStringProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessBoardManufacturerStringProperty.getValue = &getBoardManufacturerString;

    SUSIAccessBoardManufacturerStringProperty.base.optParams.bgColor = 0x500;
    SUSIAccessBoardManufacturerStringProperty.base.optParams.label = SUSIAccessBoardManufacturerStringPropertyLabel;
    SUSIAccessBoardManufacturerStringProperty.base.optParams.hints = SUSIAccessBoardManufacturerStringPropertyHints;
    SUSIAccessBoardManufacturerStringProperty.base.optParams.numHints = 1;

    initializePropertyWidget(&SUSIAccessBoardNameStringProperty);
    SUSIAccessBoardNameStringProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessBoardNameStringProperty.base, TRUE);
    setBaseWritable(&SUSIAccessBoardNameStringProperty.base, FALSE);

    SUSIAccessBoardNameStringProperty.signature = SUSIAccessBoardNameStringPropertySignature;
    SUSIAccessBoardNameStringProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessBoardNameStringProperty.getValue = &getBoardNameString;

    SUSIAccessBoardNameStringProperty.base.optParams.bgColor = 0x500;
    SUSIAccessBoardNameStringProperty.base.optParams.label = SUSIAccessBoardNameStringPropertyLabel;
    SUSIAccessBoardNameStringProperty.base.optParams.hints = SUSIAccessBoardNameStringPropertyHints;
    SUSIAccessBoardNameStringProperty.base.optParams.numHints = 1;

    initializeContainerWidget(&SUSIAccessVersionContainer);
    SUSIAccessVersionContainer.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessVersionContainer.base, TRUE);

    SUSIAccessVersionContainer.base.optParams.bgColor = 0x200;
    SUSIAccessVersionContainer.base.optParams.hints = SUSIAccessVersionContainerHints;
    SUSIAccessVersionContainer.base.optParams.numHints = 1;

    initializePropertyWidget(&SUSIAccessDriverVersionProperty);
    SUSIAccessDriverVersionProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessDriverVersionProperty.base, TRUE);
    setBaseWritable(&SUSIAccessDriverVersionProperty.base, FALSE);

    SUSIAccessDriverVersionProperty.signature = SUSIAccessDriverVersionPropertySignature;
    SUSIAccessDriverVersionProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessDriverVersionProperty.getValue = &getDriverVersionString;

    SUSIAccessDriverVersionProperty.base.optParams.bgColor = 0x500;
    SUSIAccessDriverVersionProperty.base.optParams.label = SUSIAccessDriverVersionPropertyLabel;
    SUSIAccessDriverVersionProperty.base.optParams.hints = SUSIAccessDriverVersionPropertyHints;
    SUSIAccessDriverVersionProperty.base.optParams.numHints = 1;

    initializePropertyWidget(&SUSIAccessLibraryVersionProperty);
    SUSIAccessLibraryVersionProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessLibraryVersionProperty.base, TRUE);
    setBaseWritable(&SUSIAccessLibraryVersionProperty.base, FALSE);

    SUSIAccessLibraryVersionProperty.signature = SUSIAccessLibraryVersionPropertySignature;
    SUSIAccessLibraryVersionProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessLibraryVersionProperty.getValue = &getLibraryVersionString;

    SUSIAccessLibraryVersionProperty.base.optParams.bgColor = 0x500;
    SUSIAccessLibraryVersionProperty.base.optParams.label = SUSIAccessLibraryVersionPropertyLabel;
    SUSIAccessLibraryVersionProperty.base.optParams.hints = SUSIAccessLibraryVersionPropertyHints;
    SUSIAccessLibraryVersionProperty.base.optParams.numHints = 1;

    initializeContainerWidget(&SUSIAccessTemperatureContainer);
    SUSIAccessTemperatureContainer.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessTemperatureContainer.base, TRUE);

    SUSIAccessTemperatureContainer.base.optParams.bgColor = 0x200;
    SUSIAccessTemperatureContainer.base.optParams.hints = SUSIAccessTemperatureContainerHints;
    SUSIAccessTemperatureContainer.base.optParams.numHints = 1;

    initializePropertyWidget(&SUSIAccessTemperatureProperty);
    SUSIAccessTemperatureProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessTemperatureProperty.base, TRUE);
    setBaseWritable(&SUSIAccessTemperatureProperty.base, FALSE);

    SUSIAccessTemperatureProperty.signature = SUSIAccessTemperaturePropertySignature;
    SUSIAccessTemperatureProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessTemperatureProperty.getValue = &getCPUTemperatureString;

    SUSIAccessTemperatureProperty.base.optParams.bgColor = 0x500;
    SUSIAccessTemperatureProperty.base.optParams.label = SUSIAccessTemperaturePropertyLabel;
    SUSIAccessTemperatureProperty.base.optParams.hints = SUSIAccessTemperaturePropertyHints;
    SUSIAccessTemperatureProperty.base.optParams.numHints = 1;

    initializePropertyWidget(&SUSIAccessSubscriptionProperty);
    SUSIAccessSubscriptionProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessSubscriptionProperty.base, TRUE);
    setBaseWritable(&SUSIAccessSubscriptionProperty.base, TRUE);

    SUSIAccessSubscriptionProperty.signature = SUSIAccessSubscriptionPropertySignature;
    SUSIAccessSubscriptionProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessSubscriptionProperty.getValue = &getSubscription;

    SUSIAccessSubscriptionProperty.base.optParams.bgColor = 0x500;
    SUSIAccessSubscriptionProperty.base.optParams.label = SUSIAccessSubscriptionPropertyLabel;
    SUSIAccessSubscriptionProperty.base.optParams.hints = SUSIAccessSubscriptionPropertyHints;
    SUSIAccessSubscriptionProperty.base.optParams.numHints = 1;

    initializeContainerWidget(&SUSIAccessDisplayContainer);
    SUSIAccessDisplayContainer.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessDisplayContainer.base, TRUE);

    SUSIAccessDisplayContainer.base.optParams.bgColor = 0x200;
    SUSIAccessDisplayContainer.base.optParams.hints = SUSIAccessDisplayContainerHints;
    SUSIAccessDisplayContainer.base.optParams.numHints = 1;

    initializePropertyWidget(&SUSIAccessDisplayDeviceProperty);
    SUSIAccessDisplayDeviceProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessDisplayDeviceProperty.base, TRUE);
    setBaseWritable(&SUSIAccessDisplayDeviceProperty.base, TRUE);

    SUSIAccessDisplayDeviceProperty.signature = SUSIAccessDisplayDevicePropertySignature;
    SUSIAccessDisplayDeviceProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessDisplayDeviceProperty.getValue = &getDisplayDevice;

    SUSIAccessDisplayDeviceProperty.base.optParams.bgColor = 0xffd700;
    SUSIAccessDisplayDeviceProperty.base.optParams.label = SUSIAccessDisplayDevicePropertyLabel;
    SUSIAccessDisplayDeviceProperty.base.optParams.hints = SUSIAccessDisplayDevicePropertyHints;
    SUSIAccessDisplayDeviceProperty.base.optParams.numHints = 1;

    SUSIAccessDisplayDeviceProperty.optParams.numConstraints = 4;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList = SUSIAccessDisplayDevicePropertyConstraintList;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList[0].value = &SUSIAccessDisplayDevicePropertyConstraintValue0;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList[0].display = SUSIAccessDisplayDevicePropertyDisplay0;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList[1].value = &SUSIAccessDisplayDevicePropertyConstraintValue1;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList[1].display = SUSIAccessDisplayDevicePropertyDisplay1;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList[2].value = &SUSIAccessDisplayDevicePropertyConstraintValue2;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList[2].display = SUSIAccessDisplayDevicePropertyDisplay2;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList[3].value = &SUSIAccessDisplayDevicePropertyConstraintValue3;
    SUSIAccessDisplayDeviceProperty.optParams.constraintList[3].display = SUSIAccessDisplayDevicePropertyDisplay3;

    initializePropertyWidget(&SUSIAccessBrightnessProperty);
    SUSIAccessBrightnessProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessBrightnessProperty.base, TRUE);
    setBaseWritable(&SUSIAccessBrightnessProperty.base, TRUE);

    SUSIAccessBrightnessProperty.signature = SUSIAccessBrightnessPropertySignature;
    SUSIAccessBrightnessProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessBrightnessProperty.getValue = &getBrightnessValue;

    SUSIAccessBrightnessProperty.base.optParams.bgColor = 0x008000;
    SUSIAccessBrightnessProperty.base.optParams.label = SUSIAccessBrightnessPropertyLabel;
    SUSIAccessBrightnessProperty.base.optParams.hints = SUSIAccessBrightnessPropertyHints;
    SUSIAccessBrightnessProperty.base.optParams.numHints = 1;
    SUSIAccessBrightnessProperty.optParams.unitOfMeasure = SUSIAccessBrightnessPropertyUnitMeasure;

    SUSIAccessBrightnessProperty.optParams.constraintRangeDefined = TRUE;
    SUSIAccessBrightnessProperty.optParams.constraintRange.minValue = &SUSIAccessBrightnessPropertyConstraintRangeMin;
    SUSIAccessBrightnessProperty.optParams.constraintRange.maxValue = &SUSIAccessBrightnessPropertyConstraintRangeMax;
    SUSIAccessBrightnessProperty.optParams.constraintRange.increment = &SUSIAccessBrightnessPropertyConstraintRangeInc;

    initializePropertyWidget(&SUSIAccessBacklightProperty);
    SUSIAccessBacklightProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessBacklightProperty.base, TRUE);
    setBaseWritable(&SUSIAccessBacklightProperty.base, TRUE);

    SUSIAccessBacklightProperty.signature = SUSIAccessBacklightPropertySignature;
    SUSIAccessBacklightProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessBacklightProperty.getValue = &getBacklightValue;

    SUSIAccessBacklightProperty.base.optParams.bgColor = 0xffd700;
    SUSIAccessBacklightProperty.base.optParams.label = SUSIAccessBacklightPropertyLabel;
    SUSIAccessBacklightProperty.base.optParams.hints = SUSIAccessBacklightPropertyHints;
    SUSIAccessBacklightProperty.base.optParams.numHints = 1;

    SUSIAccessBacklightProperty.optParams.numConstraints = 2;
    SUSIAccessBacklightProperty.optParams.constraintList = SUSIAccessBacklightPropertyConstraintList;
    SUSIAccessBacklightProperty.optParams.constraintList[0].value = &SUSIAccessBacklightPropertyConstraintValue0;
    SUSIAccessBacklightProperty.optParams.constraintList[0].display = SUSIAccessBacklightPropertyDisplay0;
    SUSIAccessBacklightProperty.optParams.constraintList[1].value = &SUSIAccessBacklightPropertyConstraintValue1;
    SUSIAccessBacklightProperty.optParams.constraintList[1].display = SUSIAccessBacklightPropertyDisplay1;

    initializeContainerWidget(&SUSIAccessGPIOContainer);
    SUSIAccessGPIOContainer.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessGPIOContainer.base, TRUE);

    SUSIAccessGPIOContainer.base.optParams.bgColor = 0x200;
    SUSIAccessGPIOContainer.base.optParams.hints = SUSIAccessGPIOContainerHints;
    SUSIAccessGPIOContainer.base.optParams.numHints = 1;

    initializePropertyWidget(&SUSIAccessGPIOProperty);
    SUSIAccessGPIOProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessGPIOProperty.base, TRUE);
    setBaseWritable(&SUSIAccessGPIOProperty.base, TRUE);

    SUSIAccessGPIOProperty.signature = SUSIAccessGPIOPropertySignature;
    SUSIAccessGPIOProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessGPIOProperty.getValue = &getGPIOPin;

    SUSIAccessGPIOProperty.base.optParams.bgColor = 0xffd700;
    SUSIAccessGPIOProperty.base.optParams.label = SUSIAccessGPIOPropertyLabel;
    SUSIAccessGPIOProperty.base.optParams.hints = SUSIAccessGPIOPropertyHints;
    SUSIAccessGPIOProperty.base.optParams.numHints = 1;

    SUSIAccessGPIOProperty.optParams.numConstraints = 10;
    SUSIAccessGPIOProperty.optParams.constraintList = SUSIAccessGPIOPropertyConstraintList;
    SUSIAccessGPIOProperty.optParams.constraintList[0].value = &SUSIAccessGPIOPropertyConstraintValue0;
    SUSIAccessGPIOProperty.optParams.constraintList[0].display = SUSIAccessGPIOPropertyDisplay0;
    SUSIAccessGPIOProperty.optParams.constraintList[1].value = &SUSIAccessGPIOPropertyConstraintValue1;
    SUSIAccessGPIOProperty.optParams.constraintList[1].display = SUSIAccessGPIOPropertyDisplay1;
    SUSIAccessGPIOProperty.optParams.constraintList[2].value = &SUSIAccessGPIOPropertyConstraintValue2;
    SUSIAccessGPIOProperty.optParams.constraintList[2].display = SUSIAccessGPIOPropertyDisplay2;
    SUSIAccessGPIOProperty.optParams.constraintList[3].value = &SUSIAccessGPIOPropertyConstraintValue3;
    SUSIAccessGPIOProperty.optParams.constraintList[3].display = SUSIAccessGPIOPropertyDisplay3;
    SUSIAccessGPIOProperty.optParams.constraintList[4].value = &SUSIAccessGPIOPropertyConstraintValue4;
    SUSIAccessGPIOProperty.optParams.constraintList[4].display = SUSIAccessGPIOPropertyDisplay4;
    SUSIAccessGPIOProperty.optParams.constraintList[5].value = &SUSIAccessGPIOPropertyConstraintValue5;
    SUSIAccessGPIOProperty.optParams.constraintList[5].display = SUSIAccessGPIOPropertyDisplay5;
    SUSIAccessGPIOProperty.optParams.constraintList[6].value = &SUSIAccessGPIOPropertyConstraintValue6;
    SUSIAccessGPIOProperty.optParams.constraintList[6].display = SUSIAccessGPIOPropertyDisplay6;
    SUSIAccessGPIOProperty.optParams.constraintList[7].value = &SUSIAccessGPIOPropertyConstraintValue7;
    SUSIAccessGPIOProperty.optParams.constraintList[7].display = SUSIAccessGPIOPropertyDisplay7;
    SUSIAccessGPIOProperty.optParams.constraintList[8].value = &SUSIAccessGPIOPropertyConstraintValue8;
    SUSIAccessGPIOProperty.optParams.constraintList[8].display = SUSIAccessGPIOPropertyDisplay8;
    SUSIAccessGPIOProperty.optParams.constraintList[9].value = &SUSIAccessGPIOPropertyConstraintValue9;
    SUSIAccessGPIOProperty.optParams.constraintList[9].display = SUSIAccessGPIOPropertyDisplay9;

    initializePropertyWidget(&SUSIAccessGPIODirProperty);
    SUSIAccessGPIODirProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessGPIODirProperty.base, TRUE);
    setBaseWritable(&SUSIAccessGPIODirProperty.base, TRUE);

    SUSIAccessGPIODirProperty.signature = SUSIAccessGPIODirPropertySignature;
    SUSIAccessGPIODirProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessGPIODirProperty.getValue = &getGPIODirValue;

    SUSIAccessGPIODirProperty.base.optParams.bgColor = 0xffd700;
    SUSIAccessGPIODirProperty.base.optParams.label = SUSIAccessGPIODirPropertyLabel;
    SUSIAccessGPIODirProperty.base.optParams.hints = SUSIAccessGPIODirPropertyHints;
    SUSIAccessGPIODirProperty.base.optParams.numHints = 1;

    SUSIAccessGPIODirProperty.optParams.numConstraints = 2;
    SUSIAccessGPIODirProperty.optParams.constraintList = SUSIAccessGPIODirPropertyConstraintList;
    SUSIAccessGPIODirProperty.optParams.constraintList[0].value = &SUSIAccessGPIODirPropertyConstraintValue0;
    SUSIAccessGPIODirProperty.optParams.constraintList[0].display = SUSIAccessGPIODirPropertyDisplay0;
    SUSIAccessGPIODirProperty.optParams.constraintList[1].value = &SUSIAccessGPIODirPropertyConstraintValue1;
    SUSIAccessGPIODirProperty.optParams.constraintList[1].display = SUSIAccessGPIODirPropertyDisplay1;

    initializePropertyWidget(&SUSIAccessGPIOLevelProperty);
    SUSIAccessGPIOLevelProperty.base.numLanguages = 1;
    setBaseEnabled(&SUSIAccessGPIOLevelProperty.base, TRUE);
    setBaseWritable(&SUSIAccessGPIOLevelProperty.base, TRUE);

    SUSIAccessGPIOLevelProperty.signature = SUSIAccessGPIOLevelPropertySignature;
    SUSIAccessGPIOLevelProperty.propertyType = SINGLE_VALUE_PROPERTY;
    SUSIAccessGPIOLevelProperty.getValue = &getGPIOLevelValue;

    SUSIAccessGPIOLevelProperty.base.optParams.bgColor = 0xffd700;
    SUSIAccessGPIOLevelProperty.base.optParams.label = SUSIAccessGPIOLevelPropertyLabel;
    SUSIAccessGPIOLevelProperty.base.optParams.hints = SUSIAccessGPIOLevelPropertyHints;
    SUSIAccessGPIOLevelProperty.base.optParams.numHints = 1;

    SUSIAccessGPIOLevelProperty.optParams.numConstraints = 2;
    SUSIAccessGPIOLevelProperty.optParams.constraintList = SUSIAccessGPIOLevelPropertyConstraintList;
    SUSIAccessGPIOLevelProperty.optParams.constraintList[0].value = &SUSIAccessGPIOLevelPropertyConstraintValue0;
    SUSIAccessGPIOLevelProperty.optParams.constraintList[0].display = SUSIAccessGPIOLevelPropertyDisplay0;
    SUSIAccessGPIOLevelProperty.optParams.constraintList[1].value = &SUSIAccessGPIOLevelPropertyConstraintValue1;
    SUSIAccessGPIOLevelProperty.optParams.constraintList[1].display = SUSIAccessGPIOLevelPropertyDisplay1;

    return;
}

void* IdentifyMsgOrPropId(uint32_t identifier, uint16_t* widgetType, uint16_t* propType, uint16_t* language)
{
    switch (identifier) {
    case EN_SUSIACCESS_CONTROLPANEL_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessControlPanel;

    case EN_SUSIACCESS_CONTROLPANEL_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessControlPanel;

    case EN_SUSIACCESS_CONTROLPANEL_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessControlPanel;

    case EN_SUSIACCESS_CONTROLPANEL_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessControlPanel;

    case EN_SUSIACCESS_BOARDINFOCONTAINER_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardInfoContainer;

    case EN_SUSIACCESS_BOARDINFOCONTAINER_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardInfoContainer;

    case EN_SUSIACCESS_BOARDINFOCONTAINER_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardInfoContainer;

    case EN_SUSIACCESS_BOARDINFOCONTAINER_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardInfoContainer;

    case EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardManufacturerStringProperty;

    case EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardManufacturerStringProperty;

    case EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardManufacturerStringProperty;

    case EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardManufacturerStringProperty;

    case EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardManufacturerStringProperty;

    case EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardNameStringProperty;

    case EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardNameStringProperty;

    case EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardNameStringProperty;

    case EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardNameStringProperty;

    case EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBoardNameStringProperty;

    case EN_SUSIACCESS_VERSIONCONTAINER_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessVersionContainer;

    case EN_SUSIACCESS_VERSIONCONTAINER_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessVersionContainer;

    case EN_SUSIACCESS_VERSIONCONTAINER_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessVersionContainer;

    case EN_SUSIACCESS_VERSIONCONTAINER_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessVersionContainer;

    case EN_SUSIACCESS_DRIVERVERSIONPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDriverVersionProperty;

    case EN_SUSIACCESS_DRIVERVERSIONPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDriverVersionProperty;

    case EN_SUSIACCESS_DRIVERVERSIONPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDriverVersionProperty;

    case EN_SUSIACCESS_DRIVERVERSIONPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDriverVersionProperty;

    case EN_SUSIACCESS_DRIVERVERSIONPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDriverVersionProperty;

    case EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessLibraryVersionProperty;

    case EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessLibraryVersionProperty;

    case EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessLibraryVersionProperty;

    case EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessLibraryVersionProperty;

    case EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessLibraryVersionProperty;

    case EN_SUSIACCESS_TEMPERATURECONTAINER_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureContainer;

    case EN_SUSIACCESS_TEMPERATURECONTAINER_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureContainer;

    case EN_SUSIACCESS_TEMPERATURECONTAINER_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureContainer;

    case EN_SUSIACCESS_TEMPERATURECONTAINER_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureContainer;

    case EN_SUSIACCESS_TEMPERATUREPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureProperty;

    case EN_SUSIACCESS_TEMPERATUREPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureProperty;

    case EN_SUSIACCESS_TEMPERATUREPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureProperty;

    case EN_SUSIACCESS_TEMPERATUREPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureProperty;

    case EN_SUSIACCESS_TEMPERATUREPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessTemperatureProperty;

    case EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessSubscriptionProperty;

    case EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessSubscriptionProperty;

    case EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessSubscriptionProperty;

    case EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessSubscriptionProperty;

    case EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessSubscriptionProperty;

    case EN_SUSIACCESS_DISPLAYCONTAINER_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayContainer;

    case EN_SUSIACCESS_DISPLAYCONTAINER_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayContainer;

    case EN_SUSIACCESS_DISPLAYCONTAINER_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayContainer;

    case EN_SUSIACCESS_DISPLAYCONTAINER_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayContainer;

    case EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayDeviceProperty;

    case EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayDeviceProperty;

    case EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayDeviceProperty;

    case EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayDeviceProperty;

    case EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessDisplayDeviceProperty;

    case EN_SUSIACCESS_BRIGHTNESSPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBrightnessProperty;

    case EN_SUSIACCESS_BRIGHTNESSPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBrightnessProperty;

    case EN_SUSIACCESS_BRIGHTNESSPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBrightnessProperty;

    case EN_SUSIACCESS_BRIGHTNESSPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBrightnessProperty;

    case EN_SUSIACCESS_BRIGHTNESSPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBrightnessProperty;

    case EN_SUSIACCESS_BACKLIGHTPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBacklightProperty;

    case EN_SUSIACCESS_BACKLIGHTPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBacklightProperty;

    case EN_SUSIACCESS_BACKLIGHTPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBacklightProperty;

    case EN_SUSIACCESS_BACKLIGHTPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBacklightProperty;

    case EN_SUSIACCESS_BACKLIGHTPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessBacklightProperty;

    case EN_SUSIACCESS_GPIOCONTAINER_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOContainer;

    case EN_SUSIACCESS_GPIOCONTAINER_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOContainer;

    case EN_SUSIACCESS_GPIOCONTAINER_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOContainer;

    case EN_SUSIACCESS_GPIOCONTAINER_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOContainer;

    case EN_SUSIACCESS_GPIOPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOProperty;

    case EN_SUSIACCESS_GPIOPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOProperty;

    case EN_SUSIACCESS_GPIOPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOProperty;

    case EN_SUSIACCESS_GPIOPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOProperty;

    case EN_SUSIACCESS_GPIOPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOProperty;

    case EN_SUSIACCESS_GPIODIRPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIODirProperty;

    case EN_SUSIACCESS_GPIODIRPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIODirProperty;

    case EN_SUSIACCESS_GPIODIRPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIODirProperty;

    case EN_SUSIACCESS_GPIODIRPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIODirProperty;

    case EN_SUSIACCESS_GPIODIRPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIODirProperty;

    case EN_SUSIACCESS_GPIOLEVELPROPERTY_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOLevelProperty;

    case EN_SUSIACCESS_GPIOLEVELPROPERTY_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOLevelProperty;

    case EN_SUSIACCESS_GPIOLEVELPROPERTY_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOLevelProperty;

    case EN_SUSIACCESS_GPIOLEVELPROPERTY_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOLevelProperty;

    case EN_SUSIACCESS_GPIOLEVELPROPERTY_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = SUSIACCESS_MYLANGUAGES_EN;
        return &SUSIAccessGPIOLevelProperty;

    default:
        return FALSE;
    }
}

void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty)
{
    switch (identifier) {
    case EN_SUSIACCESS_CONTROLPANEL_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessControlPanel;

    case EN_SUSIACCESS_BOARDINFOCONTAINER_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessBoardInfoContainer;

    case EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessBoardManufacturerStringProperty;

    case EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessBoardManufacturerStringProperty;

    case EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessBoardNameStringProperty;

    case EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessBoardNameStringProperty;

    case EN_SUSIACCESS_VERSIONCONTAINER_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessVersionContainer;

    case EN_SUSIACCESS_DRIVERVERSIONPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessDriverVersionProperty;

    case EN_SUSIACCESS_DRIVERVERSIONPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessDriverVersionProperty;

    case EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessLibraryVersionProperty;

    case EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessLibraryVersionProperty;

    case EN_SUSIACCESS_TEMPERATURECONTAINER_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessTemperatureContainer;

    case EN_SUSIACCESS_TEMPERATUREPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessTemperatureProperty;

    case EN_SUSIACCESS_TEMPERATUREPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessTemperatureProperty;

    case EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessSubscriptionProperty;

    case EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessSubscriptionProperty;

    case EN_SUSIACCESS_DISPLAYCONTAINER_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessDisplayContainer;

    case EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessDisplayDeviceProperty;

    case EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessDisplayDeviceProperty;

    case EN_SUSIACCESS_BRIGHTNESSPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessBrightnessProperty;

    case EN_SUSIACCESS_BRIGHTNESSPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessBrightnessProperty;

    case EN_SUSIACCESS_BACKLIGHTPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessBacklightProperty;

    case EN_SUSIACCESS_BACKLIGHTPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessBacklightProperty;

    case EN_SUSIACCESS_GPIOCONTAINER_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessGPIOContainer;

    case EN_SUSIACCESS_GPIOPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessGPIOProperty;

    case EN_SUSIACCESS_GPIOPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessGPIOProperty;

    case EN_SUSIACCESS_GPIODIRPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessGPIODirProperty;

    case EN_SUSIACCESS_GPIODIRPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessGPIODirProperty;

    case EN_SUSIACCESS_GPIOLEVELPROPERTY_SIGNAL_PROPERTIES_CHANGED:
        return &SUSIAccessGPIOLevelProperty;

    case EN_SUSIACCESS_GPIOLEVELPROPERTY_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &SUSIAccessGPIOLevelProperty;

    default:
        return FALSE;
    }
}

uint8_t IdentifyRootMsgOrPropId(uint32_t identifier)
{
    switch (identifier) {
    case SUSIACCESS_ROOT_CONTROLPANEL_CONTROLPANEL_VERSION_PROPERTY:
    case SUSIACCESS_ROOT_CONTROLPANEL_CONTROLPANEL_GET_ALL_VALUES:
        return TRUE;

    default:
        return FALSE;
    }
}

AJ_Status SetValueProperty(AJ_Message* replyMsg, uint32_t propId, void* context)
{
    AJ_Status status = AJ_ERR_UNEXPECTED;

    const char* variantSig;
    AJ_UnmarshalVariant(replyMsg, &variantSig);

    switch (propId) {
    case EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_VALUE_PROPERTY:
        {
            const char* newValue;
            status = unmarshalPropertyValue(&SUSIAccessBoardManufacturerStringProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setBoardManufacturerString(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_BOARDMANUFACTURERSTRINGPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_VALUE_PROPERTY:
        {
            const char* newValue;
            status = unmarshalPropertyValue(&SUSIAccessBoardNameStringProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setBoardNameString(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_BOARDNAMESTRINGPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_DRIVERVERSIONPROPERTY_VALUE_PROPERTY:
        {
            const char* newValue;
            status = unmarshalPropertyValue(&SUSIAccessDriverVersionProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setDriverVersionString(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_DRIVERVERSIONPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_VALUE_PROPERTY:
        {
            const char* newValue;
            status = unmarshalPropertyValue(&SUSIAccessLibraryVersionProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setLibraryVersionString(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_LIBRARYVERSIONPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_TEMPERATUREPROPERTY_VALUE_PROPERTY:
        {
            const char* newValue;
            status = unmarshalPropertyValue(&SUSIAccessTemperatureProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setCPUTemperatureString(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_TEMPERATUREPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_VALUE_PROPERTY:
        {
            uint32_t newValue;
            status = unmarshalPropertyValue(&SUSIAccessSubscriptionProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setSubscription(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_SUBSCRIPTIONPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&SUSIAccessDisplayDeviceProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setDisplayDevice(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_DISPLAYDEVICEPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_BRIGHTNESSPROPERTY_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&SUSIAccessBrightnessProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setBrightnessValue(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_BRIGHTNESSPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_BACKLIGHTPROPERTY_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&SUSIAccessBacklightProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setBacklightValue(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_BACKLIGHTPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_GPIOPROPERTY_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&SUSIAccessGPIOProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setGPIOPin(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_GPIOPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_GPIODIRPROPERTY_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&SUSIAccessGPIODirProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setGPIODirValue(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_GPIODIRPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_SUSIACCESS_GPIOLEVELPROPERTY_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&SUSIAccessGPIOLevelProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setGPIOLevelValue(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_SUSIACCESS_GPIOLEVELPROPERTY_SIGNAL_VALUE_CHANGED;
        }
        break;


    }

    return status;
}

AJ_Status ExecuteAction(AJ_Message* msg, uint32_t msgId, ExecuteActionContext* context)
{
    AJ_Message reply;
    AJ_MarshalReplyMsg(msg, &reply);

    switch (msgId) {

    }

    return AJ_DeliverMsg(&reply);
}

void TestsInit(CPSTest* testsToRun)
{

}

AJSVC_ServiceStatus GeneratedMessageProcessor(AJ_BusAttachment* bus, AJ_Message* msg, AJ_Status* msgStatus)
{
    AJSVC_ServiceStatus AJSVC_ServiceStatus = AJSVC_SERVICE_STATUS_HANDLED;

    switch (msg->msgId) {
        GET_WIDGET_VALUE_CASES
        *msgStatus = AJ_BusPropGet(msg, AJCPS_GetWidgetProperty, NULL);
        break;

        GET_WIDGET_ALL_VALUE_CASES
        *msgStatus = AJCPS_GetAllWidgetProperties(msg, msg->msgId);
        break;

        GET_ROOT_VALUE_CASES
        *msgStatus = AJ_BusPropGet(msg, AJCPS_GetRootProperty, NULL);
        break;

        GET_ROOT_ALL_VALUE_CASES
        *msgStatus = AJCPS_GetAllRootProperties(msg, msg->msgId);
        break;

        SET_VALUE_CASES
        {
            SetValueContext context;
            context.sender = msg->sender;
            context.numSignals = 0;
            *msgStatus = AJ_BusPropSet(msg, SetValueProperty, &context);
            if (*msgStatus == AJ_OK && context.numSignals != 0) {
                uint16_t indx;
                for (indx = 0; indx < context.numSignals; indx++) {
                    *msgStatus = AJCPS_SendPropertyChangedSignal(bus, context.signals[indx], AJCPS_GetCurrentSessionId());
                }
            }
        }
        break;

        ACTION_CASES
        {
            ExecuteActionContext context;
            context.numSignals = 0;
            *msgStatus = ExecuteAction(msg, msg->msgId, &context);
            if (*msgStatus == AJ_OK && context.numSignals != 0) {
                uint16_t indx;
                for (indx = 0; indx < context.numSignals; indx++) {
                    if (context.signals[indx].signalType == SIGNAL_TYPE_DATA_CHANGED) {
                        *msgStatus = AJCPS_SendPropertyChangedSignal(bus, context.signals[indx].signalId, AJCPS_GetCurrentSessionId());
                    } else if (context.signals[indx].signalType == SIGNAL_TYPE_DISMISS) {
                        *msgStatus = AJCPS_SendDismissSignal(bus, context.signals[indx].signalId, AJCPS_GetCurrentSessionId());
                    }
                }
            }
        }
        break;

        GET_URL_CASES
        *msgStatus = AJCPS_SendRootUrl(msg, msg->msgId);
        break;

    case AJ_SIGNAL_SESSION_LOST:
        break;

    default:
        AJSVC_ServiceStatus = AJSVC_SERVICE_STATUS_NOT_HANDLED;
        break;
    }

    return AJSVC_ServiceStatus;
}
