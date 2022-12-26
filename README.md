# C/C++ Image Encryption

CIE is an application that encrypt images using RSA algorithm

## Prerequisites

Magick++
```bash
sudo apt install graphicsmagick-libmagick-dev-compat
```

## Usage

Compile files

Run 
```c++
g++ -o <executable_name> main.cpp cie.cpp utils.cpp `Magick++-config --cxxflags --cppflags` `Magick++-config --ldflags --libs`
```

Execute
```c++
./<executable_name> <image_path>
```

## More features TBD