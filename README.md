# Daisy-Juce-Example

Proof of Concept of using DaisySP with JUCE

This is meant as a simple example to get started developing JUCE plugins/applications using DaisySP

## Prerequisites

* CMAKE >= v3.15

This project has been tested on:
* Windows 10 w/ VisualStudio 2019

## Setup

Clone the repo with:

```
git clone --recurse-submodules https://github.com/electro-smith/Daisy-JUCE-Example
```

This will clone this repository along with the following submodules:

* [JUCE](https://github.com/juce-framework/JUCE)
* [DaisySP](https://github.com/electro-smith/DaisySP)

## Building

This project is configured with CMake so that it can be as portable as possible.

These command line steps will generate a buildable project for your OS

```
# navigate to a clean directory for your build (i.e. plugin/build)
cd plugin/

# Create a new build folder (this doesn't have to be here, but keeps it easy)
mkdir build
cd build

# Run CMake
cmake ..
```

When this completes you will have a number of files generated depending on your OS.

### Windows

On Windows you can now open the AUDIO_PLUGIN_EXAMPLE.sln

Running Build All (`ctrl-shift-B`) should run successfully

To run the standalone version of the project:

* right click the "Standlone" project in the solution explorer, and select "Set as Start Up Project"
* click the Windows Local Debug button.
  * If you hit a break point right away just hit continue (still looking into this).
* You should now hear a sine wave, and see a slider. 
* The slider will adjust the frequency of the sine wave.
* You can now debug the project by inserting breakpoints, etc.

There will be some warnings related to the DaisySP build that can be ignored. We're working on correcting these, or suppressing them (as they have to do with class member initialization).

### Mac OS X

Details Coming Soon. . .

### Linux

Details Coming Soon. . .

