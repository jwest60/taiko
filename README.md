# Usage

This repository contains the code for a Visual Studio project.

### Prerequisites

- [Visual Studio](https://visualstudio.microsoft.com/)
- [SFML](https://www.sfml-dev.org/download.php) (Visual Studio 2017 - 32 bit)

Save SFML in a location where you can access it easily.

### Installation

To compile the code on your local machine, clone this repo in your Visual Studio projects directory.

```
git clone https://github.com/jwest60/taiko.git
```

Then open the `.sln` file to open Visual Studio.

This repo dynamically links the necessary `.dll` files, so you will need to link them to your project yourself.

Follow [this guide in the SFML documentation](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) to link all the necessary files. You will need the following libraries:
- Graphics
- Window
- System
- Audio

Note: The `.dll` files are already included, so you will not need to copy them into your project.
