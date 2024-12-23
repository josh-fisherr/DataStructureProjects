File Processor and Rövarspråket Translator

Overview

This project translates English text into Rövarspråket (robber's language), a playful linguistic cipher. It demonstrates file processing, modular programming, and algorithm design using C++.

Key Features

File Processing: Reads from an input file and writes translated text to an output HTML file.

Translation Logic: Converts consonants to Rövarspråket while retaining vowels and punctuation.

Modular Design: Separates functionalities into FileProcessor, Model, and Translator classes for clarity and reusability.

Setup Instructions

Clone the Repository:

git clone <repository-url>
cd FileProcessor

Compile the Program:

g++ src/*.cpp -o file_processor

Run the Program:

./file_processor

The program reads from input/original.txt and generates output/translation.html.

Example

Input (original.txt):

This is a test of robber language's capability!

Output (translation.html):

<b>This is a test of robber language's capability!</b><br>
<i>ToThohisos o isos o a o totesostot o ofof o rorobobboberor o lolanongoguagoge'sos o cocapopabobilolitotyoy!</i><br><br>

Technologies Used

Language: C++

Core Concepts: File I/O, Object-Oriented Programming, Algorithm Design

Future Enhancements

Add support for other linguistic ciphers.

Build a GUI for real-time text translation.

Extend functionality for batch file processing.
