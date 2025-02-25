#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void extractLogs(const std::string &logFile, const std::string &searchDate) {
    std::ifstream inFile(logFile);
    if (!inFile) {
        std::cerr << "Error: Cannot open file '" << logFile << "'\n";
        return;
    }

    std::string outputDir = "output";
    fs::create_directories(outputDir);
    std::string outputFile = outputDir + "/output_" + searchDate + ".txt";

    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error: Cannot create output file '" << outputFile << "'\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (line.rfind(searchDate, 0) == 0) { // Check if line starts with searchDate
            outFile << line << "\n";
        }
    }

    std::cout << "Logs for " << searchDate << " saved in: " << outputFile << "\n";

    inFile.close();
    outFile.close();
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <log_file_path> <YYYY-MM-DD>\n";
        return 1;
    }

    std::string logFilePath = argv[1];
    std::string dateToSearch = argv[2];

    extractLogs(logFilePath, dateToSearch);

    return 0;
}
