# Bushra’s Bazaar

A terminal based inventory management system built in C++ using object oriented programming principles. The project simulates a small scale retail inventory with extensible product categories and persistent storage.

## Overview
Bushra’s Bazaar models a mini market inventory system using class inheritance and file input output. The project emphasizes clean architecture, modular class design, and separation of concerns while remaining suitable for academic demonstration.

## Key Features
- Product class hierarchy with shared base behavior  
- Specialized product types using inheritance  
- Inventory tracking through a manager class  
- File based persistence using text files  
- Console driven interaction and testing  

## Technologies Used
- C++  
- Object Oriented Programming  
- File Input and Output  
- Git and GitHub  

## Core Logic
The system is built around a base Product class extended by specialized product types. InventoryManager coordinates loading, updating, and saving inventory data to a text file. The design allows new product categories to be added without modifying existing logic.

## Project Structure
Bushras_Bazaar/
├── main.cpp
├── InventoryManager.cpp
├── InventoryManager.hpp
├── Product.cpp
├── Product.hpp
├── Tobacco.cpp
├── Tobacco.hpp
├── LotteryTickets.cpp
├── LotteryTickets.hpp
└── Inventory.txt


## How to Run Locally
1. Compile all source files using a C++ compiler  
2. Run the generated executable from the terminal  

## Future Improvements
- Input validation and error handling  
- Support for additional product categories  
- Transition to a database backed system  
