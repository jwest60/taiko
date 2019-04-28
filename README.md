# Usage

This repository contains the code for a Visual Studio project.

### Prerequisites

- [Visual Studio](https://visualstudio.microsoft.com/)
- [SFML](https://www.sfml-dev.org/download.php) (Visual Studio 2017 - 32 bit)
- [TGUI](https://tgui.eu/download/) (Visual C++15 (2017) - 32bit)

Save SFML in a location where you can access it easily.

### Installation

To compile the code on your local machine, clone this repo in your Visual Studio projects directory.

```
git clone https://github.com/jwest60/taiko.git
```

Then open the `.sln` file to open Visual Studio.

This repo dynamically links the SFML and TGUI libraries, so you will need to handle their dependencies yourself, which is explained below.

Follow [this guide in the SFML documentation](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) to link all the necessary files. You will need the following libraries:
- Graphics
- Window
- System
- Audio

Follow [this guide in the TGUI documentation](https://tgui.eu/tutorials/0.8/visual-studio-precompiled/) to link all the necessary files.

Note: The `.dll` files are already included, so you will not need to copy them into your project.

# How To Play

### Controls

**A and F** - "Outer" drum; used to hit notes that are colored blue.

**S and D** - "Outer" drum; used to hit notes that are colored red.

**SPACE** - Pause button

Note: You don't have to use both keys. Two keys are provided for "double tapping", or when notes are appearing at intervals so close together that one key is too slow. They are not needed in the current state; using just one of each will suffice.

### Strategy

On pressing play, notes will begin to travel from the right to the left and music will begin to play after a short delay. Once they align with the hit marker, use the appropriate key to hit the note. Listening to the music will help you time this.

### Known Bugs

- Hitting the ESC button to go back to the menu doesn't reset the play state
