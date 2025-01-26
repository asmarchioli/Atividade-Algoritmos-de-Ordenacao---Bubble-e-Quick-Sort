#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>

struct DishRecord {
    int priority;
    int time;
    std::string name;
};

std::vector<DishRecord> readCSV(const std::string& filename) {
    std::vector<DishRecord> dishes;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return dishes;
    }

    std::string line;
    // Pula o cabeçalho
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        DishRecord record;
        std::string priority_str, time_str;

        if (std::getline(ss, priority_str, ',') &&
            std::getline(ss, time_str, ',') &&
            std::getline(ss, record.name, ',')) {
            try {
                record.priority = std::stoi(priority_str);
                record.time = std::stoi(time_str);
                dishes.push_back(record);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid data: " << line << std::endl;
                continue; // Pula essa linha
            }
        }
    }

    file.close();
    return dishes;
}
