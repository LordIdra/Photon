git pull
g++ -std=c++17 -Isrc src/Assembler/Assembler.cpp src/CommandLine/CommandLine.cpp src/ComponentTest/ComponentTest.cpp src/ComponentTest/ComponentTestPrint.cpp src/ComponentTest/ComponentTests.cpp src/ComponentTest/IntegrationTests.cpp src/Electronics/Debug.cpp src/Electronics/GPIO.cpp src/Electronics/ProgramMemory.cpp src/Files/Files.cpp src/SimulationTestBuilder/SimulationTestBuilder.cpp src/Util/Errors.cpp src/Util/Timer.cpp src/Util/Util.cpp src/main.cpp -lwiringPi -lstdc++fs -o photon