# Usage

This repository contains the code for a Visual Studio project.

### Prerequisites

- [Visual Studio](https://visualstudio.microsoft.com/)
- [SFML](https://www.sfml-dev.org/download.php)

Save SFML in a location where you can access it easily.

### Installation

To compile the code on your local machine, clone this repo in your Visual Studio projects directory.

```
git clone https://github.com/jwest60/taiko.git
```

Then open the `.sln` file to open Visual Studio.

This repo dynamically links the necessary `.dll` files, so you will need to link them to your project yourself.

Follow [this guide in the SFML documentation] to link all the necessary files. You will need the following libraries:
- Graphics
- Window
- System
- Audio
