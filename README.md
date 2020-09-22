# FYP-Stochastic-Computer

This repository contains all the code used for my Final Year Project (FYP) in my Bachelor's degree. The title of the FYP was "The Design
and Evaluation of a Stochastic Computer". This project attempts to build a stochastic co-processor which is used in conjunction with a
microprocessor to execute an algorithm and then examine the advantages and shortcomings of Stochastic Computing. The co-processor performs
stochastic multiplication which is used by the Jarvis March algorithm which is running on the microprocessor.

The microprocessor used was an Arduino Mega 2560. The code for this project has two parts. The code running on the Arduino and additional Java
code used to create an interface to display the results obtained for the Jarvis March algorithm.

## Java Directory
Contains program written to animate the Jarvis March Algorithm, display results, perform simulations and interface with the Arduino.

## Arduino Directory
Contains all code used on the Arduino. Each part of the stochastic co-processor has an Arduino file associated with it to test that part of
the co-processor. These test files are placed within the `Test/` directory. The final main file which needs to be uploaded to perform multiplication
is in the `Final_Code` directory and is the `stochastic_multiply.ino` file.
